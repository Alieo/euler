/*************************************************************************
	> File Name: oula36.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 14时10分05秒
 ************************************************************************/
/*
*双进制回文数

十进制数585 = 10010010012（二进制表示），因此它在这两种进制下都是回文数。

找出所有小于一百万，且在十进制和二进制下均回文的数，并求它们的和。

（请注意，无论在哪种进制下，回文数均不考虑前导零。）
* */
#include <stdio.h>
//判断回文数
int palindromic(int x, int n) {
        int temp = x, num = 0;
        while (x) {
            num = num * n + x % n;
            x /= n;
        }
        return temp == num;
    }

int main() {
    int ans = 0;
    for (int i = 1; i <= 1000000; i++) {
        if (!palindromic(i, 2)) continue;
        if (!palindromic(i, 10)) continue;
        ans += i;
    }
    printf("%d\n", ans);
    return 0;
}
