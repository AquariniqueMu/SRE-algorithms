/*
 * @Author: your name
 * @Date: 2022-03-12 17:09:16
 * @LastEditTime: 2022-03-20 21:18:45
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\tiktok\2018\用户喜好.cpp
 */
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int main()
{
    int n;cin >> n;
    unordered_map<int, vector<int>> k_index;
    for (int i = 1;i <= n;i++)
    {
        int data;cin >> data;
        k_index[data].push_back(i);
    }
    //输入查询
    int q;cin >> q;
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        unordered_map<int, vector<int> >::iterator temp_it = k_index.find(k);
        if (temp_it == k_index.end())
            cout << 0 << endl;
        else
        {
            //二分查找
            auto ln = lower_bound(temp_it->second.begin(), temp_it->second.end(),l);
            auto rn = upper_bound(temp_it->second.begin(), temp_it->second.end(),r);
            cout << rn - ln << endl;
        }
    }
    return 0;
}
