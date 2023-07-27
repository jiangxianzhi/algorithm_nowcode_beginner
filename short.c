
#include <stdio.h>
#include <malloc.h>

void main()
{

    // printf("%d%d", n, m);
    // 动态申请 arr[n][n]
    // int* arr = (int*)malloc(sizeof(int) * n);

    // 静态申请
    int arr[100][100];
    // 写arr [5001][5001]为什么不行？minGW内存满了?
    
    // 全赋值5001，表示不可达。1,表示可达
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            arr[i][j] = 5001;
        }
    }
    int n;
    int m;
    scanf("%d", &n); // 顶点数量
    scanf("%d", &m); // 边数量

    // printf("%d%d",n,m);

    // 输入路径
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);
        arr[a][b] = 1;
    }
    // 打印
    //     for (int i = 0; i < n + 1; i++)
    //     {
    //         for (int j = 0; j < n + 1; j++)
    //         {
    //             printf("%d\t", arr[i][j]);
    //         }
    //         printf("\n");
    //     }
    // 每个点到1的最短距离
    int *distance = (int *)malloc(sizeof(int) * (n + 1));
    //    初始化
    for (int i = 0; i < n + 1; i++)
    {
        distance[i] = 5001;
        // 最大只是4999,5001已经达到不可达
    }
    distance[1] = 0;
    // 自身到自身为0;

    // 创建状态,节点被扫描过就标记
    int *state = (int *)malloc(sizeof(int) * (n + 1));
    //  初始化
    for (int i = 0; i < n + 1; i++)
    {
        state[i] = 0;
    }
    state[0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        int min = 5001; // 为找到最小的距离
        int tmp = 1;    // 把最小距离的数带出来
        // 遍历distance
        for (int j = 1; j < n + 1; j++)
        {
            if (min > distance[j] && state[j] == 0)
            {
                min = distance[j];
                tmp = j;
            }
        }
        // 用它作为寻最短路节点
        state[tmp] = 1;
        // 更新距离表
        // 更新 1~2，2~1的可能性，通过了12/20个例子
 for (int j = 1; j < n + 1; j++) {
            if (distance[j] > distance[tmp] + arr[tmp][j]||distance[j] > distance[tmp] + arr[j][tmp]) {
                distance[j] = distance[tmp] + arr[tmp][j]<distance[tmp] + arr[j][tmp]?distance[tmp] + arr[tmp][j]:distance[tmp] + arr[j][tmp];
            }
        }
    }

    if(distance[n]<5001){
        printf("%d",distance[n]);
    }
}
