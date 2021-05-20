/*
 * @Descripttion: 二叉树的遍历
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-03-16 11:45:59
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-20 21:31:17
 */
#include <stdio.h>
#include <queue>
using namespace std;

struct node
{
  int data;
  //层数--层序遍历时使用
  int layer;
  node *lchild;
  node *rchild;
};

/**
 * @Descripttion: 二叉树先序遍历 
 * @param {node} *root
 * @return {*}
 */
void preOrder(node *root)
{
  if (root == NULL) //到达空树，递归边界
  {
    return;
  }
  printf("%d\n", root->data);
  //访问左子树
  preOrder(root->lchild);
  //访问右子树
  preOrder(root->rchild);
}

/**
 * @Descripttion: 二叉树中序遍历 
 * @param {node} *root
 * @return {*}
 */
void inOrder(node *root)
{
  if (root == NULL) //到达空树，递归边界
  {
    return;
  }
  //访问左子树
  preOrder(root->lchild);
  //访问根结点
  printf("%d\n", root->data);
  //访问右子树
  preOrder(root->rchild);
}

/**
 * @Descripttion: 二叉树后序遍历 
 * @param {node} *root
 * @return {*}
 */
void postOrder(node *root)
{
  if (root == NULL) //到达空树，递归边界
  {
    return;
  }
  //访问左子树
  preOrder(root->lchild);
  //访问右子树
  preOrder(root->rchild);
  //访问根结点
  printf("%d\n", root->data);
}

void layerOrder(node *root)
{
  //队列里存放地址-->实现对原元素的修改
  queue<node *> q;
  root->layer = 1;
  q.push(root);
  while (!q.empty())
  {
    //取出队首元素
    node *temp = q.front();
    printf("%d", temp->data);
    q.pop();
    //左子树非空
    if (temp->lchild)
    {
      temp->lchild->layer = temp->layer + 1;
      q.push(temp->lchild);
    }
    //右子树非空
    if (temp->rchild)
    {
      temp->rchild->layer = temp->layer + 1;
      q.push(temp->rchild);
    }
  }
}
