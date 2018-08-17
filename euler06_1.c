/*************************************************************************
	> File Name: euler06_1.c
	> Author:
	> Mail: O(∩_∩)Ohaha！.@163.com
	> Created Time: 2018年08月17日 星期五 21时22分34秒
 ************************************************************************/
/*公式：(2 * m^3 + 3 * (1 + m) * m - 2 * m) / 6 */
/*
 * 平方的和与和的平方之差
* 前十个自然数的平方的和是
*
* 12 + 22 + … + 102 = 385
* 前十个自然数的和的平方是
*
* (1 + 2 + … + 10)2 = 552 = 3025
* 因此前十个自然数的平方的和与和的平方之差是 3025 − 385 = 2640。
*
* 求前一百个自然数的平方的和与和的平方之差。
*
* */
#include <stdio.h>
int main() {
    int sum1 = 5050, sum2 = (2 * 100 * 100 * 100 + 3 * (1 + 100) * 100 - 2 * 100) / 6;
    printf("%d\n", sum1 * sum1 - sum2);
    return 0;
}

