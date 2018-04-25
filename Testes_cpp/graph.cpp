#include <iostream>
#include <stdio.h>
#include <graphics.h>
using namespace std; 

int main() { 
	int gd = DETECT;
	int gm = VGAMAX;
	initgraph( &gd, &gm, NULL);
	setbkcolor(4);
	//cleardevice();
	//circle( getmaxx()/2, getmaxy()/2, 100 );
	//circle( getmaxx()/2, getmaxy()/2, 120 );
	circle( getmaxx()/2, getmaxy()/2, 140 ); 
	outtextxy( getmaxx()/2-40, getmaxy()/2, "hello" );
	getch();
	//closegraph();
	return 0;
}
