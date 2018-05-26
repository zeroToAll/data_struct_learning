//
// Created by Administrator on 2018/5/25.
//

#ifndef DAY12_SEQSTACK_H
#define DAY12_SEQSTACK_H
typedef void SeqStack;
SeqStack* SeqStack_Create(int capacity);
void SeqStack_Destroy(SeqStack* stack);
void SeqStack_Clear(SeqStack* stack);
int SeqStack_Push(SeqStack* stack,void* item);
void* SeqStack_Pop(SeqStack* stack);
void* SeqStack_Top(SeqStack* stack);
int SeqStack_Size(SeqStack* stack);
int SeqStack_Capacity(SeqStack* stack);
#endif //DAY12_SEQSTACK_H
