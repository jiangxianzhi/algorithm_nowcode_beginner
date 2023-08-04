/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param tokens string字符串一维数组
 * @param tokensLen int tokens数组长度
 * @return int整型
 */

// 给定一个逆波兰表达式，求表达式的值。
// 输入["2","1","+","4","*"]
// 返回12

// 思路：是数字就入栈，是运算符就出栈两个，计算，然后再入栈。


int evalRPN(char** tokens, int tokensLen ) {
  
 
    int  a[10000];
    int  p = 0;
    int p1 = 0;
    while (tokensLen--) {
        if ( strcmp(tokens[p1],"+")!=0&&strcmp(tokens[p1],"-")!=0&& strcmp(tokens[p1],"*")!=0&&strcmp(tokens[p1],"/")!=0) {
            a[p] = atoi(tokens[p1]);
            p++;
            p1++;
             printf("数字%d\n",a[p]);
            continue;
        }
 
        if ( strcmp(tokens[p1],"+")==0) {
            a[p - 2] = a[p - 2] + a[p - 1];
            p = p - 1;
        } else if ( strcmp(tokens[p1],"-")==0) {
             printf("运算%d\n",p);
            a[p - 2] = a[p - 2] - a[p - 1];
            p = p - 1;
        } else if ( strcmp(tokens[p1],"*")==0) {
            a[p - 2] = a[p - 2] * a[p - 1];
            p = p - 1;
        } else if( strcmp(tokens[p1],"/")==0){
                 a[p - 2] = a[p - 2] / a[p - 1];
             p = p - 1;
        }
 
        p1++;
         
    }
    
    return a[p-1];
}