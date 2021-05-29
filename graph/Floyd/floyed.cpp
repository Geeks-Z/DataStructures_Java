/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-04-01 20:17:02
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-29 20:35:08
 */
#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAXN = 200;
const int INF = 1000000000;
//顶点数 边数
int n, m;
int dis[MAXN][MAXN];

void floyed()
{
  //以顶点 k 为中介点 枚举所有顶点对 i j
  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j])
        {
          dis[i][j] = dis[i][k] + dis[k][j];
        }
      }
    }
  }
}

int main()
{
  return 0;
}