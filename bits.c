/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * <Hawcherng Lu/卢浩程>
 * <BNU-202111998172>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
//bit-level
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  int z = ~((~(x&(~y)))&(~(y&(~x))));
  return z;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (least significant) to 3 (most significant)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  int tmp = n + n + n + n;
  int y = (((x >> tmp) >> tmp) & 0xff);
  return y;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  // 右移默认会填充符号位。
  // 尝试直接得到符号位，1为负，0为正。
  // 必须&1，否则负数的话会得到-1。
  int sgn = (x >> 31) & 1;
  int nsgn = !sgn;
  int y = ((1 << 31) >> n) << 1;// 原来，这不叫integer constant
  //int sgn = (((x >> 31) << 30) >> n) << 1;
  int nneg = ((~nsgn) + 1) & (x >> n);
  int neg = ((~sgn) + 1) & ((~y) & (x>>n));
  return nneg+neg;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  // Reference 1:
  // Brian Kernighan
  // x & (x - 1) 会将最右的零消除掉。
  // 统计这样操作的次数。
  // 但是吧，这样也还会爆 Op 的啊。。。
  
  // Reference 2:
  // Hamming Weight
  // 我何德何能想得出来。。。
  int mask1, mask2, mask3, mask4, mask5;
  int sum;

  // 也考虑过 (x >> 1) & 1，但肯定爆炸。
  // 之前也一直考虑分治和掩码，但操作类似于
  // 0101 & 1110 != 0
  // 0101 & 1100 != 0
  // 0101 & 1000 == 0
  // 结果这样只能得到howManyBits，而且还爆 Ops。
  // 想到的分治，也无非是类似打表，分成类似 4 个 Byte。
  // 每段与上掩码，一方面没有想好，另一方面求和也是老大难。
  
  // 预定义掩码
  // 俺何德何能
  mask1 = 0x55 | (0x55 << 8);
  mask1 = mask1 | (mask1 << 16); // 0x55555555

  mask2 = 0x33 | (0x33 << 8);
  mask2 = mask2 | (mask2 << 16); // 0x33333333

  mask3 = 0x0F | (0x0F << 8);
  mask3 = mask3 | (mask3 << 16); // 0x0F0F0F0F

  mask4 = 0xFF | (0xFF << 16); // 0x00FF00FF

  mask5 = 0xFF | (0xFF << 8); // 0x0000FFFF

  // 分阶段累加
  sum = (x & mask1) + ((x >> 1) & mask1);
  sum = (sum & mask2) + ((sum >> 2) & mask2);
  sum = (sum & mask3) + ((sum >> 4) & mask3);
  sum = (sum & mask4) + ((sum >> 8) & mask4);
  sum = (sum & mask5) + ((sum >> 16) & mask5);

  return sum;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // 非 0 的全都是 true！！！ 
  int mux = ((~(!x)) + 1);
  int zero =  mux & z;
  int nzero = ~mux & y;
  return zero + nzero;
}
//two's complement
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return (1<<31);
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  int sgn = (x >> 31) & 1;
  int nsgn = !sgn;
  // 原来负号不算op，但是，怪，为什么没有判-1非法。原来是没跑dlc
  // dlc蠢得很
  // 假如先左移再右移的话，正数可能变号。
  //int nneg = nsgn & !((x >> nsub1));
  //int neg = sgn & (!(((~(x>>n)))));
  int neg1 = ~0;//((~1)+1);
  int mask = neg1 << (n + neg1); // 老是忘记要减1的操作。
  int nneg = nsgn & !(x & mask);
  int neg = sgn & !(~(x | (~mask)));
  // -2147483648[0x80000000]
  // 取补后仍为它本身。
  return nneg + neg;
}
/* 
 * dividePower2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: dividePower2(15,1) = 7, dividePower2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int dividePower2(int x, int n) {
  int sgn = (x >> 31) & 1;
  //int nsgn = !sgn;
  int direct = (x >> n);
  // Old Code 3
  //int nneg = ((~nsgn) + 1) & direct;
  //int neg = ((~sgn) + 1) & (direct + odd);
  // Old Code 4
  //int mux = ((~sgn) + 1); // 这里可以砍，可见前几个代码处也可以删
  //int neg =  mux & (direct + odd);
  //int nneg = ~mux & direct;
  int mask = ~((~0) << n);
  int odd = (!(!(mask & x)));
  int y = direct + (odd & sgn);
  // Old Code 1
  //int leftmost = sgn << 31;
  //int comple = (~x)+1;
  //int neg = ((~sgn) + 1) & (((~(comple >> n))+1)|leftmost);
  // Old Code 2
  //int odd = x & 1;
  //int neg = ((~sgn) + 1) & ((x >> n) + (!(!n) & odd));
  // 猜想：末 n 位里如果有 1（也就意味着算数的中间过程中会出现奇数）
  // 奇数又会被强行向下取整，但是只需要加一回 1 就可以了。
  // 如何得到末 n 位里 1 的情况（这里只考虑负数）
  // (-2147483647[0x80000001] 假如直接 x 右移...
  // Gives -1073741824[0xc0000000]. Should be -1073741823[0xc0000001]
  // 右移对于正数是向下取整，对于负数也是向下取整取整。
  // 所以问题：30 >> 1 = 15;
  // -30 >> 1 = -15，但是-15 >> 1 = -8。
  // 一开始老是想要先换成正数再右移
  // -2147483648[0x80000000]
  // 不能表示成正数，会超限制。
  // 取补后仍为它本身。
  return y;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return (~x)+1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  // http://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetNaive
  // 不对，以上链接给的是 bitCount
  // ~评价为做不出来 bitCount 就别想做对。~
  // 想错了，不是简单的 #0 + #1 就能做对
  // 正数右移 n 次后为 0，再 + 1。（以表示符号位）
  // 负数右移 n 次后变为 -1，最少也得有一位。

  // Claude 3 Sonnet 给的几乎是对的。
  int b16, b8, b4, b2, b1, b0;
  int sgn = x >> 31;
  x = (sgn & ~x) | (~sgn & x); // x = abs(x), except when x == 0x80000000

  // Binary Search
  b16 = !!(x >> 16) << 4;
  x = x >> b16;
  b8 = !!(x >> 8) << 3;
  x = x >> b8;
  b4 = !!(x >> 4) << 2;
  x = x >> b4;
  b2 = !!(x >> 2) << 1;
  x = x >> b2;
  b1 = !!(x >> 1);
  x = x >> b1;
  b0 = x;

  return b16 + b8 + b4 + b2 + b1 + b0 + 1;
}

/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // -2147483648[0x80000000]
  // 不能表示成正数，会超限制。
  // 还要考虑溢出。
  int sgnx = (x >> 31) & 1;
  int sgny = (y >> 31) & 1;
  int sum = x + ((~y)+1); // x - y
  int sgn = (sum >> 31) & 1;
  // 当 sgn == 0 时候，还需要判断一下 sum 是否为0，即 !sum == 1
  // Warning: suggest parentheses around arithmetic in operand of |
  int leq =  (!(x ^ y)) | (sgnx & (~sgny)) | (!(sgnx ^ sgny) & sgn);
  return leq;
}
/*
 * intLog2 - return floor(log base 2 of x), where x > 0
 *   Example: intLog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int intLog2(int x) {
  // http://graphics.stanford.edu/~seander/bithacks.html#IntegerLogObvious
  int b0 = 0x2;
  int b1 = 0xC;
  int b2 = 0xF0;
  int b3 = 0xFF << 8; // 0xFF00;
  int b4 = (b3 | 0xFF) << 16; // 0xFFFF0000;

  int r = 0; // result of log2(v) will go here
  int mask;
  int shift;
  
  // 以下形式上采取与 howManyBits 略有不同但实际一样的操作。
  // 32位整数，检查高16位
  mask = !!(b4 & x);
  shift = mask << 4;
  x = x >> shift;
  r = r | shift;

  // 接下来检查高8位
  mask = !!(b3 & x);
  shift = mask << 3;
  x = x >> shift;
  r = r | shift;

  // 接下来检查高4位
  mask = !!(b2 & x);
  shift = mask << 2;
  x = x >> shift;
  r = r | shift;

  // 检查高2位
  mask = !!(b1 & x);
  shift = mask << 1;
  x = x >> shift;
  r = r | shift;

  // 最后检查最高位
  mask = !!(b0 & x);
  r = r | mask;

  return r;
}
//float
/* 
 * floatAbsVal - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatAbsVal(unsigned uf) {
  // A zero value, null pointer value,
  // or null member pointer value is converted to false;
  // any other value is converted to true.
  // 32-bit
  // 1-bit 8-bit 23-bit
  // Inf can be abs
  // NaN just return
  // 这里用不用 unsigned 都没事。
  unsigned exp = (0xff << 23);
  unsigned frac = (1 << 23 - 1);
  unsigned neg = (1 << 31);
  if((exp & uf) == exp) // 抽象，之前用成了 &&
  {
    if((frac & uf) != 0)
      return uf;
  }
  return uf & ~neg; // 无穷等同“正常”（其实也包括非规格化）的数

  // 这是对的，思路不太一样。
  /*
  unsigned mask = (1 << 31) - 1;// 0x7FFFFFFF; // Mask to clear the sign bit
  unsigned minNaN = 0x7F800001; // Smallest NaN in positive space
  if ((uf & mask) >= minNaN) { // Check for NaN
    return uf; // If NaN, just return the original value
  }
  return uf & mask; // Clear the sign bit for absolute value
  */
  // 这也是对的，思路一样，之前把 && 写成了 & 所以的到了不同的结果。
  /*
  unsigned expMask = (0xff << 23); // 0x7F800000; // 阶码掩码，用于提取阶码部分
  unsigned fracMask =  (1 << 23 - 1); // 0x007FFFFF; // 尾数掩码，用于提取尾数部分
  unsigned signMask =  0x80000000; // 符号位掩码，用于提取符号位

  unsigned exp = uf & expMask; // 提取阶码部分
  unsigned frac = uf & fracMask; // 提取尾数部分

  // 检查是否为NaN：阶码全为1且尾数不为0
  if (exp == expMask && frac != 0) {
    return uf; // 如果是NaN，直接返回原值
  }

  // 取绝对值：清除符号位
  return uf & ~signMask;
  */
}
/* 
 * floatScale1d2 - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale1d2(unsigned uf) {
  int exp_ = (uf&0x7f800000) >> 23;
  int s_ = uf&0x80000000;
  if((uf&0x7fffffff) >= 0x7f800000) return uf;
  if(exp_ > 1) return (uf&0x807fffff)|(--exp_)<<23;
  if((uf&0x3) == 0x3) uf = uf + 0x2;
  return ((uf>>1)&0x007fffff)|s_;

  /*
  //uf = 8388607;
  unsigned expMask = (0xff << 23);
  unsigned fracMask = (1 << 23 - 1);
  unsigned sgnMask = (1 << 31);
  unsigned nsgnMask = ~sgnMask;
  unsigned exp = expMask & uf;
  unsigned frac = fracMask & uf;
  unsigned sgn = sgnMask & uf;
  unsigned nsgn = nsgnMask & uf;
  unsigned nsgnrs = nsgn >> 1;
  if(nsgn == 0) // 注意运算结合优先级
  // ((nsgnMask & uf) == 0) 和 (nsgnMask & uf == 0) 是不一样的！！！
    return uf;
  else if(nsgn == (1 << 23))
    return nsgnrs|sgn;
  else if (nsgn == ((1 << 23) - 1)) { // Handle the case of 0x7fffff separately
    return ((nsgnrs|sgn >> 1) + 1);  // Return 0x3fffff + 1 (0.5 * 0x7fffff)
  }

  if(exp == expMask)
  {
    if(frac)
      return uf;
  }

  // 需要考虑最小的非规格变成0，直接减会变成0！！！

  if((exp == (1 << 23)))
  {
    exp -= (1 << 23);
    frac += (1 << 22);
    //return 1;
  }
  else if(exp != 0)
  {
    exp -= (1 << 23);
    //return 2;
  }
  else if(((exp == 0) &&((frac >> 1) != 0)))
  {
    frac >>= 1;
    frac += 1;
    //return 3;
  }
  else if(exp == 0)
  {
    frac >>= 1;
    //return 4;
  }
  
  exp += frac;
  exp |= sgn;


  return exp;
  */
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  int exp = (uf >> 23) & 0xFF; /*8 exponent bits*/
  int frac = uf & 0x7FFFFF; /*23 fraction bits*/
  int e = exp - 127; /*amount to shift normalized values by (bias of 127)*/

  /*returns if NaN*/
  if(exp == 0x7F800000)
    return 0x80000000u;
  /*rounds down to zero if exponent is zero*/
  if(!exp)
    return 0;
  /*rounds down to zero if there are no left shifts*/
  if(e < 0)
    return 0;
  /*return if out of range for ints*/
  if(e > 30)
    return 0x80000000u;

  frac = frac | 0x800000; /*normalized, append a 1 to the left of the frac*/
  if (e >= 23)
    frac = frac << (e-23); /*shift left if shift > 23*/
  else
    frac = frac >> (23 -e); /*else we need to shift right*/

  if(( uf >> 31 ) & 1) 
    return ~frac + 1; /*return negated value if sign bit is 1*/

  return frac;
}
