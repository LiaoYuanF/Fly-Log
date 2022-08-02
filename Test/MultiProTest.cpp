//
// Created by zhoux on 2022/8/2.
//
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>


#define	FILE_NAME	"demo.txt"
#define	err_exit(m)	{perror(m); exit(1);}

int	main(){
    int	fd;
    /************************参数说明如下：***********************************
    *O_RDWR	  对文件的操作权限，可读可写操作
    *O_CREAT  如果文件不存在就新建该文件，用于记录写入内容；后面的0644设定文件的进入权限
    *O_TRUNC  每次打开文件的时候都清空文件原先的内容
    *O_APPEND 设定定位与写入操作的原子性，每次写入都追加到文件末尾
    ***********************************************************************/
    fd = open(FILE_NAME, O_RDWR | O_CREAT | O_TRUNC | O_APPEND , 0644);
    if(fd == -1) err_exit("open error");
    int	pid;
    char	buf[1048576];		//设定一个很大的数组4096*1024，测试其他进程是否可以打断该操作。
    memset(buf, 'a', 1048575);	//将该数组的内容设定为"aaaaaaa...\n",方便我们观测。
    memset(buf+1048575,'\n',1);
    if((pid = fork()) < 0) err_exit("fork error");
    //利用fork产生子进程，共享同一个文件句柄，可以实现多进程的情形。
    if(pid == 0){
        for(int i = 0; i < 10; i++){
            write(fd, buf, 1048576);
        }
    }else if(pid > 0){

        for(int i = 0; i < 100; i++){
            write(fd, "bbb\n", 4);
        }
        //wait(-1);//等待子进程结束，防止僵尸进程的出现；
    }
    if(close(fd) == -1) err_exit("close error");
    return 0;
}