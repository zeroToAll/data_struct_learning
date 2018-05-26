//
// Created by Administrator on 2018/5/26.
//
#include <afxres.h>
#include <stdio.h>
#include "linkstack.h"
#include "linklist.h"

typedef struct _tag_LinkStackNode{
    LinkListNode node;
    void* item; //栈的业务节点
}TLinkStackNode;

LinkStack* LinkStack_Create(){
    return LinkList_Create();
}
void LinkStack_Destroy(LinkStack* stack){}
void LinkStack_Clear(LinkStack* stack){

}
//在线性表的头部插入元素
int LinkStack_Push(LinkStack* stack,void* item){

    TLinkStackNode *tmp = NULL;
    int ret = 0;
    tmp = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));
    memset(tmp,0, sizeof(TLinkStackNode));
    tmp->item = item;


    LinkList_insert(stack,(LinkListNode*)tmp,0);

    if(ret!=0){
        printf("error %d\n",ret);
        free(tmp);
    }

    return ret;


}
void* LinkStack_Pop(LinkStack* stack){}
void* LinkStack_Top(LinkStack* stack){}
int LinkStack_Size(LinkStack* stack){}
int LinkStack_Capacity(LinkStack* stack){}

