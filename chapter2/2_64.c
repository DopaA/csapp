#include<stdio.h>

//只要奇数位有一个为1，就返回1
int any_odd_one(unsigned x){
	return !!(0xAAAAAAAA&x);
}
