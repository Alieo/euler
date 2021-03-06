/*************************************************************************
	> File Name: oula30.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月22日 星期日 10时53分44秒
 ************************************************************************/
/*
*令人惊讶的是，只有三个数字可以写成数字的四次幂的总和：

1634 = 1^4 + 6^4 + 3^4 + 4^4
8208 = 8^4 + 2^4 + 0^4 + 8^4
9474 = 9^4 + 4^4 + 7^4 + 4^4
由于1 = 1^4不是总和，因此不包括在内。

这些数字的总和是1634 + 8208 + 9474 = 19316。

找到所有可写入的数字的总和，作为其数字的五次幂的总和。
* */
#include <stdio.h>
#include <math.h>
#define MAX_N 354294

int is_equal(int x) {
        int temp = x, sum = 0;
        while (x) {
            sum += (int)pow(x % 10, 5);//
            x /= 10;
        }
        return sum == temp;
    }

int main () {
    int ans = 0;
    for (int i = 2; i < MAX_N; i++) {
        if (!is_equal(i)) continue;
        ans += i;
    }
    printf("%d\n", ans);
    return 0;
}
/*
 * 关于上界估算的问题
 7个9
 fn = 10^n
 gn = 9^5 * n
 为什么7个9^5的和应该是一个七位数？
 因为7 * 9^5是一个六位数，小于 10^7，所以他俩的交点应该在6点多的位置，在这个位置之后再也找不出第二个相交的点 
354294 = 6 * 9^5;
*/
