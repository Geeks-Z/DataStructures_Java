/*
 * @Descripttion: 并查集
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
    //合并 将一个集合的根结点的父结点设置为另一个根结点
    father[faA] = faB;
  }
}

//路径压缩
void  compressPath(int x){
	//因为x最终会变成根节点 所以先保存x的值
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
