#include <stdio.h>
#include <string.h>

// AB5 点击消除

int main()
{
    char str[300000];
    scanf("%s", str);
    // printf("%s",str);

    int len = strlen(str);
    // printf("%d",len);
    char k[len];
    // c里面不能这样申请哦！
    // 正确写法
    // char *k = (char*)malloc(sizeof(char)*len);
    int p = 0; // 指针

    // 先录进入一个
    k[0] = str[0];

    for (int i = 1; i < len; i++)
    {
        if (str[i] == k[p])
        {
            p--;
        }
        else
        {
            k[++p] = str[i];
        }
    }

    if (p == -1)
    {
        printf("0");
    }
    for (int i = 0; i < p + 1; i++)
    {
        printf("%c", k[i]);
    }

    return 0;
}