//双向循环链表

#include <iostream>
#include <stdio.h>

using namespace std;

#define OK 1
#define ERROR -2 
#define OVERFLOW -1
typedef int Status; 

typedef double ElemType;

typedef struct DulNode
{
	ElemType data;
	struct DulNode *prior,*next;
}*DulLinkList;

Status CreateDulLL(DulLinkList &L,int n)
{
//倒序输入一组数据
	DulLinkList p;
    L = (DulLinkList)malloc(sizeof(DulNode));
    L->next= null;             
    for(int i = n; i>0; i--){
        p = (DulLinkList)malloc(sizeof(DulNode));
        cin>>(&p->data);
        p->next = L->next;
        L->next= p;
    }   
} 
}

DulLinkList GetElem(DulLinkList &L,inti)
{
	DulLinkList p;
	p = L->next;
	int j =1;
	while(p!=L && j<i)
	{
		p = p->next;
		++j;
	}
	if(p == L || j > i) return null;
	else return p;
}

Status ListDelete(DulLinkList &L,int i,ElemType &e)
{
	DulLinkList p;
	if(!(p = GetElem(L,i))) return ERROR;

	e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;

	free(p);
	return OK;
}

Status ListInsert(DulLinkList &L,int i,ElemType e)
{
	DulLinkList p,s;
	if(!(p=GetElem(L,i))) return ERROR;
	s = (DulLinkList)malloc(sizeof(DulNode));
	if(!s) return OVERFLOW;

	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;

	return OK;
}

int main()
{


}










