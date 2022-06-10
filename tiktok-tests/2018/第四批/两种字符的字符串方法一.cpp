/*
 * @Author: your name
 * @Date: 2022-03-10 17:20:37
 * @LastEditTime: 2022-03-10 17:20:37
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\tiktok\2018\两种字符的字符串方法二.cpp
 */
#include <iostream>
#include <string>
using namespace std;

int GetLongStr(string str,int num,int count){
    int res=-1;
    int left=0,right=0;
    int tmp1=0,tmp2=0;
    for (right=0;right<str.size();right++){
        if (str[right]=='a'){
            tmp1++;
        }else{
            tmp2++;
        }
        if (tmp1>count && tmp2>count){
            res=max(res,right-left);
            if (str[left]=='a'){
                tmp1--;
            }else{
                tmp2--;
            }
            left++;
        }
    }
    return res;
}

int main(){
    int num,count;
    cin>>num>>count;
    string str_in;
    cin>>str_in;
    cout<<GetLongStr(str_in,num,count);
    return 0;
}

