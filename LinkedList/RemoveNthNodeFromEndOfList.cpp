# Better approach that I searched on the internet:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head;
        
        for(auto i = 0; i < n; i++){
            fast = fast->next;
        }
        
        if(fast == nullptr){
            return head->next;
        }
        
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return head;
    }
};

# Naive approach:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        int8_t cnt = 1;
        
        while (ptr->next != nullptr){
            ptr = ptr->next;
            cnt++;
        }
        
        ptr = head;
        
        for (int i = 0; i < cnt - n - 1; i++){
            ptr = ptr->next;
        }
        
        if (cnt == 1){
            head = nullptr;
        } else if (cnt == n){
            head = head->next;
        } else if (ptr->next->next == nullptr){
            ptr->next = nullptr;
        } else{
            ptr->next = ptr->next->next;
        }
        
        return head;
    }
};
