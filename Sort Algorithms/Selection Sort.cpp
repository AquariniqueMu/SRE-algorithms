/*
 * @Author: your name
 * @Date: 2022-04-21 19:24:59
 * @LastEditTime: 2022-04-21 19:29:17
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\SRE Train\Sort Algorithms\Selection Sort.cpp
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        void Sort_swap(int &a, int &b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        //方法1
        void Selection_sort(vector<int>::iterator begin,vector<int>::iterator end)
        {
            for (auto p1 = begin; p1 != end; ++p1)
            {
                for (auto p2 = p1; p2 != end; ++p2)
                {
                    if (*p1 > *p2)
                    {
                        int temp = *p1;
                        *p1 = *p2;
                        *p2 = temp;
                    }
                }
            }
        }
        //改进：
        //传入数组指针和数组大小，进行第一次改进，每次循环找出一个最小值和最大值
        void Selection_sort(int a[],size_t size)
        {
            for (size_t i = 0; i < size/2; ++i)
            {
                int max_elem = size-1-i;
                int min_elem = i;
                for (size_t j = i+1; j < size-i; ++j)
                {
                    if (a[j] < a[min_elem])
                    {
                        min_elem = j;
                        continue;//找到小值可直接跳出
                    }
                    if (a[j] > a[max_elem])
                    {
                        max_elem = j;
                    }
                }
                Sort_swap(a[i],a[min_elem]);
                Sort_swap(a[size-1-i],a[max_elem]);	
        
                //关键点：若最后最前位置重复参与了交换过程，则会产生错误
                if((i==size-i-1&&min_elem==max_elem)||(i==max_elem&&size-i-1==min_elem))
                {  
                    Sort_swap(a[i],a[min_elem]);//再换回来
                }  
            }
        }
};