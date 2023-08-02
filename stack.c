// 描述
// 请你实现一个栈。
// 操作：
// push x 入栈
// x 为 int 型整数。
// pop：输出栈顶，并让栈顶出栈
// top：输出栈顶，栈顶不出栈

// 输出描述：
// 如果操作为push，则不输出任何东西。
// 如果为另外两种，若栈为空，则输出 "error“
// 否则按对应操作输出


#include<stdlib.h>
#include<string.h>
// 题目标题是100000，你就写10万呀，也不考虑下需要多少 内存
#define MAX 100000
// 定义栈结构，其实用个数组就行了，topp = top point 指针
typedef struct Stack{
    int a[MAX];
    int topp;
}*LStack;
// 这tm是我写的吗，居然给初始化
void inistack(LStack s){
    s->topp=0;
}
void push(LStack s,int x){
    s->a[s->topp]=x;
    s->topp++;
}
int pop(LStack s){
    if(s->topp==0){
        return -1;
    }
    return s->a[--s->topp];
    
}
int top(LStack s){
    if(s->topp==0){
        return -1;
    }
    int num=s->a[--s->topp];
    s->topp++;
    return num;
}
int main(){
    LStack s=(LStack)malloc(sizeof(struct Stack));
    inistack(s);
    int n=0;
    scanf("%d",&n);
    while(n--){
        char *str=(char*)malloc(6*sizeof(char));
        
        scanf("%s",str);
        if(!strcmp(str,"push")){
            int num=0;
            scanf("%d",&num);
            push(s,num);
        }
        if(!strcmp(str,"pop")){
            int num1=pop(s);
            if(num1==-1){
				printf("error\n");
				continue;
			}
            printf("%d\n",num1);
        }
        if(!strcmp(str,"top")){
            int num2=top(s);
            if(num2==-1){
				printf("error\n");
				continue;
			}
            printf("%d\n",num2);
        }
        
    }
    
    
    
    
    return 0;
}