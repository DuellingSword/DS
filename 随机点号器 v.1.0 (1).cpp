#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
static const int MAXN=100;//limit

struct Information //�洢��Ϣ 
{
	char name[MAXN];
}info[MAXN];

  FILE *fp;
  int temp;
  char ch;
  bool occupy[MAXN];
  char line[MAXN];
  char filename[MAXN];
  char namestr[MAXN]; //�����û��Լ���������� 

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
 cout<<"Welcome OVO~\n\n����1Ϊ��ȡ�ļ�(.txt), ����2Ϊ�ֶ�������������.\n";
 cin>>temp;
 getchar();
 
 if(temp == 1) { //����txt�ı��ļ� 
 	
	cout<<"�������ļ�����\n";
 	cin.getline(filename,MAXN);
 	fp=fopen(filename,"r"); //�����ı��ļ�
	  
 if(fp==NULL) { 
	cout<<"�޷����ļ���\n";
	exit(0);
  } 
  
}else{ //�ֶ��������� 
	
  	cout<<"���뼸������(���ּ��Կո�ָ�, ��-1����)��\n";
  	fp=fopen("Test111.txt","w+");
  	cin>>namestr;
  	while(namestr[0] != '-') {
  		fputs(namestr,fp);
  		fputc('\n',fp);
  		cin>>namestr;
  	}
  	rewind(fp);//ʹ�ļ�λ�ñ�Ƿ����ļ���ͷ 
  	
}
 
 puts("Everything is ready.\n");
}

inline void work()
{ 
	
	while(fgets(line,sizeof(line),fp)) if(line[0]!='\n'&&line[0]!=' ') sscanf(line,"%s\n",info[cnt++].name);//input information
 	cout<<"���¿ո�����һ��������֣������������˳�����.\n";
  
 	srand(time(0));//time(0)�ķ��ص��Ǵ�1970 UTC Jan 1 00:00����ǰʱ�̵�������Ϊunsigned int����
 while((ch=getch())==' ') //ʵ��������ܵĺ��Ĳ���! 
 {

  int randnum=rand()%cnt; //���������randnum 
  
  while(occupy[randnum]) randnum=rand()%cnt; //ʵ�ַ�ֹ�ظ���ȡ���� 
  occupy[randnum]=true;
  
  printf("%s\n",info[randnum].name);
  system("pause");//�ӳ�������á�pause�����
    
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
 copyright();//Production instructions  ����˵��ģ�� 
 input();//Input module ����ģ�� 
 work();//Core work points ���Ĺ�����ģ�� 
 fclose(fp);//�ر������ļ� 
 return 0;
}
