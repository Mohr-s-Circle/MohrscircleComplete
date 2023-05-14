#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<graphics.h>

float pi=3.14;
float Ixy,Ix,Iy,area;
int triangle()
{
	float b,h,c;
	int i=1;
	printf("Let's find moment of inertia of triangle.\n\nPlease put the side length of triangle\n");
	do
	{
	printf("\nH =");
	scanf("%2f",&h);
	printf("B =");
	scanf("%2f",&b); 
	printf("C =");
	scanf("%2f",&c);
	if(c>b) printf("From picture B>=C.please put your value again");
	else break;
	}
	while(i=1);
	area=b*h/2;
	printf("Area of this is %.2f",area);
	Ix=b*pow(h,3)/36;
	Iy=b*h*(pow(b,2)-(b*c)+pow(c,2))/36;
	Ixy=b*pow(h,2)*(b-(2*c))/72;
}

int square()
{
	float a,b;
	printf("Let's find moment of inertia of square.\n\nPlease put the side length of square\n");
	printf("\nwidth =");
	scanf("%f",&a);
	printf("length =");
	scanf("%f",&b);
	area=a*b;
	printf("area = %.2f m^2\n",area);
	Ix=a*pow(b,3)/12;
	Iy=b*pow(a,3)/12;
	Ixy=0;
}

int circle()
{
	double r;
	printf("Let's find moment of inertia of circle.\nPlease put the side length of circle\n");
	printf("radius = ");
	scanf("%lf",&r);
	area=pi*pow(r,2);
	printf("\nArea of this is %.2f\n",area);	
	Ix=pi*pow(r,4)/4;
	Ixy=0;
}

int semicircle()
{
	double r;
	printf("Let's find moment of inertia of semicircle.\nPlease put the side length of semicircle\n");
	printf("radius = ");
	scanf("%lf",&r);
	area=pi*pow(r,2)/2;
	printf("Area is %.2f",area);
	Ix=((pi/8)-(8/(9*pi)))*pow(r,4);
	Iy=pi*pow(r,4)/8;
	Ixy=0;
}

int quatercircle()
{
	double r;
	printf("Let's find moment of inertia of quatercircle.\nPlease put the side length of quatercircle\n");
	printf("radius = ");
	scanf("%lf",&r);
	area=pi*pow(r,2)/4;
	printf("Area is %.2f",area);
	Ix=Iy=((pi/16)-(4/(9*pi)))*pow(r,4);
	Ixy=-0.01647*pow(r,4);
}

int H_beam()
{
	float h,b,t;
	printf("Let's find moment of inertia of H-beam.\n\nPlease put the scale of H-beam\n");
	printf("\nheight =");
	scanf("%f",&h);
	printf("widgth =");
	scanf("%f",&b);
	printf("thickness =");
	scanf("%.2f",&t);
	Ix=(b*pow(h,3)/12)+((b-t)*pow(h-(2*t),3)/12);
	Iy=(h*pow(b,3)/12)-((h-2*t)*(pow((b-t)/2,3))/6);
	Ixy=0;
	
}

int channel()
{
	float b,h,t,sumXi,Xc,Yc;
	printf("Let's find moment of inertia of channel.\n\nPlease put the scale of channel\n");
	printf("\nheight =");
	scanf("%f",&h);
	printf("widgth =");
	scanf("%f",&b);
	printf("thickness =");
	scanf("%f",&t);
	sumXi=(b*b*h/2)-((b-t)*(h-(2*t))*(b-t)/2);
	area=(b*h)-((b-t)*(h-2*t));
	Xc=sumXi/area;
	Yc=h/2;
	Ix=(b*pow(h,3)/12)-((b-t)*pow(h-t,3)/12);
	Iy=(t*pow(b,3)/6)+(b*t*pow(Xc-(b/2),2))+((h-2*t)*pow(t,3)/12)+(h-2*t)*t*pow((b-t)/2,2);
	Ixy=0;
}


