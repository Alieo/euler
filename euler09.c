/*************************************************************************
> File Name: euler09.c
> Author: 
> Mail: 
> Created Time: 2018年08月20日 星期一 19时25分32秒
************************************************************************/
/*
*特殊毕达哥拉斯三元组(求素勾股数)

毕达哥拉斯三元组是三个自然数a < b < c组成的集合，并满足
a^2 + b^2 = c^2

例如，3^2 + 4^2 = 9 + 16 = 25 = 5^2。

有且只有一个毕达哥拉斯三元组满足 a + b + c = 1000。求这个三元组的乘积abc。
* */
#include<stdio.h>
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    int a = 0, b = 0, c = 0;
    int ans = 0;
    for (int i = 1; ; i++) {
        for (int j = i + 1; ; j++) {
            if (gcd(i, j) != 1) continue;
            a = 2 * i * j;
            b = j * j - i * i;
            c = j * j + i * i;    
            int sum = a + b + c;
            if (1000 % sum == 0) { 
                //因为na nb nc也是勾股数，所以要乘上n
                a *= 1000 / sum;
                b *= 1000 / sum;
                c *= 1000 / sum;
                ans = a * b * c;
                printf("%d\n", ans);
                return 0;
            }
        }
    }
}

