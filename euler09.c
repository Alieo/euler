/*************************************************************************
	> File Name: euler09.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月20日 星期一 19时25分32秒
 ************************************************************************/

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
            if (a * a + b * b == c * c && gcd(a, b) == 1) {
                int sum = a + b + c;
                if (1000 % sum == 0) {
                    a *= gcd(1000, sum);
                    b *= gcd(1000, sum);
                    c *= gcd(1000, sum);
                    if (a + b + c == 1000) {
                        ans = a * b * c;
                        printf("%d\n", ans);
                        return 0;
                    }
                }
            }
            return 0;
        }
    }
}
