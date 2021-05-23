/*
 * @Descripttion: 实现二叉查找树的基本操作
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-03-25 09:18:36
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-21 15:11:02
 */

#include <stdio.h>

struct node
{
  int data;
  node *lchild;
  node *rchild;
};

/**
 * @Descripttion: 查找算法 
 * @param {node} *root
 * @param {int} val
 * @return {*}
 */
void search(node *root, int val)
{

  if (root == NULL)
  {
    printf("failed\n");
    return;
  }
  if (root->data == val)
  {
    printf("%d", root->data);
  }
  //往右子树递归查找
  else if (root->data < val)
  {
    search(root->rchild, val);
  }
  //往左子树递归查找
  else
  {
    search(root->lchild, val);
  }
}

/**
 * @Descripttion: 插入算法
 * @param {node} *root
 * @param {int} val
 * @return {*}
 */
void insert(node *&root, int val)
{

  if (root == NULL)
  {
    node *root = new node();
    root->data = val;
    return;
  }
  if (root->data == val)
  {
    return;
  }
  //往右子树递归插入
  if (root->data < val)
  {
    insert(root->rchild, val);
  }
  else
  {
    insert(root->lchild, val);
  }
}

/**
 * @Descripttion: 寻找以root为根结点的树中的最大权值结点
 * @param {*}
 * @return {*}
 */
node *findMax(node *root)
{
  //!!! 如果是查找原始二叉排序树根结点的最大权值结点
  //root应该为原始二叉排序树根结点的左结点
  while (root->rchild != NULL)
  {
    root = root->rchild;
  }
  return root;
}

node *findMin(node *root)
{
  while (root->lchild != NULL)
  {
    root = root->lchild;
  }
  return root;
}

/**
 * @Descripttion: 删除算法 
 * @param {int} val
 * @return {*}
 */
void deleteNode(node *&root, int val)
{
  if (root == NULL)
    return;
  if (root->data == val)
  {
    if (root->lchild == NULL && root->rchild == NULL)
    {
      //没有左右子结点  直接删除
      root = NULL;
    }
    //左子树不为空
    else if (root->lchild != NULL)
    {
      node *pre = findMax(root->lchild);
      root->data = pre->data;
      //在左子树删除结点pre
      deleteNode(root->lchild, pre->data);
    }
    else
    {
      node *next = findMin(root->rchild);
      root->data = next->data;
      //在右子树删除结点next
      deleteNode(root->rchild, next->data);
    }
  }
  else if (root->data > val)
  {
    deleteNode(root->lchild, val);
  }
  else
  {
    deleteNode(root->rchild, val);
  }
}

int main()
{

  return 0;
}
