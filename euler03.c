/*************************************************************************
	> File Name: euler03.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月12日 星期日 21时40分32秒
 ************************************************************************/
/*
 * 最大质因数
 
 13195的所有质因数为5、7、13和29。

 600851475143最大的质因数是多少？
*/
#include <stdio.h>
#include <inttypes.h>
#define max_n 600851475143
int main() {
    int prime = 0;
    int64_t ans = 0;
    int64_t max = max_n;
    for (int i = 2; i * i <= max; i++) {
        if (max % i == 0) prime = i;
        while (max % i == 0) {
            max /= i;

        }
    }
    if (max != 1) ans = max;
    printf("%"PRId64"\n", ans);
    return 0;
}
/*
 * 本题bug：while结束后prime只能取到第二大的质因数，取不到最大的，因为在最大的质因数是max本身
*/
/*本题判断素数运用了素数筛的思想，将素数的倍数一一除尽*/
