//
// Created by Administrator on 2018/5/21.
//
#include <afxres.h>
#include <stdio.h>
#include "seqlist.h"

typedef struct _tag_SeqList{
    int length;
    int capacity;
    unsigned int **node;
} TSeqList;

SeqList* SeqList_Create(int capacity){

    TSeqList *tmp = NULL;
    tmp = (TSeqList *)malloc(sizeof(TSeqList));
    if(tmp==NULL){
        printf("error");
        return -1;
    }
    memset(tmp,0, sizeof(TSeqList));

    tmp->node = (unsigned int **)malloc(sizeof(unsigned int*)*capacity);

    tmp->capacity = capacity;
    tmp->length = 0;


    return tmp;

}

void SeqList_Destroy(SeqList* list){

    TSeqList *tlist = NULL;
    if(list==NULL){
        return;
    }

    tlist = (TSeqList *)list;
    if(tlist->node!=NULL){
        free(tlist->node);
    }
    free(tlist);
}

void SeqList_Clear(SeqList* list){
    TSeqList *tlist = NULL;
    if(list==NULL){
        return;
    }

    tlist = (TSeqList *)list;
    tlist->length = 0;
    return;

}

int SeqList_Length(SeqList* list){

        TSeqList *tlist = NULL;
        if(list==NULL){
            return -1;
        }

        tlist = (TSeqList *)list;
    return tlist->length;

}

int SeqList_Capacity(SeqList* list){

        TSeqList *tlist = NULL;
        if(list==NULL){
            return -1;
        }

        tlist = (TSeqList *)list;
    return tlist->capacity;
}

int SeqList_Insert(SeqList* list,SeqListNode* node,int pos){
    TSeqList *tlist = NULL;

    if(list==NULL||node==NULL||pos<0){
        return -1;
    }
    tlist = (TSeqList*)list;

    if(tlist->length>=tlist->capacity){
        printf("can't insert");
    }

    if(pos>=tlist->length){
        pos = tlist->length;
    }



    int i=0;
    for(i=tlist->length;i>pos;i--){
        tlist->node[i] = tlist->node[i-1];

    }
    tlist->node[i] = (unsigned int *)node;
    tlist->length++;

}

SeqListNode* SeqList_Get(SeqList* list,int pos){
    int i=0;
    TSeqList *tlist = NULL;

    if(list==NULL||pos<9){
        printf("can't find");
    }
    tlist = (TSeqList*)list;

    return (void *)tlist->node[pos];



}

SeqListNode* SeqList_Delete(SeqList* list,int pos){

    int i=0;
    SeqListNode *ret = 0;
    TSeqList *tlist = NULL;

    if(list==NULL||pos<0){
        printf("error");
    }

    tlist=(TSeqList*)list;

    ret=(SeqListNode *)tlist->node[pos];

    for(i=pos+1;i<tlist->length;i++){
        tlist->node[i-1]=tlist->node[i];

    }

    tlist->length--;

    return ret;




}
