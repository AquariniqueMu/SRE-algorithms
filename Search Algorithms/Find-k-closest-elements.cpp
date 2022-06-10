/*
 * @Author: your name
 * @Date: 2022-04-20 23:41:03
 * @LastEditTime: 2022-04-20 23:49:53
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\SRE Train\find-k-closest-elements.cpp
 */

#include <iostream>    
#include <vector>
#include <cstring>
using namespace std;  

class Solution {
public:
    //首先进行快速排序
    void quicksort(int left, int right, vector<int>& arr){
    if(left >= right)
        return;
    int i,j,base, temp;
    i = left, j = right;
    base = arr[left];
    while(i < j)
    {
        while(arr[j] >= base && i < j) j--;
        while(arr[i] <= base && i < j) i++;
        if(i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
        //base setup
    arr[left] = arr[i];
    arr[i] = base;
    quicksort(left, i - 1, arr);
    quicksort(i + 1, right, arr);
}


    //其次进行数字寻找
    //原理：假设 mid 是左边界，则当前区间覆盖的范围是 [mid, mid + k -1]. 如果发现 a[mid] 与 x 距离比 a[mid + k] 与 x 的距离要大，说明解一定在右侧
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        quicksort(0, arr.size()-1, arr);
        int lo = 0, hi = arr.size() - k;
        while (lo < hi) {
        int mid = lo + (hi - lo >> 1);
        if (x - arr[mid] > arr[mid + k] - x ) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
        }
    return vector<int>(arr.begin() + lo, arr.begin() + lo + k);
    }



};

int main()  
{  
    Solution sl;
    
    vector<int> nums;
    for(int temp = 0; cin >> temp;){
        nums.push_back(temp);
        if(cin.get() == '\n')
            break;
    }
    vector<int> res = sl.findClosestElements(nums, 2, 5);
    cout << "The cloest emements are: "<<endl;
    for(auto e:res){
        cout<<e<<" ";
    }
    cout<<endl;
    //system("pause");
    return 0;
}  

