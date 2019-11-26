#line 177 "bits.c"
int bitAnd(int x, int y) {
  return ~((~x)|(~y));
#line 31 "<command-line>"
#include "/usr/include/stdc-predef.h"
#line 179 "bits.c"
}
#line 188
int getByte(int x, int n) {
 n <<= 3;
  return (x>>n)&0xff;
}
#line 201
int logicalShift(int x, int n) {
 int mask=1<<31;
 mask=mask>>n;
 return (x>>n)&~(mask<<1);
}
#line 214
int bitCount(int x) {
 int count;
    int tmpMask1=(  0x55)|(0x55<<8);
    int mask1=(  tmpMask1)|(tmpMask1<<16);
    int tmpMask2=(  0x33)|(0x33<<8);
    int mask2=(  tmpMask2)|(tmpMask2<<16);
    int tmpMask3=(  0x0f)|(0x0f<<8);
    int mask3=(  tmpMask3)|(tmpMask3<<16);
    int mask4=(  0xff)|(0xff<<16);
    int mask5=(  0xff)|(0xff<<8);
    count =( x&mask1)+((x>>1)&mask1);
    count =( count&mask2)+((count>>2)&mask2);
    count =( count +( count >> 4)) & mask3;
    count =( count +( count >> 8)) & mask4;
    count =( count +( count >> 16)) & mask5;
    return count;
}
#line 238
int bang(int x) {
 int tmp=~x+1;
 tmp=x|tmp;
 tmp >>=31;
 return (tmp+1);
}
#line 250
int tmin(void) {
 return 1<<31;
}
#line 262
int fitsBits(int x, int n) {
 int shifts=32+(~n+1);
 return !(x^((x<<shifts)>>shifts));
}
#line 274
int divpwr2(int x, int n) {
 int signx=x>>31;
 int mask=(  1<<n)+(~0);
 int bias=signx&mask;
    return (x+bias)>>n;
}
#line 287
int negate(int x) {
  return (~x)+1;
}
#line 297
int isPositive(int x) {
  return !((x>>31)|(!x));
}
#line 307
int isLessOrEqual(int x, int y) {
 int singx=(  x>>31)&1;
 int singy=(  y>>31)&1;
 int sing=(singx^singy)&singx;
 int tmp= x+((~y)+1);
 tmp =(( tmp>>31)&1)&(!(singx^singy));
 return (sing|tmp|(!(x^y)));
}
#line 322
int ilog2(int x) {
 int bitsNumber=0;
    bitsNumber=(!!(x>>16))<<4;
    bitsNumber=bitsNumber+((!!(x>>(bitsNumber+8)))<<3);
    bitsNumber=bitsNumber+((!!(x>>(bitsNumber+4)))<<2);
    bitsNumber=bitsNumber+((!!(x>>(bitsNumber+2)))<<1);
    bitsNumber=bitsNumber+(!!(x>>(bitsNumber+1)));
 bitsNumber=bitsNumber+(!!bitsNumber)+(~0)+(!(1^x));
 return bitsNumber;
}
#line 343
unsigned float_neg(unsigned uf) {
 unsigned result;
 unsigned tmp;
 result=uf^0x80000000;
 tmp=uf&(0x7fffffff);
 if (tmp>0x7f800000) 
  return uf;
 return result;
}
#line 361
unsigned float_i2f(int x) {
    unsigned shiftLeft=0;
    unsigned afterShift;unsigned tmp;unsigned flag;
    unsigned absX=x;
    unsigned sign=0;

    if (x==0) return 0;

    if (x<0) 
    {
        sign=0x80000000;
        absX=-x;
    }
    afterShift=absX;

    while (1) 
    {
        tmp=afterShift;
        afterShift<<=1;
        shiftLeft++;
        if (tmp & 0x80000000) break;
    }
    if ((afterShift & 0x01ff)>0x0100) 
        flag=1;
    else if ((afterShift & 0x03ff)==0x0300) 
        flag=1;
    else 
        flag=0;

    return sign +( afterShift>>9) +(( 159-shiftLeft)<<23) + flag;
}
#line 403
unsigned float_twice(unsigned uf) {
 unsigned f=uf;
 if ((f&0x7f800000)==0) 
  f=((f&0x007fffff)<<1)|(0x80000000 & f);
 else if ((f&0x7f800000)!=0x7f800000) 
  f=f+0x00800000;
 return f;
}
