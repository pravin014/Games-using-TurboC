//Return to home planet game.
//Has How to play, levels.
//Has time, shop.
//Once pressed moves continuously.
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
void howplay(void);
void starting(void);
void level(void);
void shop(void);
void main()
{
start:
int   gd=DETECT,gm,val;                                  //graph & get
int   i;				   		 //for case
int   lev,rd;                                            //difficulty level,required dollars
int   x=0,dol=0,life=0;                                  //battle ship coordinates,dollars,life
int   sta=0;   					         //started or not
int   bla1=0,bla2=0,bla3=0,bla4=0,ebla=0;                //shop items
int   sec=0,min=0,ds=0;                                  //time
float fx[15],fy[15];                                     //circle bombs
float rx[1],ry[1];                                       //rectancle package
clrscr();

for(i=0;i<=14;i++)     { fy[i]=0; }    			 //zero maker
rx[0]=0;   ry[0]=0;    fx[0]=0;
for(i=1;i<=14;i++)     { fx[i] =  fx[i-1] + 55	  ;}     //fx val - circle val

initgraph(&gd,&gm,"c://TurboC3//BGI");                   //graph mode

starting();                                              //starting page

val=getch();
	     if(val==104 || val==72) { howplay(); val=0;}//If press h display how play
cleardevice();
   if(val==115 || val==83)  			 	 //If press s display shop
	{
	sho:
	cleardevice();
	shop();    val=0;

	gotoxy(50,6);   cout<<"DOLLARS YOU HAVE = "<<dol;
	if(sta==1) { gotoxy(50,7); cout<<" LIFES  YOU HAVE = "<<life; }
	gotoxy(50,8 ); 	cout<<"Small blast="<<bla1;
	gotoxy(50,9 ); 	cout<<"Big blast="<<bla2;
	gotoxy(50,10); 	cout<<"Mega blast="<<bla3;
	gotoxy(50,11); 	cout<<"Nuclear blast="<<bla4;

	val=getch();
							 //purchase input
	if(val==49 && dol-50  >=0) {bla1+=1; dol-=50 ;  }
	if(val==50 && dol-100 >=0) {bla2+=1; dol-=100;  }
	if(val==51 && dol-500 >=0) {bla3+=1; dol-=500;  }
	if(val==52 && dol-350 >=0) {life+=1; dol-=350;  }
	if(val==53 && dol-650 >=0) {life+=2; dol-=650;  }
	if(val==54 && dol-950 >=0) {life+=3; dol-=950;  }
	if(val==55 && dol-1400>=0) {bla3+=1; life+=3; dol-=1400; }
	if(val==56 && dol-1000>=0) {bla4+=1; dol-=1000; }
	val=0;

	gotoxy(30,20);
	cout<<"Press  S  to buy more.";
	val=getch();
	cleardevice();
	if(val==115)   { val=0; goto sho; }
	if(sta==1  )   { val=0; goto game;}
	}

level();
lev=getch();                                             //level input
cleardevice();

if     (lev==53) { rd=5000; life+=1; lev=5; }            //assing target/level
else if(lev==52) { rd=2500; life+=2; lev=4; }
else if(lev==51) { rd=1000; life+=3; lev=3; }
else if(lev==50) { rd=500 ; life+=3; lev=2; }
else   		 { rd=100 ; life+=5; lev=1; }

while(1)                                                 //infinite conditon
{
game:
sta=1;
for(i=0;i<=10;i++){                                      //max checker
		  if(fy[i]>415 )   { fy[i]=0 ; fx[i]+=25; }
		  if(ry[0]>450 )   { ry[0]=50; rx[0]+=30; }
		  if(fx[i]>600 )   { fx[i]=10;            }
		  if(rx[0]>500 )   { rx[0]=0 ;		  }
		  }

setcolor(4);
rectangle(rx[0]+100,ry[0]+20,rx[0]+125,ry[0]+45);        //package
ry[0]+=5;


setcolor(14);
circle(fx[0],fy[0]+8 ,10);  fy[0]+= 7;                   //bombs
circle(fx[1],fy[1]+10,10);  fy[1]+= 8;
circle(fx[2],fy[2]+25,10);  fy[2]+= 9;
circle(fx[3],fy[3]+0 ,10);  fy[3]+=10;
circle(fx[4],fy[4]+20,10);  fy[4]+= 6;
circle(fx[5],fy[5]+10,10);  fy[5]+=10;
circle(fx[6],fy[6]+20,10);  fy[6]+=11;
circle(fx[7],fy[7]+10,10);  fy[7]+= 9;
circle(fx[8],fy[8]+15,10);  fy[8]+=10;
circle(fx[9],fy[9]+10,10);  fy[9]+=12;
circle(fx[10],fy[10]+9,10); fy[10]+=14;


if(kbhit())  {  val=getch();  }                          //input key press
	if(val==77  && x<=480 ) {x+=35;}                 //move right
	if(val==75  && x>=-75 ) {x-=35;}                 //move left
	if(val==27 )	        {break;}                 //stop if press Esc
   else if(val==104) 		{ howplay(); val=0;}     //goto how to play
	if(val==115)            { goto sho;	   }	 //shop
	if(val==98  && bla1>0)  { bla1-=1; ebla=25 ; val=0;}  //small blast
	if(val==110 && bla2>0)  { bla2-=1; ebla=75 ; val=0;}  //big  blast
	if(val==109 && bla3>0)  { bla3-=1; ebla=125; val=0;}  //mega blast
	if(val==106 && bla4>0)  { bla4-=1; ebla=200; val=0;}  //nuclear blast
if(ebla!=0)
  {
  setfillstyle(1,14);
  int a=0;
  for(i=470;a<=15;i--)
   {
   a++;
   delay(3);  cleardevice();
   rectangle(10,i-(3*a),600,i-((35*a)+50));
   floodfill(100,i-(3*a)-10,14);
   }
  for(i=0;i<=10;i++)
	{
	fy[i]=0; fy[i]-=ebla;
	}
  ebla=0;
  }

setcolor(6);
rectangle(100+x,400,150+x,450);                          //battle ship

for(i=0;i<=10;i++)
  {
  if(fy[i]>390    && fx[i]+10>100+x && fx[i]-10<150+x)   //minus life,dollar condition
	       { life--;   dol-=10;  fy[i]=600;  }
  if(ry[0]+45>390 && rx[0]+125>100+x && rx[0]+100<150+x) //plus life,dollar condition
	       {
	       if(life<8) { life++; dol+=10;}
	       dol+=20;  ry[0]=-130; rx[0]+=30;
	       }
  }

gotoxy(5,2);                                             //move display point
cout<<"LIFE = "<<life;                                   //output life
cout<<"  DOLLARS = "<<dol;                              //output dollars
cout<<"  TIME = "<<min<<" min : "<<sec<<" sec";         //output time
cout<<"  LEVEL = "<<lev;                                 //output level
cout<<"  TARGET = "<<rd;                                //required dollars

ds++;
if(ds>=10)
    { sec++; ds=0;
      if(sec>=60)
	  {
	  min++; sec=0;
	  if(min>=15)
	      {
	      cout<<"TIME OUT";
	      goto end;
	      }
	  }
    }

cout<<"\n     Small blast="<<bla1;
cout<<"     Big blast="<<bla2;
cout<<"     Mega blast="<<bla3;
cout<<"     Nuclear blast="<<bla4;

if(life<=0 || dol>=rd) { goto end; }                     //game over if life=0 ,won if dollar>=target(rd)
delay(100);
cleardevice();
}

end:
closegraph();

if(dol>=rd)
{
cout<<"\n\n\n   CONGRATULATIONS YOU HAVE WON THE GAME. ";
cout<<"\n\n\n CAPTAIN X HAS RETURNED TO HIS PLANET SAFELY.";
cout<<"\n\n\n  EXTRA LIFE YOU HAVE = "<<life<<".";
cout<<"\n\n\n TRY TO COMPLETE GAME IN OTHER LEVELS.";
cout<<"\n\n\n       ALL THE BEST!!!";
}

else
{
cout<<"\n			GAME OVER";
cout<<"\n\n\n 		DOLLARS you have collected  = "<<dol;             //dollars collected
cout<<"\n\n\n		 Extra LIFES you have = "<<life;
cout<<"\n\n\n 		TRY TO COLLECT MORE DOLLARS NEXT TIME ";
}

cout<<"\n\n\n 		PRESS   R   TO PLAY AGAIN.";     //replay option
val=getch();                                             //input yes/no
if(val==82 || val==114)  { goto start; }                 //if yes start again

getch();                                                                                                                                                                                               //By R.Pravin
}


