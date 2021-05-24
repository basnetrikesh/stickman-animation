#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int x,y;
	int j=0;//to jump near clif
	bool jump=false;
	bool bend=false;//to bend 
	bool hlmv=false;// to rotate the hand and leg while walking
	char st;
	int xL1=50,xL2=50;//end point of legs
	int xH=60,yH=560;//end points of hands while using umbrella xH=70,yH=540
	int xHe=50;//x cordinate of center of head at bending xHe=63
	int yHe=500;//y cordinate of the center of head at bending yHe=510
	int dist=50;
	do
	{
		cout<<"pree 'p' to play animation::\n";
		st=getche();
		if(st=='p'||st=='P')
		{
			break;
		}
		system("cls");
	}while(1);
	initwindow(1200,800);
	for(int i=0;i<=750;i++)
	{
		dist++;
		setcolor(GREEN);
		line(0,600,200,600);//ground1
		line(200,600,200,650);//obstacle
		line(250,600,1200,600);//ground2
		//tree
		/*line(1000,600,1000,400);
		line(950,600,950,400);
		ellipse(900,400,90,360,50,80);
		ellipse(950,400,0,180,50,80);
		ellipse(950,300,120,360,20,30);*/
		//rain
		setcolor(WHITE);
		if(dist>400)
		{
			if(dist>410)
			{
				//use umbrella
				xH=70;
				yH=540;
				line(xH+i,yH,xH+i,455);
				ellipse(xH+i,455,0,180,35,35);
				line(35+i,455,105+i,455);
				
			}
			
			for(int x=0;x<1150;x++)
			{
				x=rand()%1200;
				y=rand()%600;
				outtextxy(x,y,"/");
			}
		}
		
		
		//stickman
		setcolor(BROWN);
		if(jump==true)
		{
			hlmv=false;
			j++;
			circle(xHe+i,yHe-j,15);//head
			line(50+i,515-j,50+i,570-j);//body
			line(50+i,570-j,xL1+i,600-j);//leg1
			line(50+i,570-j,xL2+i,600-j);//leg2
			line(50+i,530-j,55+i,550-j);//hand
			line(55+i,550-j,xH+i,yH-j);
			
		}
		else
		{
			circle(xHe+i,yHe,15);//head
			line(50+i,515,50+i,570);//body
			line(50+i,570,xL1+i,600);//leg1
			line(50+i,570,xL2+i,600);//leg2
			line(50+i,530,55+i,550);//hand
			line(55+i,550,xH+i,yH);
		}
		if(hlmv==false)
		{
			xL1=40;
			xL2=60;
			//xH1=xH2=45;
			
			hlmv=true;
		}
		else
		{
			xL1=45;
			xL2=55;
			//xH1=xH2=60;
			
			hlmv=false;
		}
		if(dist==190)//to enable bend
		{
			xHe=63;
			yHe=510;
			bend=true;
			
		}
		if(dist==193)
		{
			delay(2000);
			xHe=50;
			yHe=500;
			//now jump
			jump=true;
			
		}
		if(dist==255)//to disable jump
		{
			jump=false;
			
		}
		
		if(jump==true)
		{
			delay(10);
		}
		else
		{
			delay(100);
			
		}
		
		cleardevice();
		
	}
	
	getch();
	return 0;
}
