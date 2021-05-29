/*
 * @Descripttion: 拓扑排序
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-04-02 08:32:18
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-29 22:12:38
 */
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
const int MAXV = 1000;

vector<int> G[MAXV];

//顶点数 入度
int n, m, inDegree[MAXV];

//拓扑排序
bool topologicalSort()
{
  //记录加入拓扑序列的顶点数
  int num = 0;
  queue<int> q;
  for (int i = 0; i < n; i++)
  {
    //将所有入度为0的顶点入队
    if (inDegree[i] == 0)
    {
      q.push(i);
    }
  }
  while (!q.empty())
  {
    int u = q.front();
    //此处可以输出顶点u 作为拓扑序列中的顶点
    // printf("%d", u);
    q.pop();
    for (int i = 0; i < G[u].size(); i++)
    {
      int v = G[u][i];
      //顶点v的入度减1
      inDegree[v]--;
      if (inDegree[v] == 0)
      {
        q.push(v);
      }
    }
    //清空顶点u的出边(如无必要可不写)
    G[u].clear();
    num++;
  }

  if (num == n)
  {
    return true;
  }
  else
  {
    return false;
  }
}