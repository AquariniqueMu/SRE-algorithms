/*
 * @Author: your name
 * @Date: 2022-04-20 20:40:59
 * @LastEditTime: 2022-04-20 21:19:27
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\SRE Train\二分查找.cpp
 */
/*
请实现无重复数字的升序数组的二分查找

给定一个 元素升序的、无重复数字的整型数组 nums 和一个目标值 target ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标（下标从 0 开始），否则返回 -1

数据范围：0 \le len(nums) \le 2\times10^50≤len(nums)≤2×10 
5
  ， 数组中任意值满足 |val| \le 10^9∣val∣≤10 
9
 
进阶：时间复杂度 O(\log n)O(logn) ，空间复杂度 O(1)O(1)

EXP1:
输入：[-1,0,3,4,6,10,13,14],13
返回值：6
说明：13 出现在nums中并且下标为 6   


EXP2:
输入：[],3
返回值：-1
说明：nums为空，返回-1    

EXP3:
输入：[-1,0,3,4,6,10,13,14],2
返回值：-1
说明：2 不存在nums中因此返回 -1 

*/

#include <iostream>
#include <vector>

using namespace std;


//Lambda表达式是C++11引入的特性，是一种描述函数对象的机制，它的主要应用是描述某些具有简单行为的函数。Lambda也可以称为匿名函数。
//因为C++中的std :: cin和std :: cout为了兼容C，保证在代码中同时出现std :: cin和scanf或std :: cout和printf时输出不发生混乱，所以C++用一个流缓冲区来同步C的标准流。通过std :: ios_base :: sync_with_stdio函数可以解除这种同步，
//让std :: cin和std :: cout不再经过缓冲区，自然就节省了许多时间

static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @param target int整型 
     * @return int整型
     */
    int search(vector<int>& nums, int target) {
        // write code here
        int start = 0, end = nums.size() - 1, middle;
        while(start <= end){
            middle = start + ((end - start) >> 1);
            if (nums[middle] == target)
                return middle;
            else if (nums[middle] < target)
                start = middle + 1;
            else
                end = middle - 1;
        }
        return -1;
    }
};

int main(){
    vector<int> nums;
    for(int temp = 0; cin >> temp;){
        nums.push_back(temp);
        if(cin.get() == '\n')
            break;
    }

    cout<< "The number of this vector is: "<< nums.size()<<endl;
    Solution sl;
    int result = sl.search(nums, 8);
    cout<<"The index of the target is: "<<result<<endl;
    // for(int i = 0; i < nums.size(); i++)
    //     cout<<"nums["<<i<<"]:"<<nums[i]<<endl;
    system("pause");
    return 0;

}