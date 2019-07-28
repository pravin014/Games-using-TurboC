//Car in worng way.
//verion 2.0
//sucess - trying to include distance measurer.
//trying to make more obstacle.
//sucess with four obstacle. It is enough no. of obstacle.
//sucess - trying to completely color obstacles.
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
void main()
{
start:
int gd=DETECT,gm;
int val,i;
int x=1,y=0,life=10,lev=1;
int ox[5],oy[5];
int met=0,km=0;
clrscr();

initgraph(&gd,&gm,"c://TurboC3//BGI");

for(i=0;i<=5;i++)
{
setcolor(i+1);
settextstyle(1,0,i+2);
outtextxy(270-i*28,200-i*3,"WORNG WAY");
delay(100);
if(i!=5){cleardevice();}
}
getch();


setfillstyle(0,GREEN);

for(i=0;i<=3;i++)    {  oy[i]=0;  }			    //Zero maker

ox[0]=0;
for(i=1;i<=3;i++)    {  ox[i]=ox[i-1]+1;  }                 //ox[0]=0,ox[1]=1,ect.

while(1)
{
val=0;                                                          //input val=0
setcolor(15);
setfillstyle(1,6);
line(8,30,150,30);                                              // box top
line(8,450,150,450);                                            // box bottom
line(8,30,8,450);                                               // box start
line(150,30,150,450);                                           // box & 1
floodfill(149,449,15);
line(250,30,250,450);                                           // lane 1&2
line(350,30,350,450);                                           // lane 2&3
line(450,30,450,450);                                           // lane 3 and opp. border

if(kbhit())  { val=getch(); }                                   //get input val
if(val==27)  break;                                             //exit condition

else if(val==77 && x!=2)   {   x++;     }			//move right
else if(val==75 && x!=0)   {   x--;     }			//move left
else if(val==72 && y<10)   {   y++;     }			//move up
else if(val==80 && y>0)    {   y--;     }			//move down

setcolor(14);
setfillstyle(9,4);
rectangle(175+(x*100),375-(y*25),225+(x*100),425-(y*25));       //rectangle car
floodfill(176+x*100,376-y*25,14);

for(i=0;i<=3;i++)
  {
  setcolor(10+i);
  setfillstyle(1,9+i);
  rectangle((ox[i]*100)+185,31+oy[i],(ox[i]*100)+215,51+oy[i]); //obstacle
  floodfill(ox[i]*100+186,32+oy[i],10+i);

  if(x==ox[i] && 51+oy[i]>375-(y*25) && 31+oy[i]<425-(y*25))	//minus life condition
  { life--;
  setcolor(8);
  setfillstyle(1,14);
  circle(200+x*100,400-y*25,10);
  floodfill(200+x*100,400-y*25,8);
  gotoxy(7,15);   cout<<"DAMAGE";
  }

  if(31+oy[i]>=500) { oy[i]=0; ox[i]+=1;  }			//max y checker
  if(ox[i]>=3)  { ox[i]=0; oy[i]=-500;}				//max x checker

  oy[i]+=(5*i)+5;
  }


met++;  if(met>=100)  {  km++; met=0;  }			//distance

if(km>1 && (km+1)%3==0 && met==90)                              //restart obstacles
	{
	for(i=0;i<=3;i++)   {  oy[i]=0;  }			//Zero maker
	ox[0]=0;
	for(i=1;i<=3;i++)   { ox[i]=ox[i-1]+1 ; }               //ox[0]=0,ox[1]=1,etc
	}

gotoxy(3,5);  cout<<"DISTANCE = "<<km<<":"<<met;                //distance output
gotoxy(5,7);  cout<<"LIFE   = "<<life;                  //life output
gotoxy(4,9);  cout<<"LEVEL  = "<<lev;
gotoxy(3,11); cout<<"TARGET = "<<lev*15<<"Km";
if(km>1 && km%(lev*15)==0)
     {
     gotoxy(15,15);
     cout<<"CONRAGULATIONS YOU HAVE COMPLETED LEVEL "<<lev;
     gotoxy(17,17);
     cout<<" TRY TO COMPLETE OTHER LEVELS";
     lev++; met=0; km=0;
     life+=3;
     getch();
     }

if(life<=0) { goto end; }

delay(100);
cleardevice();
}
end:
gotoxy(37,6 );  cout<<"GAME OVER";
gotoxy(33,8 );	cout<<"Current level = "<<lev;
gotoxy(30,10);  cout<<"Distance Travelled = "<<km<<":"<<met;
gotoxy(24,12);  cout<<"TRY TO TRAVEL MORE DISTANCE NEXT TIME";
gotoxy(27,16);  cout<<"PRESS   R   TO PLAY AGAIN";
val=getch();
if(val==114 || val==82) { goto start; }

getch();                                                                                                                                                                      //R.Pravin
closegraph();
}
