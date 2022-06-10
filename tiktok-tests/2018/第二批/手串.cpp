/*
 * @Author: your name
 * @Date: 2022-03-12 17:13:38
 * @LastEditTime: 2022-03-12 17:16:49
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\tiktok\2018\第二批\手串.cpp
 */
/*设置一个大小为wnd(m)的滑动窗口，vis向量记录窗口内珠子颜色的种类及其次数，
窗口每次向右吸纳新一个珠子前将最左边珠子的颜色信息删除，这样可以避免重复计算，
由于是环形，设置left=i%n可以做到窗口包含第一个和最后一个珠子，当vis[i]>=2
时，说明该颜色已经记录到结果中了，不用管它，继续检查下一种颜色*/
 
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
int main(){
    int n,wnd,color,res=0;
    vector<vector<int>> vec;
    cin>>n;
    cin>>wnd;
    cin>>color;
    vector<int> vis(color+1,0);
        int tmp1;
    while(cin>>tmp1){
        vector<int> num;
            for(int i=0;i<tmp1;i++){
                int tmp2;
                cin>>tmp2;
                num.push_back(tmp2);
            }
        vec.push_back(num);
        num.clear();
    }
    for(int i=0;i<n+wnd;i++){
        if(i>=wnd){
        for(int j=0;j<vec[i-wnd].size();j++){
            if(vis[vec[i-wnd][j]]==1)
                vis[vec[i-wnd][j]]--;
        }
        }
            int left=i%n;
        for(int j=0;j<vec[left].size();j++){
            if(vis[vec[left][j]]<2)//vis[a]只能是等于0，1，2或者3
                vis[vec[left][j]]++;
            if(vis[vec[left][j]]==2){
                res++;
                vis[vec[left][j]]++;
            }
        }
    }
        cout<<res<<endl;
    return 0;
}