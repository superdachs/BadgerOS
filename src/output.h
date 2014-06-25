static int x = 0;
static int y = 0;

int clrscr(char* video) {
	int i;
	for (i = 0; i < 2 * 25 * 80; i++) {
		video[i] = 0;
	}
        return 0;
}

void kputc(char* video, char c, int x, int y) {
	video[2 * (y * 80 + x)] = c;
	video[2 * (y * 80 + x) + 1] = 0x07;
}

void kprintfxy(char* video, char string[], int x, int y) {
	int i;
	for (i = 0; string[i] != '\0'; i++) {
		video[2 * (y * 80 + x)] = string[i];
		video[2 * (y * 80 + x) +1] = 0x07;
		x++;
	}
} 	


