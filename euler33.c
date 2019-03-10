/*************************************************************************
	> File Name: oula33.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 15时10分57秒
 ************************************************************************/
/*
*消去数字的分数

49/98是一个有趣的分数，因为缺乏经验的数学家可能在约简时错误地认为，等式49/98 = 4/8之所以成立，是因为在分数线上下同时抹除了9的缘故。

我们也会想到，存在诸如30/50 = 3/5这样的平凡解。

这类有趣的分数恰好有四个非平凡的例子，它们的分数值小于1，且分子和分母都是两位数。

将这四个分数的乘积写成最简分数，求此时分母的值。
* */

#include <stdio.h>
#include <stdbool.h>
#define MAX_N 5
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b); 
}
bool is_zuijian(int a, int b) {
    if (a > 100 || b > 100 || a < 10 || b < 10 || a > b) return false;
    int a1, a2, b1, b2;
    a1 = a / 10; 
    a2 = a % 10;
    b1 = b / 10;
    b2 = b % 10;
    if (!a1 || !a2 || !b1 || !b2) return false;
    if (a1 == b2 && a2 * b == b1 * a) return true;
    if (a2 == b1 && a1 * b == b2 * a) return true;
    return false;
}

int main() {
    int x = 1, y = 1, c;
    for (int i = 10; i < 100; i++) {
        for (int j = i + 1; j < 100; j++) {
            if (is_zuijian(i, j)) {
                //printf("%d  %d\n", i, j);
                x *= i; 
                y *= j;
            }
        }
    }
    c = gcd(x , y); 
    printf("%d\n", y / c);
    return 0;
}
