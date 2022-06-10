/*
 * @Author: your name
 * @Date: 2022-03-10 17:30:12
 * @LastEditTime: 2022-03-10 17:30:12
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\tiktok\2018\三支球队方法三.cpp
 */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
bool judge(ll n, ll k, ll d1, ll d2) {
    if(n % 3 != 0) return false;
    ll residue = n-k;
    for(int i = 0; i<2; i++) {
        d1 = -d1;
        for(int j = 0; j<2; j++) {
            d2 = -d2;
            vector<ll> v;
            v.push_back(d1);
            v.push_back(d2);
            v.push_back(0);
            sort(v.begin(), v.end());
            while(v[0] < 0) {
                v[1]+=-v[0], v[2]+=-v[0];
                v[0]+=-v[0];
            }
            if(v[2]+v[2]+v[2] > n) continue;
            ll tem = 2*v[2]-v[0]-v[1];
            if(residue >= tem) {
                if((residue-tem) % 3 == 0) return true;
            }
        }
    }
    return false;
}
int main() {
    //freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    ll n, k, d1, d2;
    for(int i = 0; i<t; i++) {
        cin >> n >> k >> d1 >> d2;
        judge(n, k, d1, d2) ? cout << "yes\n" : cout << "no\n";
    }
    return 0;
}