#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
#include<layout.h>
#include<itc.h>
#include<dtime.h>
#include<dino.h>
#include<obs.h>

char* h = c_hours();
char* m = c_mins();
char* s = c_secs();
char* t_s = s;
char* t_m = m;
char* t_h = h;

void desktop() {
	taskbar();
	wifi_icon();
	battery_icon();
}

void click_animation() {
	int cur_x = 84;
	int cur_y = 128;
	clr_chrome_icon(84,128);
	clr_cursor(cur_x,cur_y);
	setcolor(LIGHTGRAY);
	rectangle(47,189,123,95);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	floodfill(112,161,LIGHTGRAY);
	setcolor(WHITE);
	chrome_icon(84,128);
	cursor(cur_x,cur_y);
}

void cursor_movement() {
	int cur_x = 326;
	int cur_y = 248;
	int flag1 = 0;
	int d_a = 0;
	int cursor_move = 1;
	// Initial cursor
	cursor(cur_x,cur_y);
	// Movemet
	d_time(h,m,s,getmaxx()/2-25,25);
	while(cursor_move == 1) {
		h = c_hours();
		m = c_mins();
		s = c_secs();
		if(s != t_s) {
			clr_d_time(t_h,t_m,t_s,getmaxx()/2-25,25);
			d_time(h,m,s,getmaxx()/2-25,25);
			t_s = s;
			t_m = m;
			t_h = h;
		}
		
		clr_cursor(cur_x,cur_y);
		cur_x = cur_x -1;
		cur_y = (flag1%2 == 0) ? cur_y-1 : cur_y;
		cursor(cur_x,cur_y);
		if(cur_x == 84) {
			cursor_move = 0;
		}
		chrome_icon(84,128);
		flag1++;
		d_a++;
		d_a = d_a == 4 ? 0 : d_a;
		delay(2);
	}

}

void click_chrome() {
	desktop();
	chrome_icon(84,128);
	cursor_movement();
	delay(300);
	click_animation();

}
