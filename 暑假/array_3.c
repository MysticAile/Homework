/**
��Ŀ:
��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
����
�������飺
[
  [1,2,8,9]��
  [2,4,9,12]��
  [4,7,10,13]��
  [6,8,11,15]
]
������������ֵΪ7���򷵻�true��
������������ֵΪ5���򷵻�false��
˼·:
���������ά����Ĺ���:ÿ�������ұߵ����ÿ�������²������
�������Ϸ���ʼɨ��
����ǰ��ֵ���õ���target������true
����ǰֵС��target����˵����ǰλ����������С��target���к�i++
����ǰֵ����target����˵����ǰ���·�����������target���к�j--;
ֱ���������·���û���ҵ�target���򷵻�false
**/
bool searchArray(int **array, int arrayRowSize, int arrayColSize, int target)
{
  int i = 0;
  int j = arrayColSize - 1;
  while (i < arrayRowSize && j >= 0)
  {
    if (array[i][j] == target)
      return true;
    else if (array[i][j] < target)
      i++;
    else
      j--;
  }
  return false;
}