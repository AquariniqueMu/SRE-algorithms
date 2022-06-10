/*
 * @Author: your name
 * @Date: 2022-04-21 00:55:46
 * @LastEditTime: 2022-04-21 00:57:56
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\SRE Train\Binary Tree\B-Tree InorderTraversal.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
 	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    void Traversal(vector<int> &res,TreeNode* root){
        if(root == NULL) return;
        Traversal(res,root->left);
        res.push_back(root->val);
        Traversal(res,root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        Traversal(res,root);
        return res;
    }
};