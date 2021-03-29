/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-03-28 19:56:40
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-03-29 20:55:37
 */
#include <stdio.h>
#include <string>
#include <map>

using namespace std;
//题目中最多有1000条通话记录 所以最多有2000人
const int maxn = 2000;
//无穷大
const int INF = 10000000;

struct Gang
{
  string head;
  int numMember;
} arrayGang[maxn];

//编号 姓名
map<int, string> int2String;
//姓名 编号
map<string, int> string2int;
// head 人数
map<string, int> Gang;

//邻接矩阵G
int G[maxn][maxn] = {0};
//点权
int weight[maxn] = {0};

//边数n 下限k 总人数numPerson
int n, k, numPerson;
//标记是否被访问
bool vis[maxn] = {false};

//DFS函数访问当个连通块 nowVisit为当前访问的编号
//head为头目 numMember为成员编号 totalValue为连通块的总边权
void DFS(int nowVisit, int &head, int &numMember, int &totalValue)
{
}