//Space Shooting Game.
//Mouse controlled game.
//Fire when clicked.
//Fire at blue boxes not green boxes.
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

void main()
{
union REGS i,o;

int gd=DETECT,gm,sco=0,fire=20;
float x,y;                              //mouse  coordinates
float fifx,fify,filx,fily,firx,firy;    //firing coordinates
float ox1=0,oy1=0,ox2=0,oy2=0;		//object coordinates
float ox01=0,oy01=0,ox02=0,oy02=0,ox03=0,oy03=0;      //our object coordinates
int r;
initgraph(&gd,&gm,"c://TurboC3//BGI");

for(r=0;r<=5;r++)
{
setcolor(r+1);
settextstyle(1,0,r+2);
outtextxy(225-r*28,200-r*3,"SPACE SHOOTING");
delay(100);
if(r!=5){cleardevice();}
}
getch();
i.x.ax=1;
int86(0x33,&i,&o);


while(!kbhit())
{
start:
cleardevice();
settextstyle(1,0,2);
setcolor(4);
outtextxy(275,10,"Score = ");
gotoxy(301,2);
cout<<sco;
outtextxy(450,10,"Firing left = ");
gotoxy(73,2);
cout<<fire;
i.x.ax=3;
int86(0x33,&i,&o);
x=o.x.cx;
y=o.x.dx;

/*setcolor(15);
line(250,10,250,475);
line(350,10,350,475);
line(450,10,450,475);*/

setcolor(14);
rectangle(x-25,y-25,x+25,y+25);
rectangle(x-5,y-40,x+5,y-25);


setcolor(1);
rectangle(10 +ox1 ,10 +oy1 ,30 +ox1 ,30+oy1);   ox1+=2;oy1+=2;  //object 01
rectangle(610-ox2 ,10 +oy2 ,640-ox2 ,30+oy2);   ox2+=3;oy2+=3;  //object 02

setcolor(3);
rectangle(50 +ox01,10 +oy01,70 +ox01,30+oy01); ox01+=2;oy01+=3; //our object 01
rectangle(20 +ox02,100+oy02,40 +ox02,70+oy02); ox02+=3;oy02+=2; //our object 02
rectangle(600-ox03,20 +oy03,620-ox03,40+oy03); ox03+=3;oy03+=1; //our object 03

int detcl;  i.x.ax=3;   detcl=o.x.bx;


if(detcl==1)    {setcolor(4);  fifx=x;	fify=y; fire--;
		while(1)  {     rectangle(fifx-3,fify-50,fifx+3,fify-40);   fify-=0.0625;

				if(fify<=5) { goto start;}			}
		}
/*if(detcl==2)    {setcolor(4);
		 fifx=x;   filx=x;   firx=x;
		 fify=y;   fily=y;   firy=y;
		while(1) { 	rectangle(fifx-3 ,fify-50,fifx+3 ,fify-40);
				rectangle(filx-25,fily+3 ,filx-30,fily-3 );
				rectangle(firx+25,firy+3 ,firx+30,firy-3 );
				fify-=0.0625;  filx-=0.125;   firx+=0.125;
				if(fify<=5 && filx<=5 && firx>=630){goto start;}
			 }
		}*/

if(fifx+3>10 +ox1  && fifx-3<30 +ox1 ) {  ox1=300;oy1=10 ;sco++;  }
if(fifx+3>610-ox2  && fifx-3<640-ox2 ) {  ox2=300;oy2=10 ;sco++;  }

if(fifx+3>50 +ox01 && fifx-3<70 +ox01) {ox01=10 ;oy01=150;sco-=2; }
if(fifx+3>20 +ox02 && fifx-3<40 +ox02) {ox02=350;oy02=0  ;sco-=2; }
if(fifx+3>600-ox03 && fifx-3<620-ox03) {ox03=640;oy03=50 ;sco-=2; }

fifx=650;
if(10 +ox1>=getmaxx() || 10 +oy1>=getmaxy() )	{ ox1=0;oy1=0; }
if(640-ox2<=0	      || 10 +oy2>=getmaxy() )	{ ox2=0;oy2=0; }


if(fire<=0){	outtextxy(100,150,"GAME OVER 	Your Score = ");
		gotoxy(45,11);
		cout<<sco;
		goto end;
	   }

delay(100);
}
end:
getch();                                                                                                                                                                      //By R.Pravin

}

