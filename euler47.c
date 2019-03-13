
/*
*不同的质因数

首次出现连续两个数均有两个不同的质因数是在：

14 = 2 × 7
15 = 3 × 5
首次出现连续三个数均有三个不同的质因数是在：

644 = 22 × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19
首次出现连续四个数均有四个不同的质因数时，其中的第一个数是多少？
* */
#include <stdio.h>
#define MAX_N 1000000
int prime[MAX_N] = {0};
int dnum[MAX_N] = {0};
void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            dnum[i * prime[j]] = dnum[i] + (i % prime[j] != 0);
            if (i % prime[j] == 0) break;
        }
    }
}
int main() {
    init();
    for (int i = 647; ; i++) {
        if (dnum[i] == 4 && dnum[i + 1] == 4 && dnum[i + 2] == 4 &&dnum[i + 3] == 4) {
            printf("%d\n", i);
            break;
        }  
    }
    
    return 0;
}
