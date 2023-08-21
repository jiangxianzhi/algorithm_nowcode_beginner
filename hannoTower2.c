/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param n int整型
 * @return string字符串一维数组
 * @return int* returnSize 返回数组行数
 */

// 卡在拼接问题上
#include<string.h>
#include<stdio.h>
#include <malloc.h>

int Steps(int n ) {
    if (n == 1) {
        return 1;
    } else {
        return Steps(n - 1) * 2 + 1;
    }
}

void showHanoStep(int n, char* a, char* b, char* c, char** array, int count) {
    if (n == 1) {
        char *mo = "move from ";
        strcat(array[count], mo);
        strcat(array[count],a);
        char *to = " to ";
        strcat(array[count], to);
        strcat(array[count++], c);

        printf("%s",array[count]);
        
    } else {
        showHanoStep(n - 1, a, c, b,array,count);
         char mo[10] = "move from ";
        strcat(array[count], mo);
        strcat(array[count], a);
         char *to = " to ";
        strcat(array[count], to);
        strcat(array[count++], c);
        printf("%s",array[count]);
        showHanoStep(n - 1, b, a, c,array,count);
    }

}
char** getSolution(int n, int* returnSize ) {
    // write code here
    int k = Steps(n);
    char** array = (char**)malloc(sizeof(char*)*k);
    for (int i = 0; i < k; i++) {
        array[i] =  (char*)malloc(sizeof(char) * 30);

    }
    showHanoStep(n, "left", "mid", "right",array, 0);
return array;


}