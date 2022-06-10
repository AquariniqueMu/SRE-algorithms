/*
 * @Author: your name
 * @Date: 2022-03-09 21:15:14
 * @LastEditTime: 2022-03-09 21:20:07
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\魔法权值.cpp
 */

// https://blog.csdn.net/wolfGuiDao/article/details/106739147


#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
vector<string> strs;//存储输入的字符串
vector<int> flag;//存储全排列标记信息
int n, k;
int count;//计数
 
//全排列 + 解决问题
//pos代表当前是第pos位
//sequence代表全排列的临时数组
void backTracking(int pos, vector<int> &sequence)
{
	//如果相等代表已经找到一种全排列的方式，就需要判断是否权值的要求
    if(pos == n)
    {
        string s;
        
        //链接在一起构成新的字符串
        for(int i = 0; i < n; i++)
            s += strs[sequence[i]];
 
        string tmps = s;

		//权值计数器
        int lcount = 1;
        //判断左移[1,length - 1]的权值情况
        for(int i = 0; i < s.length() / 2; i++)
        {
            tmps = tmps.substr(1) + tmps[0];
            if(tmps == s)
            {
                lcount = s.length() / (i + 1);
                break;
            }
        }

		//如果权值计数器和题目要求的权值K相等代表改种字符串排列算作一种情况，++即可
        if(lcount == k)
            ::count++;
        return;
    }
    //全排列代码，就是回溯
    for(int i = 0; i < n; i++)
    {
        if(flag[i])
        {
        	//做选择
            sequence.push_back(i);
            flag[i] = false;
            backTracking(pos + 1, sequence);
            flag[i] = true;
            //撤销选择
            sequence.resize(sequence.size() - 1);
        }
    }
}
 
int main()
{
    ::count = 0;
    cin>>n>>k;
    strs.resize(n);
    flag.resize(n);
    vector<int> seq;
     
    for(int i = 0; i < n; i++)
    {
        cin>>strs[i];
        flag[i] = true;
    }
    backTracking(0, seq);
    cout<<::count<<endl;
    return 0;
}

