#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
int numberOfResult(int length)
{
    if (length == 1)
        return 1;
    return length * numberOfResult(length - 1);
}

void addListArray(int *num, int *list, int **result, int currentLength, int length, int *boolArray, int *count)
{
    if (currentLength == length)
    {
      int *temp = (int *)malloc(sizeof(int) * length);
        memcpy(&temp[0], &list[0], sizeof(int) * length);
        result[count[0]] = temp; // 指针指向拷贝的数组
        count[0] += 1;
        return;
    }
    for (int i = 0; i < length; i++)
    {
        if (boolArray[i] == 1)
        {
            continue;
        }
        list[currentLength] = num[i];
        boolArray[i] = 1;
        addListArray(num, list, result, currentLength + 1, length, boolArray, count);
        boolArray[i] = 0;
        list[currentLength] = 0;
    }
}

int **permute(int *num, int length)
{

    int *list = (int *)malloc(sizeof(int) * length);
    int numberOfpossibleResult = numberOfResult(length);
    // printf("%d",numberOfpossibleResult);
    int **result = (int **)malloc(sizeof(int *) * numberOfpossibleResult);
    int *boolArray = (int *)malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++)
    {
        boolArray[i] = 0;
        // printf("%d ", boolArray[i]);
    }
    int count[1] = {0};

    addListArray(num, list, result, 0, length, boolArray, count);
    return result;
}

void main()
{
    int nums[] = {1, 2, 3,4,5,6,7,8};
    int length = sizeof(nums) / sizeof(int);
    // printf("%d", length);
    int **result1 = permute(nums, length);

    for (int i = 0; i < numberOfResult(length); i++)
    {
        for (int j = 0; j < length; j++)
        {
            printf("%d ", result1[i][j]);
        }
        printf("\n");
    }
}