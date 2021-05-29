/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-04-01 15:26:55
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-04-01 15:50:49
 */
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

const int MAXN = 510;
const int INF = 0xfffffff;
struct Node
{
  int v, w;
  //构造函数
  Node(int _v, int _w) : v(_v), w(_w) {}
};

vector<Node> Adj[MAXN];
//顶点数 边数 起点 终点 点权
int n, m, st, ed, weight[MAXN];
//最短距离 最大点权之和 最短路径条数
int dis[MAXN], wMax[MAXN], num[MAXN];
//顶点是否在队列中
bool inq[MAXN];
bool SPFA(int s)
{
  //初始化
  memset(inq, false, sizeof(inq));
  memset(num, 0, sizeof(num));
  fill(dis, dis + MAXN, INF);
  //源点入队
  queue<int> q;
  q.push(s);
  inq[s] = true;
  num[s]++;
  dis[s] = 0;
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    inq[u] = false;
    //遍历u的所有邻接边
    for (int j = 0; j < n; j++)
    {
      //邻接边的顶点
      int v = Adj[u][j].v;
      int w = Adj[u][j].w;
      //松弛操作
      if (dis[u] + w < dis[v])
      {
        dis[v] = dis[u] + w;
        if (!inq[v])
        {
          q.push(v);
          inq[v] = true;
          num[v]++;
          if (num[v] >= n)
          {
            return false; //有可达负环
          }
        }
      }
    }
  }
  return true; //无可达负环
}