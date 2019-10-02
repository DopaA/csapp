#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#include<inttypes.h>
typedef unsigned packet_t;

//2.70
//查看x能否被n位的2进制补码数表示
int fits_bits(int x,int n){
	int w=sizeof(int)<<3;
	int offset=w-n;
	return (x<<offset>>offset)==x;
}
//2.71
//题中的那个不能提取负数
//从一个数中提取一个字节转为int
int xbyte(packet_t word,int bytenum){
	int size=sizeof(unsigned);
	int shift_left=(size-1-bytenum)<<3;
	int shift_right=(size-1)<<3;
	return (int)word<<shift_left>>shift_right;
}

//2.72
//size_of返回的是size_t类型的，因此作加减运算会将结果转为unsigned
void copy(int val,void *buf,int maxbytes){
	if(maxbytes>=(int)sizeof(val))
		memcpy(buf,(void *)&val,sizeof(val));
}

//2.73
//正溢出返回TMAX，下溢返回TMIN
//有不能用条件语句等限制
int saturating_add(int x,int y){
	int sum=x+y;
	int sig_mask=INT_MIN;
	int pos_over=!(x&sig_mask)&&!(y&sig_mask)&&(sum&sig_mask);
	int neg_over=(x&sig_mask)&&(y&sig_mask)&&!(sum&sig_mask;
	(pos_over&&(sum = INT_MAX)|| neg_over&&(sum=INT_MIN));
	return sum;
}

//2.74
//减法，不溢出
int tsub_ok(int x,int y){
	int ret=1;
	(y==INT_MIN)&&(ret=0);
	int s=x-y;
	int pos_over=x>0&&y<0&&sub<0;
	int neg_over=x<0&&y>0&&sub>0;
	ret=ret&&!(pos_over||neg_over);
	return ret;
}

//2.75
//求x*y的2w位表示,只返回高阶(即高阶的32位)
int singed_high_prod(int x,int y){
	int64_t mul=x*y;
	return mul>>32;
}

unsigned unsigned_high_prod(unsigned x,unsigned y){
	int sig_x=x>>31;
	int sig_y=y>>31;
	int signed_prod=signed_prod(x,y);
	return signed_prod+x*sig_y+y*sig_x;//加上少了的两个
}

unsigned another_unsigned_high_prod(unsigned x,unsigned y){
	uint64_t mul=(uint64_t)x*y;
	return mul>>32;
}

//2.76
//用malloc和memset实现calloc
void *calloc(size_t n,size_t size){
	if(n==0||size==0){
		return NULL;
	}
	size_t buff_size=n*size;
	if(n==buff_size/size){
		void *ptr=malloc(buff_size);
		if(ptr!=NULL)
			memset(ptr,0,buff_size);
		return ptr;
	}
	return NULL;
}

//2.77
//乘以常数，只用加减和<<
//K=17
int A(int x){
	return (x<<4)+x;
}

//K=-7
int B(int x){
	return x-(x<<3);
}


//2.78
//计算x/2^k
int divide_power2(int x,int k){
	int is_neg=x&INT_MIN;
	(is_neg&&(x=x+(1<<k)-1));//道理呢
	return x>>k;
}

//2.79
//
int mul3div4(int x){
	int mul3=(x<<1)+x;
	return divide_power2(mul3,2);
}

