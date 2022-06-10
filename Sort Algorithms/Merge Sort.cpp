/*
 * @Author: your name
 * @Date: 2022-04-21 00:27:40
 * @LastEditTime: 2022-04-21 00:52:21
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\SRE Train\PartitionSort.cpp
 */
#include <iostream>    
#include <vector>
#include <cstring>
using namespace std;  

 /*
 归并排序原理:
    一种递归算法，采用分治法思想，不断将列表拆分为一半，直到每个数组只有一个元素。
    再将两个已排序的表合并成一个表

    通过对若干个有序结点序列的归并来实现排序
    所谓归并是指将若干个已排好序的部分合并成一个有序的部分

    我们首先把一个未排序的序列从中间分割成2部分，再把2部分分成4部分，
    依次分割下去，直到分割成一个一个的数据，再把这些数据两两归并到一起，
    使之有序，不停的归并，最后成为一个排好序的序列
 */



#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> merge(vector<int> a, vector<int> b) {
        vector<int> res;
        size_t ai = 0, bi = 0;
        while (ai < a.size() && bi < b.size()) {
            if (a[ai] <= b[bi])
                res.push_back(a[ai++]);
            else
                res.push_back(b[bi++]);
        }
        if (ai == a.size())
            res.insert(res.end(), b.begin() + bi, b.end());
        else if (bi == b.size())
            res.insert(res.end(), a.begin() + ai, a.end());
        return res;
    }

    vector<int> mergeSort(vector<int>& arr) {
        if (arr.size() < 2) return arr;
        const size_t mid = arr.size() / 2;
        vector<int> left(arr.begin(), arr.begin() + mid);
        vector<int> right(arr.begin() + mid, arr.end());
        return merge(mergeSort(left), mergeSort(right));
    }
};


int main() {
	vector<int> arr;
    Solution sl;

    for(int temp = 0; cin >> temp;){
        arr.push_back(temp);
        if(cin.get() == '\n')
            break;
    }

	arr = sl.mergeSort(arr);
	
	for (const int& a : arr)
		cout << a << ' ';
	cout << endl;
}
