/*
 * @Descripttion: 选择排序
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-04-10 08:07:38
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-04-10 08:57:25
 */

#include <stdio.h>

/**
 * @Descripttion: 选择排序
 * @param {int} arr
 * @param {int} len
 * @return {*}
 */
void selectSort(int arr[], int len)
{
  for (int i = 0; i < len - 1; i++)
  {
    int minVal = arr[i];
    int minIndex = i;
    for (int insertIndex = i + 1; insertIndex < len; insertIndex++)
    {
      if (arr[insertIndex] < minVal)
      {
        minVal = arr[insertIndex + 1];
        minIndex = insertIndex + 1;
      }
    }
    //交换arr[i] 与 minVal
    arr[minIndex] = arr[i];
    arr[i] = minVal;
  }
}

int main()
{
  int arr[5] = {5, 4, 3, 2, 0};
  selectSort(arr, 5);
  for (int i = 0; i < 5; i++)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}