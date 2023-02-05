#include<desktop.h>


// Variables
int cur_obs1, cur_obs2, cur_obs3;
int obs1_x, obs1_y, obs2_x, obs2_y, obs3_x, obs3_y;
int last_x;
int score = 0;
int b, c;
char* c_score = score_char(score);

int random_obs_no() {
	return rand()%5+1;
}

int random_distance() {
	return rand()%250+150;
}

void assign_random_obs(int x) {
	if(x == 1) { cur_obs1 = random_obs_no(); }
	if(x == 2) { cur_obs2 = random_obs_no(); }
	if(x == 3) { cur_obs3 = random_obs_no(); }
}



void random_obs(int x, int y, int cur_obs) {
	if(cur_obs == 1) { obs_g1(x,y); }
	if(cur_obs == 2) { obs_g2(x,y); }
	if(cur_obs == 3) { obs_g3(x,y); }
	if(cur_obs == 4) { obs_g4(x,y); }
	if(cur_obs == 5) { obs_g5(x,y); }
}

void clr_random_obs(int x, int y, int cur_obs) {
	setcolor(BLACK);
	if(cur_obs == 1) { obs_g1(x,y); }
	if(cur_obs == 2) { obs_g2(x,y); }
	if(cur_obs == 3) { obs_g3(x,y); }
	if(cur_obs == 4) { obs_g4(x,y); }
	if(cur_obs == 5) { obs_g5(x,y); }
	setcolor(WHITE);
}

int start_game();

void game_over() {
	score = 0;
	setcolor(LIGHTGRAY);
	outtextxy(getmaxx()/2-45,getmaxy()/2-30,"Game Over");
	setcolor(WHITE);
	while(!kbhit()) {
		// Fetch Current time.
		h = c_hours();
		m = c_mins();
		s = c_secs();
		// Change time on the screen. (If seconds incremented)
		if(s != t_s) {
			clr_d_time(t_h,t_m,t_s,getmaxx()/2-25,25);
			d_time(h,m,s,getmaxx()/2-25,25);
			t_s = s;
			t_m = m;
			t_h = h;
		}
	}
	cleardevice();
	return;
}