int angle()
{
	float B,H,T,Xc,Yc;
	printf("Let's find moment of inertia of H-beam.\n\nPlease put the scale of angle\n");
	printf("\nheight =");
	scanf("%f",&H);
	printf("widgth =");
	scanf("%f",&B);
	printf("thickness =");
	scanf("%f",&T);
	Xc	= (((B*H)*(B/2))-((B-T)*(H-T)*((B-T)/2)))/((B*H)-((B-T)*(H-T)));
	Yc 	= (((B*H)*(H/2))-((B-T)*(H-T)*((H+T)/2)))/((B*H)-((B-T)*(H-T)));
	Ix 	= (B*pow(H,3)/12)+(B*H*pow((H/2)-Yc,2))-((B-T)*pow(H-T,3)/12)-((B-T)*(H-T)*pow(((H+T)/2)-Yc,2));
	Iy 	= (H*pow(B,3)/12)+(B*H*pow((B/2)-Xc,2))-((H-T)*pow(B-T,3)/12)-((B-T)*(H-T)*pow(Xc-((B-T)/2),2));
	Ixy = B*T*(Xc-B/2)*(Yc-T/2)+T*(H-T)*(B-Xc-T/2)*((H+T)/2-Yc);
}

int cut_beam()
{ 
	float Yc,b,h,d;
	printf("Let's find moment of inertia of cut-beam.\n\nPlease put the scale of cut-beam\n");
	printf("\nheight =");
	scanf("%f",&h);
	printf("widgth =");
	scanf("%f",&b);
	printf("thickness =");
	scanf("%f",&d);
	Yc = ((b*d*d/2)+((h-d)*d*(h+d)/2))/((b*d)+((h-d)*d));
	Ix = (b*pow(d,3)/12)+(b*d*pow(Yc-d/2,2))+(d*pow(h-d,3)/12)+((h-d)*d*pow((h+d)/2-Yc,2));
    Iy = d*pow(b,3)/12+(h-d)*(pow(d,3))/12;
    Ixy=0;
}
int squaretube()
{
	
	float B,H,t;
	printf("Let's find moment of inertia of square tube.\n\nPlease put the scale of square tube\n");
	printf("\nheight =");
	scanf("%f",&H);
	printf("widgth =");
	scanf("%f",&B);
	printf("thickness =");
	scanf("%f",&t);
	Ix = (B*pow(H,3)/12)-((B-(2*t))*pow((H-(2*t)),3)/12);
	Iy = (H*pow(B,3)/12)-((H-(2*t))*pow((B-(2*t)),3)/12);
	Ixy=0;
	
}
int circletube()
{
	float D,d;
	int i=1;
	printf("Let's find moment of inertia of circle tube.\n\nPlease put the scale of circle tube\n");
	do
	{
	printf("\nOuter diameter =");
	scanf("%f",&D);
	printf("Inner diameter =");
	scanf("%f",&d);
	if(d>D) printf("From picture B>=C.please put your value again");
	else break;
	}
	while(i=1);
	Ix = Iy = ((pi*pow(D/2,4))/4) - ((pi*pow(d/2,4))/4);
	Ixy=0;
}

int main()
{	
	int i;
	printf("Choose geometry to find a moment of inertia at centroid of geometry\n");
	printf("1.triangle\n2.square\n3.circle\n4.semi-circle\n5.quater-circle\n");
	while(!(i>=1&&i<=11))
	{
	printf("\nEnter your choice =");
	scanf("%d",&i);
	printf("\n");
	switch (i)
	{
	case 1 : triangle();break;
	case 2 : square();break;
	case 3 : circle();break;
	case 4 : semicircle();break;
	case 5 : quatercircle();break;
	case 6 : H_beam();break;
	case 7 : channel();break;
	case 8 : angle();break;
	case 9 : cut_beam();break;
	case 10 : squaretube();break;
	case 11 : circletube();break;
	default : printf("You can't use the program.Please enter number 1-11\n");
	}
	}
	printf("\nIxy=%.2f m^4\nIx=%.2f m^4\nIy=%.2f m^4",Ixy,Ix,Iy);

}