void starting(void)
{
int i;
for(i=0;i<=5;i++)
{
setcolor(i+1);
settextstyle(1,0,i+2);
outtextxy(300-i*28,200-i*3,"WATCHOUT");
delay(100);
if(i!=5){cleardevice();}
}
getch();
cleardevice();
settextstyle(1,0,2);
setcolor(4);
outtextxy(120,115,"WATCHOUT - the game you should play.");
gotoxy(10,11); cout<<"Watchout is the most amazing 2-D Game in the WORLD.";
	       cout<<"\n\t\t\tIT IS Designed BY PRAVIN.";
gotoxy(10,15); cout<<"\n\n\t Press   H   for HOW TO PLAY";
	       cout<<"\n\t Press   S   to view shop.";
}

void level(void)
{
gotoxy(10,3);
cout<<"\n\n\t SELECT DIFFICULTY LEVEL \n\n IT VARIES FROM 1 TO 5	";
cout<<"\n 1 - target = 100  dollars  , Life = 5";        //level options
cout<<"\n 2 - target = 500  dollars  , Life = 3";
cout<<"\n 3 - target = 1000 dollars  , Life = 3";
cout<<"\n 4 - target = 2500 dollars  , Life = 2";
cout<<"\n 5 - target = 5000 dollars  , Life = 1";
}

