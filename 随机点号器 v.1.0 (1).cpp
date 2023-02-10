#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
static const int MAXN=100;//limit

struct Information //存储信息 
{
	char name[MAXN];
}info[MAXN];

  FILE *fp;
  int temp;
  char ch;
  bool occupy[MAXN];
  char line[MAXN];
  char filename[MAXN];
  char namestr[MAXN]; //用于用户自己输入的数据 

int num,cnt,randnum;

inline void copyright()
{
 cout<<"Program Name: Random Name.\n";
 cout<<"Improver: DS\n";
 Sleep(500);
 cout<<"Get ready.\n"<<endl;
 //Sleep(1000);
}

inline void input()
{
 cout<<"Welcome OVO~\n\n输入1为读取文件(.txt), 输入2为手动输入若干名字.\n";
 cin>>temp;
 getchar();
 
 if(temp == 1) { //导入txt文本文件 
 	
	cout<<"请输入文件名：\n";
 	cin.getline(filename,MAXN);
 	fp=fopen(filename,"r"); //读入文本文件
	  
 if(fp==NULL) { 
	cout<<"无法打开文件！\n";
	exit(0);
  } 
  
}else{ //手动输入名字 
	
  	cout<<"输入几个名字(名字间以空格分隔, 以-1结束)：\n";
  	fp=fopen("Test111.txt","w+");
  	cin>>namestr;
  	while(namestr[0] != '-') {
  		fputs(namestr,fp);
  		fputc('\n',fp);
  		cin>>namestr;
  	}
  	rewind(fp);//使文件位置标记返回文件开头 
  	
}
 
 puts("Everything is ready.\n");
}

inline void work()
{ 
	
	while(fgets(line,sizeof(line),fp)) if(line[0]!='\n'&&line[0]!=' ') sscanf(line,"%s\n",info[cnt++].name);//input information
 	cout<<"按下空格生成一个随机名字，按其它键则退出程序.\n";
  
 	srand(time(0));//time(0)的返回的是从1970 UTC Jan 1 00:00到当前时刻的秒数，为unsigned int类型
 while((ch=getch())==' ') //实现随机功能的核心部分! 
 {

  int randnum=rand()%cnt; //产生随机数randnum 
  
  while(occupy[randnum]) randnum=rand()%cnt; //实现防止重复抽取功能 
  occupy[randnum]=true;
  
  printf("%s\n",info[randnum].name);
  system("pause");//从程序里调用“pause”命令。
    
  if(++num==cnt)
  {
   puts("~Program has been exited.\n");
   puts("~Thank you for your using.\n");
   return ;
  }
  
 }
 
}

int main()
{
 copyright();//Production instructions  制作说明模块 
 input();//Input module 输入模块 
 work();//Core work points 核心工作点模块 
 fclose(fp);//关闭数据文件 
 return 0;
}
