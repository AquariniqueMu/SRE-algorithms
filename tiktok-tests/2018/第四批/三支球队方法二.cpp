/*
 * @Author: your name
 * @Date: 2022-03-10 17:16:00
 * @LastEditTime: 2022-03-10 17:16:01
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\tiktok\2018\三支球队方法二.cpp
 */
//方法二

/**********************
编程思路：参考jiack
比赛场次能被3整除且当前球队最高分小于等于n/3，则有可能踢平，步骤：
1、n是否能被3整除，否输出no，是进行2
2、求满足(k,d1,d2)的所有最大得分的最小值
3、如果这个最小值≤n/3，输出yes，否则输出no
**********************/
 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n, k, d1, d2, tmp, m, maxScore;
		//m表示球队1暂时的得分，tmp求出的是3m，maxScore是每种情况下得分最多的球队得分
		cin >> n >> k >> d1 >> d2;
 
		if(n%3 != 0)//判断总场数能不能被3整除
		{
			cout << "no" << endl;
			continue;
		}
 
		//q1-球队1，q2-球队2，q3-球队3，下同。
 
		//q1 < q2 < q3
		tmp = (k - d1 - d1 - d2);
		//每次都要判断tmp是不是能被3整除，不能整除就不能满足这种情况，这个bug搞半天才发现，下同
		if(tmp >= 0 && tmp % 3 == 0)
		{
			m = tmp/3;
			maxScore = m + d1 + d2;
			if(m >= 0 && maxScore <= n/3)
			{//最大值不超过n/3，最小值还要大于等于0，不限制最小值可能出现负值满足的情况，下同
				cout << "yes" << endl;
				continue;
			}
		}
 
		//q1 > q2 > q3
		tmp = (k + d1 + d1 + d2);
		if(tmp >= 0 && tmp % 3 == 0)
		{
			m = tmp/3;
			maxScore = m;
			if(m - d1 - d2 >= 0 && maxScore <= n/3)
			{
				cout << "yes" << endl;
				continue;
			}
		}
 
		//q1 < q2 > q3
		tmp = (k - d1 - d1 + d2);
		if(tmp >= 0 && tmp % 3 == 0)
		{
			m = tmp/3;
			maxScore = m + d1;
			if(m >= 0 && m + d1 - d2 >= 0 && maxScore <= n/3)
			{
				cout << "yes" << endl;
				continue;
			}
		}
 
		//q1 > q2 < q3
		tmp = (k + d1 + d1 - d2);
		if(tmp >= 0 && tmp % 3 == 0)
		{
			m = tmp/3;
			if(d1 > d2)
				maxScore = m;
			else 
				maxScore = m - d1 + d2;
			if(m - d1 >= 0 && maxScore <= n/3)
			{
				cout << "yes" << endl;
				continue;
			}
		}
 
		cout << "no" << endl;
	}
 
	system("pause");
	return 0;
}
 