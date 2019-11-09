#include<stdio.h>

#define BUFF_SIZE 12

void good_echo(){
	char buf[BUFF_SIZE];
	while(1){
		char *p=fgets(buf,BUFF_SIZE,stdin);
		if(p==NULL)
			break;
		printf("%s",p);
		printf("%d",1);
	}
	return ;
}

int main(int argc,char * argv[]){
	good_echo();
	return 0;
}
