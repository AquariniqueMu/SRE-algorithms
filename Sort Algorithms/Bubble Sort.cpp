/*
 * @Author: your name
 * @Date: 2022-04-21 19:29:50
 * @LastEditTime: 2022-04-21 19:34:05
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\SRE Train\Sort Algorithms\Bubble Sort.cpp
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void swap(int* a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    void BubbleSort(int a[], int len){
        int max = len - 1;
        for(int i=0;i<max;i++){
            for (int j = 0; j < max - i; j++) {
                if (a[j] > a[j + 1]) {
                    swap(a, j, j + 1);
                }
            }
        }
    }

};