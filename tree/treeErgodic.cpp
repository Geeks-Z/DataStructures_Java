/*
 * @Descripttion: 树的遍历 不限于二叉树
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-03-18 08:48:23
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-03-18 10:21:39
 */
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 100;

struct node
{
  int data;
  //指针域 存放所有子结点的下标
  vector<node *> child;
  //层数
  int layer;
} Node[maxn];

/**
 * @Descripttion: 树的先序遍历 
 * @param {node} *root
 * @return {*}
 */
void preOrder(node *root)
{
  printf("%d ", root->data);
  for (int i = 0; i < root->child.size(); i++)
  {
    preOrder(root->child[i]);
  }
}

/**
 * @Descripttion: 树的层序遍历 
 * @param {*}
 * @return {*}
 */
void layerOrder(node *root)
{
  queue<node *> q;
  root->layer = 1;
  q.push(root);
  while (!q.empty())
  {
    node *top = q.front();
    printf("%d ", top->data);
    q.pop();
    for (int i = 0; i < top->child.size(); i++)
    {
      top->child[i]->layer = top->layer + 1;
      q.push(top->child[i]);
    }
  }
}

int main()
{
  node *root = new node;
  root->data = 1;
  node *b = new node;
  b->data = 2;

  node *c = new node;
  c->data = 3;

  node *d = new node;
  d->data = 5;

  node *e = new node;
  e->data = 4;
  root->child.push_back(b);
  root->child.push_back(c);
  root->child.push_back(d);
  b->child.push_back(e);

  layerOrder(root);
  printf("\n");
  printf("%d", e->layer);
  return 0;
}