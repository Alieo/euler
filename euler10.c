/*************************************************************************
> File Name: euler10.c
> Author: 
> Mail: 
> Created Time: 2018年08月19日 星期日 23时57分51秒
************************************************************************/

/*素数的总和
* * 问题10 
* * 低于10的素数之和为2 + 3 + 5 + 7 = 17。
* * 找出200万以下所有素数的总和。*/
#include <stdio.h>
#include <inttypes.h>
#define MAX_N 2000000
int main() {
    int64_t sum = 0;
    int prime[MAX_N + 5] = {0};
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j] * i <= MAX_N; j++) {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;

        }    

    }
    for (int i = 1; i <= prime[0]; i++) {
        sum += prime[i];

    }
    printf("%"PRId64"\n", sum);
    return 0;

}
/*本题用了线性筛求素数*/
