#include<stdio.h>


//算术右移返回1
int int_shifts_are_arithmetic(){
	int t=-1;
	return (t>>((sizeof(int))>>3))&0x1;
	//answer is return !(t^(t>>1));
}
int main(){
	
}
