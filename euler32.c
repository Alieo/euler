/*************************************************************************
	> File Name: oula32.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 14时22分51秒
 ************************************************************************/
/*
 *全数字的乘积
 如果一个n位数包含了1至n的所有数字恰好一次，我们称它为全数字的；例如，五位数15234就是1至5全数字的。

 7254是一个特殊的乘积，因为在等式39 × 186 = 7254中，被乘数、乘数和乘积恰好是1至9全数字的。
 找出所有被乘数、乘数和乘积恰好是1至9全数字的乘法等式，并求出这些等式中乘积的和。

 注意：有些乘积可能从多个乘法等式中得到，但在求和的时候只计算一次。
 *
* */
#include <stdio.h>
#include <math.h>
#define MAX_N 10000
int digit(int x) {
    return floor(log10(x)) + 1;
}

int get_degit(int a, int arr[]) {
    while (a) {
        if (a % 10 == 0) return 0;
        if (arr[a % 10]) return 0;
        arr[a % 10] = 1;
        a /= 10;
    } 

    return 1;
}
int is_valid(int a, int b, int c) {
    int num[10] = {0};
    if (!get_degit(a, num)) return 0;
    if (!get_degit(b, num)) return 0; 
    if (!get_degit(c, num)) return 0;
    return 1;
}
int valid[MAX_N] = {0};
int main() {
    int ans = 0;
    for (int a = 2; digit(a) + digit(a) + digit(a * a) <= 9; a++) {
        for (int b = a + 1; digit(a) + digit(b) + digit(a * b) <= 9; b++) {
            if (digit(a) + digit(b) + digit(a * b) < 9) continue;
            if (is_valid(a, b, a * b)) {
                ans += a * b * (1 - valid[a * b]);
                valid[a * b] = 1;
                printf("%d * %d = %d\n", a, b, a * b);
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
/*求一个正整数n在m进制下的数字位数
*   g(n) = logmn + 1  m为底*/
