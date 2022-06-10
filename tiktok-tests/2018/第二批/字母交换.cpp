/*
 * @Author: your name
 * @Date: 2022-03-12 17:20:13
 * @LastEditTime: 2022-03-12 17:21:59
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\tiktok\2018\第二批\字母交换.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;
    int m;
    while (cin >> s >> m) 
    {
        int ans = 1;
        //枚举每一个字符
        for (char c = 'a'; c <= 'z'; c++) 
        {
        	//构建pos数组
            vector<int> pos;
            for (int i = 0; i < (int)s.size(); i++)
                if (c == s[i])
                    pos.push_back(i);

			//过滤掉只出现一次的字符
            if (pos.size() < 2)
                continue;

			//dp数组
            int ret = 1;
            vector<vector<int> > dp(pos.size(), vector<int>(pos.size(), 0));
            
            for (int len = 2; len <= (int)pos.size(); ++len) 
            {
                for (int i = 0; i + len - 1 < (int)pos.size(); i++) 
                {
                    dp[i][i + len - 1] = dp[i + 1][i + len - 2] + pos[i + len - 1] - pos[i] - len + 1;
                    if (dp[i][i + len - 1] <= m)
                        ret = len;
                }
            }
            ans = max(ans, ret);
        }
        cout << ans << endl;
    }
    return 0;
}

