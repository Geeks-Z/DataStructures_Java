/*
 * @Descripttion: 邻接矩阵实现最小生成树
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-04-01 21:22:24
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-18 15:38:05
 */

#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
const int INF = 100000000;

int n, G[MAXN][MAXN];
//顶点与集合的最短距离
int dis[MAXN];
//标记是否被加入到集合中
bool vis[MAXN];

/**
 * @Descripttion: 默认0号位初始点
 * @param {*}
 * @return {*} 最小生成树的边权之和
 */
int prim()
{
  fill(dis, dis + MAXN, INF);
  dis[0] = 0;
  //存放最小生成树的边权之和
  int ans = 0;
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
      return;
    }
    vis[u] = true;
    //将与集合最小的边加入最小生成树
    ans += dis[u];
    for (int v = 0; v < n; v++)
    {
      if (vis[v] == false && G[u][v] != INF && dis[v] > G[u][v])
      {
        //与Dijkstra相比 不是到起点的距离 而是到集合的距离
        dis[v] = G[u][v];
      }
    }
  }
}
