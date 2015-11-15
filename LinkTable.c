#include <stdlib.h>
#include <stdio.h>

#define LIST_INIT_SIZE 100     //线性表初始长度
#define LISTINCREMENT 10       //线性表每次增加的长度

typedef  int  ElemType ;        //定义ElemType 类型

typedef struct SqList
{
    ElemType *elem;
    int length;
    int listsize;
}*QLink;               //定义结构体   SqList和指针QLink


//主体功能 
int InitList_Sq(SqList &L);                        //初始化 
int AddElem(SqList &L,int k,ElemType value);       //添加元素
int DeleteByValue(SqList &L,ElemType value);       //按值删除元素 
int DeleteByKey(SqList &L,int k);                  //按角表删除元素
ElemType* ToOneList(SqList  &L1,SqList  &L2); //合并两个表 



//辅助函数 
void swap(ElemType arr[],int i,int j); 
void showElem(ElemType arr[], int length);
void bubbleSort(SqList &L); 

int main()
{
    
    SqList L1,L2;
    InitList_Sq(L1);
    InitList_Sq(L2);
    L1.elem[0] = 10; L1.length++;
    L1.elem[1] = -8; L1.length++;
    L1.elem[2] = 32; L1.length++;
    L1.elem[3] = 25; L1.length++;
    L1.elem[4] = 7 ; L1.length++;
    L1.elem[5] = -37; L1.length++;
    L1.elem[6] = 0;  L1.length++;
    L1.elem[7] = 20; L1.length++;
    L1.elem[8] = 56; L1.length++;               
    //运用的时候修改了一下LIST_INIT_SIZE,让它小于9，因为我这里定义了 9个数 ，然后就报错了，有意思 
    
    printf("原始列表：\n");
    showElem(L1.elem,L1.length);
    printf("在第三个元素前添加元素12：\n");
    AddElem(L1,3,12) ;
    showElem(L1.elem,L1.length);
    printf("删除元素37：\n");
    DeleteByValue(L1,-37);
    showElem(L1.elem,L1.length);
    printf("删除角表为5的元素：\n");
    DeleteByKey(L1,5); 
    showElem(L1.elem,L1.length);
    
    
    L2.elem[0] = 52; L2.length++;
    L2.elem[1] = -16; L2.length++;
    L2.elem[2] = 35; L2.length++;
    L2.elem[3] = -5; L2.length++;
    L2.elem[4] = 7 ; L2.length++;
    L2.elem[5] = 37; L2.length++;
    L2.elem[6] = 99;  L2.length++;
                        
    ElemType *L;
    L = ToOneList(L1,L2);
    printf("L1+L2:");
    showElem(L,L1.length+L2.length);
} 

 /*
 初始化 InitList_Sq(SqList *L)   
 首先考虑需不需要参数，我需要初始化三个量，第一个要分配内存，地址的传递，那么需要返回，
 如果内存分配失败，那么也要返回，所以我需要参数，而且能改变实参的值，所以定义一个引用
  */ 
int InitList_Sq(SqList &L)
{
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof (ElemType));  //分配内存
    if(!L.elem) exit(0);                                              //分配失败返回
    L.length = 0;                                                     //数组元素个数
    L.listsize = LIST_INIT_SIZE;                                      //数组长度

    return 0;
}

/*
添加元素 AddElem()
考虑函数参数，需要数组，元素添加在哪个元素前，元素值，所以有三个参数
AddElem(SqList &L,int k, ElemType value)

考虑添加的时候有哪些注意点：
1.首先添加的位置是否合法 即    k<1 || k>L.length+1
2.如果数组已经满了 ，即 L.length == L.listsize ,
   那么需要再给数组增加空间  remalloc 检测是否分配成功
3.填加元素，则后面的元素依次后移

 */
 

int AddElem(SqList &L,int k,ElemType value)
{
    if(k<1 || k>L.length+1)   exit(0);                          //添加的位置是否合法

    if(L.length >= L.listsize)
    {
        L.elem = (ElemType *)realloc(L.elem,(L.listsize + LISTINCREMENT)*sizeof(ElemType));

        if(!L.elem) exit(0);

        L.listsize  +=  LISTINCREMENT;

    }
                                                                //如果数组已经满
    for(int i = L.length-1; i>=k-1 ; i--)
        L.elem[i+1] = L.elem[i];                                
         //这里没有显性的移动指针 与Delete功能里的形成对比 

    L.elem[k-1] = value ;
    L.length++;
    return 0;
}

/*
删除元素
1.按值删除元素
函数的参数显然，从哪里删，删什么 得知有两个参数
考虑：
    找这个值，遍历，由于无序所以从头开始遍历
    如果没有，返回-1；
    有，将后面的元素依次前移一位，也就是直接覆盖要删除的元素
    同时记得length要-1 
2.按角表删除元素
函数参数考虑
角表是否合法
同1 
*/ 

int DeleteByValue(SqList &L,ElemType value)
{
    for(int i =0; i < L.length - 1; i++)
    {
        if(L.elem[i] == value)
        {
            ElemType *p ,*q;
            q = &L.elem[i];
            for( p=&(L.elem[L.length-1]);q<=p;++q) *q = *(q+1);
            
            L.length--; 
            return 0;
        }
        else 
        {
            printf("找不到该元素\n");
            return -1;
         }
    } 
} 

int DeleteByKey(SqList &L,int k)
{
    if(k<1 || k>L.length+1)   exit(0);                          //删除的位置是否合法
    
    for(int i = k; i<L.length-1 ; i++)
        L.elem[i] = L.elem[i+1]; 
        L.length--; 
}


//合并两个列表 
ElemType* ToOneList(SqList  &L1,SqList  &L2)
{
    bubbleSort(L1);
    //showElem(L1.elem,L1.length);
    bubbleSort(L2);
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