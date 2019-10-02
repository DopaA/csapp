#include<stdio.h>

//查看x能否被n位的2进制补码数表示
int fits_bits(int x,int n){
	int w=sizeof(int)<<3;
	int offset=w-n;
	return (x<<offset>>offset)==x;
}
