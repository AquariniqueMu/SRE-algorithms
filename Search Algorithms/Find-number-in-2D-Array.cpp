/*
 * @Author: your name
 * @Date: 2022-04-21 18:19:58
 * @LastEditTime: 2022-04-21 19:01:21
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\SRE Train\Search Algorithms\Find-number-in-2D-Array.cpp
 */

/*
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

EXP:
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

给定 target = 5，返回 true。
给定 target = 20，返回 false。

*/


/*
最优思路：
我们将矩阵逆时针旋转 45° ，并将其转化为图形式，发现其类似于 二叉搜索树 ，
即对于每个元素，其左分支元素更小、右分支元素更大。
因此，通过从 “根节点” 开始搜索，遇到比 target 大的元素就向左，反之向右，即可找到目标值 target 。

*/



//二维数组中的查找问题
#include <iostream>    
#include <vector>
using namespace std;  

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int i = matrix.size() - 1, j = 0;
        while(i >= 0 && j < matrix[0].size())
        {
            if(matrix[i][j] > target) i--;
            else if(matrix[i][j] < target) j++;
            else return true;
        }
        return false;
    }
};

int main(){
    vector<vector<int>> matrix;
    vector<int> tmp;
    Solution sl;
    int target;
    int temp=0;
    cout << "Please input the matrix by rows (with a space at the begining): "<<endl;
    while(true){
        for(temp = 0; cin >> temp;){
            tmp.push_back(temp);
            if(cin.get() == '\n')
                break;
        }
        matrix.push_back(tmp);
        vector <int>().swap(tmp);
        if(cin.get() == '\n')
                break;
    }

    for(auto e:matrix){
        cout<<"[ ";
        for(auto a:e){
            cout<<a<<" ";
        }
        cout<<"]"<<endl;
    }

    cout << "Please input the search target: ";
    cin >> target;
    bool res = sl.findNumberIn2DArray(matrix, target);
    cout << "The search result is: "<<res<<endl;
}

