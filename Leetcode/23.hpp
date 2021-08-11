/*
23.合并K个升序链表
    给你一个链表数组，每个链表都已经按升序排列。请你将所有链表合并到一个升序链表中，
    返回合并后的链表。
示例 1：
    输入：lists = [[1,4,5],[1,3,4],[2,6]]
    输出：[1,1,2,3,4,4,5,6]
示例 2：
    输入：lists = []
    输出：[]
示例 3：
    输入：lists = [[]]
    输出：[]
*/

#ifndef PAT_23_HPP
#define PAT_23_HPP

#include <algorithm>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



bool cmp (ListNode *a, ListNode *b) {
    return a->val>b->val;
}

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        int n=lists.size(), hi{};
        if (n==0) return nullptr;
        ListNode ans{}; ListNode *ptr=&ans;
        ListNode *heap[n];
        for(int i=0;i!=n;) {
            if(lists[hi]!= nullptr) {
                heap[i++]=lists[hi++];
            } else {
                --n;++hi;
            }
        }
        std::make_heap(heap, heap+n, cmp);
        while(n!=0) {
            ptr->next=new ListNode {heap[0]->val, nullptr};
            ptr=ptr->next;
            std::pop_heap(heap, heap+n, cmp);
            if(heap[n-1]->next!= nullptr) {
                heap[n-1] = heap[n-1]->next;
                std::push_heap(heap, heap+n, cmp);
            } else {
                --n;
            }
        }
        return ans.next;
    }
};

#endif //PAT_23_HPP
