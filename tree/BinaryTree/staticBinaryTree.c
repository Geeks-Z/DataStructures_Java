/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-20 21:40:34
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-20 21:45:40
 */
#include <stdio.h>
#define MAXN 10010
struct node
{
  int data;
  int lchild, rchild;
} Node[MAXN];

int newNode(int index, int val)
{
  Node[index].data = val;
  //-1表示空
  Node[index].lchild = Node[index].rchild = -1;
}

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}
