/**
eg:��Ʋ���ͷ���ĵ�����ݹ��㷨
1.�������е����ݽڵĸ���
��F(L)Ϊ���������ݽڵ��еĸ���
���������Ϊ0
���ڷǿյ�����
F(L)=F(L->next)+1
2.
������ʾ���нڵ��ֵ
����F��L->next)�Ѿ����
F(L)->F(L->next);���L->data;
3.������ʾ���нڵ��ֵ
**/
int count(Node *L)
{
    if (L == NULL)
        return 0;
    else
        return count(L->next) + 1;
}

void traverse(Node *L)
{
    if (L == NULL)
        return;
    printf("%d", L->data);
    traverse(L->next);
}

void traverseR(Node *L)
{
    if (L == NULL)
        return;
    traverseR(L->next);
    printf("%d", L->data);
}