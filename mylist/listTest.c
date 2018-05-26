//
// Created by Administrator on 2018/5/24.
//
#include <stdint.h>
#include <afxres.h>
#include <stdio.h>
#include "linklist.h"
typedef struct listTeacher
{
    LinkListNode node;
    int age;
    char name[64];
}listTeacher;


int main() {
    int ret = 0, i = 0;
    LinkList *list = NULL;

    listTeacher t1, t2, t3, t4, t5;
    t1.age = 31;
    t2.age = 32;
    t3.age = 33;
    t4.age = 34;
    t5.age = 35;

    list = LinkList_Create();
    if(list==NULL) {
        return -1;
    }

    int len = LinkList_Length(list);
    ret = LinkList_insert(list, (LinkListNode*)&t1,0);
    ret = LinkList_insert(list, (LinkListNode*)&t2,0);
    ret = LinkList_insert(list, (LinkListNode*)&t3,0);
    ret = LinkList_insert(list,(LinkListNode*) &t4,0);
    ret = LinkList_insert(list, (LinkListNode*)&t5,0);

    for(i=0;i<LinkList_Length(list);i++){
        listTeacher *tmp = LinkList_Get(list,i);
        if(tmp==NULL){
            return -1;
        }
        printf("tmp->age:%d",tmp->age);
    }

}



