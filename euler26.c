/*************************************************************************
	> File Name: 26.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月06日 星期日 09时08分46秒
 ************************************************************************/

/*
*倒数的循环节

单位分数指分子为1的分数。分母为2至10的单位分数的十进制表示如下所示：

1/2= 0.5
1/3= 0.(3)
1/4= 0.25
1/5= 0.2
1/6= 0.1(6)
1/7= 0.(142857)
1/8= 0.125
1/9= 0.(1)
1/10= 0.1

这里0.1(6)表示0.166666…，括号内表示有一位循环节。可以看出，1/7有六位循环节。

找出正整数d < 1000，其倒数的十进制表示小数部分有最长的循环节。


* */

#include<stdio.h>

int get_circle_length(int d) {
    int first_ind[1010] = {0};
    int y = 1, ind = 1;
    while (y && first_ind[y] == 0) {
        first_ind[y] = (ind++);
        y = (y * 10) % d;
    }
    if (!y) return 0;
    return ind - first_ind[y];
}

int main() {
    int max_length = 0, ans;
    for (int i = 2; i < 1000; i++) {
        int temp = get_circle_length(i);
        if (temp > max_length) {
            ans = i;
            max_length = temp;
        }
    }
    printf("%d", ans);
    return 0;
}
