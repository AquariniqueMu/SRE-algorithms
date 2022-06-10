/*
 * @Author: your name
 * @Date: 2022-04-21 21:07:50
 * @LastEditTime: 2022-04-21 21:14:12
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\SRE Train\Elements Processing\Remove-Duplicate-Letters.cpp
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//方法一：贪心算法 + 单调栈
class Solution1 {
public:
    string removeDuplicateLetters(string s) {
        vector<int> vis(26), num(26);
        for (char ch : s) {
            num[ch - 'a']++;
        }

        string stk;
        for (char ch : s) {
            if (!vis[ch - 'a']) {
                while (!stk.empty() && stk.back() > ch) {
                    if (num[stk.back() - 'a'] > 0) {
                        vis[stk.back() - 'a'] = 0;
                        stk.pop_back();
                    } else {
                        break;
                    }
                }
                vis[ch - 'a'] = 1;
                stk.push_back(ch);
            }
            num[ch - 'a'] -= 1;
        }
        return stk;
    }
};


//方法二：栈判断
/*
要想使结果的字典序最小，就应该尽可能地将小的元素留在前面。

 

如果stk栈顶的元素大于当前遍历到的元素，根据上述原则，则应该在条件允许的情况下回避这一情况，根据题目要求（去重）,只有在后续还有这个栈顶元素的情况下才能将这个栈顶元素去掉（减少一个逆序）。如果后续没有这个栈顶元素，则只能将它保留在这儿，即使它大于它的下一个元素。

这样一来，stk中保存的两两相邻元素要么是顺序的（前一个小于后一个）要么是逆序的（前一个大于后一个，虽有违背最小排列，但由于没有后续相同元素可以替换，只能这样将就）。

由2）可知如果当前元素存在于stk中，则说明stk中的这个元素已经是顺序的了（^-^），所以应该在循环中先判断这一情况，直接跳过当前元素。

同时，当根据条件去掉一个栈顶元素时，新的栈顶元素可能也大于当前元素，所以应该继续判断新的栈顶元素和当前元素的关系，用一个while循环，直到出现一个不满足循环条件的栈顶元素（要么小于当前元素，要么大于当前元素但后续又无与之相同的元素来替代）。


*/

class Solution2 {
public:
    string removeDuplicateLetters(string s) {
        string stk;   ////模拟栈
        size_t i=0;  ////非负整数
        for(;i<s.size();i++){
            if(stk.find(s[i])!=string::npos) continue;   //栈中不包含这个字符
            while(!stk.empty()&&stk.back()>s[i]
            &&s.find(stk.back(),i)!=string::npos){  ////栈不为空且当前字符大于栈顶字符且这个元素以后还会出现
                stk.pop_back();   ////弹出栈顶元素
            }
            stk.push_back(s[i]);
            //cout<<stk<<endl;
        }
        return stk;
    }
};


//方法三：表 + 两遍遍历
class Solution3 {
public:
    //count表示字符表，used用来记录已经添加过的字符
    string removeDuplicateLetters(string s) {
        vector<int> count(26);
        bool used[26];
        memset(used,false,sizeof(used));
        string s1="";

        //1、建立字符表
        for(auto c:s)
            count[c-'a']++;

        //2、用来添加字符
        for(auto c:s){
            count[c-'a']--;//无论是否添加字符c到s1中，都需要将该字符个数减1，表示能使用该字符的次数少了一次
            if(used[c-'a']) continue;//字符c已使用过了，不能重复使用

            //字符c小于s1的尾字符，其尾字符在字符表中还有剩余，所以我们需要删除尾字符，同时标记尾字符为没有使用过
            while(s1.length()>0 && c<s1[s1.length()-1] && count[s1[s1.length()-1]-'a']>0){
                used[s1[s1.length()-1]-'a']=false;
                s1.erase(s1.length()-1);
            }

            //添加字符c，并标记字符c已使用过了
            s1+=c;
            used[c-'a']=true;
        }
        return s1;
    }
};
