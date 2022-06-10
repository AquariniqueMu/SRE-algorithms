/*
 * @Author: your name
 * @Date: 2022-03-10 18:46:26
 * @LastEditTime: 2022-03-11 23:24:48
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\tiktok\2022\字符串分区与01翻转.CPP
 */
/*
翻转01串---第一行给一个字符串和分区个数k 接下来k行是具体每个分区的左断点和右端点（从1开始）求翻转后的结果
 eg： 给一个字符串“010110”，它的分区个数是2，第二行给出具体分区
情况是1 3， 第三行是 2 2。那么也就意味着 先将第一个数 到第三个数进行翻
转，然后再将第二个数进行翻转，所以结果是111110。
*/


#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;
int main(){
    
    string str;
    vector<vector<int>> op;
    vector<int> op_index;
    str.resize(100);
    int blockNum;
    //获取字符串和分区个数 K
    cout<<"input the string and the blockNum:"<<endl;
    scanf("%s%d", &str[0], &blockNum);
    //输入分区的左右端点并将其push_back进存储每次操作的变量
    for(int cnt= 0; cnt < blockNum; cnt++){
        int a,b;
        scanf("%d%d",&a,&b);
        op_index.push_back(a);
        op_index.push_back(b);
        op.push_back(op_index);
        op_index.clear();
    }
    //循环分区个数 K 次
    for(int index_1=0;index_1<op.size();index_1++){
        //观察是否成功储存分区端点
        cout<<op[index_1][0]<<" | "<<op[index_1][1]<<" | "<<endl;
        //观察是否能根据分区端点输出相应的字符串子串
        cout<<"substr is: "<<str.substr(op[index_1][0]-1,op[index_1][1]+1-op[index_1][0])<<endl;
        //从本次分区的左端点起，到右端点为止进行循环，并翻转 0 和 1
        for(int index_2 = op[index_1][0]-1; index_2 < op[index_1][1]; index_2++){
            if(str[index_2] == '1')
                str[index_2] = '0';
            else if(str[index_2] == '0')
                str[index_2] = '1';
        }
        //输出当前字符串查看是否翻转
        cout<<str<<endl;
    }
    return 0;
}