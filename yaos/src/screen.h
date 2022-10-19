/* current cursor location */
unsigned int current_loc = 0;
/* video memory begins at address 0xb8000 */
char *vidptr = (char*)0xb8000;


#define LINES 25
#define COLUMNS_IN_LINE 80
#define BYTES_FOR_EACH_ELEMENT 2
#define SCREENSIZE BYTES_FOR_EACH_ELEMENT * COLUMNS_IN_LINE * LINES

void kprint_newline(void) {
        unsigned int line_size = BYTES_FOR_EACH_ELEMENT * COLUMNS_IN_LINE;
        current_loc = current_loc + (line_size - current_loc % (line_size));
}

void kprint(const char *str, int color) {
	for(size_t i = 0; i < strlen(str); i++) {
		switch(str[i]) {
		case '\n':
			kprint_newline();
			break;
		case '\t':
			for(int j = 0; j < 4; j++)
				kprint(" ", color);
			break;
		default:
			vidptr[current_loc++] = str[i];
			vidptr[current_loc++] = color;
			break;
		}
	}
}


void clear_screen(void)
{
	unsigned int i = 0;
	while (i < SCREENSIZE) {
		vidptr[i++] = ' ';
		vidptr[i++] = 0x07;
	}
}
