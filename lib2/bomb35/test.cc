#include<iostream>
using namespace std;


int func4(int x1,int x2){
	if(x1<=0)return 0;
	if(x1==1)return x2;
	int result=x2;
	result=func4(x1-1,x2);
	int r12d=result+x2;
	result=func4(x1-2,x2);
	result+=r12d;
	return result;
}


int main(){
	cout<<func4(9,3)<<endl;
	return 0;
}
