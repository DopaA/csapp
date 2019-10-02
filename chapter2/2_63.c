#include<stdio.h>

//用算术右移实现逻辑右移
unsigned srl(unsigned x,int k){
	unsigned xsra=(int)x>>k;
	int t=-1;
	int w=sizeof(int)<<3;//总位数
	int mask=~(t<<(w-k));
	return xsra&mask;
}

//用逻辑右移实现算术右移
unsigned sra(int x,int k){
	int xsrl=(unsigned)x>>k;
	int w=sizeof(int)<<3;
	int mask=(int)-1<<(w-k);
	int m=1<<(w-1);
	mask &=!(x&m)-1;//我傻了
	return xsrl|mask;
}
int main(){
	
}
