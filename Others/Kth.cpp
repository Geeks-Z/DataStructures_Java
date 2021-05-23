/*
 * @Descripttion: 返回第k大的数
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-04-11 18:00:56
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-23 08:56:32
 */
/**
 * @Descripttion: 随即确定一个元素划分数组
 * @param {int} arr
 * @param {int} left
 * @param {int} right
 * @return {*}
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

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
    while (left < right && arr[left] <= temp)
    {
      left++;
    }
    arr[right] = arr[left];
  }
  arr[left] = temp;
  //返回相遇的下标
  return left;
}

int randSelect(int arr[], int left, int right, int K)
{
  //递归边界
  if (left == right)
  {
    return arr[left];
  }
  //划分后主元的位置 已对数组进行了划分
  int p = randPartition(arr, left, right);
  //arr[p]是arr[left, right]中第M大数
  int M = p - left + 1;
  if (M == K)
  {
    return arr[p];
  }
  else if (M < K)
  {
    return randSelect(arr, p + 1, right, K - M);
  }
  else
  {
    return randSelect(arr, left, p - 1, K);
  }
}

int main()
{
  //生成随机数的种子
  srand((unsigned)time(NULL));
  int arr[6] = {5, 12, 7, 2, 9, 3};
  printf("%d \n", randSelect(arr, 0, 5, 5));
  return 0;
}