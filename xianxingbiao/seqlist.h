//
// Created by Administrator on 2018/5/21.
//

#ifndef DAY12_SEQLIST_H
#define DAY12_SEQLIST_H
typedef void SeqList;
typedef void SeqListNode;

SeqList* SeqList_Create(int capacity);

void SeqList_Destroy(SeqList* list);

void SeqList_Clear(SeqList* list);

int SeqList_Length(SeqList* list);

int SeqList_Capacity(SeqList* list);

int SeqList_Insert(SeqList* list,SeqListNode* node,int pos);

SeqListNode* SeqList_Get(SeqList* list,int pos);

SeqListNode* SeqList_Delete(SeqList* list,int pos);
#endif //DAY12_SEQLIST_H
