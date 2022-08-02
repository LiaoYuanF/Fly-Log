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
    /************************����˵�����£�***********************************
    *O_RDWR	  ���ļ��Ĳ���Ȩ�ޣ��ɶ���д����
    *O_CREAT  ����ļ������ھ��½����ļ������ڼ�¼д�����ݣ������0644�趨�ļ��Ľ���Ȩ��
    *O_TRUNC  ÿ�δ��ļ���ʱ������ļ�ԭ�ȵ�����
    *O_APPEND �趨��λ��д�������ԭ���ԣ�ÿ��д�붼׷�ӵ��ļ�ĩβ
    ***********************************************************************/
    fd = open(FILE_NAME, O_RDWR | O_CREAT | O_TRUNC | O_APPEND , 0644);
    if(fd == -1) err_exit("open error");
    int	pid;
    char	buf[1048576];		//�趨һ���ܴ������4096*1024���������������Ƿ���Դ�ϸò�����
    memset(buf, 'a', 1048575);	//��������������趨Ϊ"aaaaaaa...\n",�������ǹ۲⡣
    memset(buf+1048575,'\n',1);
    if((pid = fork()) < 0) err_exit("fork error");
    //����fork�����ӽ��̣�����ͬһ���ļ����������ʵ�ֶ���̵����Ρ�
    if(pid == 0){
        for(int i = 0; i < 10; i++){
            write(fd, buf, 1048576);
        }
    }else if(pid > 0){

        for(int i = 0; i < 100; i++){
            write(fd, "bbb\n", 4);
        }
        //wait(-1);//�ȴ��ӽ��̽�������ֹ��ʬ���̵ĳ��֣�
    }
    if(close(fd) == -1) err_exit("close error");
    return 0;
}