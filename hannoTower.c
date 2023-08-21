
#include <stdio.h>

int hannoTower(int a)
{
    if (a == 1)
    {
        return 1;
    }

    return 2 * hannoTower(a - 1) + 1;
}

void main()
{
    int n;
    scanf("%d", &n);
    int k = hannoTower(n);
    printf("%d", k);
}
