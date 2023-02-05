#include<time.h>
char* int_to_char(int n);

char* c_hours() {
	time_t tmNow;
    	tmNow = time(NULL);
    	struct tm t = *localtime(&tmNow);
	char* a = int_to_char(t.tm_hour);
    	return a;
}

char* c_mins() {
	time_t tmNow;
    	tmNow = time(NULL);
    	struct tm t = *localtime(&tmNow);
	char* a = int_to_char(t.tm_min);
    	return a;
}

char* c_secs() {
	time_t tmNow;
    	tmNow = time(NULL);
    	struct tm t = *localtime(&tmNow);
	char* a = int_to_char(t.tm_sec);
    	return a;
}

void d_time(char* h, char* m, char* s, int x, int y) {
	settextstyle(2,0,5);
	outtextxy(x,y,h);
	outtextxy(x+17,y,":");
	outtextxy(x+22,y,m);
	outtextxy(x+39,y,":");
	outtextxy(x+44,y,s);
}

void clr_d_time(char* h, char* m, char* s, int x, int y) {
	setcolor(BLACK);
	settextstyle(2,0,5);
	outtextxy(x,y,h);
	outtextxy(x+17,y,":");
	outtextxy(x+22,y,m);
	outtextxy(x+39,y,":");
	outtextxy(x+44,y,s);
	setcolor(WHITE);
}


char* int_to_char(int n) {
	char* a = "";
	switch(n) {
		case 0: a= "00"; break;
		case 1: a="01"; break;
		case 2: a="02"; break;
		case 3: a="03"; break;
		case 4: a="04"; break;
		case 5: a="05"; break;
		case 6: a="06"; break;
		case 7: a="07"; break;
		case 8: a="08"; break;
		case 9: a="09"; break;
		case 10: a="10"; break;
		case 11: a="11"; break;
		case 12: a="12"; break;
		case 13: a="13"; break;
		case 14: a="14"; break;
		case 15: a="15"; break;
		case 16: a="16"; break;
		case 17: a="17"; break;
		case 18: a="18"; break;
		case 19: a="19"; break;
		case 20: a="20"; break;
		case 21: a="21"; break;
		case 22: a="22"; break;
		case 23: a="23"; break;
		case 24: a="24"; break;
		case 25: a="25"; break;
		case 26: a="26"; break;
		case 27: a="27"; break;
		case 28: a="28"; break;
		case 29: a="29"; break;
		case 30: a="30"; break;
		case 31: a="31"; break;
		case 32: a="32"; break;
		case 33: a="33"; break;
		case 34: a="34"; break;
		case 35: a="35"; break;
		case 36: a="36"; break;
		case 37: a="37"; break;
		case 38: a="38"; break;
		case 39: a="39"; break;
		case 40: a="40"; break;
		case 41: a="41"; break;
		case 42: a="42"; break;
		case 43: a="43"; break;
		case 44: a="44"; break;
		case 45: a="45"; break;
		case 46: a="46"; break;
		case 47: a="47"; break;
		case 48: a="48"; break;
		case 49: a="49"; break;
		case 50: a="50"; break;
		case 51: a="51"; break;
		case 52: a="52"; break;
		case 53: a="53"; break;
		case 54: a="54"; break;
		case 55: a="55"; break;
		case 56: a="56"; break;
		case 57: a="57"; break;
		case 58: a="58"; break;
		case 59: a="59"; break;
		case 60: a="60"; break;
	}
	return a;
}
