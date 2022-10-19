#define PROG_ADDRESS (void*)0x80000

// we do a little copy-pasting

void clear_binary(int size){
    memset(PROG_ADDRESS, 0,size);
}

void run_binary(void* program_block, int programSize){
    if(programSize == 0) return;
    memcpy(PROG_ADDRESS,program_block,programSize);
    asm volatile("call *%0"
							 :
							 : "r"(PROG_ADDRESS));
    clear_binary(programSize);
}

