/*************************************************************************
	> File Name: euler19.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月23日 星期四 21时53分45秒
 ************************************************************************/
/*
*求1901年到2000年一共有多少个星期日落在每月的一号
* */
#include<stdio.h>
int week(int y, int m, int d) { //把一月和二月当成去年的13,14月来算
    if (m == 1 || m == 2) {
        --y;
        m += 12;
    }
    int w;
    w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    return w + 1;
}
int main() {
    int sunday = 0;
    for (int y = 1901; y < 2001; y++) {
        for (int m = 1; m < 13; m++) {
            if (week(y, m, 1) == 7) sunday++;
        }
    }
    printf("%d\n", sunday);
    return 0;
}
//蔡勒公式
//平年闰年判断方法：y % 4 ==0 && y % 100 == 0 || y % 400 == 0
