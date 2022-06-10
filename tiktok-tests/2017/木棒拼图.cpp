/*
 * @Author: your name
 * @Date: 2022-03-09 21:12:14
 * @LastEditTime: 2022-03-09 21:14:20
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\木棒拼图.cpp
 */
// 判断几条棍子能否组成面积大于 0 的简单多边形只需满足一个条件：

// 木棍集合中找出一根最长的，记为 max_len
// 除了这一根外，剩下的长度之和，记为 Len

// 则必须满足 Len > max_len 。

// 换言之， 设总长度为 Tlen，
// 则仅当 Tlen - max_len > max_len 时，才能组成面积大于0 的简单多边形

// 那剩下的编程就简单多了


#include <iostream>
#include <vector>
 
using namespace::std;
 
int getmax(vector<int>& vec) {
	int max = 0;
	for (int i = 0; i < vec.size(); ++i) {
		if (max < vec[i]) max = vec[i];
	}
	return max;
}
 
int getsum(vector<int>& vec) {
	int sum = 0;
	for (int i = 0; i < vec.size(); ++i) {
		sum += vec[i];
	}
	return sum;
}
 
int main() {
	int n;
 
	while (cin >> n) {
		vector<pair<int, int>> vec;
		for (int i = 0; i < n; ++i) {
			int op, len;
			cin >> op >> len;
			vec.push_back(make_pair(op, len));
		}
 
		vector<int> vol;
		for (int i = 0; i < n; ++i) {
			if (vec[i].first == 1) {
				vol.push_back(vec[i].second);
			}
			else if (vec[i].first == 2) {
				vector<int>::iterator iter = vol.begin();
				for (; iter != vol.end(); ++iter) {
					if (*iter == vec[i].second) break;
				}
				if (iter != vol.end()) vol.erase(iter);
			}
 
			int max = getmax(vol);
			int sum = getsum(vol);
			if (sum - max > max) 
				cout << "Yes" << endl;
			else 
				cout << "No" << endl;
		}
	}
 
	return 0;
}