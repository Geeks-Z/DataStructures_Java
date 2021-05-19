/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-19 19:00:04
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-19 19:04:50
 */
#include <stdio.h>
#include <stdbool.h>
const int N = 101;
bool vis[N] = {false};
int res[N];
void full(int n, int index)
{
  //递归边界
  if (index == n + 1)
  {
    for (int i = 1; i <= n; i++)
    {
      printf("%d ", res[i]);
    }
    printf("\n");
    return;
  }
  //递归体
  //枚举1~n 试图将x加入res中
  for (int i = 1; i <= n; i++)
  {
    if (vis[i] == false)
    {
      vis[i] = true;
      res[index] = i;
      //处理排列的n+1位
      full(n, index + 1);
      //处理完res[index] = i的子问题 还原状态
      vis[i] = false;
    }
  }
}