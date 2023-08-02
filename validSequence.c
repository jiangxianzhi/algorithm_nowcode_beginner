//  描述
// 给出一个仅包含字符'(',')','{','}','['和']',的字符串，判断给出的字符串是否是合法的括号序列
// 括号必须以正确的顺序关闭，"()"和"()[]{}"都是合法的括号序列，但"(]"和"([)]"不合法
 
 #include<stdbool.h>
bool isValid(char* s ) {
    // write code here
    int p = 0;
    int p1 = 0;
    int a[10000];
 
    while (s[p]) {
        if (s[p] == '(') {
            a[p1] = s[p];
            p1++;
            p++;
            continue;
        }
        if (s[p] == '{') {
            a[p1] = s[p];
            p1++;
            p++;
             continue;
        }
        if (s[p] == '[') {
            a[p1] = s[p];
            p1++;
            p++;
             continue;
        }
 
 
        if (s[p] == ')') {
            p1--;
            p++;
           if(a[p1]!='('){
               return false;
           }
            continue;
        }
 
        if (s[p] == ']') {
            p1--;
            p++;
           if(a[p1]!='['){
               return false;
           }
            continue;
        } 
 
         if (s[p] == '}') {
            p1--;
            p++;
           if(a[p1]!='{'){
               return false;
           }
            continue;
        }
 
 
    }
 
 
    if(p1==0){
         return true;
    }else {
        return false;
    }
 
    
}