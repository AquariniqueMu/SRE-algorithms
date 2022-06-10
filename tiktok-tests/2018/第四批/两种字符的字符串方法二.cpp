
//leetcode 424

#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
int main()
{
    int n,m;
    cin>>n>>m;
    string str;
    cin>>str;
    vector<int> Hash(2,0);
    int res = 0, maxNum = 0;
    for(int i=0,j=0;j<str.size();j++){
        Hash[str[j]-'a']++;
        maxNum = max(maxNum, Hash[str[j]-'a']);
        while(j-i+1-maxNum>m)
            Hash[str[i++]-'a']--;
        res = max(res,j-i+1);
    }
    cout<<res<<endl;
}