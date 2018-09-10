/*************************************************************************
	> File Name: oula35.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 15时12分34秒
 ************************************************************************/
/*
*圆周素数（数字重排列）

197被称为圆周素数，因为将它逐位旋转所得到的数：197/971和719都是素数。

小于100的圆周素数有十三个：2、3、5、7、11、13、17、31、37、71、73、79和97。

小于一百万的圆周素数有多少个？
* */
#include <stdio.h>
#include <math.h>
#define MAX_N 1000000
int prime[MAX_N + 3] = {0};

int digit(int x) {
    return floor(log10(x)) + 1;
}

int fun(int n) {
    return n % (int)pow(10, digit(n) - 1) * 10 + n / (int)pow(10, digit(n) - 1);
}

void init_prime() {
    int is_prime[MAX_N] = {0};
    for (int i = 2; i <= MAX_N; i++) {
        if(!prime[i]) is_prime[++is_prime[0]] = i;
        for (int j = 1; j <= is_prime[0] && is_prime[j] * i <= MAX_N; j++) {
            prime[is_prime[j] * i] = 1;
            if (i % is_prime[j] == 0) break;
        } 
    }
}

int main() {
    int ans = 0;
    init_prime();
    for (int i = 2; i < MAX_N; i++) {
        int temp = i;
        for (int j = 1; j <= digit(i); j++) {
            if (!prime[temp]) temp = fun(temp);
            else break;
        
        }
        if (temp == i && !prime[temp]) ans++;
    }
    printf("%d\n", ans);
    return 0;
} 
/*
 * 
 *翻转结束方法：翻转他的位数次，看翻转得到的最后一个数是否等于他的原数。
 * */
