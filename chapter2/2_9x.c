#include<stdio.h>
#include<math.h>


float u2f(unsigned x){
	return *(float *)&x;
}
//2.90
//返回2^x的浮点数表示
float fpwr2(int x){
	unsigned exp,frac;
	unsigned u;
	if(x< 2-pow(2,7)-23){//too small//x< -149,无法表示
		exp=0;
		frac=0;
	}else if(x<2-pow(2,7)){//denormailed，x<-126,保证了指数全为0及以下
		exp=0;
		frac=1<<(unsigned)(x-(2-pow(2,7)-23));//-127，frac的第一位为1，-128，第二位.............，因为E=1-bias= -126！
	}else if(x<pow(2,7)){//normailed
		exp=pow(2,7)-1+x;
		frac=0;
	}else{//to big  x>=128
		exp=0xff;
		frac=0;
	}
	u=exp<<23|frac;
	return u2f(u);
}


typedef unsigned float_bits;
//2.92
//计算-f，如果f是NaN，返回f

float_bits float_negate(float_bits f){
	unsigned sig=f>>31;
	unsigned exp=f>>23&0xff;
	unsigned frac=f&0x7fffff;
	
	int is_NAN = (exp==0xff)&&(frac!=0);
	if(is_NAN)
		return f;
	return (~(sig<<31))|exp<<23|frac;
}


//2.93
//计算|f|,如果是nan，返回f

float_bits float_abs(float_bits f){
	unsigned sig=f>>31;
	unsigned exp=f>>23&0xff;
	unsigned frac=f&0x7fffff;
	
	int is_NAN = (exp==0xff)&&(frac!=0);
	if(is_NAN)
		return f;
	return 0<<31|exp<<23|frac;
}



//2.94 2*f
float_bits float_twice(float_bits f){
	unsigned sig=f>>31;
	unsigned exp=f>>23&0xff;
	unsigned frac=f&0x7fffff;
	
	int is_NAN_or_oo = (exp==0xff);//一旦指数为最大，就算不是nan也会溢出
	if(is_NAN_or_oo)
		return f;
	if(exp==0){
		frac<<1;
	}else{
		exp+=1;
	}
	return sig<<31|exp<<23|frac;
}

//2.95 0.5f
float_bits float_half(float_bits f){
	unsigned sig=f>>31;
	unsigned exp=f>>23&0xff;
	unsigned frac=f&0x7fffff;
	unsigned rest=f&0x7fffffff;
	
	int is_NAN = (exp==0xff)&&(frac!=0);//这里不清楚参考资料不要frac!=0，应该不会溢出阿
	if(is_NAN)
		return f;
	//00->0 >>1
	//01->0 to even >>1
	//10->1 >>1
	//11->1+1 to even >>1and +1
	int addition=(frac&0x3)==0x3;
	if(exp==0){
		frac>>1;
		frac+=addition;
	}else if(exp==1){//存疑//当frac最后两位为11，则exp=0x80，frac=0，否则exp=0x3f,frac=0x7fffff;????
		rest>>1;
		rest+=addition;
		exp=rest>>23&0xff;
		frac=rest&0x7fffff;
	}else{
		exp-=1;
	}
	return sig<<31|exp<<23|frac;
}

//2.96
//
int float_f2i(float_bits f){
	unsigned sig=f>>31;
	unsigned exp=f>>23&0xff;
	unsigned frac=f&0x7fffff;
	unsigned bias=0x7f;
	
	int num;
	unsigned E;
	unsigned M;
	
	if(exp>>0&&exp<0+bias){//小于1，即为0
		num=0;
	}else if(exp>=31+bias){ //>2^31
		num=0x80000000;
	}else{
		E=exp-bias;
		M=frac|0x800000;
		if(E>23){//>23即表示可以左移，并且可以左移已经减去移过的23位的余下的
			num=M<<(E-23);
		}else{
			num=M>>(23-E);
		}
	}
	return sig?-num:num;
}

//2.97
//int to float
int bit_length(int i){
	if((i&INT_MIN)!=0){
		return 32;
	}
	unsigned u=(unsigned)i;
	int length=0;
	while(u>=(1<<length)){
		length++;
	}
	return length;
}

unsigned bits_mask(int l){
	return (unsigned)-1>>(32-l);
}

float_bits float_i2f(int i){
	unsigned sig,exp,frac,resr,exp_sig,round_part;
	unsigned bits,fbits;
	unsigned bias=0x7f;
	
	//为0的情况
	if(i==0){
		sig=0;
		exp=0;
		frac=0;
		return sig<<31| exp<<23| frac;
	}
	//为最大负数的情况
	if(i==INT_MIN){
		sig=1;
		exp=bias+31;
		frac=0;
		return sig<<31| exp<<23| frac;
	}
	//其他情况
	//确定符号位
	sig=0;
	if(i<0){
		sig=1;
		i=-i;
	}
	//
	bits=bit_length(i);
	fbits=bits-1;
	exp=bias+fbits;
	rest=i&bits_mask(fbits);
	if(fbits<=23){
		frac=rest<<(23-fbits);
		exp_sig=exp<<23|frac;
	}else{//frac的位数大于23的话，需要舍入
		int offset=fbits-23;
		int round_mid = 1<<(offset-1);
		round_part=rest&bits_mask(offset);
		frac=rest>>offset;
		exp_sig=exp<<23|frac;
		
		if(round_part<round_mid){
			
		}else if(round_part>round_mid){
			exp_sig+=1;
		}else{
			if((frac&0x1)==1)
				exp_sig+=1;
		}
	}
	return sig<<31 | exp_sig;
}
