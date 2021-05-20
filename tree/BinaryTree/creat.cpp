/*
 * @Descripttion: 根据中序序列 + 先序（后序、层序）构建二叉树 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-03-16 15:23:03
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-03-18 08:50:25
 */
#include <stdio.h>
#include <stdlib.h>

const int maxn = 100;
struct node
{
  int data;
  node *lchild;
  node *rchild;
};

int pre[maxn];
int in[maxn];

node *creat(int preL, int preR, int inL, int inR)
{
  //递归边界 当前序序列为空
  if (preL > preR)
  {
    return NULL;
  }
  //根据先序序列确定根结点
  node *root = new node;
  root->data = pre[preL];

  int k;
  //根据中序序列找到根结点 -->确定左子树个数
  for (k = inL; k <= inR; k++)
  {
    if (in[k] == pre[preL])
      break;
  }

  //左子树个数
  int numLeft = k - inL;

  //左子树先序序列区间为[preL + 1, preL + numLeft]
  //中序序列区间为 [inL, k-1]
  root->lchild = creat(preL + 1, preL + numLeft, inL, k - 1);
  //右子树先序序列区间为[preL + numLeft + 1, preR]
  //中序序列区间为 [k + 1, inR]
  root->rchild = creat(preL + numLeft + 1, preR, k + 1, inR);

  return root;
}