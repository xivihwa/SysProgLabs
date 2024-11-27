#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h> 

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Factorial Kernel Module");
MODULE_AUTHOR("Antonenko Violetta");

static int n;

static int factorial(int num) {
    if (num < 0) { 
        return -1; 
    }
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

static ssize_t write_func(struct file *filp, const char __user *buf, size_t count, loff_t *offp) {
    ssize_t ret;

    if (count < sizeof(int)) {
        return -EINVAL;
    }

    ret = copy_from_user(&n, buf, sizeof(int)); 
    if (ret) {
        return -EFAULT; 
    }

    printk(KERN_INFO "Factorial module received number: %d\n", n);

    return sizeof(int); 
}

static ssize_t read_func(struct file *filp, char __user *buf, size_t count, loff_t *offp) {
    char result_str[64]; 
    int factorial_result = factorial(n);

    if (factorial_result == -1) {
        snprintf(result_str, sizeof(result_str), "Invalid input: negative number\n");
    } else {
        snprintf(result_str, sizeof(result_str), "Factorial of %d is %d\n", n, factorial_result);
    }

    return simple_read_from_buffer(buf, count, offp, result_str, strlen(result_str));
}

static struct file_operations fops = {
    .write = write_func,
    .read = read_func,
};

static struct miscdevice miscdev = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = "factorial",
    .fops = &fops,
};

static int __init factorial_init(void) {
    int ret = misc_register(&miscdev);
    if (ret) {
        printk(KERN_ERR "Failed to register factorial device\n");
        return ret;
    }
    printk(KERN_INFO "Factorial module loaded\n");
    return 0;
}

static void __exit factorial_exit(void) {
    misc_deregister(&miscdev);
    printk(KERN_INFO "Factorial module unloaded\n");
}

module_init(factorial_init);
module_exit(factorial_exit);
