/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Geeks_Z
 * @Date: 2021-03-28 19:18:52
 * @LastEditors: Geeks_Z
 * @LastEditTime: 2021-03-28 19:33:07
 */
#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> q;

int main()
{
  int n;
  long long temp, x, y, ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &temp);
    //将初始重量压入队列
    q.push(temp);
  }

  while (q.size() > 1)
  {
    //取出队列中较小的两个元素
    x = q.top();
    q.pop();
    y = q.top();
    q.pop();
    q.push(x + y);
    ans += (x + y);
  }
  printf("lld\n", ans);
  return 0;
}
