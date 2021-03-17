/*
 * @Descripttion: 根据二叉树后序和中序遍历 打印层序遍历结果 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-03-17 21:34:57
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-03-17 22:04:49
 */

#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
//定义存储后序与中序序列的结果
const int maxn = 100;
//后序序列
int post[maxn];
//中序序列
int in[maxn];
//节点个数
int n;

struct node
{
  int data;
  node *lchild;
  node *rchild;
};

/**
 * @Descripttion: 根据后序和中序遍历结果构建二叉树 
 * @param {int} postL
 * @param {int} postR
 * @param {int} inL
 * @param {int} inR
 * @return {*}
 */
node *craet(int postL, int postR, int inL, int inR)
{
  if (postL > postR)
  {
    return NULL;
  }

  node *root = (node *)malloc(sizeof(node));
  root->data = post[postR];

  //寻找根节点在中序序列的位置
  int k;
  for (k = inL; k <= inR; k++)
  {
    if (in[k] == post[postR])
    {
      break;
    }
  }

  //左子树个数
  int leftNum = k - inL;

  //左子树
  root->lchild = craet(postL, postL + leftNum - 1, inL, k - 1);

  //右子树
  root->rchild = craet(postL + leftNum, postR - 1, k + 1, inR);

  return root;
}

//已输出节点个数
int num;
/**
 * @Descripttion: 层序遍历 
 * @param {*}
 * @return {*}
 */
void layerOrder(node *root)
{
  queue<node *> q;
  q.push(root);
  while (!q.empty())
  {
    node *top = q.front();
    q.pop();
    printf("%d", top->data);
    num++;
    if (num < n)
    {
      printf(" ");
    }
    if (top->lchild)
    {
      q.push(top->lchild);
    }
    if (top->rchild)
    {
      q.push(top->rchild);
    }
  }
}

int main()
{
  scanf("%d", &n);

  //获取后序序列结果
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &post[i]);
  }
  //获取中序序列结果
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &in[i]);
  }

  node *root = craet(0, n - 1, 0, n - 1);
  layerOrder(root);
  printf("\n");
  return 0;
}