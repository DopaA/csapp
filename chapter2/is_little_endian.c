#include<stdio.h>

typedef unsigned char* byte_pointer;

int is_little(){
	int test_num=0x11;
	byte_pointer byte_start=(byte_pointer)&test_num;
	if(byte_start[0]==0x11){
		return 1;
	}
	return 0;
}

int main(){
	int t=is_little();
	printf("%d",t);	
	return 0;
}
