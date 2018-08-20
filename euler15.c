/*************************************************************************
> File Name: euler15.c
> Author: 
> Mail: 
> Created Time: 2018年08月19日 星期日 23时42分44秒
************************************************************************/
/*
*Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?
从一个2×2方阵的左上角出发，只允许向右或向下移动，则恰好有6条通往右下角的路径。

对于20×20方阵来说，这样的路径有多少条？

* */
#include <stdio.h>
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);

}
int jc(int n) {
    if (n == 1) return 1;
    return n * jc(n - 1);

}
int main() {
    long long int sum = 0;
    long long int x = 1, y = 1;
    for (int i = 39; i >= 21; i -= 2) {
        x *= (2 * i);    

    }
    sum = (x / gcd(x, y)) / (jc(10) / gcd(x, y));
    printf("%lld\n", sum);
    return 0;

}
/*转换思维
 *本题主要求解C40 20
 * */
