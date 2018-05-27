//
// Created by Administrator on 2018/5/26.
//
#include <afxres.h>
#include <stdio.h>
#include "linkstack.h"
void main(){
    int i = 0;
    int a[10];

    LinkStack* stack = NULL;

    stack = LinkStack_Create();

    if(stack==NULL){
        return;
    }

    //添加元素
    for(i=0;i<5;i++){
        a[i] = i+1;
        LinkStack_Push(stack,&a[i]);

    }

    printf("len:%d\n",LinkStack_Size(stack));
    printf("top:%d\n",*((int *)LinkStack_Top(stack)));
    printf("top:%d\n",*((int *)LinkStack_Pop(stack)));
    printf("top:%d\n",*((int *)LinkStack_Pop(stack)));
    int tmp = *((int *)LinkStack_Pop(stack));
//    while(LinkStack_Size(stack)>0){
//        int tmp = *((int *)LinkStack_Pop(stack));
//    }
}
