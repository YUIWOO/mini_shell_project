#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
    int fd;

    fd = open("anyfile", O_RDONLY);
    fd = -1;
    if (1)
    {
        perror("open");
        perror("zsh");
        exit(1);
    }
    return 0;

}