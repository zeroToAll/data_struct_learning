#include <afxres.h>
#include <stdio.h>

//
// Created by Administrator on 2018/5/30.
//
struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
};
typedef struct BiTNode BiTNode;
typedef struct BiTNode* BiTree;

void preOrder(BiTNode* root){


    if(root==NULL){
        return;

    }
    printf("%d\n",root->data);
    preOrder(root->lchild);
    preOrder(root->rchild);
}

void inOrder(BiTNode* root){
    if(root==NULL){
        return;
    }
    inOrder(root->lchild);
    printf("%d\n",root->data);
    inOrder(root->rchild);

}

void postOrder(BiTNode* root){
    if(root==NULL){
        return;
    }
    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%d\n",root->data);

}
int sum;
void coutLeaf(BiTNode *T){

    if(T!=NULL){
        if(T->lchild==NULL&&T->rchild==NULL){
            sum++;
        }
        if(T->lchild){
            coutLeaf(T->lchild);
        }
        if(T->rchild){
            coutLeaf(T->rchild);
        }
    }
}

void coutLeaf3(BiTNode *T,int* sum){

    if(T!=NULL){
        if(T->lchild==NULL&&T->rchild==NULL){
            (*sum) = (*sum)+1;
        }
        if(T->lchild){
            coutLeaf3(T->lchild,sum);
        }
        if(T->rchild){
            coutLeaf3(T->rchild,sum);
        }
    }
}

int main(){
    BiTNode t1,t2,t3,t4,t5;
    memset(&t1,0, sizeof(BiTNode));
    memset(&t2,0, sizeof(BiTNode));
    memset(&t3,0, sizeof(BiTNode));
    memset(&t4,0, sizeof(BiTNode));
    memset(&t5,0, sizeof(BiTNode));
    t1.data = 1;
    t2.data = 2;
    t3.data = 3;
    t4.data = 4;
    t5.data = 5;

    BiTree root = &t1;
    //建立关系
    t1.lchild = &t2;
    t1.rchild = &t3;
    t2.lchild = &t4;
    t3.lchild = &t5;

   // sum = 0;
   // coutLeaf(root);
    int sum1=0;
    coutLeaf3(root,&sum1);

//    preOrder(root);
//    printf("\n");
//    inOrder(root);
//    printf("\n");
//    postOrder(root);
//    printf("\n");
    printf("sum:%d",sum1);


}

