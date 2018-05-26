//
// Created by Administrator on 2018/5/26.
//
#include <afxres.h>
#include <stdio.h>
#include "seqstack.h"

void main(){

    int i=0;
    int a[10];
    SeqStack* stack = NULL;
    stack = SeqStack_Create(10);
    if(stack==NULL){
        return;
    }


    //压栈
    for(i=0;i<5;i++){
        a[i] = i+1;
        SeqStack_Push(stack,&a[i]);
    }

    printf("Capacity:%d\n",SeqStack_Capacity(stack));
    printf("length:%d\n",SeqStack_Size(stack));

    printf("top:%d\n",*((int*)SeqStack_Top(stack)));

    while(SeqStack_Size(stack)>0){
       int tmp =  *((int*)SeqStack_Pop(stack));
        printf("tmp%d\n",tmp);
    }

}

