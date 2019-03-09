/*************************************************************************
> File Name: oula08.c
> Author: 
> Mail: 
> Created Time: 2018年07月24日 星期二 11时24分26秒
************************************************************************/
/*滑动窗口法：逆运算*/
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
int main() {


    char temp[1007] = {0}, num[1007] = {0};
    while(~scanf("%s", temp)) {
        strcat(num, temp);
    }

    int64_t p = 1, zero = 0, ans = 0;
    for (int i = 0; num[i]; i++) {
        if (num[i] == '0') {
            zero += 1;
        } else {
            p *= (num[i] - '0');
        }
        if (i >= 13) {
            if (num[i - 13] == '0') {
                zero -= 1;
            } else {
                p /= (num[i - 13] - '0');
            }
        }
        if (zero == 0 && p > ans) ans = p;
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
