/*************************************************************************
	> File Name: euler07.c
	> Author: 
	> Mail: O(∩_∩)Ohaha！
	> Created Time: 2018年08月17日 星期五 21时34分08秒
 ************************************************************************/
/*
第10001个素数

列出前6个素数，它们分别是2、3、5、7、11和13。我们可以看出，第6个素数是13。
第10,001个素数是多少？

* */
#include <stdio.h>
#define max_n 200000
int prime[max_n + 5] = {0};
void init() {
    for (int i = 2; prime[0] <= 10001; i++) {
        if (prime[i]) continue;
        if (!prime[i]) prime[++prime[0]] = i;
        for (long long j = (long long)i * i; j <= max_n; j += i) {
            prime[j] = 1;
        }
    }
}
int main() {
    init();
    printf("%d\n", prime[10001]);
    return 0;
}
/*素数筛：
 *先把2的倍数全筛掉，然后把3的倍数筛掉，以此类推，但缺点是同一个合数可能会被选中多次，比如6，会被2和3各筛一次
 ***********************************************
 
 段错误：
 1.两数相乘超出int
 2.数组开的太小
 3.max_n不够大

************************************************

 关于两个long long：

 longlong1：因为当i是个5位数的时候，i * i就爆int了，所以j要用long long

 longlong2：这里涉及到了单目运算符和双目运算符的知识。
单目运算符：对一个参数进行操作的运算符，比如++，负号之类的
双目运算符：对两个参数进行操作的运算符，比如四则运算，取余等
单目运算的优先级大于双目运算。
（long long）i * i这个式子是将第一个i开到long long然后与后面的第二个i（int型）相乘，最终结果向上取，所以结果也是long long型。（long long）的优先级大于* 

*/
