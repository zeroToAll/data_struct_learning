//
// Created by Administrator on 2018/5/25.
//
#include <afxres.h>
#include "seqstack.h"
#include "seqlist.h"

SeqStack* SeqStack_Create(int capacity){
    return SeqList_Create(capacity);
}

//销毁栈
void SeqStack_Destroy(SeqStack* stack){
    SeqList_Destroy(stack);
}

//清空栈
void SeqStack_Clear(SeqStack* stack){
    SeqList_Clear(stack);
}
int SeqStack_Push(SeqStack* stack,void* item){
    return SeqList_Insert(stack,item,SeqList_Length(stack)); //线性表尾部插入相当于压栈

}
//从栈中拿出元素相当于从链表的尾部拿出元素
void* SeqStack_Pop(SeqStack* stack){

    return SeqList_Delete(stack,SeqList_Length(stack)-1);
}
void* SeqStack_Top(SeqStack* stack){
    return SeqList_Get(stack,SeqList_Length(stack)-1);
}
int SeqStack_Size(SeqStack* stack){

    return SeqList_Length(stack);

}
//
int SeqStack_Capacity(SeqStack* stack){
    return SeqList_Capacity(stack);
}