// cesun, 9/20/20 12:32 PM.

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

static ListNode *foo(ListNode *cur, ListNode *prev) {
    if (cur->next) {
        ListNode *ret = foo(cur->next, cur);
        cur->next = prev;
        return ret;
    } else {
        cur->next = prev;
        return cur;
    }
}

#include <stack>

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) return nullptr;
        return foo(head, nullptr);
    }
};