/*************************************************************************
	> File Name: euler05.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月16日 星期四 10时23分35秒
 ************************************************************************/
/*
 * 最小倍数
  
  2520是最小的能够被1到10整除的数。

  最小的能够被1到20整除的正数是多少？
* */
#include <stdio.h>
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    int num = 1;
    for (int i = 2; i <= 20; i++) {
        if (num % i != 0) num = num * i / gcd(num, i);
    }
    printf("%d\n", num);
    return 0;
}
/*本题bug：没有考虑到最大公约数*/

