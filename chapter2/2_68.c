#include<stdio.h>

int lower_one_mask(int n){
	unsigned int x=(unsigned)-1;
	int w=sizeof(int)<<3;
	return x>>(w-n);
}
