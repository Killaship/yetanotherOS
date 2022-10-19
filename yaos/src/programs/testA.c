//#include "lib/printf.h"

void volatile printf(const char *str, int color) {
	

	asm volatile( "push %[color]"
	:
	: [color] "b" (color)
	);
	asm volatile( "push %[string]"
	:
	: [string] "b" (str)
	);
	asm volatile ("int $0x80");
}

void main() {
	printf("test\n", 0x07);
}

void start() {
	main();
}