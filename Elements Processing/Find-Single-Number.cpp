/*
 * @Author: your name
 * @Date: 2022-04-21 20:50:30
 * @LastEditTime: 2022-04-21 20:54:11
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\SRE Train\Elements Processing\Find-Single-Number.cpp
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//异或运算

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto e: nums) ret ^= e;
        return ret;
    }
};

int main(){
    vector<int> nums;
    Solution sl;
    cout<<"Please input the int nums: "<<endl;
    for(int temp = 0; cin >> temp;){
        nums.push_back(temp);
        if(cin.get() == '\n')
            break;
    }
    int res = sl.singleNumber(nums);
    cout<<"The only single number in this array is: [ "<<res<<" ]"<<endl;
}