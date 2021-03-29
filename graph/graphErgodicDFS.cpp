/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-03-26 11:54:34
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-03-29 21:17:36
 */
#include <stdio.h>
#include <vector>
using namespace std;

//最大顶点数
const int MAXN = 1000;
//无穷大 表示不能到达
const int INF = 1000000000;
int n;

//图G的邻接表
vector<int> Adj[MAXN];
//如果顶点i已被访问 则vis[i] = true
bool vis[MAXN] = {false};

//u为当前访问的顶点标号 depth为深度
void DFS(int u, int depth)
{
	vis[u] = true;
	//需要对u进行一些操作 可在此处处理
	for (int i = 0; i < Adj[u].size(); i++)
	{
		int v = Adj[u][i];
		if (vis[v] == false)
		{
			DFS(v, depth + 1);
		}
	}
}

//遍历图G
void DFSTrave()
{
	//对每个顶点u
	for (int u = 0; u < n; u++)
	{
		//如果u未被访问
		if (vis[u] == false)
		{
			//访问u和u所在的连通块 1表示初始为第一层
			DFS(u, 1);
		}
	}
}
