/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-05-19 19:05:10
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-05-19 19:12:47
 */
#include <stdio.h>
#include <stdbool.h>
const int N = 101;
bool vis[N] = {false};
int res[N], count = 0;
void full(int n, int index)
{
  //递归边界
  if (index == n + 1)
  {
    count++;
    return;
  }
  //递归体
  //枚举1~n 试图将x加入res中
  for (int i = 1; i <= n; i++)
  {
    if (vis[i] == false)
    {
      bool flag = true;
      for (int pre = 1; pre < index; pre++)
      {
        if (abs(index - pre) == abs(i - res[pre]))
        {
          flag = false;
          break;
        }
      }
      if (flag)
      {
        res[index] = i;
        vis[i] = true;
        //处理排列的n+1位
        full(n, index + 1);
        //处理完res[index] = i的子问题 还原状态
        vis[i] = false;
      }
    }
  }
}