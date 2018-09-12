/*************************************************************************
	> File Name: oula20.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月30日 星期一 10时28分13秒
 ************************************************************************/
/*
*阶乘数字和(大整数乘法: 求阶乘)

n! 的意思是 n × (n − 1) × … × 3 × 2 × 1

例如，10! = 10 × 9 × … × 3 × 2 × 1 = 3628800，所以10!的各位数字和是 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27。

*求出100!的各位数字和。
* */
#include <stdio.h>
#include <inttypes.h>
#define MAX_N 250

int64_t num[MAX_N] = {1, 1};
int main() {
    int sum = 0;
    for (int i = 2; i <= 100; i++) {
        for (int j = 1; j <= num[0]; j++) {
            num[j] *= i;
        }
        for (int j = 1; j <= num[0]; j++) {
            if (num[j] < 10) continue;
            num[j + 1] += num[j] / 10;
            num[j] %= 10;
            num[0] += (j == num[0]);
        }
    }
    for (int i = 1; i <= num[0]; i++) {
        sum += num[i];
    }
    printf("%d\n", sum);
    return 0;
}
