/*
 * @Author: your name
 * @Date: 2022-03-10 17:59:30
 * @LastEditTime: 2022-03-10 18:13:42
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\tiktok\2022\字符串子集可能性.cpp
 */
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
    int cnt = 0;
    int lengthSubstr;
	cout << "input the string:";
	cin>>str;
    cout << "the substr length is:";
    cin>>lengthSubstr;
	cout << "the child strings include:" << endl;
	for (int low = 0; low < str.length(); low++)//low位子串的起始位置，遍历整个原字符串的每个元素作为子串起始位
		for(int step = 1; low + step <= str.length(); step++)//step为步长，当前起始位下从步长唯1开始加以增长到最大步长，遍历以low为首的所有子串
		{
            if(str.substr(low,step).size() == lengthSubstr){
            cout << str.substr(low, step) << endl;//输出子串
            cnt++;
            }
        }
    cout << cnt <<endl;
    return 0;
}
