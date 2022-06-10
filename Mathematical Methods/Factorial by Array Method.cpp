/*
 * @Author: your name
 * @Date: 2022-04-20 22:16:10
 * @LastEditTime: 2022-04-21 18:15:34
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\SRE Train\Factorial.cpp
 */
#include <iostream>    
#include <vector>
#include <cstring>
#define MAX 40000
using namespace std;  
int a[MAX];
class Solution {
public:
    vector<int> thefactorial(int num){
        vector<int> res;
        if(num >= 0){
            memset(a, 0, sizeof(a));                            //初始化0；下面的a[j] = a[j] * i + carry计算过程中会用到a[j]=0
	        int topDigit = 0;                                        //最高位
	        a[0] = 1;
	        int carry = 0;                                          //用于判断是否进位，也就是j是否+1。
	        for (int i = 2; i <= num; i++) {                    //i为用来阶乘的数字，就是2~n之间的数字
		        for (int j = 0; j <= topDigit; j++) {                //j循环用来将计算出来的结果按位分割并存储到数组中
			        a[j] = a[j] * i + carry;
			        carry = a[j] / 10;                              //carry就是下一次再次进入j循环时的a[j]初始值，结合下面的判断语句
				     //如果这里的carry<10,topDigit最高位就没必要再加了，如果carry>10,则继续分割，直到carry<10为止
			        if (j == topDigit && carry >= 1) {
				        topDigit++;
			        }
			        a[j] = a[j] % 10;                                   //取余得到第j位上该放置的数字
		        }
	        }
            for( int i = topDigit; i >= 0; i--){
                res.push_back(a[i]);
            }
            return res;
        }
        else
            return {-1};
    }

};



int main()  
{  
    Solution sl;
    int num;
    cout << "Please input the factorial number: ";
    cin >> num;
    vector<int> res = sl.thefactorial(num);
    cout << "The result of factorial is: "<<endl;
    for(auto e:res){
        cout<<e;
    }
    cout<<endl;
    //system("pause");
    return 0;
}  