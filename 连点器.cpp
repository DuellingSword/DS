#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
POINT position; //Point为鼠标位置
float v;  //点击速度 
int total;  //点击总数 
int buffer;  //缓冲器
 
void Select(); //用于输入v和count
void Click(); //用于鼠标点击工作 
int main(int argc, char const *argv[])
{
 system("mode con cols=48 lines=20"); //窗口大小(cols控制列,lines控制行)
 system("title 重剑DS制作--鼠标左键连点器1.0");
 
 printf("1.此程序用于鼠标左键连点\n2.按空格开始、暂停或继续\n3.按Ctrl可以锁定或解锁鼠标\n4.按Esc退出程序");
 while(1){
  Select();
  Click();
 }
}
 
void Select()
{
 Sleep(300);       //(里面单位为ms) 
 printf("\n按下空格键开始\n");
 while(1){ 
 if(GetAsyncKeyState(VK_SPACE)){  //判断空格是否被按下
  system("cls"); 
  printf("请输入需要点击的速度 n 次/秒(n<=1000)↓\n");
  scanf("%f",&v);
  buffer = (int)(1000/v);    //四舍五入     
  printf("请输入需要点击的总数 N 次( 0为接近无限次)↓\n");
  scanf("%d",&total);
  total==0? 2147483647/*以一个很大的数字来表示接近无限次*/:total; 
  system("cls");
  break;
 }
 } 
    
}

void Click()  
{
 Sleep(300);     
 printf("速度是%d次/秒\n点击的总数是%d\n",(int)v,total);
 printf("1.输入空格开始、暂停、继续或重复现参数的操作\n2.输入Enter重新设置参数\n3.输入Esc退出程序\n");
 while(1){
   if(GetAsyncKeyState(VK_SPACE)){   //以是否输入空格判断开始工作 
    printf("开始运行\n");
    int cnt = total;    //初始化 
  while(cnt--){    
   if(GetAsyncKeyState(VK_CONTROL)){ //判断是否按下Ctrl 
    if(position.x || position.y){
     position.x = 0;
     position.y = 0;
     printf("已解锁\n");
   }else{
    GetCursorPos(&position); //得到鼠标位置 
    printf("已锁定, x=%d y=%d\n",(int)position.x,(int)position.y);
   } 
  } 
  
  Sleep(buffer); //用于缓冲(很重要这一步!!!)  
  
    if(GetAsyncKeyState(VK_SPACE)){
    printf("已暂停\n");
    while(1){
     if(GetAsyncKeyState(VK_SPACE)){
      printf("继续\n");
      break;
     }else if(GetAsyncKeyState(VK_ESCAPE)){
      printf("结束程序\n");
      exit(0);
     } 
    }
   }
     
    if(position.x||position.y) SetCursorPos(position.x,position.y); //移动鼠标到指定位置(前提是已经按下Ctrl来固定位置)
   mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0); //模拟鼠标左键按下 
   mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); //模拟鼠标左键松开
  }
  
  Sleep(400);    //防止如v=1, total=1的情况,因为这样后面会读到空格而导致bug  
  printf("\n运行结束,请根据上述提示输入:\n");
  while(1){
  if(GetAsyncKeyState(VK_SPACE)) break;
  if(GetAsyncKeyState(VK_RETURN)) return;
  if(GetAsyncKeyState(VK_ESCAPE)) exit(0);
 } 
}
}
}

