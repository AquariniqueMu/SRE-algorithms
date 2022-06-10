/*
 * @Author: your name
 * @Date: 2022-04-21 00:05:26
 * @LastEditTime: 2022-04-21 00:12:30
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\SRE Train\addTwoNumbers.cpp
 */
#include <iostream>
#include <vector>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 使用prenode而不需要单独考虑头节点，以简化代码
        ListNode *prenode = new ListNode(0);
        ListNode *lastnode = prenode;
        int val = 0;
        while(val || l1 || l2) {
            val = val + (l1?l1->val:0) + (l2?l2->val:0);
            lastnode->next = new ListNode(val % 10);
            lastnode = lastnode->next;
            val = val / 10;
            l1 = l1?l1->next:nullptr;
            l2 = l2?l2->next:nullptr;
        }
        ListNode *res = prenode->next;
        delete prenode; // 释放额外引入的prenode
        return res;
    }
};

ListNode* generateListNode(std::vector<int> vals);
void freeListNode(ListNode* head);
void printListNode(ListNode* head);

int main()
{
    auto list1 = generateListNode({1, 4, 6});
    auto list2 = generateListNode({9, 4, 6, 9});
    printListNode(list1);
    printListNode(list2);
    Solution s;
    auto sum = s.addTwoNumbers(list1, list2);
    printListNode(sum);
    freeListNode(list1);
    freeListNode(list2);
    freeListNode(sum);
    return 0;
}

ListNode* generateListNode(std::vector<int> vals) 
{
    ListNode *res = nullptr;
    ListNode *last = nullptr;
    for(auto val : vals) {
        if(last) {
            last->next = new ListNode(val);
            last = last->next;
        }
        else {
            res = new ListNode(val);
            last = res;
        }
    }
    return res;
}

void freeListNode(ListNode* head)
{
    ListNode* node = head;
    while(node) {
        auto temp = node->next;
        delete node;
        node = temp;
    }
}

void printListNode(ListNode* head)
{
    ListNode* node = head;
    while(node) {
        std::cout << node->val << ", ";
        node = node->next;
    }
    std::cout << std::endl;
}
