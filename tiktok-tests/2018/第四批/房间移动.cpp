/*
 * @Author: your name
 * @Date: 2022-03-10 17:23:27
 * @LastEditTime: 2022-03-10 17:32:23
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\tiktok\2018\房间移动.cpp
 */




/*
仔细分析 1<=pi<=i 知道用动态规划做。

记录第一次到达i为dp[i]，此时前面的所有门肯定是已经到达偶数次了因为传送只会后退，前进的唯一方式是偶数次到达并+1，不能跳跃所以到达i门前面所有门都走过并且经过偶数次（反正法也可以证明）

dp[i]=dp[i-1]+（第二次到达i-1步数） + 1

第一次到达i-1门后再走一步会回到p[i-1]，此时p[i-1]门到达奇数次，其他所有门到达偶数次

这和第一次到达p[i-1]门的情况完全相同，所以从p[i-1]门回到i-1门，需要dp[i-1]-dp[p[i-1]]

所以dp[i] = dp[i-1] + dp[i-1] - dp[p[i-1]] + 1 + 1

dp[i] = 2 * dp[i-1] - dp[p[i-1]] + 2
*/

#include<iostream>
#include <memory.h>
 
using namespace std;

 
const int MAXSIZE = 1002;
const long long M = 1e9 + 7;
// 第一次到达点i的步数
long long visited[MAXSIZE];
long long pi[MAXSIZE];
 
int main()
{
    memset(visited, 0, sizeof(visited));
    memset(pi, 0, sizeof(pi));
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> pi[i];
    for (int i = 2; i <=n+1; ++i) {
        visited[i] = (2 * visited[i - 1] % M - visited[pi[i - 1]] + 2) % M;
    }
    
    cout << visited[n+1] << endl;
    return 0;
} 