/*
 * @Descripttion: 插入排序
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-04-10 08:57:07
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-04-10 08:57:48
 */

#include <stdio.h>

/**
 * @Descripttion: 插入排序
 * @param {int} arr
 * @param {int} len
 * @return {*}
 */
void insertSort(int arr[], int len)
{
  for (int i = 1; i < len; i++)
  {
    //待插入的位置
    int insertIndex = i - 1;
    //寻找插入位置
    while (insertIndex >= 0 && arr[insertIndex] > arr[i])
    {
      arr[insertIndex + 1] = arr[insertIndex];
      insertIndex--;
    }
    arr[insertIndex + 1] = arr[i];
  }
}