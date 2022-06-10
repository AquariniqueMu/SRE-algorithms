/*
 * @Author: your name
 * @Date: 2022-03-09 21:04:03
 * @LastEditTime: 2022-03-09 21:04:03
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\tiktok\最大映射.cpp
 */
#include <iostream>
#include <String> 
#include <algorithm>
#include <cmath>
using namespace std;
struct weight{
	long long num;
	bool head;
}A[10];
int cmp(const weight &a,const weight &b)
{
    return a.num<b.num;
}
int main() {
	int n;
	cin >> n;
	string str;
	long long MAX = 0;
	while(n--) {
		cin >> str;
		for(int i=str.length()-1; i>=0; i--) {
			A[str[i]-'A'].num += pow(10, str.length()-i-1);
			if(i==0)
				A[str[i]-'A'].head = true;
		}
	}
	sort(A, A+10,cmp);
	if(A[0].head){
		int i;
		for(i=1;i<10;i++){
			if(!A[i].head){
				swap(A[0],A[i]);
				break;
			}
		}
		sort(A+1, A+i+1,cmp);
	}
	for(int i=0; i<=9; i++) {
		MAX += (A[i].num * i);
	} 
	cout << MAX;
}

