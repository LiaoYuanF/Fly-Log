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
int	fd;	//���ó�ȫ�ֱ�������������ĳ������
int	main(){
    /************************����˵�����£�***********************************
    *O_RDWR	  ���ļ��Ĳ���Ȩ�ޣ��ɶ���д����
    *O_CREAT  ����ļ������ھ��½����ļ������ڼ�¼д�����ݣ������0644�趨�ļ��Ľ���Ȩ��
    *O_TRUNC  ÿ�δ��ļ���ʱ������ļ�ԭ�ȵ�����
    *O_APPEND �趨��λ��д�������ԭ���ԣ�ÿ��д�붼׷�ӵ��ļ�ĩβ
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
