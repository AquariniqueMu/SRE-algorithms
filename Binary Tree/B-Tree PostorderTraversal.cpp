/*
 * @Author: your name
 * @Date: 2022-04-21 00:55:55
 * @LastEditTime: 2022-04-21 00:57:54
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\SRE Train\Binary Tree\B-Tree PostorderTraversal.cpp
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

class PostSolution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型vector
     */
    vector<int> res;
    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        dfs(node->left);
        dfs(node->right);
        res.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        // write code here
        if (root == nullptr) return {};
        dfs(root);
        return res;
    }
};