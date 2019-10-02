#include<stdio.h>

//x的所有位都为1返真
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
