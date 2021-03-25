/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-03-25 13:19:23
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-03-25 17:06:57
 */
#include <stdio.h>
#include <vector>
using namespace std;

struct node
{
  int data;
  node *lchild;
  node *rchild;
};

void insert(node *&root, int val)
{
  if (root == NULL)
  {
    root = new node;
    root->data = val;
    // !!!
    root->lchild = root->rchild = NULL;
    return;
  }
  if (root->data > val)
  {
    insert(root->lchild, val);
  }
  else
  {
    insert(root->rchild, val);
  }
}

/**
 * @Descripttion: 先序遍历
 * @param {vector<int>} &vi
 * @return {*}
 */
void preOrder(node *root, vector<int> &preOrderVi)
{
  if (root == NULL)
    return;
  preOrderVi.push_back(root->data);
  preOrder(root->lchild, preOrderVi);
  preOrder(root->rchild, preOrderVi);
}

/**
 * @Descripttion: 后序遍历
 * @param {*}
 * @return {*}
 */
void postOrder(node *root, vector<int> &postOrderVi)
{
  if (root == NULL)
  {
    return;
  }
  postOrder(root->lchild, postOrderVi);
  postOrder(root->rchild, postOrderVi);
  postOrderVi.push_back(root->data);
}

/**
 * @Descripttion: 镜像树的先序遍历 
 * @param {vector<int>} &mPreOrderVi
 * @return {*}
 */
void mPreOrder(node *root, vector<int> &mPreOrderVi)
{
  if (root == NULL)
    return;
  mPreOrderVi.push_back(root->data);
  mPreOrder(root->rchild, mPreOrderVi);
  mPreOrder(root->lchild, mPreOrderVi);
}

/**
 * @Descripttion: 镜像树后序遍历
 * @param {node} *root
 * @param {vector<int>} &mPostOrderVi
 * @return {*}
 */
void mPostOrder(node *root, vector<int> &mPostOrderVi)
{

  if (root == NULL)
    return;
  mPostOrder(root->rchild, mPostOrderVi);
  mPostOrder(root->lchild, mPostOrderVi);
  mPostOrderVi.push_back(root->data);
}

int main()
{
  vector<int> origin, pre, post, Mpre, Mpost;
  //二叉树个数
  int num, temp;
  scanf("%d", &num);
  node *root = NULL;
  for (int i = 0; i < num; i++)
  {
    scanf("%d", &temp);
    origin.push_back(temp);
    insert(root, temp);
  }

  //分别求二叉树和镜像二叉树先序 后序 序列
  preOrder(root, pre);
  postOrder(root, post);
  mPreOrder(root, Mpre);
  mPostOrder(root, Mpost);

  //初始序列等于先序序列
  if (origin == pre)
  {
    printf("YES\n");
    for (int i = 0; i < post.size(); i++)
    {
      printf("%d", post[i]);
      if (i < post.size() - 1)
      {
        printf(" ");
      }
    }
  }
  else if (origin == Mpre)
  { //等于镜像树的先序序列
    printf("YES\n");
    for (int i = 0; i < Mpost.size(); i++)
    {
      printf("%d", Mpost[i]);
      if (i < Mpost.size() - 1)
      {
        printf(" ");
      }
    }
  }
  else
  {
    printf("NO\n");
  }
  return 0;
}