//
// Created by Administrator on 2018/5/24.
//

#ifndef DAY12_LINKLIST_H
#define DAY12_LINKLIST_H
typedef void LinkList;

typedef struct _tag_LinkListNode{
    struct _tag_LinkListNode* next;
} LinkListNode;

LinkList* LinkList_Create();
void LinkList_Destory(LinkList* list);
void LinkList_Clear(LinkList* list);
int LinkList_Length(LinkList *list);
int LinkList_insert(LinkList *list,LinkListNode* node,int pos);
LinkListNode* LinkList_Get(LinkList* list,int pos);
LinkListNode* LinkList_Delete(LinkList* list,int pos);


#endif //DAY12_LINKLIST_H
