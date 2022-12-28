#include<graphics.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
class circle2
{        
	public: 
		int x,y,d,x1,y1,x2,y2,r;
};  

class circle1:public circle2
{
	public:
		void br_circle(int x1,int y1,int r)
		{
			x=0,y=r;
			d=3-2*r;
			//putpixel(y1,y1,BLUE);
			while(x<=y)
    			{delay(100);
				putpixel(x1+x,y1+y,10);
				putpixel(x1+y,y1+x,12);
				putpixel(x1-y,y1+x,9);
				putpixel(x1+x,y1-y,11);
				putpixel(x1-x,y1-y,4);
				putpixel(x1-y,y1-x,7);
				putpixel(x1-x,y1+y,15);
				putpixel(x1+y,y1-x,14);
				if(d<0)
				{
					d=d+4*x+6;
					x++;
				}
				else
				{
					d=d+4*(x-y)+10;
					x++;y--;
				}
    			}
		}


		void dda_line(int x1,int y1,int x2,int y2)
		{
			float x,y,dx,dy,len;
			int i;
			
			dx=abs(x2-x1);

			dy=abs(y2-y1);

			if(dx>=dy)
			{
				len=dx;
			}
			else
			{
				len=dy;
			}

			dx=(x2-x1)/len;
			dy=(y2-y1)/len;

			x=x1+0.5;
			y=y1+0.5;

			i=1;

			while(i<=len)
			{
				delay(20);
				putpixel(x,y,11);
				x=x+dx;
				y=y+dy;
				i=i+1;
			}

			//putpixel(x,y,15);
		}


		void triangle(int x1,int y1,int r)
		{
			int h,ax,bx,ay,by,cx,cy;
			h=1.73*r;
					
			ax=x1+h;
			ay=y1+r;

			bx=x1-h;
			by=y1+r;

			cx=x1;
			cy=y1-2*r;

			circle1 d;
			d.dda_line(ax,ay,bx,by);
			d.dda_line(bx,by,cx,cy);
			d.dda_line(cx,cy,ax,ay);

		}


};

int main()
  {
	circle1 c1;
	int x1,y1,r;
	int gd=DETECT,gm;
	int xmax,ymax,xmid,ymid;

	cout<<"Enter the centre of the circle\t";
	cin>>x1>>y1; 
	cout<<"Enter the radius	\t";
	cin>>r;

	initgraph(&gd,&gm,NULL);

	 xmax=getmaxx();
	 ymax=getmaxy();
	 xmid=xmax/2;
	 ymid=ymax/2;

	 line(xmid,0,xmid,ymax);
	 line(0,ymid,xmax,ymid);

	c1.br_circle(xmid+x1,ymid-y1,r);	
	c1.br_circle(xmid+x1,ymid-y1,2*r);

	c1.triangle(xmid+x1,ymid-y1,r);

	
	delay(1000);
	getch();
	closegraph();
	return 0;
}
