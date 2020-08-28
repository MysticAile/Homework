/*��̬����Ĵ*/
//��̬���������Խ�����ڴ�ŵ�����  capacity
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct DYNAMICARRY
{
    int *PAddr;   //������ݵĵ�ַ
    int size;     //��ǰԪ��
    int capacity; //����
} Dynamic_Array;
//��ʼ��

Dynamic_Array *Init_Arry();
int At_Array(Dynamic_Array *arr, int pos);
int Size_Array(Dynamic_Array *arr);
int Capacity_Array(Dynamic_Array *arr);
void Clear_Array(Dynamic_Array *arr);
void FreeSpace_Array(Dynamic_Array *arr);
void Print_Array(Dynamic_Array *arr);
int Find_Array(Dynamic_Array *arr, int value);
void RemoveByvalue_Array(Dynamic_Array *arr, int value);
void PushBack_Array(Dynamic_Array *arr, int value);
void RemoveByPos_Array(Dynamic_Array *arr, int pos);
Dynamic_Array *Init_Arry();
int main()
{
    //��ʼ����̬����
    Dynamic_Array *myArray = Init_Arry();
    //��ӡ����
    printf("���������:%d\n", Capacity_Array(myArray));
    printf("����Ĵ�С:%d\n", Size_Array(myArray));
    //����Ԫ��
    for (int i = 0; i < 30; i++)
    {
        PushBack_Array(myArray, i);
    }
    printf("���������:%d\n", Capacity_Array(myArray));
    printf("����Ĵ�С:%d\n", Size_Array(myArray));
    //��ӡ
    Print_Array(myArray);
    //ɾ��
    RemoveByPos_Array(myArray, 0);
    RemoveByvalue_Array(myArray, 27);
    //��ӡ
    Print_Array(myArray);
    //����
    int pos = Find_Array(myArray, 5);
    printf("λ��5�鵽:%d %d\n ", pos, At_Array(myArray, pos));
    //����
    FreeSpace_Array(myArray);
}
Dynamic_Array *Init_Arry()
{
    Dynamic_Array *myArray = (Dynamic_Array *)malloc(sizeof(Dynamic_Array));
    myArray->size = 0;
    myArray->capacity = 20;
    myArray->PAddr = (int *)malloc(sizeof(int) * myArray->capacity);
    return myArray;
}
//����
void PushBack_Array(Dynamic_Array *arr, int value)
{
    if (arr == NULL)
        return;
    //�жϿռ��Ƿ��㹻
    if (arr->size == arr->capacity)
    {
        //����һ�������ڴ�ռ� �¿ռ�Ĭ���Ǿɿռ�2��
        int *newSpace = (int *)malloc(sizeof(int) * arr->capacity * 2);
        //�ڶ����������ݵ��¿ռ�
        memcpy(newSpace, arr->PAddr, arr->capacity * sizeof(int));
        //�ͷžɿռ���ڴ�
        free(arr->PAddr);
        //��������
        arr->capacity = arr->capacity * 2;
        arr->PAddr = newSpace;
    }
    //������Ԫ��
    arr->PAddr[arr->size] = value;
    arr->size++;
}
//����λ��ɾ��
void RemoveByPos_Array(Dynamic_Array *arr, int pos)
{
    if (arr == NULL)
        return;
    //�ж�λ���Ƿ���Ч
    if (pos < 0 || pos >= arr->size)
        return;
    //ɾ��Ԫ��
    for (int i = pos; i < arr->size - 1; i++)
        arr->PAddr[i] = arr->PAddr[i + 1];
    arr->size--;
}
//����ֵɾ��
void RemoveByvalue_Array(Dynamic_Array *arr, int value)
{
    if (arr == NULL)
        return;
    //�ҵ�ֵ��λ��

    int pos = Find_Array(arr, value);

    RemoveByPos_Array(arr, pos);
}
//����
int Find_Array(Dynamic_Array *arr, int value)
{
    if (arr == NULL)
        return -1;
    //����
    //�ҵ�ֵ��λ��
    int pos = -1;
    for (int i = 0; i < arr->size; i++)
    {
        if (arr->PAddr[i] == value)
        {
            pos = i;
            break;
        }
    }
    return pos;
}
//��ӡ
void Print_Array(Dynamic_Array *arr)
{
    if (arr == NULL)
        return;
    for (int i = 0; i < arr->size; i++)
        printf("%d ", arr->PAddr[i]);
    printf("\n");
}
//�ͷŶ�̬������ڴ�
void FreeSpace_Array(Dynamic_Array *arr)
{
    if (arr == NULL)
        return;
    if (arr->PAddr != NULL)
        free(arr->PAddr);
    free(arr);
}
//�������
void Clear_Array(Dynamic_Array *arr)
{
    if (arr == NULL)
        return;
    //pAddr->�ռ�
    arr->size = 0;
}
//��ö�̬��������
int Capacity_Array(Dynamic_Array *arr)
{
    if (arr == NULL)
        return -1;
    return arr->capacity;
}
//��ö�̬����ĵ�ǰԪ�صĸ���
int Size_Array(Dynamic_Array *arr)
{
    if (arr == NULL)
        return -1;
    return arr->size;
}
//����λ�û��ĳ��Ԫ��
int At_Array(Dynamic_Array *arr, int pos)
{
    return arr->PAddr[pos];
}