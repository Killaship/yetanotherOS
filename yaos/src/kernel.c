// (C) Killaship 2022, lol
#define OS_BUILD "0.1" // Update this every release
#include "testA.h"
void *progaddr = &testA_bin;

#include "multiboot.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdarg.h>
#include <ctype.h>
#include "common.h"
#include "ports.h"
#include "screen.h"
#include "panic.h"
#include "memory.h"
#include "cpu.h"
#include "rtc.h"
#include "ramdisk.h"
#include "pload.h"
#include "syscall.h"
#include "idt.h"



void kmain(/*unsigned int ebx*/) {
	clear_screen();
	idt_init();
	
	timer_phase(100);
	run_binary(progaddr, testA_bin_len);
	//bsodmsg("test");
	while(1);
}


