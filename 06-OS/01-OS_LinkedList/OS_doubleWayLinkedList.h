#ifndef OS_DOUBLE_WAY_LINKED_LIST_H_
#define	OS_DOUBLE_WAY_LINKED_LIST_H_

typedef struct NodeStructure node;

typedef struct{
	u32 uNID;
	u32 periodicity;
	u32 periority;
	void (*pToTask) (void);
}TaskNode;

struct NodeStructure{
	TaskNode Task;
	node * Next;
	node * Prev;
};

u16 Counter = 0;

node *Head = NULL;
node *Current = NULL;
node *Last = NULL;

void OS_voidNewTask(TaskNode * Copy_StrTask);

void OS_voidDeleteAllTasks(void);

void OS_voidDeleteLastTask(void);

TaskNode * OS_StrSearchTaskByID(u32 NID);

void OS_voidDeleteTaskNode(node CurrentNode);

u16 OS_SearchNodeByID_And_Destroy(u32 NID);

void OS_voidBubbleSort(void);



#endif /*OS_DOUBLE_WAY_LINKED_LIST_H_*/