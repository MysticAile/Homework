/**
֪ʶ�㣺
˫����  ÿ���ڵ㶼��ǰ��ָ���� ͨ�����洢�ܶȵ��ڵ�����
ѭ������  
���������ѭ�����ҹ���һ����  
˫�������ѭ�����ҿ���ͨ��ͷ�ڵ�����ҵ�β�ڵ�ɾ��β�ڵ㡢��β�ڵ�ǰ�����һ���ڵ��ʱ���ΪO(1)��
�ص㣺��֪ĳ���ڵ�ĵ�ַ��ɾ������ʱ��ΪO(1)����ĳ���ڵ��ǰ�������һ���ڵ��ʱ��ΪO(1)��
�����
�������Կ�������㷨��Ч��
eg:����һ����������˳���洢�����һ����Ч�㷨ɾ���ظ���Ԫ�ء�
���磺L=(1��1��1��2��2��3) 
�𰸣�
L=(1��2��3)
**/
void deldupnode1(SqList **L)
{
    int k = 1, i; //k��¼������Ԫ�ظ���
    for (i = 1; i < L->length; i++)
        if (L->data[i] != L->data[i - 1])
        {
            L->data[k] = L->data[i];
            k++; //������Ԫ����1
        }
    L->length = k; //˳���L�ĳ��ȵ���k
}
/**
��·�鲢��˼·���Ч��
�������������������õ�����ha��hc�洢������ͬһ��������
�в������ظ���Ԫ�أ������һ����Ч�㷨�����ǵĹ���Ԫ�أ�
���������ڵ�����hc�С�
ha=(1��2��3)��hb=(2��3��4) 
hc=(2��3)
**/
//˼·:��·�鲢��β�巨
void InterSect(LinkList *ha��LinkList *hb��LinkList *&hc)
{
    LinkList *pa = ha->next�� *pb = pb->next�� * s�� * r;
    hc = (LinkNode *)malloc(sizeof(LinkNode));
    r = hc; //rָ��β�ڵ�
    while (pa != NULL && pb != NULL)
    {
        if (pa->data < pb->data)
            pa = pa->next;
        if (pa->data > pb->data)
            pb = pb->next;
        if (pa->data == pb->data) //��ͬԪ��
        {
            s = (LinkNode *)malloc(sizeof(LinkNode)); //���ƽڵ�
            s->data = pa->data;
            r->next = s;
            r = s;
            pa = pa->next;
            pb = pb->next;
        }
    }
    r->next = NULL;
}