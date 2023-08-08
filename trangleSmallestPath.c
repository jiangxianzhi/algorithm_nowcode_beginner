#include<stdio.h>
#include<malloc.h>
// 三角形最小路径

void main(){
    // 输入三角形，数组
   int **arr =(int **)malloc(sizeof(int* )*3);
   for(int i = 0;i<3;i++){
    arr[i] = (int *)malloc(sizeof(int )*(i+1));

   } 

   for(int i = 0;i<3;i++){
    printf("\n");
    for(int j = 0;j<=i;j++){
        arr[i][j] = 0;
        printf("%d",arr[i][j]);
    }
   }
     printf("\n");
   //输入
      for(int i = 0;i<3;i++){
    for(int j = 0;j<=i;j++){
       scanf("%d",&arr[i][j]);
       
    }
   }
      for(int i = 0;i<3;i++){
    printf("\n");
    for(int j = 0;j<=i;j++){
        
        printf("%d\t",arr[i][j]);
    }
   }

// 数组2，用来储存每个点最短路径
   int **arr1 =(int **)malloc(sizeof(int* )*3);
   for(int i = 0;i<3;i++){
    arr1[i] = (int *)malloc(sizeof(int )*(i+1));

   } 
//    计算每个点最短路径
   arr1[0][0] = arr[0][0];

   for(int i = 1;i<3;i++){
    for(int j = 0;j<=i;j++){
        if(j==0){
arr1[i][j] = arr1[i-1][j]+arr[i][j];
        }
        if(j>0&&j<i){
arr1[i][j] = arr[i-1][j-1]<arr[i-1][j]?arr1[i-1][j-1]+arr[i][j]:arr1[i-1][j]+arr[i][j];
        }
        if(j==i){
arr1[i][j] = arr1[i-1][j-1]+arr[i][j];
        }
    }
   }

     for(int i = 0;i<3;i++){
    printf("\n");
    for(int j = 0;j<=i;j++){
        
        printf("%d\t",arr1[i][j]);
    }
   }


//    比较最后一排点，选出最短的
int min=arr1[2][2];
for(int i = 0;i<3;i++){
      min = min<arr1[2][i]?min:arr1[2][i];
}
printf(" min is %d",min);
   
}