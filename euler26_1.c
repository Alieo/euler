/*************************************************************************
	> File Name: 26.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月06日 星期日 09时08分46秒
 ************************************************************************/

#include<stdio.h>

int get_next (int n, int d) {
    return (n * 10) % d;
}

int get_circle_length(int d) {
    int ar = 1, br = 1;
    do {
        ar = get_next(ar, d);
        br = get_next(br, d);
        br = get_next(br, d);
    } while (br != 0 && ar != br);
    if (br == 0) return 0;
    int len = 0;
    do {
        br = get_next(br, d);
        len++;
    } while (ar != br);
    return len;
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
