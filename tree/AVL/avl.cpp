/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-03-25 19:53:56
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-03-25 21:03:17
 */
#include <stdio.h>
#include <algorithm>
using namespace std;
struct node
{
  int data;
  //以当前结点为根节点子树的高度
  int height;
  node *lchild, *rchild;
};

/**
 * @Descripttion: 新建一个结点 
 * @param {int} val
 * @return {*}
 */
node *newNode(int val)
{
  //申请一个node型变量的地址空间
  node *Node = new node;
  Node->data = val;
  Node->height = 1;
  Node->lchild = Node->rchild = NULL;
  return Node;
}

//获取root所在子树的当前高度
int getHeight(node *root)
{
  if (root == NULL)
    return 0;
  return root->height;
}

int getBalanceFactor(node *root)
{
  //左子树高度减去右子树高度
  return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(node *root)
{
  //当前结点的高度等于左右子树高度最大值 + 1
  root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

void search(node *root, int val)
{
  if (root == NULL)
  {
    return;
  }
  if (root->data == val)
  {
    printf("%d", root->data);
  }
  else if (root->data > val)
  {
    search(root->lchild, val);
  }
  else
  {
    search(root->rchild, val);
  }
}

void leftRotation(node *root)
{
  //定义一个结点保存根结点的右子结点
  node *newRoot = root->rchild;
  root->rchild = root->rchild->lchild;
  newRoot->lchild = root;
  //更新旋转完之后相关结点高度
  updateHeight(newRoot);
  updateHeight(root);
  //根结点指向原根结点的右子结点
  root = newRoot;
}

void rightRotation(node *root)
{
  //定义一个结点保存根结点的左子结点
  node *newRoot = root->lchild;

  root->lchild = newRoot->rchild;
  newRoot->rchild = root;
  //更新旋转完之后相关结点高度
  updateHeight(newRoot);
  updateHeight(root);
  //根结点指向原根结点的左子结点
  root = newRoot;
}

void insert(node *&root, int val)
{
  if (root == NULL)
  {
    root = newNode(val);
    return;
  }
  if (root->data > val)
  {
    insert(root->lchild, val);
    updateHeight(root);
    if (getBalanceFactor(root) == 2)
    {
      //需要右旋
      if (getBalanceFactor(root->lchild) == 1)
      {
        rightRotation(root);
      }
      else if (getBalanceFactor(root->lchild) == -1)
      { //左右旋
        leftRotation(root->lchild);
        rightRotation(root);
      }
    }
  }
  else
  {
    insert(root->rchild, val);
    updateHeight(root);
    if (getBalanceFactor(root) == -2)
    {
      if (getBalanceFactor(root->rchild) == -1)
      {
        leftRotation(root);
      }
      else if (getBalanceFactor(root->rchild) == 1)
      { //右左旋
        rightRotation(root->rchild);
        leftRotation(root);
      }
    }
  }
}

node *creat(int data[], int n)
{
  node *root = NULL; //新建空根结点root
  for (int i = 0; i < n; i++)
  {
    insert(root, data[i]);
  }
  return root;
}

int main()
{
  return 0;
}