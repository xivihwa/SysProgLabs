#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int fd;
    int num;
    char buffer[64];

    printf("Enter a number: ");
    scanf("%d", &num);

    fd = open("/dev/factorial", O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return 1;
    }

    if (write(fd, &num, sizeof(int)) != sizeof(int)) {
        perror("Failed to write to the device");
        close(fd);
        return 1;
    }

    if (read(fd, buffer, sizeof(buffer)) < 0) {
        perror("Failed to read from the device");
        close(fd);
        return 1;
    }

    printf("Factorial calculated by the Kernel module: %s\n", buffer);

    close(fd);
    return 0;
}
