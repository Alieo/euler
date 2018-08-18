/*************************************************************************
	> File Name: euler07_1.c
	> Author: 
	> Mail: O(∩_∩)Ohaha！
	> Created Time: 2018年08月18日 星期六 23时02分44秒
 ************************************************************************/
/*
 * 线性筛：
    基于合数都可以被拆解为几个质因数相乘思想去实现，可以保证每个合数只会被其最小的素数筛掉，所有的合数只会被筛一遍，不会有重复筛选的情况出现，时间复杂度是线性的
* */
#include <stdio.h>
#define max_n 200000
int prime[max_n] = {0};
void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= max_n; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
int main() {
    init();
    printf("%d\n", prime[10001]);
    return 0;
}

