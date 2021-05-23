/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-23 10:40:15
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-23 11:22:16
 */
#include <stdio.h>

/**
 * @Descripttion: 
 * @param {int} arr
 * @param {int} low 预调整元素下标
 * @param {int} high 最后一个元素
 * @return {*}
 */
void downAdjust(int arr[], int low, int high)
{
  //i保存当前需要调整的结点 j保存左子结点
  int i = low, j = i * 2;
  while (j <= high)
  {
    if (j + 1 <= high && arr[j + 1] > arr[j])
    {
      //j保存右子结点下标
      j = j + 1;
    }
    if (arr[i] < arr[j])
    {
      swap(arr[i], arr[j]);
      //保持 i 为当前调整结点 j为左子结点
      i = j;
      j = 2 * i;
    }
    else
    {
      break;
    }
  }
}

/**
 * @Descripttion: 向上调整
 * @param {int} arr
 * @param {int} low
 * @param {int} high
 * @return {*}
 */
void upAdjust(int arr[], int low, int high)
{
  int i = high, j = i / 2;
  while (j >= low)
  {
    if (arr[j] < arr[i])
    {
      swap(arr[i], arr[j]);
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
 * @Descripttion: 从最后一个非叶子结点开始调整
 * @param {int} arr
 * @param {int} len 数组长度
 * @return {*}
 */
void creatHeap(int arr[], int len)
{
  for (int i = len / 2; i >= 1; i--)
  {
    downAdjust(arr, i, len);
  }
}

void deleteTop(int arr[], int len)
{
  //用最后一个元素覆盖堆顶元素 并让元素减1
  arr[1] = arr[len--];
  downAdjust(arr, 1, len);
}

void insert(int arr[], int len, int x)
{
  //让元素个数加1 然后将数组末位赋值为x
  arr[len++] = x;
  //向上调整新加入的结点
  upAdjust(arr, 1, len);
}

void heapSort(int arr[])
{
  int len = sizeof(arr) / sizeof(arr[0]);
  creatHeap(arr, len);
  //倒着枚举 直到堆中只有一个元素
  for (int i = len; i > 1; i--)
  {
    //交换堆顶 与 arr[i];
    swap(arr[1], arr[i]);
    //调整堆顶
    downAdjust(arr, 1, i - 1);
  }
}