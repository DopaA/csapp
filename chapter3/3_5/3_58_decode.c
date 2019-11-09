#include<stdio.h>

long decode2(long x,long y,long z){
	y-=z;
	x*=y;
	return ((y<<63)>>63)^x;
}


//在网上的参考答案如下
long decode(long x,long y,long z){
	long tmp=y-z;
	return (tmp*x)^(tmp<<63>>63);
}
