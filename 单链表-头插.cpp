#include<stdio.h>
#include<stdlib.h>
#define elementype int
typedef struct LNode
{
	elementype data;
	struct LNode *next;
}LNode, *LinkNode ;


void InitList(LinkNode *L) {   //�ýṹָ������LinkNode��ʾͷָ�����
								  //(LinkNode *L����ͷָ��ĵ�ֵַ)
	    *L = (LinkNode)malloc(sizeof(LNode));
		if (*L == NULL) {
			printf("�����ڴ�ռ�ʧ��/n");
			exit(-1);
		}
	   (*L)->next = NULL;   //L��ʾ����ʼ���������ͷָ�����
}


LinkNode List_HeadInsert(LinkNode L) {                  //��ͷ�巨����ڵ�
	LNode *s; int x;
	printf("������ڵ��ֵ:");
	scanf("%d", &x);
	while (x!=9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		if (s==NULL)
		{
			printf("û���㹻���ڴ�ռ�");
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