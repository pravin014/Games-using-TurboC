#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>
#include<stdlib.h>
//void mousecor();   int mousexcor();   int mouseycor();   int mouseclk();
//union REGS i,o;
void main()
{
union REGS i,o;
int gd=DETECT,gm;
int mx,my,mco=0;
char read[100],del=0;
int sco=0;
int o1=-1,o1t=0,o1s=0;
float o1x=0,o1y=0,o1r=0,o1i=0,j1=4;
int j;
clrscr();	randomize();
initgraph(&gd,&gm,"c://turboc3//bgi");

for(j=0;j<=5;j++)
{
setcolor(j+1);
settextstyle(1,0,j+2);
outtextxy(300-j*28,200-j*3,"SHOOTING");
delay(100);
if(j!=5){cleardevice();}
}
for(j=0;j<=8;j++)
{
setcolor(9-j);
rectangle(295-3*j,300-3*j,295+3*j,300+3*j);
delay(100);
}
putpixel(295,300,4);
getch();

setcolor(15);
while(1)
{
strcpy(read,"A");    o1++;
if(kbhit()) { cin>>read; }
gotoxy(10,1); cout<<"score="<<sco<<"  "<<o1i<<"  "<<o1t<<endl;
i.x.ax=3;  int86(0x33,&i,&o);  mx=o.x.cx; my=o.x.dx;
if(stricmp(read,"mousho")==0)   { i.x.ax=1;   int86(0x33,&i,&o);  }
if(stricmp(read,"mouoff")==0)   { i.x.ax=2;   int86(0x33,&i,&o);  }
if(stricmp(read,"moucor")==0)   { cout<<mx<<"  "<<my;  delay(200); }
if(stricmp(read,"delay")==0)    { cin>>del; }
if(stricmp(read,"o1touch")==0)  { cout<<o1t<<" "<<o1i;}
if(stricmp(read,"o1stop")==0)   { cin>>o1s; }
circle(mx,my,20);  line(mx-20,my,mx+20,my);  line(mx,my-20,mx,my+20);   //gun

if(o1%50==0&&o1s==0)
{ o1r=random(20)+10; o1x=random(640-2*o1r)+o1r; o1y=random(480-2*o1r)+o1r; }  //target genrator
circle(o1x,o1y,o1r); circle(o1x,o1y,o1r/2);   circle(o1x,o1y,o1r/4);   //target
setfillstyle(1,4);  floodfill(o1x,o1y,15);
setfillstyle(1,7);  floodfill(o1x+o1r/2-1,o1y,15);
setfillstyle(1,1);  floodfill(o1x+o1r-1,o1y,15);


for(j1=4;j1>=1;j1/=2)
{ o1i=(mx-o1x)*(mx-o1x)+(my-o1y)*(my-o1y)-o1r*o1r/(j1*j1);    //inside or not
if(o1i<=0) { o1t=j1; break; } }    			      //if inside
if(j1<1)  o1t=0;

mco=o.x.bx;                                                      //clk sensor
if(o1t!=0&&mco==1) { sco+=5*o1t; o1=-1; }                      //if correct score++


{}if(stricmp(read,"exit")==0) { break; }
delay(del);
delay(50); cleardevice();
}
}

/*void mousecor()
{
int x,y;  i.x.ax=3;  int86(0x33,&i,&o);
x=o.x.cx; y=o.x.dx; cout<<x<<"  "<<y;
}

int mousexcor()  { int x; i.x.ax=3;   int86(0x33,&i,&o);   x=o.x.cx; return x; }
int mouseycor()  { int x; i.x.ax=3;   int86(0x33,&i,&o);   x=o.x.dx; return x; }
int mouseclk()   { int x; i.x.ax=3;   int86(0x33,&i,&o);   x=o.x.bx; return x; }
*/

