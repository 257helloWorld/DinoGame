void obs1(int x, int y) {
	y += 5;
	line(x-(-4),y-(15),x-(-6),y-(15));
	line(x-(-4),y-(15),x-(-4),y-(-5));
	line(x-(-6),y-(15),x-(-6),y-(-5));
	line(x-(-4),y-(-5),x-(-6),y-(-5));
	line(x-(-6),y-(-5),x-(-6),y-(-3));
	line(x-(-6),y-(6),x-(-8),y-(6));
	line(x-(-8),y-(6),x-(-8),y-(12));
	line(x-(-8),y-(12),x-(-10),y-(12));
	line(x-(-10),y-(12),x-(-10),y-(4));
	line(x-(-10),y-(4),x-(-6),y-(4));
	line(x-(-4),y-(2),x-(-2),y-(2));
	line(x-(-2),y-(2),x-(-2),y-(9));
	line(x-(-2),y-(9),x-(0),y-(9));
	line(x-(0),y-(9),x-(0),y-(0));
	line(x-(0),y-(0),x-(-4),y-(0));
}

void clr_obs1(int x, int y) {
	setcolor(BLACK);
	obs1(x,y);
	setcolor(WHITE);
}

void obs2(int x, int y) {
	line(x-(-5),y-(23),x-(-9),y-(23));
	line(x-(-9),y-(23),x-(-9),y-(-10));
	line(x-(-9),y-(-10),x-(-5),y-(-10));
	line(x-(-5),y-(-10),x-(-5),y-(23));
	line(x-(-9),y-(8),x-(-12),y-(8));
	line(x-(-12),y-(8),x-(-12),y-(18));
	line(x-(-12),y-(18),x-(-15),y-(18));
	line(x-(-15),y-(18),x-(-15),y-(5));
	line(x-(-15),y-(5),x-(-9),y-(5));
	line(x-(-5),y-(3),x-(-2),y-(3));
	line(x-(-2),y-(3),x-(-2),y-(14));
	line(x-(-2),y-(14),x-(0),y-(14));
	line(x-(0),y-(14),x-(0),y-(0));
	line(x-(0),y-(0),x-(-4),y-(0));
}

void clr_obs2(int x, int y) {
	setcolor(BLACK);
	obs2(x,y);
	setcolor(WHITE);
}


// Obstacle Group: 1
void obs_g1(int x, int y) {
	obs1(x,y);
}
void clr_obs_g1(int x, int y) {
	setcolor(BLACK);
	obs_g1(x,y);
	setcolor(WHITE);
}

// Obstacle Group: 2
void obs_g2(int x, int y) {
	obs2(x,y);
}
void clr_obs_g2(int x, int y) {
	setcolor(BLACK);
	obs_g2(x,y);
	setcolor(WHITE);
}

// Obstacle Group: 3
void obs_g3(int x, int y) {
	obs1(x,y);
	obs1(x+18,y);
}
void clr_obs_g3(int x, int y) {
	setcolor(BLACK);
	obs_g3(x,y);
	setcolor(WHITE);
}

// Obstacle Group: 4
void obs_g4(int x, int y) {
	obs2(x,y);
	obs2(x+18,y);
}
void clr_obs_g4(int x, int y) {
	setcolor(BLACK);
	obs_g4(x,y);
	setcolor(WHITE);
}

// Obstacle Group: 5
void obs_g5(int x, int y) {
	obs1(x,y);
	obs2(x+18,y);
	obs1(x+33,y);
}
void clr_obs_g5(int x, int y) {
	setcolor(BLACK);
	obs_g5(x,y);
	setcolor(WHITE);
}

