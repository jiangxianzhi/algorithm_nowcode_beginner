#include <stdio.h>
#include <malloc.h>


int KillNextGetWhoIsLast(int * array, int length){
for(int i = 0;i<=length;i++){
    if(i == length){
      i = 0;
    }
    // 他的下一个就是0
    if(array[i]!=0){


        for(int k = i+1;k<=length;k++){
            if(k == length){
                k = 0;
            }
            if(k == i){
                return k+1;
            }
            if(array[k]!= 0 ){
                   array[k] = 0;
                   break;
            }
        }
    }
    // printf("%d ",array[i]);
}


}

void main()
{
    int n;
    scanf("%d", &n);
    int *array = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        array[i] = i + 1;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", array[i]);
    // }

    printf("%d" ,KillNextGetWhoIsLast(array,n));
}