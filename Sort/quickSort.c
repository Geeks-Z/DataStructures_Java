/*
 * @Descripttion: 快速排序
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-04-11 14:38:53
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-04-11 15:05:56
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @Descripttion: 根据第一个元素划分数组
 * @param {int} arr
 * @param {int} left
 * @param {int} right
 * @return {*}
 */
int partition(int arr[], int left, int right)
{
  int temp = arr[left];
  while (left < right)
  {
    while (left < right && arr[right] > temp)
    {
      right--;
    }
    arr[left] = arr[right];
    while (left < right && arr[left] < temp)
    {
      left++;
    }
    arr[right] = arr[left];
  }
  arr[left] = temp;
  //返回相遇的下标
  return left;
}

/**
 * @Descripttion: 随即确定一个元素划分数组
 * @param {int} arr
 * @param {int} left
 * @param {int} right
 * @return {*}
 */
int randPartition(int arr[], int left, int right)
{
  //生成[left,right]范围内的数
  int random = rand() % (right - left + 1) + left;
  swap(arr[random], arr[left]);
  int temp = arr[left];
  while (left < right)
  {
    while (left < right && arr[right] > temp)
    {
      right--;
    }
    arr[left] = arr[right];
    while (left < right && arr[left] < temp)
    {
      left++;
    }
    arr[right] = arr[left];
  }
  arr[left] = temp;
  //返回相遇的下标
  return left;
}

void quickSort(int arr[], int left, int right)
{
  //当前区间长度超过1
  if (left < right)
  {
    int pos = partition(arr, left, right);
    //对左子区间递归进行快速排序
    quickSort(arr, left, pos - 1);
    //对右子区间递归进行快速排序
    quickSort(arr, pos + 1, right);
  }
}

int main()
{
  //生成随机数的种子
  srand((unsigned)time(NULL));
  for (int i = 0; i < 10; i++)
  {
    printf("%d ", rand());
  }
  printf("\n");
  //生成[a,b]内的随机数
  for (int i = 0; i < 10; i++)
  {
    //生成[3,7]内的随机数
    printf("%d ", rand() % 5 + 3);
  }

  return 0;
}