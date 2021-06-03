/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-03-02 08:59:31
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-06-03 11:30:08
 */
#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  node *next;
};

//创建链表
node *creat(int Array[])
{
  //pre保存当前结点的前驱结点，head为头结点
  node *p, *pre, *head;
  //创建头结点
  //head = new node //c++
  head = (node *)malloc(sizeof(node));
  head->next = NULL;
  pre = head;
  for (int i = 0; i < 5; i++)
  {
    p = (node *)malloc(sizeof(node));
    p->data = Array[i];
    p->next = NULL;
    //将前驱结点的指针域设为当前新建结点的地址
    pre->next = p;
    //把pre设为p，作为下个结点的前驱结点
    pre = p;
  }
  return head;
}

/**
 * @Descripttion: 指定位置插入结点 
 * @param {node} *head 头结点
 * @param {int} pos
 * @param {int} x
 * @return {*}
 */
void insert(node *head, int pos, int x)
{
  node *p = head;
  for (int i = 0; i < pos - 1; i++)
  {
    p = p->next;
  }
  node *q = (node *)malloc(sizeof(node));
  q->data = x;
  q->next = p->next;
  p->next = q;
}

//删除元素
void del(node *head, int x)
{
  //p从第一个结点开始枚举
  node *p = head->next;
  node *pre = head;
  while (p->next != NULL)
  {
    if (p->data == x)
    {
      pre->next = p->next;
      free(p);
      p = pre->next;
    }
    else
    {
      //两个指针均后移
      pre = p;
      p = p->next;
    }
  }
}

int main()
{
  int array[5] = {5, 2, 3, 1, 4};
  node *L = creat(array);
  //头结点没有数据
  L = L->next;
  while (L != NULL)
  {
    printf("%d ", L->data);
    L = L->next;
  }

  return 0;
}