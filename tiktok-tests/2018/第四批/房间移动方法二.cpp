/*
 * @Author: your name
 * @Date: 2022-03-10 17:30:59
 * @LastEditTime: 2022-03-10 17:31:00
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\tiktok\2018\房间移动方法二.cpp
 */
#include <iostream>
using namespace std;

long long p[1001], dp[1001], n;
const long long mod = 1e9 + 7;

int main (){
    cin >> n;
    for (int i = 1; i<= n; ++i) cin >> p[i];
    for (int i = 2; i<= n+1; ++i) 
        dp[i] = (2 * dp[i-1] - dp[p[i-1]] + 2) % mod;
    cout << (dp[n + 1] < 0 ? dp[n + 1] + mod : dp[n + 1]);
}
