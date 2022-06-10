/*
 * @Author: your name
 * @Date: 2022-04-21 18:00:15
 * @LastEditTime: 2022-04-21 18:10:12
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\SRE Train\Binary Tree\Fibonacci Series.cpp
 */

#include <iostream>
#include <vector>
using namespace std;
//动态规划方法，优化递归栈空间
class Solution {
public:
    int Fibonacci(int n) {
        int a = 1 , b = 1 , c = 1;
        for (int i = 3 ; i <= n ; i ++) {
            c = a+b , a = b , b = c;
        }
        return c;
    }
};

class Solution1 {
public:
    int dp[50]{0};
    int Fibonacci(int n) {
        dp[1] = 1, dp[2] =1;
        for (int i = 3 ; i <= n ; i ++) dp[i] = dp[i-1]+dp[i-2];
        return dp[n];
    }
};



int main(){
    Solution sl;
    int length;
    cout<<"Please Input the length of Fibonacci Series: ";
    cin>>length;
    int res = sl.Fibonacci(length);
    cout<<"The "<<length<<" number of Fibonacci Series is ["<<res<<"]"<<endl;
}