/**
 * 1��ʲô�������
��ν�������ָ���������Ա���������Ԫ���Ե������ ����ʽ�������С�
����� ���� ���Ա�
Ϊ�˼򵥣����������Ԫ�����Ե�����ʽ���С�
���п��������������Ա���Ԫ��֮����߼���ϵ��ͬ����
����������ʵ�ֵĲ�ͬ��
��Ȼ�������Ԫ���߼���ϵ�����Ա����ͬ���������Բ�
�������Ա���ͬ�Ĵ洢�ṹ��
����˳���洢������ᷢ�ֻ��������㷨��ֻ��ListInsert()
�㷨��ǰ���˳����Ӧ�������������죬���඼����ͬ�ġ�����˳
����ListInsert()�㷨���£�
**/
//���Ա�
void LinkInsert(SqList **L,int e)
{
    int i=0,j;
    while(i<L->length&&L->data[i]<e)
    i++;  //����λ��
    for(j=ListLength(L);j>i;i--)
    {
        L->data[j]=L->data[j-1];
    }
    L->data[i]=e;
    L->length++;           //������ȼ�1
}
//������
void ListInsert(LinkList **L,int e)
{
    LinkList *pre=L,*p;
    while (pre->next!=NULL&&pre->next->data<e)
    {
        pre=pre->next;//���Ҳ����ǰ���ڵ�
    }
    p=(LinkList *)malloc(sizeof(LinkList));
    p->data=e;
    p->next=pre->next;//��pre�ڵ�����p�ڵ�
    pre->next=p;
}