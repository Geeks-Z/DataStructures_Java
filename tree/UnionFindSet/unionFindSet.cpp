/*
 * @Descripttion: 并查集
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-03-25 21:29:30
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-03-25 21:43:45
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
    //合并 将一个集合的根结点的父节点设置为另一个根结点
    father[faA] = faB;
  }
}

int main()
{
  return 0;
}