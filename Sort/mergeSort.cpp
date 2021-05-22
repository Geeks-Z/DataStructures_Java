/*
 * @Descripttion: 归并排序
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-08 16:12:50
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-22 20:45:20
 */
#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;

void merge(int arr[], int l1, int r1, int l2, int r2)
{
  int i = l1, j = l2;
  int temp[r2 - i + 1];
  int index = 0;
  while (i <= r1 && j <= r2)
  {
    if (arr[i] <= arr[j])
    {
      temp[index++] = arr[i++];
    }
    else
    {
      temp[index++] = arr[j++];
    }
  }
  //左子数组有剩余
  while (i <= r1)
  {
    temp[index++] = arr[i++];
  }
  while (j <= r2)
  {
    temp[index++] = arr[j++];
  }
  //重新写回数组arr
  for (int i = 0; i < index; i++)
  {
    arr[l1 + i] = temp[i];
  }
}

void mergeSort(int arr[], int l, int r)
{
  if (l < r)
  {
    int mid = (int)floor(1.0 * (r + l) / 2);
    //将左子区间[left,mid]归并排序
    mergeSort(arr, l, mid);
    //将右子区间[mid,right]归并排序
    mergeSort(arr, mid + 1, r);
    //将左子区间和右子区间合并
    merge(arr, l, mid, mid + 1, r);
  }
}

int main()
{
  // freopen("input.txt", "r",stdin);
  int arr[7] = {66, 12, 33, 57, 64, 27, 18};
  int arrLen = sizeof(arr) / sizeof(arr[0]);
  mergeSort(arr, 0, arrLen - 1);
  for (int i = 0; i < arrLen; i++)
  {
    cout << arr[i] << ' ';
  }

  return 0;
}