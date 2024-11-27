#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/random.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/list.h> // Обязательно для LIST_HEAD и связанных операций

MODULE_AUTHOR("Antonenko Violetta");
MODULE_DESCRIPTION("Inversion of elements in list");
MODULE_LICENSE("GPL");

#define LIST_LEN 10
#define MSG_PREP "TEST: "

struct int_list_node {
    struct list_head list;
    int data;
};

LIST_HEAD(int_list);

static void invert_list(void) { 
    struct int_list_node *entry, *temp;
    list_for_each_entry_safe(entry, temp, &int_list, list) {
        entry->data = 9 - entry->data;
    }
}

static void print_list(void) {
    struct int_list_node *current_node;
    printk(KERN_INFO "List content:\n");
    list_for_each_entry(current_node, &int_list, list) {
        printk(KERN_INFO "Data: %d\n", current_node->data);
    }
}

static int __init list_module_init(void) {
    int i;
    printk(KERN_INFO "Loading module\n");
    for (i = 0; i < LIST_LEN; i++) {
        struct int_list_node *new_node = kmalloc(sizeof(*new_node), GFP_KERNEL);
        if (!new_node) {
            printk(KERN_ALERT "Allocation failed\n");
            return -ENOMEM;
        }
        new_node->data = i;
        list_add_tail(&new_node->list, &int_list);
    }
    print_list();
    invert_list();
    print_list();
    return 0;
}

static void __exit list_module_exit(void) {
    struct int_list_node *entry, *temp;
    printk(KERN_INFO "Unloading module\n");
    print_list();
    list_for_each_entry_safe(entry, temp, &int_list, list) {
        list_del(&entry->list);
        kfree(entry);
    }
}

module_init(list_module_init);
module_exit(list_module_exit);
