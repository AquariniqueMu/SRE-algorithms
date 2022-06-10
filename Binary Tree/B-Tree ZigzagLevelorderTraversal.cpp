/*
 * @Author: your name
 * @Date: 2022-04-21 19:13:33
 * @LastEditTime: 2022-04-21 19:17:18
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\SRE Train\Binary Tree\B-Tree ZigzagLevelorderTraversal.cpp
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//二叉树的锯齿形层序遍历
//即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行

struct TreeNode {
 	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


/*
此题是「102. 二叉树的层序遍历」的变种，最后输出的要求有所变化，要求我们按层数的奇偶来决定每一层的输出顺序。
规定二叉树的根节点为第 00 层，如果当前层数是偶数，从左至右输出当前层的节点值，否则，从右至左输出当前层的节点值。

我们依然可以沿用第 102 题的思想，修改广度优先搜索，对树进行逐层遍历，用队列维护当前层的所有元素，
当队列不为空的时候，求得当前队列的长度 \textit{size}size，每次从队列中取出 \textit{size}size 个元素进行拓展，然后进行下一次迭代。

为了满足题目要求的返回值为「先从左往右，再从右往左」交替输出的锯齿形，我们可以利用「双端队列」的数据结构来维护当前层节点值输出的顺序。

双端队列是一个可以在队列任意一端插入元素的队列。在广度优先搜索遍历当前层节点拓展下一层节点的时候我们仍然从左往右按顺序拓展，
但是对当前层节点的存储我们维护一个变量 \textit{isOrderLeft}isOrderLeft 记录是从左至右还是从右至左的：

如果从左至右，我们每次将被遍历到的元素插入至双端队列的末尾。

如果从右至左，我们每次将被遍历到的元素插入至双端队列的头部。

当遍历结束的时候我们就得到了答案数组。

*/




class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        bool isOrderLeft = true;

        while (!nodeQueue.empty()) {
            deque<int> levelList;
            int size = nodeQueue.size();
            for (int i = 0; i < size; ++i) {
                auto node = nodeQueue.front();
                nodeQueue.pop();
                if (isOrderLeft) {
                    levelList.push_back(node->val);
                } else {
                    levelList.push_front(node->val);
                }
                if (node->left) {
                    nodeQueue.push(node->left);
                }
                if (node->right) {
                    nodeQueue.push(node->right);
                }
            }
            ans.emplace_back(vector<int>{levelList.begin(), levelList.end()});
            isOrderLeft = !isOrderLeft;
        }

        return ans;
    }
};

