
/*
 * @Descripttion: 根据一棵二叉树的前序遍历和中序遍历结果，要求写出这棵二叉树的后序遍历结果
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-03-23 22:59:28
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-03-26 09:08:34
 */
#include <stdio.h>

struct node
{
  char data;
  node *lchild;
  node *rchild;
};

const int maxn = 100;
char preOrderArr[maxn];
char inOrderArr[maxn];
/**
 * @Descripttion: 根据一棵二叉树的前序遍历和中序遍历结果,构建二叉树
 * @param {int} preLeft
 * @param {int} preRight
 * @param {int} inLeft
 * @param {int} inRight
 * @return {*}
 */
node *restoreTree(int preLeft, int preRight, int inLeft, int inRight)
{

  //先序序列长度小于等于0时 直接返回
  if (preLeft > preRight)
  {
    return NULL;
  }
  node *root = new node;
  //新结点的数据域为根结点的值
  root->data = preOrderArr[preLeft];

  //从中序序列中找到根结点的坐标 进而划分中序遍历中左右子树
  int rootIndex;
  for (rootIndex = inLeft; rootIndex <= inRight; rootIndex++)
  {
    if (inOrderArr[rootIndex] == preOrderArr[preLeft])
    {
      break;
    }
  }

  //左子树个数
  int leftNum = rootIndex - inLeft;
  //左子树
  root->lchild = restoreTree(preLeft + 1, preLeft + leftNum, inLeft, leftNum - 1);
  //右子树
  root->rchild = restoreTree(preLeft + leftNum + 1, preRight, rootIndex + 1, inRight);
  return root;
}

/**
 * @Descripttion: 二叉树后序遍历
 * @param {*}
 * @return {*}
 */
void postOrder(node *root)
{

  if (root == NULL)
  {
    return;
  }
  postOrder(root->lchild);
  postOrder(root->rchild);
  printf("%c", root->data);
}

int main()
{
  while (scanf("%s", preOrderArr) != EOF)
  {
    //处理字符串输入
    scanf("%s", inOrderArr);
    // int preOrderArrLen = sizeof(preOrderArr) / sizeof(preOrderArr[0]);
    int preOrderArrLen = 0;
    while (preOrderArr[preOrderArrLen] != '\0')
    {
      preOrderArrLen++;
    }

    node *root = restoreTree(0, preOrderArrLen - 1, 0, preOrderArrLen - 1);
    postOrder(root);
    printf("\n");
  }

  return 0;
}