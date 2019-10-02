#include<stdio.h>

//包含了奇数个1,假设32位
//目前没看懂
int odd_ones(unsigned x){
	x^=x>>16;
	x^=x>>8;
	x^=x>>4;
	x^=x>>2;
	x^=x>>1;
	x&=0x01;
	return x;
}
