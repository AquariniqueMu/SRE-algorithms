/*
 * @Author: your name
 * @Date: 2022-03-11 23:25:04
 * @LastEditTime: 2022-03-20 21:18:48
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\tiktok\2022\跳伞问题.cpp
 */

/*
跳伞问题---第一行输入玩家个数n（玩家编号0到 n-1）和跳伞跟随操作数k 接下来k行是具体跟随情况 如果A跟随B 那么A的跟随者也会成为B的跟随者 一个人跟他的跟随者是一个队伍 求一个最长的队伍的长度
 eg： 给定玩家的个数为5，跳伞的操作数为3，第二行是4 2，第三行是3 2，第四行是2 1，那么最长队伍1-2-3/4 长度为4个人。
*/

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

int main(){
    vector<vector<int>> playerFollow;

    vector<vector<int>> op;
    vector<int> op_index;
    int playerNum;
    int opNum;
    cout<<"input the player number and the Operator number: "<<endl;
    scanf("%d%d", &playerNum, &opNum);
    cout<<"input the plan of each operator: "<<endl;
    for(int cnt= 0; cnt < opNum; cnt++){
        int a,b;
        scanf("%d%d",&a,&b);
        op_index.push_back(a);
        op_index.push_back(b);
        op.push_back(op_index);
        op_index.clear();
    }
    //循环操作数 K 次
    for(int index_1=0;index_1<op.size();index_1++){
        //观察是否成功储存每次操作情况
        cout<<op[index_1][0]<<" | "<<op[index_1][1]<<" | "<<endl;
        //
        
    }
    
}