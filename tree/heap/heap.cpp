/*
 * @Descripttion: 二叉堆的实现
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-03-27 21:00:38
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-03-28 18:56:12
 */

#include <stdio.h>
const int maxn = 100;
//定义一个二叉堆 元素个数 从1号位开始存储
int n = 10;
int heap[11] = {0, 10, 9, 2, 5, 8, 7, 4, 6, 3, 1};
/**
 * @Descripttion: //对heap数组从上到下在low high范围内调整
 * @param {int} low
 * @param {int} high
 * @return {*}
 */
void downAdjust(int low, int high)
{
  //i 为欲调整的结点 j 为其左孩子
  int i = low, j = 2 * i;
  //存在孩子结点
  while (j <= high)
  {
    //j指向子结点中较大的
    if (j + 1 <= high && heap[j + 1] > heap[j])
    {
      j = j + 1;
    }
    if (heap[i] < heap[j])
    {
      //当前结点与子结点进行交换
      int temp = heap[i];
      heap[i] = heap[j];
      heap[j] = temp;
      i = j;
      j = 2 * i;
    }
    else
    {
      //孩子的权值均比欲调整结点i小 调整结束
      break;
    }
  }
}

/**
 * @Descripttion: 向上调整 
 * @param {int} low
 * @param {int} high
 * @return {*}
 */
void upAdjust(int low, int high)
{
  //i为欲调整的结点
  int i = low;
  //j为欲调整结点的父结点
  int j = i / 2;
  while (j >= low)
  {
    //父结点的值小于当前需要调整的结点的值
    if (heap[j] < heap[i])
    {
      //交换父结点 子结点的值
      int temp = heap[j];
      heap[j] = heap[i];
      heap[i] = temp;
      i = j;
      j = i / 2;
    }
    else
    {
      break;
    }
  }
}

/**
 * @Descripttion: 二叉堆的构建 
 * @param {*}
 * @return {*}
 */
void creatHeap()
{
  for (int i = n / 2; i >= 1; i--)
  {
    downAdjust(i, n);
  }
}

void deleteTop()
{
  //让最后一个元素覆盖根结点
  heap[1] = heap[n--];
  //向下调整堆顶元素
  downAdjust(1, n);
}

void insert(int x)
{
  heap[++n] = x;
  //向上调整新加入的结点
  upAdjust(1, n);
}

void heapSort()
{
  creatHeap();
  for (int i = n; i > 1; i--)
  {
    int temp = heap[1];
    heap[1] = heap[i];
    heap[i] = temp;
    downAdjust(1, i - 1);
  }
}
int main()
{
  heapSort();
  for (int i = 0; i < 11; i++)
  {
    printf("%d ", heap[i]);
  }

  return 0;
}