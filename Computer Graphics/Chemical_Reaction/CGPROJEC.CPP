#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
int pk,x1,y1;
void atom(double x,double y,int c,int r)
{
	setcolor(c);
	circle(x,y,r);
}
void print(int c, int ch)
{
	setcolor(c);
	switch(ch)
	{
		case 1:
			settextstyle(7,0,4);
			outtextxy(125,50,"Nuclear Fission Reaction");
			settextstyle(2,0,4);
			outtextxy(225,94,"    235         144     89        ");
			outtextxy(225,104,"n +    U    --->   Ba  +  Kr + 3n");
			outtextxy(225,114,"        92           56    36    ");
			break;
		case 2:
			settextstyle(7,0,4);
			outtextxy(125,50,"Nuclear Fission Reaction");
			settextstyle(2,0,4);
			outtextxy(225,100," 2     6             4    ");
			outtextxy(225,110,"  H  +  Li   --->  2   He ");
			outtextxy(225,120,"   1      3              2");
			break;
		case 3:
			settextstyle(7,0,4);
			outtextxy(150,50,"Combination Reaction");
			settextstyle(2,0,4);
			outtextxy(225,110,"2H    +   O   --->   2 H O   ");
			outtextxy(225,120,"  2(g)     2(g)          2 (l)");
			break;
		case 4:
			break;
		default:
			printf("Enter a valid input.\n");
	}
}
void main()
{
	int gdriver = DETECT,gmode,xm,ym,i,j,ch=0;
	double x,t,y1,y2,y3,y4;
	clrscr();
	printf("Class : SE-B\n");
	printf("\nBranch: Computer Engineering\n");
	printf("Subject: Computer Graphics.\n");
	printf("\nProject:Animation Demonstrating Various Chemical Reactions\n");
	printf("Team Members:\nSr.No.\tName\t\tSAP ID:\n");
	printf("1.\tRomil\t\t60004170096\n");
	printf("2.\tRushikesh\t60004170097\n");
	printf("3.\tRobin\t\t60004170093\n");
	do
	{
		printf("\n\nWhat would you like to see??\n4.Or you would leave?");
		printf("\n1.Neutron + Uranium.");
		printf("\n2.Deuterium + Lithium.");
		printf("\n3.Hydrogen + Oxygen.");
		printf("\n\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
				xm=getmaxx();
				ym=getmaxy();
				line(0,0,xm,0);
				line(0,0,0,ym);
				line(0,ym,xm,ym);
				line(xm,0,xm,ym);
				print(15,ch);
				delay(15);
				circle(xm/2,ym/2,30);
				settextstyle(2,0,4);
				outtextxy(xm/2-15,ym/2+50,"Uranium");
				delay(15);
				for(i=20;i<xm/2-45;i++)
				{
					atom(i-1,ym/2,15,10);
					outtextxy(i-18,ym/2+50,"Neutron");
					delay(15);
					atom(i-1,ym/2,0,10);
					outtextxy(i-18,ym/2+50,"Neutron");
				}
				sound(1000);
				delay(15);
				settextstyle(2,0,4);
				outtextxy(xm/2-15,ym/2+50,"Uranium");
				print(0,ch);
				circle(xm/2,ym/2,30);
				x=xm/2;
				y1=ym/2;
				nosound();
				setcolor(15);
				settextstyle(2,0,4);
				outtextxy(xm-100,50,"Barium");
				outtextxy(xm-100,120,"Neutron");
				outtextxy(xm-100,230,"Neutron");
				outtextxy(xm-100,350,"Neutron");
				outtextxy(xm-100,ym-50,"Krypton");
				for(i=x;i<=xm-125;i++)
				{
					x++;
					y1=ym/2+(xm/2-x)*(tan(3.142/6));
					y2=ym/2+(xm/2-x)*(tan(3.142/4));
					y3=ym/2-(xm/2-x)*(tan(3.142/6));
					y4=ym/2-(xm/2-x)*(tan(3.142/4));
					atom(x,ym/2,15,10);
					atom(x,y1,15,10);
					atom(x,y2,15,20);
					atom(x,y3,15,10);
					atom(x,y4,15,20);
					delay(15);
					atom(x,ym/2,0,10);
					atom(x,y1,0,10);
					atom(x,y2,0,20);
					atom(x,y3,0,10);
					atom(x,y4,0,20);
				}
				closegraph();
				break;
			case 2:
				initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
				xm=getmaxx();
				ym=getmaxy();
				line(0,0,xm,0);
				line(0,0,0,ym);
				line(0,ym,xm,ym);
				line(xm,0,xm,ym);
				print(15,ch);
				delay(15);
				circle(xm/2,ym/2,20);
				settextstyle(2,0,4);
				outtextxy(xm/2-15,ym/2+50,"Lithium");
				delay(15);
				for(i=20;i<xm/2-45;i++)
				{
					atom(i-1,ym/2,15,10);
					outtextxy(i-18,ym/2+50,"Deuterium");
					delay(15);
					atom(i-1,ym/2,0,10);
					outtextxy(i-18,ym/2+50,"Deuterium");
				}
				sound(1000);
				delay(15);
				settextstyle(2,0,4);
				outtextxy(xm/2-15,ym/2+50,"Lithium");
				print(0,ch);
				circle(xm/2,ym/2,20);
				x=xm/2;
				y1=ym/2;
				nosound();
				setcolor(15);
				settextstyle(2,0,4);
				outtextxy(xm-100,120,"Helium-4");
				outtextxy(xm-100,350,"Helium-4");
				for(i=x;i<=xm-125;i++)
				{
					x++;
					y1=ym/2+(xm/2-x)*(tan(3.142/6));
					y3=ym/2-(xm/2-x)*(tan(3.142/6));
					atom(x,y1,15,10);
					atom(x,y3,15,10);
					delay(15);
					atom(x,y1,0,10);
					atom(x,y3,0,10);
				}
				closegraph();
				break;
			case 3:
				initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
				xm=getmaxx();
				ym=getmaxy();
				line(0,0,xm,0);
				line(0,0,0,ym);
				line(0,ym,xm,ym);
				line(xm,0,xm,ym);
				print(15,ch);
				delay(15);
				circle(xm/2-8,ym/2,8);
				circle(xm/2+8,ym/2,8);
				settextstyle(2,0,4);
				outtextxy(xm/2-30,ym/2+30,"Hydrogen (H2)");
				delay(15);
				for(i=30;i<xm/2-45;i++)
				{
					atom(i-1,ym/2,15,20);
					outtextxy(i-18,ym/2+30,"Oxygen");
					delay(15);
					atom(i-1,ym/2,0,20);
					outtextxy(i-18,ym/2+30,"Oxygen");
				}
				sound(1000);
				delay(15);
				circle(xm/2,ym/2,12);
				circle(xm/2-8,ym/2,8);
				circle(xm/2+8,ym/2,8);
				settextstyle(2,0,4);
				outtextxy(xm/2-30,ym/2+30,"Hydrogen (H2)");
				print(0,ch);
				circle(xm/2,ym/2,30);
				x=xm/2;
				y1=ym/2;
				nosound();
				setcolor(15);
				settextstyle(2,0,4);
				outtextxy(xm-100,120,"Water");
				outtextxy(xm-100,350,"Water");
				for(i=x;i<=xm-135;i++)
				{
					x++;
					y1=ym/2+(xm/2-x)*(tan(3.142/6));
					y3=ym/2-(xm/2-x)*(tan(3.142/6));
					atom(x,y1,15,32);
					atom(x,y3,15,32);
					delay(15);
					atom(x,y1,0,32);
					atom(x,y3,0,32);
				}
				closegraph();
				break;
			case 4:
				break;
			default:
				printf("Enter a valid input.\n");
				break;
		delay(250);
		}
	}while(ch!=4);
}