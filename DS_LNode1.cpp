//���Ա����ʽ��ʾ��ʵ��
#include <iostream>

using namespace std;

#define OK 1
#define ERROR -2 
typedef int Status; 

typedef double ElemType;

typedef struct LNode{
	ElemType data;
	struct Lnode *next;
	
}*LinkList;

/*
��Ҫʵ�ֵĹ���
1.���� 
2.��ȡ��i��Ԫ�� 
3.����Ԫ��
4.ɾ��Ԫ�� 
5.�ϲ��� 
*/

//��ʼ�� �ӱ�β����ͷ������һ�����ݸ���Ϊn���ĵ�����
void CreastList(LinkList &L,int n){
	L = (LinkList)malloc(sizeof(LNode));
	L->next= null;             //��ͷ�ڵ�ĵ����� 
	for(int i = n; i>0; i--){
		p = (LinkList)malloc(sizeof(LNode));
		cin>>(&p->data);
		
		//���뵽��ͷ 
		p->next = L->next;
		L->next= p;
	}	
} 

/*��ȡ��i��Ԫ�� Status GetElem(LinkList &L ,int i,ElemType &e)
						 LΪ��ͷ�ڵ�ĵ�����ͷָ��
						 ����i��Ԫ�ش��ڵ�ʱ����ֵ����e 
*/ 
Status GetElem(LinkList &L ,int i,ElemType &e)
{
	LinkList p;
	p = L->next;
	
	int j=1;
	
	while(p && j<i){
		p = p->next; j++;
	}
	if(!p || j>i)  return ERROR;
	e = p->data;
	return OK;
	
} 

/*
�ڵ������в���һ���ڵ� 
�ڵ�i��λ��֮ǰ����һ��Ԫ��e
 Status ListInsert(LinkList &L, int i,ElemType e) 
*/ 
Status ListInsert(LinkList &L, int i,ElemType e) 
{
	LinkList p,q;
	p = L->next;
	int j = 1;
	while(p && j<i-1)
	{
		p = p->next;j++;
	}
	if(!p || j>i-1) return ERROR;
	q->data= e;
	q->next = p->next;
	p-next = p;
	return OK;
} 

/*
�ڵ������г�ȥһ���ڵ�
�ڴ�ͷ�ڵ�ĵ�����L�У�ɾ����i��Ԫ�أ�����e��������ֵ
Status ListDelete(LinkList &L,int i,ElemType &e) 
*/
Status ListDelete(LinkList &L,int i,ElemType &e)
{
	LinkList p,q;
	p = L->next;
	int j =1;
	while(p && j<i-1)
	{
		p = p->next;
		j++;
	}
	if(!p || j > i-1)  return ERROR;
  	q = p->next;
  	e = q->data;
  	p->next = q->next;
  	free(q);
  	return OK;
}

/*
�ϲ�����������
��֪�������Ե�����La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
�鲢La��Lb�õ��µķǵݼ�������
LinkList ListCombine(LinkList &La,LinkList &Lb); 
*/
LinkList ListCombine(LinkList &La,LinkList &Lb)
{
	LinkList Lc,pa,pb,pc;
 	pa = La->next;
 	pb = Lb->next;
 	Lc = pc = La; 
 	while(pa && pb){
	 	if(pa->data <pb->data)
	 	{
			pc->next = pa; pc = pa; pa=pa->next;	 
	 	}
	 	else{
	 		pc->next = pb; pc = pb; pb = pb->next;
	 	}
	 }
	 pc->next = pa?pa:pb;
	 
	 free(Lb);
	 return Lc;
} 









