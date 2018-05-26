//
// Created by Administrator on 2018/5/24.
//
//
// Created by Administrator on 2018/5/24.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "seqlist.h"

typedef struct _Teacher
{
    int age;
    char name[64];
}Teacher;


typedef struct _Teacher2
{
    int age;
    char name[64];
}Teacher2;

typedef struct _Teacher3
{
    int age;
    char name[64];
    int age3;

}Teacher3;
int main()
{
    int		ret = 0, i = 0;
    SeqList* list = NULL;

    Teacher t1, t2, t3, t4,t5;
    t1.age = 31;
    t2.age = 32;
    t3.age = 33;
    t4.age = 34;
    t5.age = 35;

    list = SeqList_Create(10);
    if (list == NULL)
    {
        printf("func SeqList_Create() ret :%d \n", ret);

    }

    ret = SeqList_Insert(list, (SeqListNode*) &t1, 0); //头插法
    ret = SeqList_Insert(list, (SeqListNode*) &t2, 0); //头插法
    ret = SeqList_Insert(list, (SeqListNode*) &t3, 0); //头插法
    ret = SeqList_Insert(list, (SeqListNode*) &t4, 0); //头插法
    ret = SeqList_Insert(list, (SeqListNode*) &t5, 0); //头插法

    //遍历
    for (i=0; i<SeqList_Length(list); i++)
    {
        Teacher*  tmp = (Teacher *) SeqList_Get(list, i);
        if (tmp == NULL)
        {

        }
        printf("tmp->age:%d\n ", tmp->age);
    }

    //删除链表中的节点
    while( SeqList_Length(list) > 0 )
    {
        SeqList_Delete(list, 0);
    }

    system("pause");

    /*
    typedef void SeqList;
    typedef void SeqListNode;

    SeqList* SeqList_Create(int capacity);

    void SeqList_Destroy(SeqList* mylist);

    void SeqList_Clear(SeqList* mylist);

    int SeqList_Length(SeqList* mylist);

    int SeqList_Capacity(SeqList* mylist);

    int SeqList_Insert(SeqList* mylist, SeqListNode* node, int pos);

    SeqListNode* SeqList_Get(SeqList* mylist, int pos);

    SeqListNode* SeqList_Delete(SeqList* mylist, int pos);
    */


}


