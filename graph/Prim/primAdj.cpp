/*
 * @Descripttion: prim邻接表实现
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-18 15:42:51
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-18 15:59:10
 */
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 100;
const int INF = 100000;
bool vis[MAXN] = {false};
int ans, n, dis[MAXN];

struct node
{
  int v, d;
};
vector<node> Adj[MAXN];
int prime()
{
  //默认0号为顶点
  dis[0] = 0;
  fill(dis, dis + MAXN, INF);
  //n个顶点 循环n次
  for (int i = 0; i < n; i++)
  {
    int u = -1, min = INF;
    for (int j = 0; j < n; j++)
    {
      if (vis[j] == false && dis[j] < min)
      {
        u = j;
        min = dis[j];
      }
    }
    if (u == -1)
    {
      return -1;
    }
    ans += dis[u];
    vis[u] = true;
    for (int j = 0; j < Adj[u].size(); j++)
    {
      int v = Adj[u][j].v;
      if (vis[v] == false && Adj[u][j].d < dis[v])
      {
        dis[v] = Adj[u][j].d;
      }
    }
  }
  return ans;
}

int main()
{
  freopen("input.txt", "r", stdin);

  return 0;
}