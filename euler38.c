/*************************************************************************
	> File Name: euler38.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月11日 星期五 15时08分54秒
 ************************************************************************/
/*
*全数字的倍数

将192分别与1、2、3相乘：

192 × 1 = 192
192 × 2 = 384
192 × 3 = 576

连接这些乘积，我们得到一个1至9全数字的数192384576。我们称192384576为192和(1,2,3)的连接乘积。

同样地，将9分别与1、2、3、4、5相乘，得到1至9全数字的数918273645，即是9和(1,2,3,4,5)的连接乘积。

对于n > 1，所有某个整数和(1,2, … ,n)的连接乘积所构成的数中，最大的1至9全数字的数是多少？


* */
#include<stdio.h>
#include<math.h>
int judge(int num) {
    int flag[10] = {0}, sum = 0;
    for (int i = 1; i < 10 && flag[0] < 9; i++) {
        int temp = num * i;
        int bit = (int)log10(temp) + 1;
        while (temp) {
            if (flag[temp % 10]++ || temp % 10 == 0) {
                i = 10;
                break;
            }
            temp /= 10;
            ++flag[0];
        }
        sum = (sum * pow(10, bit) + num * i) * (i < 10);
    }
    if (flag[0] == 9) {
        return sum;
    }
    return 0;
}
int main() {
    int max = 0;
    for (int i = 1; i < 10000; i++) {
        int temp = judge(i);
        max = temp > max ? temp : max;
    }        
    printf("%d", max);
    return 0;
}
