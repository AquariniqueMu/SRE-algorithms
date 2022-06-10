/*
 * @Author: your name
 * @Date: 2022-03-11 00:14:05
 * @LastEditTime: 2022-03-20 21:18:46
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\tiktok\2022\字符串子集可能性.cpp
 */

// /*
// 字符串子集的可能性----第一行给一个字符串B 和它的子字符串A的位数 求共有多少种可能性（不考虑B中有重复字符的情况）
//  eg: 给一个字符串B "word", 它的子字符串A有两位，那么A是有6种可能性
// 的。
// */




#include<iostream>
#include<string.h>
#include<string>
#include<vector>
using namespace std;

// void Combination(char* str) {
// 	size_t len = strlen(str);
// 	for (int i = 1; i < (1 << len); ++i) {
// 		for (int j = 0; j < len; ++j) {
// 			if (i & (1 << j))
// 				cout << str[j];
// 		}
// 		cout << endl;
// 	}
// }



int main(){
    vector<char> p;
    string str;
    cout<<"input the string:"<<endl;
    cin>>str;

    int place;
    cout<<"input the digit places:"<<endl;
    cin>>place;

    for(int index = 0; index <str.size();index++){
        //cout<<str[index]<<endl;
        p.push_back(str[index]);
        
    }
    for(auto e:p){
        cout<<e<<" "<<endl;
    }
    int cnt=0;
    int looptimes = 0.5*(place)*(place-1);
    for(int index_1 = 0; index_1 < looptimes; index_1++){
        for(int index_2 =0; index_2 < p.size(); index_2++){
            for(int step = 1; index_2+step < p.size();step++){
                cout<<p[index_2]<<p[index_2+step]<<endl;
                cnt++;
            }
        }
    }
    cout<<"the num of substr is: "<<cnt<<endl;



    // int cnt = 0;
    // for (int i = 1; i < (1 << p.size()); ++i) {
	// 	for (int j = 0; j < p.size(); ++j) {
	// 		if (i & (1 << j))
                
	// 			cout << p[j]<<" "<<i<<" "<<j<<" "<<cnt<<endl;
	// 	}
    //     cnt++;
	// 	cout << endl;

    // }
    





    // int cnt = 0;
    
    // for(int index_1 = 0; index_1 < p.size(); index_1++){
    //     for(int index_2 = 0; index_2 < )
    // }

}
