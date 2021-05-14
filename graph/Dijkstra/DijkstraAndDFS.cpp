/*
 * @Descripttion: 改进路径存储数组的存储方式
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-03-31 19:46:28
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-14 15:00:42
 */
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

//最大顶点数
const int MAXV = 1000;
//设置无穷大 表示两点没有连接
const int INF = 1000000000;
//顶点数量 路径矩阵 起点
int n, G[MAXV][MAXV], st;
//起点到各点的最短路径长度 记录题目中添加的额外边权代价信息 从题目中获取
int dis[MAXV], cost[MAXV][MAXV], weight[MAXV];
//标记数组 vis=true表示已访问
bool vis[MAXV] = {false};
//表示从起点到顶点v的最短路径上v的前一个顶点
vector<int> pre[MAXV];

/**
 * @Descripttion: 连接矩阵实现
 * @param {int} s
 * @return {*}
 */
void Dijkstra(int s)
{
  //fill函数将整个d数组赋为INF
  fill(dis, dis + MAXV, INF);
  dis[s] = 0;
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
          pre[v].clear();
          pre[v].push_back(u);
        }
        else if (dis[v] == G[u][v] + dis[u])
        {
          pre[v].push_back(u);
        }
      }
    }
  }
}
//最优路径和临时路径
vector<int> path, tempPath;
//第二标尺最优值
int optValue;
/**
 * @Descripttion: 输出路径
 * @param {int} v 当前访问的结点
 * @return {*}
 */
void DFS(int v)
{
  //递归边界
  if (v == st) //到达了叶子结点
  {
    tempPath.push_back(v);
    int value;
    //此处添加计算第二标尺的value值
    //边权
    for (int i = tempPath.size() - 1; i > 0; i--)
    {
      //当前结点id 下一结点idNext
      int id = tempPath[i], idNext = tempPath[i - 1];
      value += cost[id][idNext];
    }
    //点权
    for (int i = tempPath.size() - 1; i >= 0; i--)
    {
      //当前结点id 下一结点idNext
      int id = tempPath[i];
      value += weight[id];
    }
    if (value < optValue)
    {
      optValue = value;
      path = tempPath;
    }
    //将刚加入的结点删除
    tempPath.pop_back();
    return;
  }
  //递归式
  tempPath.push_back(v);
  for (int i = 0; i < pre[v].size(); i++)
  {
    //结点v的前驱结点pre[v][i] 递归
    DFS(pre[v][i]);
  }

  //遍历完所有结点 删除v
  tempPath.pop_back();
}