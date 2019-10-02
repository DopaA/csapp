#include<stdio.h>
#include<limits.h>

//2.80
//计算3/4x 不能溢出
//分开算的原因？因为要向0舍入
int threeforths(int x){
	int is_neg=x&INT_MIN;
	int f=x&~0x3;
	int l=x&0x3;
	int fd4=f>>2;
	int fd4m3=(fd4<<1)+fd4;
	
	int lm3=(l<<1)+1;
	int bias=(1<<2)-1;
	(is_neg&&(lm3+=bias));
	int lm3d4=lm3>>2;
	
	return fd4m3+lm3d4;
}

//2.81
//
int A(int k){
	return -1<<k;
}

int B(int k,int j){
	return ~A(k)<<j;
}

//2.82
//A.wrong,x=INT_MIN
//right
//right
///*
// * right
//  *
//   * ~x + ~y + 1
//    *   =>
//     * ~x + 1 + ~y + 1 - 1
//      *   =>
//       * -x + -y - 1
//        *   =>
//         * -(x + y) - 1
//          *   =>
//           * ~(x + y) + 1 - 1
//            *   =>
//             * ~(x + y)
//              */
//right
//right


//2.83
//A:
//n = 0.yyyyy...
//n << k = y.yyyyy... = Y + n
//n << k - n = Y
//n = Y/(2^k - 1)
//B:
//a Y=5,k=3,n=5/7
//n=2/5
//n=19/63
//

//2.84
int float_le(float x, float y) {
	unsigned ux = f2u(x);
	unsigned uy = f2u(y);

	unsigned sx = ux >> 31;
	unsigned sy = uy >> 31;
	return (ux<<1==0&&uy<<1==0)||
			(sx&&!sy)||
			(!sx&&!sy&&ux<=uy)||
			(sx&&sy&&ux>=uy);
}

//2.85
//