int start_game() {
	srand(time(0));
	// Time
	d_time(h,m,s,getmaxx()/2-25,25);
	// Variables
	int input = 0;
	int jump = 0;
	int line_v = 1;
	int x = 132, y = 260;
	int line_x = 132+60, line_y = 260;
	
	int bound_x1 = 148, bound_x2 = 480;
	
	int dino_x = x+50, dino_y = y;
	int jump_y = 186;
	
	obs1_x = 800;
	obs1_y = 250;
	obs2_x = obs1_x + random_distance();
	obs2_y = 250;
	obs3_x = obs2_x + random_distance();
	obs3_y = 250;
	last_x = obs3_x;
	
	cur_obs1 = 1;
	cur_obs2 = 2;
	cur_obs3 = 1;
	
	int d_a = 0;
	int d_b = 0;
	int d_c = 0;
	int d_d = 0;
	int d_e = 0;
	// Initial Jump
	while(dino_y > jump_y) {
		clr_dino(dino_x,dino_y);
		dino_y--;
		dino(dino_x,dino_y);
		line(x+20,y,x+60,y);
		delay(2);
	}
	while(dino_y < y) {
		clr_dino(dino_x,dino_y);
		dino_y++;
		dino(dino_x,dino_y);
		line(x+20,y,x+60,y);
		delay(2);
	}
	
	
	while(1) {
		// Fetch Current time.
		h = c_hours();
		m = c_mins();
		s = c_secs();
		// Change time on the screen. (If seconds incremented)
		if(s != t_s) {
			clr_d_time(t_h,t_m,t_s,getmaxx()/2-25,25);
			d_time(h,m,s,getmaxx()/2-25,25);
			t_s = s;
			t_m = m;
			t_h = h;
		}
		
		int t_x = dino_x;
		int t_y = dino_y;
		
		// Keyboard inputs
		if(kbhit()) { input = getch(); }
		if(input == 8) { // 08 - Backspace
			closegraph();
			break;
		}
		if(input == 32) { // 32 - Space bar
			if(dino_y == y && dino_x == x+65) {
				jump = 1;
				input = 0;
			}
		}
		
		// Moving Dino First Time.
		if(dino_x < x+65 && d_c == 5) {
			clr_dino(dino_x,dino_y);
			dino_x += 1;
			dino(dino_x,dino_y);
		}
		
		// Extending Line First Time.
		if(line_x <= 480) {
			putpixel(line_x,line_y,WHITE);
			line_x++;
			if(line_x == 480) { line_v = 0; }
		}
		
		// Score
		if(d_d == 100) {
			setcolor(BLACK);
			outtextxy(getmaxx()/2+100,getmaxy()/2-100,c_score);
			setcolor(WHITE);
			score++;
			c_score = score_char(score);
			outtextxy(getmaxx()/2+100,getmaxy()/2-100,c_score);
		}
		
		// Obstacles Movement.
		if(d_b == 2) {
			if(obs1_x < bound_x2) { clr_random_obs(obs1_x,obs1_y,cur_obs1); }
			if(obs2_x < bound_x2) { clr_random_obs(obs2_x,obs2_y,cur_obs2); }
			if(obs3_x < bound_x2) { clr_random_obs(obs3_x,obs3_y,cur_obs3); }
			obs1_x -= 2;
			obs2_x -= 2;
			obs3_x -= 2;
			last_x -= 2;
			if(obs1_x < bound_x2) { random_obs(obs1_x,obs1_y,cur_obs1); }
			if(obs2_x < bound_x2) { random_obs(obs2_x,obs2_y,cur_obs2); }
			if(obs3_x < bound_x2) { random_obs(obs3_x,obs3_y,cur_obs3); }
			window();
			
		}
		
		if(obs1_x > obs2_x && obs1_x > obs3_x) { last_x = obs1_x; }
		else if(obs2_x > obs1_x && obs2_x > obs3_x) { last_x = obs2_x; }
		else if(obs3_x > obs1_x && obs3_x > obs2_x) { last_x = obs3_x; }
		
		// Assign random distance values to the obstalces.
		if(obs1_x < bound_x1) {
			clr_random_obs(obs1_x,obs1_y,cur_obs1);
			obs1_x = last_x + random_distance();
			cur_obs1 = random_obs_no();
		
		}
		if(obs2_x < bound_x1) {
			clr_random_obs(obs2_x,obs2_y,cur_obs2);
			obs2_x = last_x + random_distance();
			cur_obs2 = random_obs_no();
		
		}
		if(obs3_x < bound_x1) {
			clr_random_obs(obs3_x,obs3_y,cur_obs3);
			obs3_x = last_x + random_distance();
			cur_obs3 = random_obs_no();
		
		}
		
		
		// Redraw erased line
		if(line_v == 1) {
			line(x+20,y,x+60,y);
		}
		if(line_v == 0) {
			line(x+20,y,480,y);
		}
		
		
		// Collision Detection.
		if(dino_x > obs1_x-2 && dino_x < obs1_x+1 && dino_y > obs1_y-20 && obs1_x > bound_x1) {	
			game_over();	
			return 1;
		}
		if(dino_x > obs2_x-2 && dino_x < obs2_x+1 && dino_y > obs2_y-20 && obs2_x > bound_x1) {
			game_over();
			return 1;
		}
		if(dino_x > obs3_x-2 && dino_x < obs3_x+1 && dino_y > obs3_y-20 && obs3_x > bound_x1) {
			game_over();
			return 1;
		}
		
		
		// Dino Jump.
		if(jump == 1 && d_a == 2) {
			if(dino_y > jump_y) {
				dino_y -= 2;
			} 
			else if(dino_y == jump_y) {
				jump = 2;
			}
		}
		if(jump == 2 && d_a == 2) {
			if(dino_y < y) {
				dino_y += 2;
			} 
			else if(dino_y == y) {
				jump = 0;
			}
		}
		
		
		// Redraw dino
		if(t_x != dino_x || t_y != dino_y || d_e == 1) {
			clr_dino(t_x,t_y);
			dino(dino_x,dino_y);
		}
		
		
		// Custom delays
		d_a++;
		d_b++;
		d_c++;
		d_d++;
		d_e++;
		if(d_a == 3) { d_a = 0; }
		if(d_b == 6) { d_b = 0; }
		if(d_c == 10) { d_c = 0; }
		if(d_d == 101) { d_d = 0; }
		if(d_e == 50) { d_e = 0; }
		delay(1);
	}
}



