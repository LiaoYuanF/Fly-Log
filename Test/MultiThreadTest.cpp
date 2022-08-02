#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/unistd.h>
#include<thread>
#include<string.h>

using namespace std;

#define	FILE_NAME	"demo.txt"
#define	err_exit(m)	{perror(m); exit(1);}
int	fd;	//设置成全局变量，方便下面的程序访问
int	main(){
    /************************参数说明如下：***********************************
    *O_RDWR	  对文件的操作权限，可读可写操作
    *O_CREAT  如果文件不存在就新建该文件，用于记录写入内容；后面的0644设定文件的进入权限
    *O_TRUNC  每次打开文件的时候都清空文件原先的内容
    *O_APPEND 设定定位与写入操作的原子性，每次写入都追加到文件末尾
    ***********************************************************************/
    void* 	func1();
    void* 	func2();
    void* 	func3();
    void* 	func4();
    std::thread thread1(func1);
    std::thread thread2(func2);
    std::thread thread3(func3);
    std::thread thread4(func4);
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    return 0;
}
void* func1(){
    int fd = open(FILE_NAME, O_RDWR | O_CREAT | O_TRUNC | O_APPEND , 0644);
    if(fd > 0)
        std::cout << "func fd1 create success\n";
    char buffer[100];
    memset(buffer, 'a', 20);
    memset(buffer, '\n', 1);
    write(fd, buffer, 21);
}
void* func2(){
    int fd = open(FILE_NAME, O_RDWR | O_CREAT | O_TRUNC | O_APPEND , 0644);
    if(fd > 0)
        std::cout << "func fd2 create success\n";
    char buffer[100];
    memset(buffer, 'b', 20);
    memset(buffer, '\n', 1);
    write(fd, buffer, 21);
}
void* func3(){
    int fd = open(FILE_NAME, O_RDWR | O_CREAT | O_TRUNC | O_APPEND , 0644);
    if(fd > 0)
        std::cout << "func fd3 create success\n";
    char buffer[100];
    memset(buffer, 'c', 20);
    memset(buffer, '\n', 1);
    write(fd, buffer, 21);
}
void* func4(){
    int fd = open(FILE_NAME, O_RDWR | O_CREAT | O_TRUNC | O_APPEND , 0644);
    if(fd > 0)
        std::cout << "func fd4 create success\n";
    char buffer[100];
    memset(buffer, 'd', 20);
    memset(buffer, '\n', 1);
    write(fd, buffer, 21);
}
