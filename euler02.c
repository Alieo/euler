/*************************************************************************
> File Name: oula02.c
> Author: 
> Mail: 
> Created Time: 2018年08月11日 星期六 21时33分44秒
************************************************************************/
/*

* 题目：偶斐波那契数
斐波那契数列中的每一项都是前两项的和。由1和2开始生成的斐波那契数列前10项为：

 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, …

考虑该斐波那契数列中不超过四百万的项，求其中为偶数的项之和。

*/
#include <stdio.h>
#define max_n 4000000
int fib[max_n + 4] = {0};
int main() {
    fib[0] = 1;
    fib[1] = 1;
    int sum = 0;
    for (int j = 2; ; j++) {
        fib[j] = fib[j - 1] + fib[j - 2];
        if (fib[j] > max_n) break;
        if (fib[j] & 1) continue;
        sum += fib[j];
    }
    printf("%d\n", sum);
    return 0;
}
/*本题bug：理解错题意。不是求fib[400万]，而是求小于400万的fib[j].循环的条件不是j < max_n，而是fib[j] < max_n*/
/*
*fib公式：fib[i] = fib[i - 1] + fib[i - 2]
fib序列可以往后推导，也可以往前推导
fib序列：
        1 1 2 3 5 8
 -1 1 0 1 1 2 3
因为fib序列中的第一个偶数是2，所以可以从2开始往后找。

* */
