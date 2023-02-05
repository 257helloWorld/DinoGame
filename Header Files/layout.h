#include<graphics.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>

void battery_icon() {
	rectangle(569,33,579,40);
	rectangle(579,40,569,25);

	setfillstyle(SOLID_FILL,WHITE);
	floodfill(573,36,WHITE);

	settextstyle(2,0,5);
	outtextxy(590,25,"78%");
}

void wifi_icon() {
	settextstyle(2,0,5);
	int wx = 455;
	line(wx,18,wx+90,18);
	line(wx,45,wx+90,45);
	ellipse(455,31,90,270,13,13);
	ellipse(wx+90,31,-90,90,13,13);
	setcolor(BLACK);
	setcolor(WHITE);
	sector(536,38,50,130,12,12);
	outtextxy(460,23,"MLDC_5G");
}
void clr_wifi_icon() {
	setcolor(BLACK);
	wifi_icon();
	setcolor(BLACK);
	outtextxy(460,23,"MLDC_5G");
	setcolor(WHITE);
}

void wifi_off_icon() {
	int wx = 405;
	line(wx,18,wx+140,18);
	line(wx,45,wx+140,45);
	ellipse(405,31,90,270,13,13);
	ellipse(wx+140,31,-90,90,13,13);
	int x = 38;
	sector(536,38,50,130,12,13);
	setcolor(BLACK);
	sector(536,35,50,130,10,8);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(536,30,BLACK);
	setcolor(WHITE);
	outtextxy(wx+7,23,"NOT CONNECTED");
}

void clr_wifi_off_icon() {
	int wx = 405;
	setcolor(BLACK);
	wifi_off_icon();
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(536,30,BLACK);
	setcolor(BLACK);
	outtextxy(wx+7,23,"NOT CONNECTED");
	setcolor(WHITE);
}

void taskbar() {
	line(0,57,getmaxx(),57);
}

void chrome_icon(int x, int y) {
	circle(x,y,25);
	circle(x,y,13);
	circle(x,y,8);

	line(x,y-13,x+20,y-13);
	line(x,y+25,x+13,y+4);
	line(x-12,y+5,x-20,y-13);

	settextstyle(2,0,5);
	outtextxy(x-22,y+35,"Chrome");
}

void clr_chrome_icon(int x, int y) {
	setcolor(BLACK);
	chrome_icon(x,y);
	setcolor(WHITE);
}

void cursor(int x, int y) {
	line(x,y,x+1,y+16);
	line(x+1,y+16,x+5,y+8);
	line(x,y,x+14,y+9);
	line(x+14,y+9,x+5,y+8);
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(x+2,y+5,WHITE);
}

void clr_cursor(int x, int y) {
	setcolor(BLACK);
	cursor(x,y);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(x+2,y+5,BLACK);
	setcolor(WHITE);
}

// Scene 2
void window() {
	rectangle(27,80,616,461);
	line(27,110,616,110);
}

void window_title() {
	settextstyle(2,0,5);
	outtextxy(300,87,"Chrome");
}

void google() {
	settextstyle(3,0,7);
	outtextxy(233,190,"Google");
	setcolor(WHITE);
}

void search_bar() {
	for(int x = 160; x < 480; x++) {
		circle(x,320,14);
	}
	setcolor(BLACK);
	for(int y = 160; y < 480; y++) {
		circle(y,320,13);
	}
	setcolor(WHITE);
	circle(480-10,318,5);
	line(475,323,478,326);
}
void search_button() {
	setcolor(WHITE);
	int x = 190;
	int y = 360;
	settextstyle(2,0,4);
	rectangle(x,y,x+100,y+20);
	outtextxy(x+13,y+4,"Google Search");
}
void lucky_button() {
	setcolor(WHITE);
	int x = 320;
	int y = 360;
	settextstyle(2,0,4);
	rectangle(x,y,x+120,y+20);
	outtextxy(x+13,y+4,"I'm Feeling Lucky");
}
