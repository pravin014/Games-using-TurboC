//ready with numbers and arrows.
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
void main()
{
int gd=DETECT,gm;
clrscr();
cout<<"\n\n\n\n";
initgraph(&gd,&gm,"c://TurboC3//BGI");
//settextstyle(1,1,6);
//gotoxy(1.5,30);
//cout<<"\n\n    1     2      3\n\n\n    4     5      6\n\n\n    7     8      9";

int C[10],X[10],i,play=1;
int num=0,x,y;

for(i=0;i<=5;i++)
{
setcolor(i+1);
settextstyle(1,0,i+2);
outtextxy(275-i*28,200-i*3,"TIC-TAC-TOE");
delay(100);
if(i!=5){cleardevice();}
}
getch();
cleardevice();

setcolor(4);
line(60,10,60,160);  line(110,10,110,160);        //vertical lines
line(10,60,160,60);  line(10,110,160,110);        //horizontal lines

for(i=0;i<=9;i++)  { C[i]=0; X[i]=0; }		 //Zero maker

while(1)
{
i=0; x=0; y=0;
num=getch();

if(num==27)   break;                             //exit condition
if(num<49 && num<57) { num=0; }                  //checking number or not

if(num>=71 && num<=73)    { num=num-22; }        //num val change at arrow
if(num>=75 && num<=77)    { num=num-23; }
if(num>=79 && num<=81)    { num=num-24; }

if(play==1 || play==3 || play==5 || play==7 || play==9)   //X to play
  {
  if(C[num-48]==0 && X[num-48]==0)                        //checking not repeated
	{
	if(num==49 || num==52 || num==55)  { x=19 ; X[num-48]=1;}
	if(num==50 || num==53 || num==56)  { x=69 ; X[num-48]=1;}
	if(num==51 || num==54 || num==57)  { x=119; X[num-48]=1;}
	if(num==49 || num==50 || num==51)  { y=19 ; }
	if(num==52 || num==53 || num==54)  { y=69 ; }
	if(num==55 || num==56 || num==57)  { y=119; }
	}

  if(x>0) {
	  setcolor(YELLOW);
	  line(x,y,x+32,y+32 );   line(x+32,y,x,y+32);    //Put X
	  play++;
	  }

  }

else if(play==2 || play==4 || play==6 || play==8)         //O to play
  {
  if(C[num-48]==0 && X[num-48]==0)                        //checking not repeated
	{
	if(num==49 || num==52 || num==55)  { x=30 ; C[num-48]=1;}
	if(num==50 || num==53 || num==56)  { x=87 ; C[num-48]=1;}
	if(num==51 || num==54 || num==57)  { x=135; C[num-48]=1;}
	if(num==49 || num==50 || num==51)  { y=33 ; }
	if(num==52 || num==53 || num==54)  { y=85 ; }
	if(num==55 || num==56 || num==57)  { y=138; }
	}

  if(x>0) { setcolor(BLUE); circle(x,y,15); play++;}                      //put O
  }


if(C[1]+C[2]+C[3]==3 || C[4]+C[5]+C[6]==3 || C[7]+C[8]+C[9]==3 || C[1]+C[4]+C[7]==3 || C[2]+C[5]+C[8]==3 || C[3]+C[6]+C[9]==3 || C[1]+C[5]+C[9]==3 || C[3]+C[5]+C[7]==3  )     //O win condition
{	cout<<"\n\n\n\n\n\n\n\n\n\n\n Player 2 has WON the match\n\n\n Player 1 try again\n BETTER LUCK NEXT TIME "; break; }
if(X[1]+X[2]+X[3]==3 || X[4]+X[5]+X[6]==3 || X[7]+X[8]+X[9]==3 || X[1]+X[4]+X[7]==3 || X[2]+X[5]+X[8]==3 || X[3]+X[6]+X[9]==3 || X[1]+X[5]+X[9]==3 || X[3]+X[5]+X[7]==3  )     //X win condition
{	cout<<"\n\n\n\n\n\n\n\n\n\n\n Player 1 has WON the match\n\n\n Player 2 try again\n BETTER LUCK NEXT TIME ";  break; }

if(play==10)	{ cout<<"\n\n\n\n\n\n\n\n\n\n\n     Match DRAW \n     TRY AGAIN\n BETTER LUCK NEXT TIME"; break;}                                                              //Draw conditon
}
getch();                                                                                                                                                                                                                                                                          //By R.Pravin
closegraph();
}