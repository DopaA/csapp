#include<stdio.h>
#include<assert.h>

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

int main(){
	assert(leftmost_one(0xff00)==0x8000);
	return 0;
}
