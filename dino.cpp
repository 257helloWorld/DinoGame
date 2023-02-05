#include<chrome.h>
void main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");

	getch();
	click_chrome();
	delay(1000);
	cleardevice();
	open_chrome(1);

	getch();
	closegraph();
}