/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-03-29 20:48:40
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-03-29 21:55:13
 */
#include <stdio.h>
#include <queue>

using namespace std;

struct node
{
  //顶点的编号
  int v;
  //顶点层号
  int layer;
};
//最大顶点数
const int MAXN = 1000;
//无穷大 表示不能到达
const int INF = 1000000000;
//顶点数
int n;
//图的邻接矩阵
int G[MAXN][MAXN];
//图的邻接表
vector<int> Adj[MAXN];
vector<node> AdjN[MAXN];

//如果顶点i已被访问 则inq[i] = true
bool inq[MAXN] = {false};

//图的遍历-邻接矩阵
void BFS(int u)
{
  queue<int> q;
  q.push(u);
  //设置u已被加入过队列
  inq[u] = true;
  while (!q.empty())
  {
    int u = q.front();
    //枚举u的所有相邻结点
    for (int v = 0; v < n; v++)
    {
      //如果u的领结点v未加入队列且通过u可达
      if (inq[v] == false && G[u][v] != INF)
      {
        q.push(v);
        inq[v] = true;
      }
    }
  }
}

//图的遍历-邻接表
void BFS(int u)
{
  queue<int> q;
  q.push(u);
  inq[u] = true;
  while (!q.empty())
  {
    q.front();
    for (int i = 0; i < Adj[u].size(); i++)
    {
      if (inq[Adj[u][i]] == false)
      {
        q.push(Adj[u][i]);
        inq[Adj[u][i]] = true;
      }
    }
  }
}

//考虑层号的输出
void BFS(int s)
{
  queue<node> q;
  node start;
  start.v = s;
  start.layer = 0;
  q.push(start);
  inq[start.v] = true;
  while (!q.empty())
  {
    //取出队首元素
    node topNode = q.front();
    q.pop();
    int u = topNode.v;
    for (int i = 0; i < Adj[u].size(); i++)
    {

      node next = AdjN[u][i];
      next.layer = topNode.layer + 1;
      if (inq[next.v] == false)
      {
        q.push(next);
        inq[next.v] = true;
      }
    }
  }
}

void BFSTrave()
{
  for (int u = 0; u < n; u++)
  {
    if (inq[u] == false)
    {
      BFS(u);
    }
  }
}