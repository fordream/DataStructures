//线性表的顺序表示及实现 

# include<iostream>

using namespace std;

#define LIST_INIT_SIZE 100
#define LISTINCREASEMENT 10 
#define OVERFLOW -1
#define OK 1
#define ERROR -2

typedef double ElemType;  //定义ElemType类型为double 

typedef struct{
	ElemType *elem;      
	int len;               //线性表的长度 
	int listsize;		   //线性表空间大小 
}SqList;                     //线性表结构 



/*
需要实现的功能
1.初始化
2.插入元素
3.删除元素  按值删除  按下标删除 
4.合并表 
*/ 

//*******************辅助函数******************************
//按照固定格式打印数组
void showElem(ElemType arr[], int length)
{
    printf("Elem:[");
    for(int i=0; i<length-2;i++)
        printf("%d,",arr[i] );                  
        //用C语言的  一个很大的不便， %d  只有当我ElemType是int时才行
    printf("%d]\n",arr[length-1] );

}

//交换数组元素位置

void swap(ElemType arr[],int i,int j)
{
    ElemType temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] =temp;

}

//冒泡排序
void bubbleSort(SqList &L)
{
    int temp = 1;
        for(int i = 1; i < L.length && temp==1 ;i++){
           
            temp = 0;
           
            for(int j = 0; j <L.length-i; j++){
               
                if(L.elem[j]>L.elem[j+1]){
                   
                    temp = 1;
                    swap(L.elem,j,j+1);
                }
               
            }
        }
}
//*******************辅助函数******************************

//1.初始化  int InitList_Sq(SqList &L)
int InitList_Sq(SqList &L)
{
	 	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	 	if(!L.elem) return OVERFLOW;
	 	
	 	L.len = 0;
	 	L.listsize = LIST_INIT_SIZE;
	 	return OK;
}

//2.插入元素 int InsertList_Sq(SqList &L,int i,ElemType e);
int InsertList_Sq(SqList &L,int i,ElemType e)
{
	//L为需要插入元素的表 ，i为插入在第i个元素之前，e为需要插入的元素
	//首先检查i的合法性
	if( i<1 || i>L.len )return ERROR;
	//再检查list空间是否够  不够则分配 
	if(L.len>=L.listsize)
	{
		ElemType *temp;
		temp = (ElemType *)realloc(L.elem,(LIST_INIT_SIZE+LISTINCREASEMENT)*sizeof(ElemType));
		if(!temp) return OVERFLOW;
		L.elem = temp;
		L.listsize+=LISTINCREASEMENT;   
	}	
	ElemType *p,*q;
	q = &(L.elem[i-1]);  //需要插入元素的位置
	for(p = &(L.elem[L.len-1]);p>=q;p--) *(p+1) = *p; //元素从后往前依次后移 
 	*q = e;				//赋值 
 	L.len++;            //表长加1 
 	
 	return OK;
	
} 
//3.删除元素
/*
1、按下标 int DeleteElemByIndex(SqList &L,int i,ElemType &e) 

2、按值   int DeleteElemByValue(SqList &L,ElemType value) 
*/
int DeleteElemByIndex(SqList &L,int i,ElemType &e)
{
	if( i<1 || i>L.len) return ERROR;
	ElemType *p;
	p = &(L.elem[i-1]);
	e = *p;
	for(;p<= &(L.elem[L.len-1]);p++) *p = *(p+1);
	cout<<"删除成功!"<<endl;
	L.len--;
	return OK;
} 


int DeleteElemByValue(SqList &L,ElemType value)
{
    for(int i =0; i < L.length - 1; i++)
    {
        if(L.elem[i] == value)
        {
            ElemType *p ,*q;
            q = &L.elem[i];
            for( p=&(L.elem[L.length-1]);q<=p;++q) *q = *(q+1);
           
            L.length--;
            return OK;
        }
        else
        {
            printf("找不到该元素\n");
            return ERROR;
         }
    }
}

 /*4.合并表 ElemType CombineList1(SqList &L1,SqList &L2) 
 			ElemType CombineList(SqList &L1,SqList &L2)
 */ 
 //方式1.全部塞进一个大的链表后对链表进行排序 此算法复杂度为O(L1.len+L2.len) 
 ElemType* CombineList1(SqList  &L1,SqList  &L2)
{
   //bubbleSort(L1);
    //showElem(L1.elem,L1.length);
   // bubbleSort(L2);
    //showElem(L2.elem,L2.length);
    SqList L;
    L.length = L1.length+L2.length;
    L.elem = (ElemType*)malloc(L.length*sizeof(ElemType));
    for(int i=0;i<L1.length;i++)
    {
        L.elem[i] = L1.elem[i];
    }  
    int i=0;
    for(int j = L1.length ;j<L.length&&i<L2.length ;j++ )
    {
        L.elem[j] = L2.elem[i];
        i++;
    }
    bubbleSort(L);
    return L.elem;
}
//方式2. 按大小放进一个
 SqList CombineList(SqList &La,SqList &Lb)
 {
 	ElemType *pa,*pb,*pc,*pa_last,*pb_last;
 	bubbleSort(La);
 	bubbleSort(Lb);
 	SqList Lc;
 	Lc.listsize = Lc.len = La.len + Lb.len;
 	pc=Lc.elem = (ElemType *)malloc(Lc.listsize*sizeof(ElemType));
 	if(!pc) return OVERFLOW;
 	pa = La.elem;     pa_last = La.elem + La.len - 1;
 	pb = Lb.elem;	  pb_last = Lb.elem + Lb.len - 1;
 	while(pa<=pa_last && pb<=pb_last)
 	{
	 	if(*pa<=*pb) {*pc++ = *pa++;}
	 	else {*pc++ = *pb++	}
 	}
 	while(pa<pa_last) *pc++ = *pa++;
 	while(pb<pb_last) *pc++ = *pb++;
 	
 	return Lc;
 } 

