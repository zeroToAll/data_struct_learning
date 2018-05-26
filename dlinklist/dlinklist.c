//
// Created by Administrator on 2018/5/25.
//
#include <stdio.h>
#include <malloc.h>
#include "dlinklist.h"

typedef struct _tag_DLinkList{
    DLinkListNode header;
    DLinkListNode* slider;
    int length;
} TDLinkList;

DLinkList* DLinkList_Create(){
    TDLinkList* ret = (TDLinkList*)malloc(sizeof(TDLinkList));

    if(ret!=NULL){
        ret->length=0;
        ret->header = NULL;
        ret->slider = NULL;
    }

    return ret;
}

void DLinkList_Destroy(DLinkList *list){
    if(list!=NULL){
        free(list);
    }
}

void DLinkList_Clear(DLinkList* list){
    TDLinkList* sList = (TDLinkList*)list;
    if(sList!=NULL){
        sList->length = 0;
        sList->header.next = NULL;
        sList->header.pre = NULL;
        sList->slider = NULL;
    }
}

int DLinkList_Length(DLinkList* list){
    TDLinkList* sList = (TDLinkList*)list;
    int ret = -1;
    if(sList!=NULL){
        ret = sList->length;
    }

    return ret;

}

int DLinkList_Insert(DLinkList* list,DLinkListNode* node,int pos){

    int ret = 0,i=0;
    TDLinkList* sList = (TDLinkList*)list;
    if(list==NULL||node==NULL||pos<0){
        ret=-1;
    }

    DLinkListNode* current = &sList->header;
    DLinkListNode* next = NULL;

    for(i=0;(i<pos)&&(current->next!=NULL);i++){
        current = current->next;
    }
    next = current->next;

    current->next = node;
    node->next = next;


    //在第一个位置插入元素的时候
    if(next!=NULL){
        next->pre = node;
    }
    node->pre = current;

    //若在0位置插入
    if(current==(DLinkListNode*)sList){
        node->pre = NULL;
    }
    sList->length++;

    return ret;

}

DLinkListNode* DLinkList_Get(DLinkList* list,int pos){
    TDLinkList* sList = (TDLinkList*)list;
    DLinkListNode* ret = NULL;
    int i = 0;

    if((sList!=NULL)&&(0<=pos)&&(pos<sList->length)){

        DLinkListNode* current = (DLinkListNode*)sList;
        for(i=0;(i<pos)&&(current->next!=NULL);i++){
            current = current->next;
        }

        ret = current->next;

    }

    return ret;

}

DLinkListNode* DLinkList_Delete(DLinkListNode* list,int pos){
    TDLinkList* sList = (TDLinkList*)list;
    DLinkListNode* ret = NULL;
    int i = 0;
    if(sList==NULL||pos<0){
        return NULL;
    }

    {
        DLinkListNode* current = &sList->header;
        DLinkListNode* next = NULL; //增加next指针

        for(i=0;(i<pos)&&(current->next!=NULL);i++){
            current = current->next;
        }

        ret = current->next;
        next = current->next->next;

        current->next = next;

        if(next!=NULL){
            next->pre = current;
            if(current==&sList->header){
                next->pre = NULL;
            }
        }

        if(sList->slider == ret){
            sList->slider = next;
        }


    }

}
