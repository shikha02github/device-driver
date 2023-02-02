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
    int num1,num2;
    printf("Enter two number to write into driver\n");
    scanf("%d %d",&num1,&num2);
    int ubuff[2]={num1,num2};

    fd=open("/dev/write2_device",O_RDWR,0777)
    if(fd > 0)
    {
        printf("device successfully open\n");

    }
    else
    {
        printf("cannot open device file\n");
        return 0;
    }

    printf("Data writing");
    write(fd,(char *)buff,sizeof(ubuff));
    close(fd);
    return 0;
}