#define freetop 8192 // kernel heap size
void *heap[freetop];
int freebase = 0;

void *kmalloc(int nbytes)
{	
	void *ptr = (void *) heap[freebase];
	if(freetop - freebase > nbytes) {
		return ptr;
		freebase = freebase + nbytes;
	}
	else {
		bsodmsg("Out of kheap memory!\nThere's probably some kmalloc() that went wrong.");
		return 0;
	}
}
