#include<stdio.h>

int rorate_left(int x,int n){
	int w=sizeof(unsigned)<<3;
	return x<<n | x>>(w-n-1)>>1;//为了防止n为0而移过的情况
}
