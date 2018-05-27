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
void LinkStack_Destroy(LinkStack* stack){
    LinkStack_Clear(stack);
    LinkList_Destory(stack);
}
void LinkStack_Clear(LinkStack* stack){
    if(stack==NULL){
        return;
    }
    while(LinkList_Length(stack)>0){
        LinkStack_Pop(stack);   //在这个函数中释放节点的内存
    }
    return;
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
void* LinkStack_Pop(LinkStack* stack){

    void *item = NULL; //栈的业务节点
    TLinkStackNode *tmp = NULL;
    tmp = (TLinkStackNode*)LinkList_Delete(stack,0);
    if(tmp==NULL){
        return NULL;

    }
    item = tmp->item;
    char a = *(char *)tmp;
    free(tmp);//包装节点入栈的时候分配了内存，现在释放
    return item;
}
void* LinkStack_Top(LinkStack* stack){
    TLinkStackNode *tmp = NULL;
    tmp = (TLinkStackNode*)LinkList_Get(stack,0);
    if(tmp==NULL){
        return NULL;
    }

    return tmp->item;
}
int LinkStack_Size(LinkStack* stack){
    return LinkList_Length(stack);
}
int LinkStack_Capacity(LinkStack* stack){}

