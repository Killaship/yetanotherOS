
void syscall(unsigned int func, unsigned int arg1, unsigned int arg2) {
	
	switch(func) {
		case 0: // arg1 is pointer to string, arg2 is color
			kprint(arg1, arg2);
			break;
		default:
			bsodmsg("Improper syscall!");
			break;
	}
}