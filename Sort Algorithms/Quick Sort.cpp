/*
 * @Author: your name
 * @Date: 2022-03-06 02:40:46
 * @LastEditTime: 2022-03-06 02:40:46
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\qsort.cpp
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void swap(int* a, int* b) {
        int t = *a;
        *a = *b;
        *b = t;
    }


    int partition(std::vector<int>& v, int low, int hight) {
        int pivot = v[hight];
        int i = low;

        for (int j = low ; j <= hight - 1; ++j)  //注意这里的<=边界条件！
        {
            if (v[j] < pivot) {
                
                swap(&v[i], &v[j]);
                ++i;
            }
        }

        swap(&v[i], &v[hight]);

        return i;

    }

    void quick_sort(std::vector<int>& v, int low, int hight) {
        if (low < hight) {

            int q = partition(v, low, hight);
            quick_sort(v, low, q - 1);
            quick_sort(v, q + 1, hight);
        }

    }

};

int main() {
    Solution so;

    vector<int> test = { 9, 7, 18, -1, 5, 3, 0 };

    int length = test.size();

    so.quick_sort(test, 0, length - 1);

    for (auto e : test) {
        cout << " " << e;
    }



    return 0;
}
