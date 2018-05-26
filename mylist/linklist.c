//
// Created by Administrator on 2018/5/24.
//

#include <afxres.h>
#include "linklist.h"
typedef struct _tag_linkList{
    LinkListNode header;
    int length;


} TLinkList;
LinkList* LinkList_Create(){
    TLinkList *ret = NULL;
    ret = (TLinkList*)malloc(sizeof(TLinkList));
    memset(ret,0, sizeof(TLinkList));
    ret->length = 0;
    ret->header.next = NULL;
    return ret;

}
void LinkList_Destory(LinkList* list){
    if(list!=NULL){
        free(list);
        list = NULL;
    }
}
void LinkList_Clear(LinkList* list){
    TLinkList *tlist = NULL;
    if(list==NULL){
        return;
    }

    tlist = (TLinkList *)list;

    tlist->length = 0;
    tlist->header.next = NULL;
    return;
}
int LinkList_Length(LinkList *list){
    TLinkList *tlist = NULL;
    if(list==NULL){
        return 0;
    }

    tlist = (TLinkList *)list;

    return tlist->length;
}
int LinkList_insert(LinkList *list,LinkListNode* node,int pos){
    int ret = 0,i=0;
    LinkListNode *current = NULL;

    TLinkList *tlist=NULL;
    if(list==NULL||node==NULL||pos<0){
        ret =0;
        return ret;
    }
    tlist = (TLinkList *)list;
    current = &(tlist->header);

    for(i=0;i<pos&&current->next!=NULL;i++){
        current = current->next;
    }
    node->next = current->next;
    current->next = node;

    tlist->length++;


}
LinkListNode* LinkList_Get(LinkList* list,int pos){
    int ret = 0,i=0;
    LinkListNode *current = NULL;

    TLinkList *tlist=NULL;
    if(list==NULL||pos<0){
        ret =0;
        return ret;
    }
    tlist = (TLinkList *)list;
    current = &(tlist->header);

    for(i=0;i<pos&&current->next!=NULL;i++){
        current = current->next;
    }

    return current->next;
}
LinkListNode* LinkList_Delete(LinkList* list,int pos){
    int ret = 0,i=0;
    LinkListNode *current = NULL;

    TLinkList *tlist=NULL;
    if(list==NULL||pos<0){
        ret =0;
        return ret;
    }
    tlist = (TLinkList *)list;
    current = &(tlist->header);

    for(i=0;i<pos&&current->next!=NULL;i++){
        current = current->next;
    }
    
    current->next = current->next->next;
}
