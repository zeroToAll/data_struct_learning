//
// Created by Administrator on 2018/5/26.
//

#ifndef DAY12_LINKSTACK_H
#define DAY12_LINKSTACK_H
typedef void LinkStack;
LinkStack* LinkStack_Create();
void LinkStack_Destroy(LinkStack* stack);
void LinkStack_Clear(LinkStack* stack);
int LinkStack_Push(LinkStack* stack,void* item);
void* LinkStack_Pop(LinkStack* stack);
void* LinkStack_Top(LinkStack* stack);
int LinkStack_Size(LinkStack* stack);
int LinkStack_Capacity(LinkStack* stack);
#endif //DAY12_LINKSTACK_H
