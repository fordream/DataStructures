//���Ա��˳���ʾ��ʵ�� 

# include<iostream>

using namespace std;

#define LIST_INIT_SIZE 100
#define LISTINCREASEMENT 10 
#define OVERFLOW -1
#define OK 1
#define ERROR -2

typedef double ElemType;  //����ElemType����Ϊdouble 

typedef struct{
	ElemType *elem;      
	int len;               //���Ա�ĳ��� 
	int listsize;		   //���Ա�ռ��С 
}SqList;                     //���Ա�ṹ 



/*
��Ҫʵ�ֵĹ���
1.��ʼ��
2.����Ԫ��
3.ɾ��Ԫ��  ��ֵɾ��  ���±�ɾ�� 
4.�ϲ��� 
*/ 

//*******************��������******************************
//���չ̶���ʽ��ӡ����
void showElem(ElemType arr[], int length)
{
    printf("Elem:[");
    for(int i=0; i<length-2;i++)
        printf("%d,",arr[i] );                  
        //��C���Ե�  һ���ܴ�Ĳ��㣬 %d  ֻ�е���ElemType��intʱ����
    printf("%d]\n",arr[length-1] );

}

//��������Ԫ��λ��

void swap(ElemType arr[],int i,int j)
{
    ElemType temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] =temp;

}

//ð������
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
//*******************��������******************************

//1.��ʼ��  int InitList_Sq(SqList &L)
int InitList_Sq(SqList &L)
{
	 	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	 	if(!L.elem) return OVERFLOW;
	 	
	 	L.len = 0;
	 	L.listsize = LIST_INIT_SIZE;
	 	return OK;
}

//2.����Ԫ�� int InsertList_Sq(SqList &L,int i,ElemType e);
int InsertList_Sq(SqList &L,int i,ElemType e)
{
	//LΪ��Ҫ����Ԫ�صı� ��iΪ�����ڵ�i��Ԫ��֮ǰ��eΪ��Ҫ�����Ԫ��
	//���ȼ��i�ĺϷ���
	if( i<1 || i>L.len )return ERROR;
	//�ټ��list�ռ��Ƿ�  ��������� 
	if(L.len>=L.listsize)
	{
		ElemType *temp;
		temp = (ElemType *)realloc(L.elem,(LIST_INIT_SIZE+LISTINCREASEMENT)*sizeof(ElemType));
		if(!temp) return OVERFLOW;
		L.elem = temp;
		L.listsize+=LISTINCREASEMENT;   
	}	
	ElemType *p,*q;
	q = &(L.elem[i-1]);  //��Ҫ����Ԫ�ص�λ��
	for(p = &(L.elem[L.len-1]);p>=q;p--) *(p+1) = *p; //Ԫ�شӺ���ǰ���κ��� 
 	*q = e;				//��ֵ 
 	L.len++;            //����1 
 	
 	return OK;
	
} 
//3.ɾ��Ԫ��
/*
1�����±� int DeleteElemByIndex(SqList &L,int i,ElemType &e) 

2����ֵ   int DeleteElemByValue(SqList &L,ElemType value) 
*/
int DeleteElemByIndex(SqList &L,int i,ElemType &e)
{
	if( i<1 || i>L.len) return ERROR;
	ElemType *p;
	p = &(L.elem[i-1]);
	e = *p;
	for(;p<= &(L.elem[L.len-1]);p++) *p = *(p+1);
	cout<<"ɾ���ɹ�!"<<endl;
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
            printf("�Ҳ�����Ԫ��\n");
            return ERROR;
         }
    }
}

 /*4.�ϲ��� ElemType CombineList1(SqList &L1,SqList &L2) 
 			ElemType CombineList(SqList &L1,SqList &L2)
 */ 
 //��ʽ1.ȫ������һ���������������������� ���㷨���Ӷ�ΪO(L1.len+L2.len) 
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
//��ʽ2. ����С�Ž�һ��
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

