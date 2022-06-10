/*
 * @Author: your name
 * @Date: 2022-04-21 00:56:08
 * @LastEditTime: 2022-04-21 00:57:56
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\SRE Train\Binary Tree\B-Tree LevelorderTraversal.cpp
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
 	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class LevelSolution {
public:
    /**
     *
     * @param root TreeNode类
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > levelOrder(TreeNode* root) {
        queue<TreeNode*> leaves;
        vector<vector<int> > ans;
        int n =1;
        TreeNode* tmp;
        leaves.push(root);
        while(!leaves.empty()){
            n=leaves.size();
            vector<int> parts;
            for(int i =0;i<n;i++){
                tmp = leaves.front();
                leaves.pop();
                if(tmp->left){
                    leaves.push(tmp->left);
                }
                if(tmp->right){
                    leaves.push(tmp->right);
                }
                parts.push_back(tmp->val);
            }
            ans.push_back(parts);
        }
        return ans;
    }
};