#include <stdio.h>
#include<malloc.h>
// 先排序，然后两个指针从中间往两边移动，直到指针所指的只差比k大

int main() {
    int n;
    int k;
    scanf("%d", &n);
    scanf("%d", &k);

    int* array = (int*)malloc(sizeof(int ) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

// for(int i = 0;i<n;i++){
//     printf("%d",array[i]);
// }

// 排序
    for (int i = n; i > 0; i--) {
        for (int j = 0; j + 1 < i; j++) {
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }

// for(int i = 0;i<n;i++){
//     printf("%d",array[i]);
// }
    int maxNum = 0;
// 两指针从中间开始
    if (n % 2) {
        // 单数
        maxNum = 1;
        int point = (n - 1) / 2 - 1 + 1 - 1;
        int point2 = (n - 1) / 2 - 1 + 1 + 1;
        for (; point >= 0 && point2 <= n - 1;) {

            if (k >= array[point2] - array[point]) {
                maxNum = maxNum + 2;

            } else {
                int g = point2 - 1;
                int y = point + 1;
                if (k >= array[g] - array[point] || k >= array[point2] - array[y]) {
                    maxNum = maxNum + 1;

                }
                break;
            }
            point--;
            point2++;


        }


    } else {
        // 双数
        int point = n / 2 - 1;
        int point2 = n / 2;
        for (; point > 0 && point2 < n - 1;) {
            if (k >= array[point2] - array[point]) {
                maxNum = maxNum + 2;

            } else {
                int g = point2 - 1;
                int y = point + 1;
                if (k >= array[g] - array[point] || k >= array[point2] - array[y]) {
                    maxNum = maxNum + 1;

                }
                break;
            }
            point--;
            point2++;


        }
    }

    printf("%d", maxNum);


    return 0;
}