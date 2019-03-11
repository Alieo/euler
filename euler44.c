/*************************************************************************
	> File Name: oula44.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 15时53分56秒
 ************************************************************************/
/*
*五边形数

五边形数由公式Pn=n(3n−1)/2生成。前十个五边形数是：

1, 5, 12, 22, 35, 51, 70, 92, 117, 145, …
可以看出P4 + P7 = 22 + 70 = 92 = P8。然而，它们的差70 − 22 = 48并不是五边形数。

在所有和差均为五边形数的五边形数对Pj和Pk中，找出使D = |Pk − Pj|最小的一对；此时D的值是多少？
* */
#include <stdio.h>
#include <inttypes.h>
/*公式：Pn = n (3n - 1) / 2
 *d最小就意味着k和j的绝对值相对比较接近
 * */
 //二分查找这个数是不是5边形数
#define MAX_N 10000000
int64_t p[MAX_N] = {0};
 void init_p() {
     for (int i = 1; i <= MAX_N; i++) {
        p[++p[0]] = i * (3 * i - 1) / 2;
     }
     
 }
 int64_t is_p(int64_t x) {
     int64_t left = p[1], right = p[MAX_N], mid;
     while (left <= right) {
         mid = (left + right) >> 1;
         if (p[mid] == x) return 1;
         if (p[mid] > x) right = mid - 1;
         else left = mid + 1;
     }
    return 0;
 }
 int main() {
    init_p();
     int64_t ans = INT64_MAX;
     for (int64_t i = 1; i < p[0]; i++) {
         for (int64_t j = i + 1; p[i] - p[j] < ans; j++) {
             if (is_p(p[i] + p[j])) {
                 if (is_p(p[j] - p[i])) {
                     if (p[j] - p[i] < ans) {
                         ans = p[j] - p[i];
                     }
                 }
             }
         }
     }
     printf("%"PRId64"\n", ans);
    return 0;
 }
