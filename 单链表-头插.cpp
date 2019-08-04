#include<stdio.h>
#include<stdlib.h>
#define elementype int
typedef struct LNode
{
	elementype data;
	struct LNode *next;
}LNode, *LinkNode ;


void InitList(LinkNode *L) {   //用结构指针类型LinkNode表示头指针变量
								  //(LinkNode *L接收头指针的地址值)
	    *L = (LinkNode)malloc(sizeof(LNode));
		if (*L == NULL) {
			printf("申请内存空间失败/n");
			exit(-1);
		}
	   (*L)->next = NULL;   //L表示待初始化单链表的头指针变量
}


LinkNode List_HeadInsert(LinkNode L) {                  //用头插法插入节点
	LNode *s; int x;
	printf("请输入节点的值:");
	scanf("%d", &x);
	while (x!=9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		if (s==NULL)
		{
			printf("没有足够的内存空间");
			exit(0);
		}
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}


int main(void) {
	LinkNode L;
	InitList(&L);
	L = List_HeadInsert(L);
	LNode* p = L->next;
	while (p!=NULL) {
		printf("%5d",p->data);
		p = p->next;
	}
	system("pause");
	return 0;
}