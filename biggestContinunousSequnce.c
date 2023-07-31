// 给一个一维数组，找到和最大的连续子数组
// 例如1，3，-1，最大就是1，3

// 思路，从arr[0] 往后加，建立两层过滤，第一层是 sum >0 就继续往后
// 因为sum<0会拖累后面的，so,断开之前的，从arr[x]继续往后加直到结束
// 第二次过滤是 maxSum,在sum中找到最大的

#include <stdio.h>
#include <malloc.h>

int main()
{
    int size;
    scanf("%d", &size);
    // 得到数组length
    int *array = (int *)malloc(sizeof(int) * size);
    // 输入数组
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    // 按照思路

    int maxSum = array[0];
    int sum[1000];
    sum[0] = array[0];

    for (int i = 1; i < size; i++)
    {
        // 第一层过滤
        if (sum[i - 1] > 0)
        {
            sum[i] = sum[i - 1] + array[i];
        }
        else
        {
            sum[i] = array[i];
            // 切断前面的，从现在开始
        }
        // 第二层过滤
        maxSum = maxSum > sum[i] ? maxSum : sum[i];
    }

    printf("%d", maxSum);
}