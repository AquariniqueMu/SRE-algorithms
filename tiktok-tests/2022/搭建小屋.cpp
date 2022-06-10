/*
 * @Author: your name
 * @Date: 2022-03-12 22:53:33
 * @LastEditTime: 2022-03-20 21:18:37
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\tiktok\2022\搭建小屋.cpp
 */
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;
int main(){
    
    string str;
    vector<vector<int>> oceanland;
    vector<int> oceanland_temp;
    str.resize(100);
    int m;
    int n;
    //获取字符串和分区个数 K
    cout<<"input the row and the column:"<<endl;
    scanf("%d%d", &m, &n);
    //输入分区的左右端点并将其push_back进存储每次操作的变量
    for(int cnt= 0; cnt < m; cnt++){
        
        for(int cnt_2 = 0; cnt_2 < n;cnt_2++){
            int a;
            scanf("%d",&a);
            oceanland_temp.push_back(a);
            // oceanland_temp.push_back(b);
        }
        
        oceanland.push_back(oceanland_temp);
        oceanland_temp.clear();
    }
    for(int index_1=0;index_1<oceanland.size();index_1++){
        //观察是否成功储存分区端点
        for(int index_2=0; index_2<oceanland[0].size();index_2++)
        cout<<oceanland[index_1][index_2]<<" | ";
        cout<<endl;
        //观察是否能根据分区端点输出相应的字符串子串
    }
    
}