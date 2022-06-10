//方法一

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
编程思路：参考绅士猫
题目中只说队伍之间相差的分数，并没有说哪支队伍得分多，哪支队伍得分少。所以，本题应该分4种情况讨论。
假设球队1得分为m (m >= 0) ，至少需要need 场比赛才能持平。
当 球队1< 球队2，球队2<球队3 时，得分情况：
        球队1：m
        球队2：m + d1
        球队3：m + d1 + d2 。此时有3 * m = k - d1 - d1 - d2    need = d1 + d2 + d2（此时球队3得分
		最多，所以球队1还需要赢d1 + d2场，球队2还需要赢d2场）
当 球队1< 球队2，球队2>球队3 时，得分情况：
        球队1：m
        球队2：m + d1
        球队3：m + d1 - d2 。此时有3 * m = k - d1 - d1 + d2    need = d1 + d2 （此时球队2得分最多，所以球队1还需要赢d1场，球队3还需要赢d2场）
当 球队1> 球队2，球队2>球队3 时，得分情况：
        球队1：m
        球队2：m - d1
        球队3：m - d1 - d2 。此时有3 * m = k + d1 + d1 + d2    need = d1 + d1 + d2 （此时球队1得分最多，所以球队2还需要赢d1场，球队3还需要赢d1 + d2场）
当 球队1> 球队2，球队2<球队3 时，得分情况：
        球队1：m
        球队2：m - d1
        球队3：m - d1 + d2 。
        此时有3 * m = k + d1 + d1 - d2  。这时不能确定哪个球队得分最多，还要分情况：
                    当 d1  >= d2 时，球队1得分最多need = d1 + d1 - d2
                    当 d1  <   d2 时，球队3得分最多need = d2 - d1 + d2
但是写代码时，不能用if   else if  else if....这种结构，因为同一组数据可能满足两种以上的情况，
所以要把这几种情况都判断一遍，如果都不能输出yes，那么最后输出no
*/

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n, k, d1, d2, tmp, remain;
		cin >> n >> k >> d1 >> d2;
		
		//q1-球队1，q2-球队2，q3-球队3，下同。
 
		//q1 < q2 < q3
		tmp = k - d1 - d1 - d2;
		if(tmp >= 0 && tmp % 3 == 0)
		{
			remain = (n - k) - (d1 + d2 + d2);
			if(remain >= 0 && remain % 3 == 0)
			{
				cout << "yes" << endl;
				continue;
			}
		}
		
		//q1 > q2 > q3
		tmp = k + d1 + d1 + d2;
		if(tmp >= 0 && tmp % 3 == 0)
		{
			remain = (n - k) - (d1 + d1 + d2);
			if(remain >= 0 && remain % 3 == 0)
			{
				cout << "yes" << endl;
				continue;
			}
		}
 
		//q1 < q2 > q3
		tmp = k - d1 - d1 + d2;
		if(tmp >= 0 && tmp % 3 == 0)
		{
			remain = (n - k) - (d1 + d2);
			if(remain >= 0 && remain % 3 == 0)
			{
				cout << "yes" << endl;
				continue;
			}
		}
		
		//q1 > q2 < q3
		tmp = k + d1 + d1 - d2;
		if(tmp >= 0 && tmp % 3 == 0)
		{
			if(d1 > d2)
				remain = (n - k) - (d1 + d1 - d2);
			else
				remain = (n - k) - (d2 + d2 - d1);
			if(remain >= 0 && remain % 3 == 0)
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
 
