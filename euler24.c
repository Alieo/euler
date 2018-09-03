/*************************************************************************
	> File Name: oula24.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 16时09分20秒
 ************************************************************************/
/*全排列*/
#include <stdio.h>
#define MAX_N 10

int jnum[MAX_N] = {0};//存的是1！到9！
int dnum[MAX_N] = {0};//标记数组，标记0~9有没有用过

void init() {//将dum[10]全变为 1 。将1到9阶乘存进jnum里
    jnum[0] = dnum[0] = 1;//dnum[0] = 1表示这个数没有用过，可以使用
    for (int i = 1; i < MAX_N; i++) {
        dnum[i] = 1;
        jnum[i] = i * jnum[i - 1];
    }
}

int judge_num(int n, int k) {//n：表示当前数字后面的数字个数
                             //k：表示当前数想往后跳k个状态
    int ind = (k / jnum(n)) + 1, i = -1;//ind
    while (ind > 0) {
        i++;
        ind -= dum[i];
    }
    dnum[i] = 0;//
    return i;
}

int main() {
    init();
    int n, k;
    scanf("%d%d", &n, &k);
    k -= 1;
    for (int i = n - 1; i >= 0; i--) {
        int num = judge_num(i, k);
        printf("%d", num);
        k %= jnum[i];
    }
    printf("\n");
    return 0;
}
