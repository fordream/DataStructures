//循环链表  最后一个节点的指针域指向头节点
#include <iostream>



using namespace std;

#define OK 1
#define ERROR -2 
typedef int Status; 

typedef double ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
    
}*LinkList;
Status CreateRLNode(LinkList &L,int n);
LinkList GetNode(LinkList &L ,int i);
Status ListInsert(LinkList &L, int i,ElemType e) ;
Status ListDelete(LinkList &L,int i,ElemType &e);
LinkList ListCombine(LinkList &La,LinkList &Lb);
void showList(LinkList &L);
 
int main()
{
    LinkList L1,L2;
    ElemType e;
    
    CreateRLNode(L1,6);
    CreateRLNode(L2,6);
    showList(L1);
    showList(L2);
	ListDelete(L1,3,e);
	ListInsert(L2,2,e);
    showList(L2);
   
}



void showList(LinkList &L)
{
    LinkList p;
    p = L->next;
    cout<<"[ ";
    while(p!=L ) {cout<<p->data<<" ";
	p=p->next;}
    cout<<"]";
}


Status CreateRLNode(LinkList &L,int n)
{

    LinkList p,q;
    L = (LinkList)malloc(sizeof(LNode));
    L->next= NULL;   
    for(int i = n; i>0; i--){
        p = (LinkList)malloc(sizeof(LNode));
        cin>>p->data;
       
         p->next = L->next;
         L->next= p;
        
    }   
    q=L->next;
    int j=1;
	while(j<n)
	{
		q = q->next; j++;
	} 
	q->next = L;
}


LinkList GetNode(LinkList &L ,int i)
{
    LinkList p;
    p = L->next;
    
    int j=1;
    
    while(p!=L && j<i){
        p = p->next; j++;
    }
    if(p==L || j>i)  return NULL;
    else return p;
    
    
} 

Status ListInsert(LinkList &L, int i,ElemType e) 
{
    LinkList p,q;
    q = (LinkList)malloc(sizeof(LNode));
    if(!(p = GetNode(L,i-1))) return 0;
    q->data= e;
    q->next = p->next;
    p->next = q;
    return OK;
} 


Status ListDelete(LinkList &L,int i,ElemType &e)
{
    LinkList p,q;
    if(!(p = GetNode(L,i-1))) return 0;
    q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return OK;
}

LinkList ListCombine(LinkList &La,LinkList &Lb)
{
    LinkList Lc,pa,pb,pc;
    pa = La->next;
    pb = Lb->next;
    Lc = pc ;
	pc = La; 
    while(pa!=La && pb!=Lb){
        if(pa->data <pb->data)
        {
            pc->next = pa; pc = pa; pa = pa->next;     
        }
        else{
            pc->next = pb; pc = pb; pb = pb->next;
        }
     }
     if(pa!=La){
     	pc->next = pa;
     	Lc = La;
     } 
     if(pb!=Lb){
     	pc->next = pb;
     	Lc = Lb;
     } 
    // pc->next = (pa!=La?pa:pb);
     
    // free(Lb);
     return Lc;
} 









