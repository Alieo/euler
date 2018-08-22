/*************************************************************************
> File Name: euler12.c
> Author: 
> Mail: 
> Created Time: 2018年08月22日 星期三 22时19分48秒
************************************************************************/
/*
*高度可约的三角形数

三角形数数列是通过逐个加上自然数来生成的。例如，第7个三角形数是 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28。

三角形数数列的前十项分别是：

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, …
让我们列举出前七个三角形数的所有约数：

   1: 1
   3: 1,3
   6: 1,2,3,6
   10: 1,2,5,10
   15: 1,3,5,15
   21: 1,3,7,21
   28: 1,2,4,7,14,28
   我们可以看出，28是第一个拥有超过5个约数的三角形数。

问：第一个拥有超过500个约数的三角形数是多少？
* */
#include<stdio.h>
#define max_n 1000000
int prime[max_n] = {0};
int dnum[max_n] = {0};
int mnum[max_n] = {0};
void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 2;
            mnum[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mnum[i * prime[j]] = mnum[i] + 1;
                dnum[i * prime[j]] = dnum[i] * (mnum[i] + 2) / (mnum[i] + 1);
            } else {
                mnum[i * prime[j]] = 1;
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
            }
        }
    } 
}
int find_san(int n) {
    if (n & 1) {
        return dnum[n] * dnum[(n + 1) / 2];
    }
    return dnum[n / 2] * dnum[n + 1];
}
int main() {
    init();
    for (int i = 1; i <= max_n; i++) {
        if (find_san(i) > 499) {
            printf("%d\n", i * (i + 1) / 2);
            break;

        }
    }
    return 0;
}
/*
 求一个数n的因数个数（包括n本身和1） 基于线性筛框架
    分解质因数后：n = pow(p1, x) * pow(p2, y);
                  p1, p2都是质数；      x, y是质数的幂；
    方法：    n的因子个数 = (x + 1) * (y + 1);
              例如：72 = pow(2, 3) * pow(3, 2);
              72的因子个数 = (3 + 1) * (2 + 1) = 12个
    条件：f(c) = f(a) * f(b)   c = a * b，且a与b互素(最大公约数 = 1)
          C 的因子个数 = A 的因子个数 * B 的因数个数；
 * */
