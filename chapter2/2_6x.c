#include<stdio.h>
#include<assert.h>
//2.60
//
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
//x的所有位都为1返真
//2.61
int A(int x){
	return !~x;
}

//全为0
int B(int x){
	return !x;
}

//最低字节全为1
int C(int x){
	return A(x|!0xff);
}

//最高字节全为0
int D(int x){
	return B((x>>(sizeof(int)-1)>>3)&0xff);
}

//2.62
//算术右移返回1
int int_shifts_are_arithmetic(){
	int t=-1;
	return (t>>((sizeof(int))>>3))&0x1;
	//answer is return !(t^(t>>1));
}

//2.63
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

//2.64
//只要奇数位有一个为1，就返回1
int any_odd_one(unsigned x){
	return !!(0xAAAAAAAA&x);
}

//2.65
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


//2.66
//生成一个面具，指示最左边的1  0xFF00->0x8000
int leftmost_one(unsigned x){
	//先让最左边的1的右边全是1，比如0xff00->0xffff
	x|=x>>1;
	x|=x>>2;
	x|=x>>4;
	x|=x>>8;
	x|=x>>16;
	return (x>>1)+(x&&1);//如果x是非0，则右移一位加1就是最左边的！
}


//2.67
//error in some machines
int bad_int_size_is_32(){
	int set_msb=1<<31;
	int beyond_msb=1<<32;
	return set_msb&&!beyond_msb;
}

int int_size_is_32(){
	int set_msb=1<<31;
	int beyond_msb=set_msb<<1;
	return set_msb&&!beyond_msb;
}

int int_size_is_32_for_16bit(){
	int set_msb=1<<15<<15<<1;
	int beyond_msb=set_msb<<1;
	return set_msb&&!beyond_msb;
}
//2.68
int lower_one_mask(int n){
	unsigned int x=(unsigned)-1;
	int w=sizeof(int)<<3;
	return x>>(w-n);
}
//2,69
int rorate_left(int x,int n){
	int w=sizeof(unsigned)<<3;
	return x<<n | x>>(w-n-1)>>1;//为了防止n为0而移过的情况
}
