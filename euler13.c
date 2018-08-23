/*************************************************************************
	> File Name: euler13.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月23日 星期四 20时59分59秒
 ************************************************************************/
/* 
*计算出以下一百个50位数字之和的前十位数。(大整数加法)
* */
#include<stdio.h>
#include<string.h>
char num[55] = {0};
int ans[55] = {1, 0};//从第1位开始用来存放大整数，第0位 = 1 世记录num的长度
int main() {
    for (int i = 0; i < 100; i++) {
        scanf("%s", num);
        int len = strlen(num);
        if (ans[0] < len) ans[0] = len;
        for (int j = 0; j < len; j++) {
            ans[len - j] += (num[j] - '0');
        }
        //处理进位
        for (int j = 1; j <= ans[0]; j++) {
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (j == ans[0]);
        }
    }
    for (int i = ans[0]; i > ans[0] - 10; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
/*
 * 1.将char型数字转化为int型数字的方法：
 *      char - '0' = int
 * 2.大整数最主要的是处理进位：将高位放在数组右边，低位放左边（倒着放）
 *   输出的时候从ans[0]的位置开始输出，这样的大数才是正的
 * 3.大整数加法的执行机制是：模拟小学生列竖式做加法，从个位开始逐位相加，超过或达到10则进位。
 * */
