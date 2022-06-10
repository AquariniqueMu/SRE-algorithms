






#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int n = 24;

//六个面在经过一次逆时针旋转后的位置变化情况，可以画图验证
const int Rotate[6][24] = 
{
	//FRONT
	{0, 1, 11, 5, 4, 16, 12, 6, 2, 9, 10, 17, 13, 7, 3, 15, 14, 8, 18, 19, 20, 21, 22, 23},
	
	//BEHIND
	{9, 15, 2, 3, 1, 5, 6, 7, 8, 19, 0, 11, 12, 13, 14, 18, 16, 17, 4, 10, 22, 20, 23, 21},
	
	//LEFT
	{20, 1, 22, 3, 10, 4, 0, 7, 8, 9, 11, 5, 2, 13, 14, 15, 6, 17, 12, 19, 16, 21, 18, 23},
	
	//RIGHT
	{0, 7, 2, 13, 4, 5, 6, 17, 14, 8, 10, 11, 12, 19, 15, 9, 16, 21, 18, 23, 20, 1, 22, 3},
	
	//UP
	{2, 0, 3, 1, 6, 7, 8, 9, 23, 22, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 5, 4},
	
	//DOWN
	{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 21, 20, 10, 11, 12, 13, 18, 16, 19, 17, 15, 14, 22, 23}
};

//魔方6个面的位置坐标
const int side[6][4] = 
{
	{0, 1, 2, 3},
	{4, 5, 10, 11},
	{6, 7, 12, 13},
	{8, 9, 14, 15},
	{16, 17, 18, 19},
	{20,21, 22, 23}
};

//旋转操作
//vec就代表魔方，用数组表示
//i代表旋转那个面
void rotateRC(vector<int>& vec, int i)
{
	//拷贝一份
	vector<int> tmp(vec);
 
 	//根据i，把旋转完成后的面重新赋值给vec
 	//n为24，相当于把旋转后的内容给了vec
	for (int j = 0; j < n; ++j)
	{
		//Rotate[i][j]：i代表旋转那个面，定位在Rotate数组的那个位置
		//找到正确的位置直接赋值即可
		vec[j] = tmp[Rotate[i][j]];
	}
	tmp.clear();
}

//求整个魔方的优美度
long long getArea(const vector<int>& vec)
{
	long long sum = 0, mul = 1;
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			mul *= vec[side[i][j]];
		}
		sum += mul;
		mul = 1;
	}
	return sum;
}

//搜索
long long dfs(vector<int> vec, int count)
{
	//获取当前魔方状态的优美度并保存
	long long ans = getArea(vec);

	//判断操作次数
	if (0 == count)	
		return ans;

	//用i分别模拟待旋转的6个面
	for (int i = 0; i < 6; ++i)
	{
		vector<int> tmp(vec);
		
		//代表逆时针旋转一次
		rotateRC(tmp, i);
		//在旋转一次的基础上递归
		ans = max(ans, dfs(tmp, count - 1));
		//顺时针旋转（逆时针旋转3次相当于顺时针旋转1次）
		rotateRC(tmp, i);
		rotateRC(tmp, i);
		//在顺时针旋转的基础上递归
		ans = max(ans, dfs(tmp, count - 1));
	}
	return ans;
}
int main()
{
	vector<int> vec(n);
	for (int i = 0; i < n; ++i)
		cin >> vec[i];
	
	//dfs搜索
	cout << dfs(vec, 5) << endl;
	system("pause");
	return 0;
}
