/*************************************************************************
> File Name: euler16.c
> Author: 
> Mail: 
> Created Time: 2018年08月30日 星期四 19时34分03秒
************************************************************************/
/*大数乘法*/
#include<stdio.h>
int num[500] = {1, 1};
int main() {
    for (int i = 0; i < 50; i++) {
        for (int j = 1; j <= num[0]; j++) {
            num[j] *= 1024 * 1024;
        }
        for (int j = 1; j <= num[0]; j++) {
            if (num[j] < 10) continue;
            num[j + 1] += num[j] / 10;
            num[j] %= 10;
            num[0] += (j == num[0]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= num[0]; i++) {
        ans += num[i];
    }
    printf("%d\n", ans);
    return 0;
}
