#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{
    int fd;
    int ubuff;
    fd=open("/dev/read_device",O_RDWR,0777);
    if(fd > 0)
    {
        printf("Device file open successfully\n");
        
    }
    else
    {
        printf("cannot open device file\n");
        return 0;
    }
    printf("Data reading");
    read(fd,(char *)&ubuff, sizeof(ubuff));
    printk("Done!\n\n");
    printf("Data=%d\n\n", ubuff);
        close(fd);
    return 0;
}