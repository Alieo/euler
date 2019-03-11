/*************************************************************************
	> File Name: oula37.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 15时13分02秒
 ************************************************************************/
/*
3797有着奇特的性质。不仅它本身是一个素数，而且如果从左往右逐一截去数字，剩下的仍然都是素数：3797、797、97和7；同样地，如果从右往左逐一截去数字，剩下的也依然都是素数：3797、379、37和3。

只有11个素数，无论从左往右还是从右往左逐一截去数字，剩下的仍然都是素数，求这些数的和。

注意：2、3、5和7不被视为可截素数。
*/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define NUM 1000000

int prime[NUM] = {0};
void prime_() {
    int num[NUM] = {0};
    for (int i = 2; i <= NUM; i++) {
        if (!prime[i]) num[++num[0]] = i;
        for (int j = 1; j <= num[0] && num[j] * i <= NUM; j++) {
            num[i * num[j]] = 1;
            prime[i * num[j]] = 1;
            if (i % num[j] == 0) {
                break;
            }
        }
    }
}

int prime_num(int n) {
    int length = floor(log10(n)) + 1;
    //cout << length << endl;
    int count = 0;
    if (prime[n]) return 0;
    count++;
    //cout << "n " << n << endl;
    for (int i = 1; i < length; i++) {
        int num1 = n / (int)pow(10, i);
        //cout << "num1 : " << num1 << " ";
        int num2 = n % (int)pow(10, i);
        //cout << " num2 " << num2 << " ";
        if (prime[num1] || prime[num2]) break;
        count++;
        //cout << "i : " << i << endl;
    }
    return count == length;
}

int main() {
    prime_();
    prime[1] = 1;
    int ans = 0;
    int count = 0;
    for (int i = 10; i <= NUM; i++) {
        if (prime_num(i)) {
            ans += i;
            count++;
        }
        if (count == 11) {
            break;
        }
    }
    //cout << prime_num(3797) << endl;
    cout << ans << endl;
    return 0;
}
