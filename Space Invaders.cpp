#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
class game
{
public:
char player_name[10];
int high_score=0;
int target=1;
int craftx=80;
int shotsx[40];
int shotsy[40];
int current_shot=0;
int enemyplane=0;
int time=0;
int enemyx[20];
int enemyy[20];
int score=0;
int hearts=0;

void loading()
{

	outtextxy(200,200, "LOADING...");
	rectangle(200,240,400,220);
	for(int i=1;i<=200;i++)
	{

		setcolor(2);
		rectangle(200,240,200+i,220);
		delay(10);
	}
	getch();

}

void interface1()
{
	setcolor(WHITE);
int poly[10],k=40,x=(3*(800-2*k)/4);
poly[0]=k;
poly[1]=k;
poly[2]=k;
poly[3]=800-k;
poly[4]=800-k;
poly[5]=800-k;
poly[6]=800-k;
poly[7]=k;
poly[8]=k;
poly[9]=k;
line(x,k,x,800-k);
line(x,3*k,800-k,3*k);
line(x,3*k+120,800-k,3*k+120);
drawpoly(5,poly);
setfillstyle(CLOSE_DOT_FILL,LIGHTCYAN);
floodfill(800-2*k,3*k-1,15);
settextstyle(2,0,7);
outtextxy(x+30,3*k-50,"SPACE INVADERS");
outtextxy(x+15,3*k+15,"Playername-");
outtextxy(x+15,3*k+40,player_name);

outtextxy(x+5,3*k+140,"Instructions");
setcolor(6);
outtextxy(x+5,3*k+160,"Command Key");
setcolor(GREEN);
outtextxy(x+5,3*k+190," FIRE->SPACE ");
outtextxy(x+5,3*k+210," MOVE RIGHT->D ");
outtextxy(x+5,3*k+230," MOVE LEFT->A ");
outtextxy(x+5,3*k+250," EXIT->X ");
setcolor(YELLOW);
outtextxy(x+5,3*k+280," LIVES REMAINING");
setcolor(WHITE);
settextstyle(2,0,8);
outtextxy(x+30,3*k+500," SCORE");
int score_local=score;
char localscoreasstring[10];
itoa(score_local,localscoreasstring,10);
outtextxy(x+40,3*k+530,localscoreasstring);

//health heart
setcolor(12);
poly[8];

for(int u=hearts;u<4;u++)
{
poly[0]=x+30;
poly[1]=3*k+330;
poly[2]=x+15;
poly[3]=3*k+360;
poly[4]=x+30;
poly[5]=3*k+390;
poly[6]=x+45;
poly[7]=3*k+360;
setfillstyle(SOLID_FILL,RED);
fillpoly(4,poly);
x+=60;
}

}
void playerinput()
{
    int k=40;
	settextstyle(2,0,7);
	outtextxy(k+80,3*k,"Enter Playername");
	cin.getline(player_name,10);
    delay(120);
}
void control()
{
	if(kbhit())
	{

	char c=getch();
	{
		if(c=='a')
		{
		    craftx-=15;
		}
		if(c=='d')
		{
			craftx+=15;

		}
		if(c==' ')
		{
		     shooting();
		}
		if(c=='x')
		{
			target=0;
		}
	}
}

}
void spacecraft()
{
	int k=40;
	if(craftx<k)
	{
		craftx=(3*(800-2*k)/4);
	}

	if(craftx>(3*(800-2*k)/4))
	{
		craftx=k;
	}
	int poly[20];
	poly[0]=craftx;
	poly[1]=610;
	poly[2]=craftx-10;
	poly[3]=620;
	poly[4]=craftx-10;
	poly[5]=640;
	poly[6]=craftx-20;
	poly[7]=660;
	poly[8]=craftx-20;
	poly[9]=670;
	poly[10]=craftx+20;
	poly[11]=670;
	poly[12]=craftx+20;
	poly[13]=660;
	poly[14]=craftx+10;
	poly[15]=640;
	poly[16]=craftx+10;
	poly[17]=620;
	poly[18]=craftx;
	poly[19]=610;
	setfillstyle(SOLID_FILL,RED);
	fillpoly(10,poly);
}

void shooting()
{
	if(current_shot<21)
	{
   current_shot++;
   shotsx[current_shot]=craftx;
   shotsy[current_shot]=610;
    }
}
void shooting_object()
{
	int k=40;
	for(int j=0;j<current_shot;j++)
	{
		if(shotsy[j]<k+20)
		{

			for(int i=0;i<current_shot;i++)
			{

			 shotsy[i]=shotsy[i+1];
			 shotsx[i]=shotsx[i+1];

			}
		    shotsy[current_shot]=0;
			shotsx[current_shot]=0;
			current_shot--;
		}
		else
		{
		  shotsy[j]-=20;
		}
		setcolor(WHITE);
		line( shotsx[j], shotsy[j]-5, shotsx[j], shotsy[j]);
	}
}
void enemy()
{
	int k=40;
	int i=rand()%35;

	if(i==3)
	{
		enemyplane++;
		enemyy[enemyplane]=100;
		enemyx[enemyplane]=rand()%(500);
		enemyx[enemyplane]+=40;
			cout<<enemyy[enemyplane];
	}
	else
	{

	}

}
void enemyupd()
{
  int k=40;
	for(int j=0;j<enemyplane;j++)
	{
		   int i=rand()%10;
		   if(i==7&&enemyx[j]+10<=500)
		   {
		   	enemyx[j]+=10;
		   }
		   else if(i==5&&enemyx[j]-10<=40)
		   {
		   	enemyx[j]-=10;
		   }
		   else
		   {
		   	enemyy[j]+=10;
		   }
		 if(enemyy[j]>=750)
		{
			 enemyy[j]=0;
		     enemyx[j]=0;
          for(int i=j;i<enemyplane;i++)
          {
          	 enemyy[i]=enemyy[i+1];
			 enemyx[i]=enemyx[i+1];

		  }
		  enemyy[enemyplane]=0;
		  enemyx[enemyplane]=0;
		  enemyplane--;
		  hearts++;


        }
		for(int k=0;k<=current_shot;k++)
		{

	if(enemyy[j]+10>=shotsy[k]&&enemyx[j]+10>=shotsx[k]&&enemyx[j]-10<=shotsx[k])
		{
			 enemyy[j]=0;
		     enemyx[j]=0;
          for(int i=j;i<enemyplane;i++)
          {
          	 enemyy[i]=enemyy[i+1];
			 enemyx[i]=enemyx[i+1];

		  }
		  enemyy[enemyplane]=0;
		  enemyx[enemyplane]=0;
		  enemyplane--;
		  score+=10;



        }
		}

		setcolor(7);  //enemynplane
		int poly_2[10];
		poly_2[0]=enemyx[j];
		poly_2[1]=(enemyy[j]+20);
		poly_2[2]= enemyx[j]+15;
		poly_2[3]= enemyy[j];
		poly_2[4]= enemyx[j]+5;
		poly_2[5]= enemyy[j]-10;
		poly_2[6]= enemyx[j]-5;
		poly_2[7]= enemyy[j]-10;
		poly_2[8]= enemyx[j]-15;
		poly_2[9]= enemyy[j];
		setfillstyle(SOLID_FILL,BLUE);
		fillpoly(5,poly_2);


   }
}
void gameloop()
{
	initwindow(800,800);
	//loading();
	cleardevice();
	strcpy(player_name,"new player");

	interface1();
	playerinput();
	setcolor(BLACK);
	cleardevice();
	interface1();
	do{
		interface1();
		spacecraft();
		shooting_object();
		enemy();
		enemyupd();
		control();
		delay(100);
		time+=10;
		cleardevice();
		if(hearts==4)
		{
		 target=0;
		}
		else
		{

		}

	}while (target!=0);
setcolor(WHITE);
settextstyle(2,0,8);
outtextxy(200,400,"**** GAME OVER ****");
    getch();
	closegraph();
}


};
int main()
{
class game dj;
dj.gameloop();
return 0;
}
