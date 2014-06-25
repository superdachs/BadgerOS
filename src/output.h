static int minx = 0;
static int miny = 0;
static int x = 0;
static int y = 0;
const int maxx = 79;
const int maxy = 24;
static char* video = (char*) 0xb8000;

void cls() {
	x = minx;
	y = miny;
	int xx;
  int yy;
  for (yy = 0; yy <= maxy; yy++) {
		for (xx = 0; xx <= maxx; xx++) {
			video[2 * (yy * maxx + xx)] = ' ';
			if (xx >= minx  && xx <= maxx && yy >= miny && y <= maxy) {
				video[2 * (yy * 80 + xx) + 1] = 0x8E;
			} else {
				video[2 * (yy * 80 + xx) + 1] = 0x8E;
			}
		}
	}
}

void kputc(char c) {
	video[2 * (y * 80 + x)] = c;
	video[2 * (y * 80 + x) + 1] = 0x8E;
}

void kprintf(char string[]) {
	int p;
	for (p = 0; string[p] != '\0'; p++) {
		
		// Handle last line
		if(y > maxy) {
			int xx;
			int yy;

			for(yy = maxy; yy >= 0; yy--) {
				for(xx = 0; xx <= maxx; xx++) {
					video[2 * ((yy - 1) * 80 + xx)] = video[2 * (yy * 80 +xx)];
				}
			}
			y = maxy;
			for(xx = 0; xx <= maxx; xx++) {
				video[2 * (y * 80 + xx)] = ' ';
			}
		}

		kputc(string[p]);
		x++;
	}
  x = minx;
	y++;
} 	


