/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2018年06月01日 星期五 17时00分43秒
 ************************************************************************/
/*
*表达数字的英文字母计数

如果把1到5写成英文单词，分别是：one, two, three, four, five，这些单词一共用了3 + 3 + 5 + 4 + 4 = 19个字母。

如果把1到1000都写成英文单词，一共要用多少个字母？

【注意】 不要算上空格和连字符。例如，342（three hundred and forty-two）包含23个字母，而115（one hundred and fifteen）包含20个字母。单词“and”的使用方式遵循英式英语的规则。
* */
#include <stdio.h>
int num1[15] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};
int num2[15] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
int num3[15] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
int get_num(int a) {
    if (a < 10) {
        return num1[a];
    } else if (a < 20) {
        return num2[a % 10];
    } else if (a < 100 && a % 10 == 0) {
        return num3[a / 10];
    } else if (a == 100) {
        return 10;
    } else if (a < 100) {
        return num3[a / 10] + num1[a % 10];
    } else if (a == 1000) {
        return 11;
    } else {
        int num = get_num(a % 100);
        if (num == 0) {
            return num1[a / 100] + 7;
        } else {
            return num1[a / 100] + 10 + num;
        }
    }
}
int main() {
    int n;
    int n_sum = 0;
    for (int i = 1; i <= 1000; i++) {
        n_sum += get_num(i);
        printf("%d\n", i);
        fflush(stdout);
    }
    printf("%d", n_sum);
    return 0;
}

