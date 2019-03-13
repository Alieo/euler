/*************************************************************************
	> File Name: 46.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月17日 星期日 11时15分20秒
 ************************************************************************/
/*
*哥德巴赫的另一个猜想

克里斯蒂安·哥德巴赫曾经猜想，每个奇合数可以写成一个素数和一个平方的两倍之和。

9 = 7 + 2×12
15 = 7 + 2×22
21 = 3 + 2×32
25 = 7 + 2×32
27 = 19 + 2×22
33 = 31 + 2×12

最终这个猜想被推翻了。

最小的不能写成一个素数和一个平方的两倍之和的奇合数是多少？
* */ 
#include<stdio.h>
#include<math.h>
#define MAX 10000

int ans[MAX + 10] = {0};
int prime[MAX + 10] = {0};

void is_prime() {
    for (int i = 2; i < MAX; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            ans[i] = 1;
            for (int j = 1; j <= 100; j++) {
                if (i + 2 * j * j > MAX) break;
                ans[i + 2 * j * j] =1;
            }
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > MAX) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    is_prime();
    for (int i = 3; i < MAX; i++) {
        if (i % 2 && ans[i] == 0) {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}
