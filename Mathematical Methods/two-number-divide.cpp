/*
 * @Author: your name
 * @Date: 2022-04-20 23:52:23
 * @LastEditTime: 2022-04-21 00:03:55
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\SRE Train\two-number-divide.cpp
 */
#include <iostream>    
#include <vector>
#include <cstring>
using namespace std;  

class Solution {
public:


        // 原理：举个例子：11 除以 3 。
        // 首先 11比 3大，结果至少是 1， 然后我让 3翻倍，就是 6，发现 11 比 3 翻倍后还要大，那么结果就至少是 2 了，那我让这个 6 再翻倍，得 12 ，11 不比 12 大，知道最终结果肯定在 2 和 4 之间。
        // 也就是说 2 再加上某个数，让 11 减去刚才最后一次的结果 6 ，剩下 5 ，我们计算 5 是 3 的几倍，也就是除法，递归出现了。

    int divide(int dividend, int divisor) {         //dividend是被除数，divisor是除数
        if(dividend == 0) return 0;     
        if(divisor == 1) return dividend;
        //先考虑数据溢出
        if(divisor == -1){
            if(dividend>INT_MIN) return -dividend;// 只要不是最小的那个整数，都是直接返回相反数就好啦
            return INT_MAX;// 是最小的那个，那就返回最大的整数啦
        }
        long a = dividend; //被除数
        long b = divisor;  //除数
        int sign = 1; 
        if((a > 0 && b < 0) || (a < 0 && b > 0)){
            sign = -1;
        }
        a = a > 0 ? a : -a; //确保被除数和除数为正
        b = b > 0 ? b : -b;
        long res = div(a,b);
        if(sign > 0)return res > INT_MAX ? INT_MAX : res;
        return -res;
    }
    
    int div(long a, long b){  // 似乎精髓和难点就在于下面这几句
        if(a < b) return 0;
        long count = 1;
        long tb = b; // 在后面的代码中不更新b
        while((tb + tb) <= a){
            count = count + count; // 最小解翻倍
            tb = tb + tb; // 当前测试的值也翻倍
        }
        return count + div(a - tb, b);
    }
};

int main(){
    Solution sl;
    int dividend, divisor;
    cout << "input the dividend: ";
    cin >> dividend;
    cout << "input the divisor: ";
    cin >> divisor;
    int res = sl.divide(dividend, divisor);
    cout << "The result is: "<<res<<endl;
    return 0;
}