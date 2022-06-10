/*
 * @Author: your name
 * @Date: 2022-04-20 21:28:13
 * @LastEditTime: 2022-04-20 21:46:12
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\SRE Train\Full Permutation.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

//Di Gui
class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        getAll(res, num, 0);
        return res;
    }
    void getAll(vector<vector<int>>& res, vector<int>& num, int start){
        if(start == num.size() - 1){//if only one number left
            res.push_back(num);
            return;     
        }
        for(int i = start; i < num.size(); i++){
            swap(num[i], num[start]); //
            getAll(res, num, start+1);
            swap(num[i], num[start]);
        }
    }
};



int main(){
    vector<int> nums;
    for(int temp = 0; cin >> temp;){
        nums.push_back(temp);
        if(cin.get() == '\n')
            break;
    }

    Solution sl;
    vector<vector<int>> result = sl.permute(nums); // get the results
    //loop the vector of int vectors
    for(auto e:result){
        cout<<"[";
        //loop the int vectors
        for(auto a:e){
            cout<<a;
        }
        cout<<"], ";
    }
    system("pause");
    return 0;

}