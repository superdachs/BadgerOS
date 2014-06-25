static int x = 0;
static int y = 0;
const int maxx = 80;
const int maxy = 25;
static char* video = (char*) 0xb8000;

void clrscr() {
	x = 4;
  y = 2;
  int i;
	for (i = 0; i < 2 * 25 * 80; i++) {
		video[i] = 0;
	}
}

void cls() {
	x = 0;
	y = 0;
	int xx;
  int yy;
  for (yy = 0; yy < 25; yy++) {
		for (xx = 0; xx < 80; xx++) {
			video[2 * (yy * 80 + xx)] = ' ';
			if (xx > x && xx < maxx && yy > y && y < maxy) {
				video[2 * (yy * 80 + xx) + 1] = 0x8E;
			} else {
				video[2 * (yy * 80 + xx) + 1] = 0x8E;
			}
		}
	}
}

void kputc(char c) {
	kputcxy(c, x, y);
}

void kprintf(char string[]) {
	kprintfxy(string, x, y);
  y++;
}

void kputcxy(char c, int x, int y) {
	video[2 * (y * 80 + x)] = c;
	video[2 * (y * 80 + x) + 1] = 0x8E;
}

void kprintfxy(char string[], int x, int y) {
	int i;
	for (i = 0; string[i] != '\0'; i++) {
		kputcxy(string[i], x, y);
		x++;
	}
} 	


