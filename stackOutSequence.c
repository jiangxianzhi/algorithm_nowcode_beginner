// 输入两个整数序列，第一个序列表示栈的压入顺序
// 请判断第二个序列是否可能为该栈的弹出顺序
// 返回 true or false

// 思路:1.通过出栈数组n找到， 入栈数组相应地方， 入栈数组下标为指针a，
// 通过出栈数组n+1找到， 入栈数组相应地方， 入栈数组下标为指针b
//  b相对于a指针下一次只能往后移动（怎么往后移都没问题）
// 或者往前没有出栈的数据中移动一格
// 直到出栈数组找完
//

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param pushV int整型一维数组
 * @param pushVLen int pushV数组长度
 * @param popV int整型一维数组
 * @param popVLen int popV数组长度
 * @return bool布尔型
 */
#include <stdbool.h>
#include <stdio.h>
bool IsPopOrder(int *pushV, int pushVLen, int *popV, int popVLen)
{
    // write code here
    // 针对一个数的数组
    if (pushVLen == popVLen && pushVLen == 1)
    {
        if (pushV[0] != popV[0])
        {
            return false;
        }
        return true;
    }

    for (int i = 0; i < popVLen - 1;)
    {
        int a;
        int aTmp = a;
        int b;
        for (int j = 0; j < pushVLen; j++)
        {
            if (pushV[j] == popV[i])
            {
                a = j;
                pushV[j] = -1;
            }
        }
        if (a == aTmp)
        {
            return false;
        }
        i++;
        for (int j = 0; j < pushVLen; j++)
        {
            if (pushV[j] == popV[i])
            {
                b = j;
            }
        }
        if (b < a - 1)
        {
            for (int j = b + 1; j < a; j++)
            {
                if (pushV[j] != -1)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

// 思路2：
// 用第三个数组，演变入栈出栈过程，如果第三个数组最后是空的，那么这个出栈 顺序可以

bool IsPopOrder1(int* pushV, int pushVLen, int* popV, int popVLen ) {
    // write code here
    int stack[pushVLen];
    int top = -1;
    int in = 0;
    int out = 0;
    while(in<pushVLen&&out<popVLen){
        while(in<pushVLen&&pushV[in]!=popV[out]){
                stack[++top] = pushV[in++];
 
        }
        stack[++top] = pushV[in++];
        while(top>-1&&stack[top]==popV[out]){
            top--;
            out++;
             
        }
    }
    if(top==-1){
        return true;
    }else{
        return false;
    }
}