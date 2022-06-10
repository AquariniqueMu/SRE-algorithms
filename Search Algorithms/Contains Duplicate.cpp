/*
 * @Author: your name
 * @Date: 2022-04-21 19:00:16
 * @LastEditTime: 2022-04-21 19:12:48
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\SRE Train\Search Algorithms\Contains Duplicate.cpp
 */

//查找数组中的重复元素
#include <iostream>    
#include <vector>
#include <hash_map>
#include <unordered_set>

using namespace std;  

//哈希表方法
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int x: nums) {
            if (s.find(x) != s.end()) {
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};

int main(){
    vector<int> nums;
    Solution sl;
    cout<<"Please input the nums array: "<<endl;
    for(int temp = 0; cin >> temp;){
        nums.push_back(temp);
        if(cin.get() == '\n')
            break;
    }
    bool res = sl.containsDuplicate(nums);
    cout<<"The result of Contains Duplicate detection is: ["<<res<<"]"<<endl;
}