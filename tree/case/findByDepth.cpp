/*
 * @Descripttion: 根据输入的树的高度输出该层结点
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-03-26 23:01:53
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-03-26 23:29:07
 */
#include <stdio.h>

struct node
{
  int data;
  //树的高度
  int depth;
  //左右子结点
  node *lchild;
  node *rchild;
};

node *insert(node *&root, int data, int depth)
{
  if (root == NULL)
  {
    node *newNode = new node;
    newNode->data = data;
    newNode->depth = depth;
    newNode->lchild = newNode->rchild = NULL;
    return;
  }
  insert(root->lchild, data, depth + 1);
  insert(root->rchild, data, depth + 1);
}

int main()
{
  int nodeNum, depth;
  scanf("%d", &nodeNum);
  for (int i = 0; i < nodeNum; i++)
  {
  }

  return 0;
}