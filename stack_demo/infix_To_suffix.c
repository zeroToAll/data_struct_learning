//
// Created by Administrator on 2018/5/2
#include <malloc.h>
#include <mem.h>

#include <afxres.h>
#include <stdio.h>
#include "linkstack.h"


//判断是否是符号
//判断符号优先级



boolean isSymbol(char single_char){
    boolean ret = FALSE;
    switch(single_char){
        case '+':
            ret = TRUE;
            break;
        case '-':
            ret = TRUE;
            break;
        case '*':
            ret = TRUE;
            break;
        case '/':
            ret = TRUE;
            break;

    }

    return ret;
}

boolean is_left(char single_char){
    boolean ret = FALSE;
    switch(single_char){
        case '[':
            ret = TRUE;
            break;
        case '(':
            ret = TRUE;
            break;
        case '<':
            ret = TRUE;
            break;
        case '{':
            ret = TRUE;
            break;

    }

    return ret;

}
boolean is_right(char single_char){
    boolean ret = FALSE;
    switch(single_char){
        case ']':
            ret = TRUE;
            break;
        case ')':
            ret = TRUE;
            break;
        case '}':
            ret = TRUE;
            break;
        case '>':
            ret = TRUE;
            break;

    }

    return ret;

}
boolean is_num(char single_char){


    if(is_left(single_char)||isSymbol(single_char)||is_right(single_char)){
        return FALSE;
    } else{
        return TRUE;
    }
}
double Cauculate(char ch, double left, double right)//各个操作符对应的操作
{
    switch (ch)
    {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
        default:
            return 0;
            break;
    }
}

//优先级判断
int get_priority(char sy){
    switch (sy)
    {
        case '#':
            return 0;
        case '(':
            return 1;
        case '+':
        case '-':
            return 3;
        case '*':
        case '/':
            return 5;
        case ')':
            return 6;
        default:
            return -1;
    }

}

//"8+（3-1）*5"
char* transform(char* exp1,char* re){
    LinkStack* stack =  LinkStack_Create();
    char* tmp = exp1;
    int lens = strlen(exp1)+1;
    char* result = re;
    char* fisrt_res = result;
    //memset(result,0,strlen(exp1)+1);
    for(int i=0;i<strlen(exp1);i++){
        if(is_num(*tmp)){
            *result = *tmp;
            result++;
            tmp++;

        }else if(isSymbol(*tmp)){
            if(LinkStack_Size(stack)!=0){
                char in = *(char*)LinkStack_Top(stack);
                if(get_priority(in)<get_priority(*tmp)){
                    LinkStack_Push(stack,tmp);
                    tmp++;
                }else{
                    char p_in = *(char*)LinkStack_Pop(stack);
                    *result = p_in;
                    result++;
                    LinkStack_Push(stack,tmp);
                    tmp++;

                }

            }else{
                LinkStack_Push(stack,tmp);
                tmp++;
            }



        }else if(is_left(*tmp)){
            LinkStack_Push(stack,tmp);
            tmp++;

        }else if(is_right(*tmp)){
            char in = *((char *)LinkStack_Pop(stack));
           while(!is_left(in)){
               *result = in;
               result++;
               in = *(char*)LinkStack_Pop(stack);
           }
        }
    }
    return fisrt_res;
}

int main(){
    char* a = "8+(3-1)*5";
    char re[11] = {0};
    char* r = transform(a,re);
    for(int i=0;i<8;i++){
        printf("%c ",*r);
        r++;
    }
}

