/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-29 19:30:04
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-29 20:11:53
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int MAXV = 101;
const int INF = 0x3fffffff;
struct Node
{
  int v, dis;
  Node(int _v, int _dis)
  {
    v = _v;
    dis = _dis;
  }
};
//距离起点的最短距离 顶点数量
int d[MAXV], n, num[MAXV];
//邻接表
vector<Node> Adj[MAXV];
//前驱
set<int> pre[MAXV];

bool bellmanFord(int s)
{
  fill(d, d + MAXV, INF);
  d[s] = 0;
  for (int i = 0; i < n; i++)
  {
    //松弛每条边
    for (int u = 0; u < n; u++)
    {
      for (int j = 0; j < Adj[u].size(); j++)
      {
        int v = Adj[u][j].v;
        if (d[v] > d[u] + Adj[u][j].dis)
        {
          d[v] = d[u] + Adj[u][j].dis;
          num[v] = num[u];
          pre[v].clear();
          pre[v].insert(u);
        }
        //如果有第二评价指标
        else if (d[v] == d[u] + Adj[u][j].dis)
        {
          pre[v].insert(u);
          num[v] = 0;
          set<int>::iterator it;
          for (it = pre[v].begin(); it != pre[v].end(); it++)
          {
            num[v] += num[*it];
          }
        }
      }
    }
  }

  //判断是否存在负环
  //判断每条边
  for (int u = 0; u < n; u++)
  {
    for (int j = 0; j < Adj[u].size(); j++)
    {
      int v = Adj[u][j].v;
      //图中有负环
      if (d[v] > d[u] + Adj[u][j].dis)
      {
        return false;
      }
    }
  }
  return true;
}

int main()
{
  freopen("input.txt", "r", stdin);
  return 0;
}