void howplay(void)
{
cleardevice();
gotoxy(5,2);
cout<<"\t\t\tHOW TO PLAY       PART(1)";
cout<<"\n\n The brown coloured rectangular box is your battle ship.";
cout<<"\n\n Your are from planet X.";
cout<<"\n\n You require 100, 500, 1000, 2500, 5000 DOLLARS in 1st, 2nd, 3rd, 4th, 5th       levels respectively to go back to your planet.";
cout<<"\n\n Your ship will have 5 lifes in 1st,2nd,3rd level and 3 lifes in 4th,5th level.";
cout<<"\n\n The yellow coloured circles are bombs and if they hit your ship you will lose   A LIFE and 10 DOLLARS.";
cout<<"\n\n The red coloured boxes are packages from your planet.";
cout<<"\n\n If you collect them you will get A LIFE and 20 DOLLARS.";
cout<<"\n\n Try to collect them quickly and go back to your planet.";
cout<<"\n\n\n\n\n WARNING The ship is hyper sensitive so do not long press keys.";
cout<<"\n\n If pressed it will take some time to perform next command.";
cout<<"\n\n Give atleat 50 milli second gap and press next key.";
getch();
cleardevice();
gotoxy(5,2);
cout<<"\t\t\tHOW TO PLAY       PART(2)";
cout<<"\n\n Press RIGHT ARROW KEY to move RIGHT and LEFT ARROW KEY to move LEFT.";
cout<<"\n\n Press UP/DOWN ARROW KEY to STOP your ship.";
cout<<"\n\n\n\n Press  S  to view SHOP.";
cout<<"\n\n Press  H  to view HOW TO PLAY.";
cout<<"\n\n Press  B  for SMALL blast.";
cout<<"\n\n Press  N  for BIG blast.";
cout<<"\n\n Press  M  for MEGA blast.";
cout<<"\n\n Press  J  for NUCLEAR blast.";
cout<<"\n\n BLAST and extra LIFES are available in SHOP.";
cout<<"\n\n Shortcuts are case sensitive make sure they are in LOWER CASE.";
getch();
}

void shop(void)
{
gotoxy(10,5);
cout<<"\t\tWELCOME TO THE SHOP ";
cout<<"\n 1. Small Blast - $50  ";
cout<<"\n 2.  Big  Blast - $100 ";
cout<<"\n 3. Mega  Blast - $500 ";
cout<<"\n 4.  ONE  life  - $350 ";
cout<<"\n 5.  TWO  life  - $650 ";
cout<<"\n 6. THREE life  - $950 ";
cout<<"\n 7. Mega Blast \n         +      -$1400\n    THREE life  ";
cout<<"\n 8.Nuclear Blast- $1000";
cout<<"\n\n\n PRESS NUMBER OF THE REQUIRED PACK ";
}