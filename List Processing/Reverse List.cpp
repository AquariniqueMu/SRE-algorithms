/*
 * @Author: your name
 * @Date: 2022-04-21 21:00:53
 * @LastEditTime: 2022-04-21 21:00:54
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \cpp\SRE Train\List Processing\Reverse List.cpp
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
          
        ListNode* pre = NULL;
        ListNode* cur = pHead;
         
         
        while (cur != NULL){
            ListNode* temp;
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
             
             
        }
         
        return pre;
    }
};