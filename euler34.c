/*************************************************************************
> File Name: oula34.c
> Author: 
> Mail: 
> Created Time: 2018年07月23日 星期一 09时59分23秒
************************************************************************/
/*
*145是一个奇怪的数字，为1！+ 4！+ 5！= 1 + 24 + 120 = 145。

 求所有数字的总和等于其数字的阶乘之和。

 注意：为1！= 1和2！= 2不是它们不包括在内的总和。
 * */
 #include <stdio.h>
 #define MAX_N 2177280
 int factorial(int y) {
     if (y == 0) {
         return 1;
     }
     return factorial(y - 1) * y;
 }

int is_factorial(int x) {
    int temp = x, sum = 0;
    while (x) {
        sum += factorial(x % 10);
        x /= 10;
    }
    return sum == temp;
}

int main() {
    int ans = 0; 
    for (int i = 3; i < MAX_N; i++) {
        if (!is_factorial(i)) continue;
        ans += i;
        printf("%d\n", ans);
    }
    return 0;
}
