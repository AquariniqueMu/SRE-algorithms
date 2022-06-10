/*
 * @Author: your name
 * @Date: 2022-04-21 00:16:36
 * @LastEditTime: 2022-04-21 00:22:32
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\SRE Train\longestCommonSubsequence.cpp
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            char c1 = text1.at(i - 1);
            for (int j = 1; j <= n; j++) {
                char c2 = text2.at(j - 1);
                if (c1 == c2) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
    Solution sl;
    string text1, text2;
    cout << "Input text1: ";
    cin >> text1;
    cout << "Input text2: ";
    cin >> text2;
    int commonSub = sl.longestCommonSubsequence(text1, text2);
    cout << "The number of common subsequence is: "<<commonSub<<endl;
    return 0;
}