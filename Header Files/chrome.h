#include<game.h>

int wifi;
int st;

void wifi_off_layout() {
	d_time(h,m,s,getmaxx()/2-25,25);
	window();
	window_title();
	taskbar();
	battery_icon();
	wifi_off_icon();
	setcolor(LIGHTGRAY);
	int x = 132, y = 260;
//	line(x+20,y,x+400,y);
	line(x+20,y,x+60,y);
	setcolor(WHITE);
	dino(x+50,y);
	setcolor(LIGHTGRAY);
	settextstyle(2,0,6);
	outtextxy(x+10,y+25,"No Internet");
	settextstyle(2,0,4);
	outtextxy(x+10,y+55,"Try;");
	outtextxy(x+50,y+68,"Checking the network cables, modem and router.");
	outtextxy(x+50,y+82,"Reconnecting to Wi-Fi");
	outtextxy(x+10,y+100,"ERROR_INTERNET_DICONNECTED");
}

void wifi_on_layout() {
	d_time(h,m,s,getmaxx()/2-25,25);
	taskbar();
	battery_icon();
	wifi_icon();
	window();
	window_title();
	google();
	search_bar();
	search_button();
	lucky_button();
}

void toggle_wifi() {
	if(wifi == 1) {
		clr_wifi_icon();
		wifi_off_icon();
		cleardevice();
		wifi_off_layout();
		wifi = 0;
	} else  {
		clr_wifi_off_icon();
		wifi_icon();
		cleardevice();
		wifi_on_layout();
		wifi = 1;
	}
}

void scene2() {
	int a = 0;
	d_time(h,m,s,getmaxx()/2-25,25);
	if(wifi == 1) {	wifi_on_layout(); }
	if(wifi == 0) { wifi_off_layout(); }
	while(1) {
		// Time
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
		// End
		a = 0;
		if(kbhit()) {
			a = getch();
			if(a == 27) {
				a = 0;
				closegraph();
				break;
			}
			if(a == 59) {
				a = 0;
				toggle_wifi();
			}
			if(wifi != 1 && a == 32) {
				a = 0;
				st = start_game();
				if(st == 1) { scene2(); st = 0;}
			}
		}

	}
}

void open_chrome(int w) {
	wifi = w;
	scene2();
}
