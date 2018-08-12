/*************************************************************************
	> File Name: euler04.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月12日 星期日 22时33分25秒
 ************************************************************************/

#include <stdio.h>
int change(int x) {
    int temp = x, num = 0;
    while (x) {
        num = num * 10 + x % 10;
        x /= 10;
    }
    return temp == num;
}
int main() {
    int ans = 0;
    for (int i = 100; i < 1000; i++) {
        for (int j = 100; j < 1000; j++) {
            if (change(i * j) != 1) continue;
            if (i * j < ans) continue;//如果i * j 不是最大的就continue
            ans = i * j;
        }
    }
    printf("%d\n", ans);
    return 0;
}
/*本题采用了按位翻转置换的方法来对比回文数*/
