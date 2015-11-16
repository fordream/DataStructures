//线性表的链式表示和实现
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

/*
需要实现的功能
1.创建 
2.获取第i个元素 
3.插入元素
4.删除元素 
5.合并表 
*/

//初始化 从表尾到表头逆向建立一个数据个数为n个的单链表
void CreastList(LinkList &L,int n){
    LinkList p;
    L = (LinkList)malloc(sizeof(LNode));
   
    L->next= NULL;             //带头节点的单链表 
    for(int i = n; i>0; i--){
        p = (LinkList)malloc(sizeof(LNode));
        cin>>p->data;
        p->next= L->next;
        L->next= p;
        
    }   
} 

/*获取第i个元素 Status GetElem(LinkList &L ,int i,ElemType &e)
                         L为带头节点的单链表头指针
                         当第i个元素存在的时候，其值赋给e 
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
在单链表中插入一个节点 
在第i个位置之前插入一个元素e
 Status ListInsert(LinkList &L, int i,ElemType e) 
*/ 
Status ListInsert(LinkList &L, int i,ElemType e) 
{
    LinkList p,q;
    q = (LinkList)malloc(sizeof(LNode));
    p = L->next;
    int j = 1;

    while(p && j<i-1)
    {
        p = p->next;j++;
    }
    if(!p || j>i-1) return ERROR;
    q->data= e;
    q->next = p->next;
    p->next = q;
    return OK;
} 

/*
在单链表中除去一个节点
在带头节点的单链表L中，删除第i个元素，并由e返回它的值
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
合并两个单链表
已知两个线性单链表La和Lb的元素按值非递减排列
归并La和Lb得到新的非递减单链表
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
void showList(LinkList &L)
{
    LinkList p;
    p = L->next;
    cout<<"[ ";
    while(p ) {cout<<p->data<<" ";
    p=p->next;}
    cout<<"]";
}
int main()
{
    LinkList L1,L2;
    ElemType e,delet;
    cout<<"请倒叙输入链表1的数据："<<endl;
    CreastList(L1,4);
    
    cout<<"请倒叙输入链表2的数据："<<endl;
    CreastList(L2,3);

     cout<<"链表1的数据域为：";
    showList(L1);cout<<endl;
     cout<<"链表2的数据域为：";
    showList(L2);cout<<endl;
    
   ListDelete(L1,3,delet);
    cout<<"删除链表1的第3个元素后数据域为：";
    showList(L1);cout<<endl;
    GetElem(L1,2,e);
    cout<<"L1的第2个元素e为："<<e<<endl;

    //将e插入到链表2的第三个元素之前
    ListInsert(L2,1,e);
    cout<<"将e插入到链表2第2个元素之前后的数据域为：";
    showList(L2);cout<<endl;
    
    L1 = ListCombine(L1,L2);
    cout<<"链表1的数据域为：";
    showList(L1);cout<<endl;
    

    
}




