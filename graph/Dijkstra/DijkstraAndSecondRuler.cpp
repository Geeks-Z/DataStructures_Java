/*
 * @Descripttion: Dijkstra算法-基于多条最短路径时的其他准则
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-03-30 09:11:48
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-14 14:57:34
 */

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

//最大顶点数
const int MAXV = 1000;
//设置无穷大 表示两点没有连接
const int INF = 1000000000;
int n, G[MAXV][MAXV];
//起点到各点的最短路径长度
int dis[MAXV];
//标记数组 vis=true表示已访问
bool vis[MAXV] = {false};
//表示从起点到顶点v的最短路径上v的前一个顶点
int pre[MAXV];
//记录题目中添加的额外边权代价信息 从题目中获取
int cost[MAXV][MAXV];
//记录从起点到u的最小额外开销
int c[MAXV];
//记录最短路径条数
int num[MAXV] = {0};

//新增点权 从起点到u可收集的最大物资
int weight[MAXV], w[MAXV];

/**
 * @Descripttion: 连接矩阵实现
 * @param {int} s
 * @return {*}
 */
void Dijkstra(int s)
{
  //fill函数将整个d数组赋为INF
  fill(dis, dis + MAXV, INF);
  //初始额外代价信息
  fill(c, c + MAXV, INF);
  //初始状态设置每个结点的前驱结点为自身
  for (int i = 0; i < n; i++)
  {
    pre[i] = i;
  }

  c[s] = 0;
  dis[s] = 0;
  w[s] = weight[s];
  //至少有一条最短路径
  num[s] = 1;
  //n个顶点 循环n次
  for (int i = 0; i < n; i++)
  {
    //使dis[u]最小的还未被访问的顶点标号
    int u = -1;
    //存放最小的d[]
    int min = INF;
    for (int j = 0; j < n; j++)
    {
      if (vis[j] == false && dis[j] < min)
      {
        u = j;
        min = dis[j];
      }
    }
    //没有找到最小的u 说明与s均不相连
    if (u == -1)
    {
      return;
    }
    vis[u] = true;
    for (int v = 0; v < n; v++)
    {
      //如果v未被访问&& u能到达v && 以u为中介到达v距离更小
      if (vis[v] == false && G[u][v] != INF)
      {
        if (dis[v] > G[u][v] + dis[u])
        {
          //优化dis[v]
          dis[v] = G[u][v] + dis[u];
          c[v] = c[u] + cost[u][v];
          pre[v] = u;
          num[v] = num[u];
        }
        //距离相同时 看能否使c[v]更优
        else if (dis[u] + G[u][v] == dis[v] && c[v] > c[u] + cost[u][v])
        {
          c[v] = c[u] + cost[u][v];
          pre[v] = u;
          num[v] += num[u];
        }
      }
    }
  }
}

/**
 * @Descripttion: 输出路径
 * @param {int} s 起点
 * @param {int} v 终点
 * @return {*}
 */
void DFS(int s, int v)
{
  if (v == s)
  {
    printf("%d\n", s);
    return;
  }
  DFS(s, pre[v]);
  //从最深处return回来之后 输出每一层的顶点编号
  printf("%d\n", v);
}
