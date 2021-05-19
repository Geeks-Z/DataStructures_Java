/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-04-01 21:47:22
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-18 17:13:45
 */
#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAXN = 110;
const int MAXE = 10010;
struct edge
{
  //边的两个端点编号
  int u, v;
  //边权
  int cost;
} E[MAXE]; //最多有MAXE条边

bool cmp(edge a, edge b)
{
  return a.cost < b.cost;
}

//并查集部分
int father[MAXN];
int findFather(int x)
{
  int a = x;
  while (x != father[x])
  {
    x = father[x];
  }

  //路径压缩
  while (a != father[a])
  {
    int z = a;
    a = father[a];
    father[z] = x;
  }
  return x;
}

/**
 * @Descripttion: 
 * @param {int} n 顶点个数
 * @param {int} m 边数
 * @return {*}
 */
int kruskal(int n, int m)
{
  //边权之和 边的个数
  int ans = 0, edgeNum = 0;
  //并查集初始化--假设顶点从0开始编号
  for (int i = 0; i < n; i++)
  {
    father[i] = i;
  }
  sort(E, E + m, cmp);
  //枚举所有的边
  for (int i = 0; i < n; i++)
  {
    int faU = findFather(E[i].u);
    int faV = findFather(E[i].v);
    //不在一个集合中
    if (faU != faV)
    {
      //合并集合 即把测试边加入最小生成树
      father[faU] = faV;
      ans += E[i].cost;
      edgeNum++;
      if (edgeNum == n - 1)
        break;
    }
  }
  if (edgeNum != n - 1)
    return -1;
  else
  {
    return ans;
  }
}