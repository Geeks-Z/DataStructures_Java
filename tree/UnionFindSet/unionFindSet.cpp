/*
 * @Descripttion: ���鼯
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-03-25 21:29:30
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-03-26 09:24:41
 */
#include <stdio.h>

const int maxn = 100;
int father[maxn] = {-1};

int findFather(int val)
{
  while (val != father[val])
  {
    val = father[val];
  }

  return val;
}

void unionSet(int a, int b)
{
  int faA = findFather(a);
  int faB = findFather(b);
  if (faA != faB)
  {
    //�ϲ� ��һ�����ϵĸ����ĸ��������Ϊ��һ�������
    father[faA] = faB;
  }
}

//·��ѹ��
void  compressPath(int x){
	//��Ϊx���ջ��ɸ��ڵ� �����ȱ���x��ֵ
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	
}

int main()
{
  return 0;
}
