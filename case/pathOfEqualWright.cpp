/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-03-20 14:12:53
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-03-20 15:51:24
 */
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100;

struct node
{
  int data;
  //存储孩子结点
  vector<int> child;
} Node[maxn];

bool cmp(int a, int b)
{
  //按照结点数据域从大到小排序
  return Node[a].data > Node[b].data;
}
//定义结点数量 非叶子结点数量 权重之和
int nodesNum, nonLeafNodesNum, weightSum;
//记录路径
int path[maxn];
/**
 * @Descripttion: 
 * @param {int} index 当前访问的结点
 * @param {int} numNode 当前path上结点个数
 * @param {int} curWeightSumsum 当前结点权值之和
 * @return {*}
 */
void DFS(int index, int numNode, int curWeightSum)
{
  if (curWeightSum > weightSum)
    return;

  if (curWeightSum == weightSum)
  {
    if (Node[index].child.size() != 0)
      return;
    //到达了叶子结点
    for (int i = 0; i < numNode; i++)
    {
      printf("%d", Node[path[i]].data);
      if (i < numNode - 1)
        printf(" ");
      else
        printf("\n");
    }
    return;
  }
  //枚举所有子结点
  for (int i = 0; i < Node[index].child.size(); i++)
  {
    int child = Node[index].child[i];
    path[numNode] = child;
    DFS(child, numNode + 1, curWeightSum + Node[child].data);
  }
}

int main()
{

  scanf("%d%d%d", &nodesNum, &nonLeafNodesNum, &weightSum);
  //存储每个结点权重的数组
  for (int i = 0; i < nodesNum; i++)
  {
    scanf("%d", &Node[i].data);
  }

  //结点编号 子结点数量 子结点编号
  int id, childNum, childId;
  //生成二叉树
  for (int i = 0; i < nonLeafNodesNum; i++)
  {
    scanf("%d%d", &id, &childNum);
    for (int j = 0; j < childNum; j++)
    {
      scanf("%d", &childId);
      Node[id].child.push_back(childId);
    }
    sort(Node[id].child.begin(), Node[id].child.end(), cmp);
  }

  path[0] = 0;
  DFS(0, 1, Node[0].data);
  return 0;
}
