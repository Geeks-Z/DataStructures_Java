/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-03-16 09:58:38
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-21 16:12:25
 */
#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  node *lchild;
  node *rchild;
};

//根节点为空
node *root = NULL;

/**
 * @Descripttion: 生成一个新节点
 * @param {int} v 新节点的权值
 * @return {*}
 */
node *newNode(int v)
{
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = v;
  newNode->lchild = newNode->rchild = NULL;
  return newNode;
}

/**
 * @Descripttion: 修改数据域为x的结点值为newData 
 * @param {node} *root
 * @param {int} x
 * @param {int} newData
 * @return {*}
 */
void modify(node *root, int x, int newData)
{
  if (root == NULL)
  {
    return;
  }
  if (root->data == x)
  {
    root->data = newData;
  }
  //往左子树递归查找
  modify(root->lchild, x, newData);
  modify(root->rchild, x, newData);
}

/**
 * @Descripttion: 插入结点
 * @param {int} val
 * @return {*}
 */
/**
 * 特别注意root使用了引用，即在函数中对root的修改会改变原变量的值
 * 如果不使用引用，root = newNode(val)这个语句对root的修改就不能
 * 作用到原变量（即上一层root->lchild与root->rchild） 即不能把
 * 新结点连接到二叉树上
 * ！！！如果函数中需要新建结点，即对二叉树的结构进行改变，就需要加引用
 * 只是修改当前已有结点的内容，或是遍历 不需要加引用
 */
void insert(node *&root, int val)
{
  //空树  说明查找失败 即插入位置
  if (root == NULL)
  {
    root = newNode(val);
    return;
  }

  //由二叉树的性质，val应该插在左子树
  if (root->lchild)
  {
    insert(root->lchild, val);
  }
  //由二叉树的性质，val应该插在右子树
  else
  {
    insert(root->rchild, val);
  }
}

/**
 * @Descripttion: 二叉树的创建
 * @param {int} data
 * @param {int} n
 * @return {*}
 */
node *creatBinaryTree(int data[], int n)
{
  node *root = NULL;
  for (int i = 0; i < n; i++)
  {
    insert(root, data[i]);
  }
  return root;
}