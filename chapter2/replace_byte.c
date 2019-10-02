#include<stdio.h>
#include<assert.h>

typedef unsigned char* byte_pointer;
unsigned replace_byte(unsigned x,int i,unsigned char b){
	if(i<0){
		printf("i must be positive or 0");
		return x;
	}
	if(i>sizeof(unsigned)-1){
		printf("i is to big");
		return x;
	}
	unsigned mask=~(((unsigned)0xff)<<(i<<3));
	unsigned pos_byte=((unsigned)b)<<(i<<3);
	return (x&mask)|pos_byte;
}

int main(){
	unsigned rep_0=replace_byte(0x12345678,0,0xab);
	unsigned rep_3=replace_byte(0x12345678,3,0xcd);
	assert(rep_0==0x123456ab);
	assert(rep_3==0xcd345678);
	return 0;
}
