# Iterative solution:

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){
            return list2;
        } else if(!list2){
            return list1;
        }
        
        ListNode *head, *it;
        
        list1->val > list2->val ? (head = list2, list2 = list2->next) : (head = list1, list1 = list1->next);
        
        it = head;
        while(list1 && list2){
            if(list1->val < list2->val){
                it->next = list1;
                list1 = list1->next;
                it = it->next;
            } else{
                it->next = list2;
                list2 = list2->next;
                it = it->next;
            }
        }
        
        if(list1){
            it->next = list1;
        } else if(list2){
            it->next = list2;
        }
        
        return head;
    }
};


# My solution from long time ago:


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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
            return list2;
        else if(list2 == nullptr)
            return list1;
        
        ListNode *first = list1, *second = list2, *head, *third;
        if(list1 -> val <= list2 -> val){
            head = list1;
            first = first->next;
        }
        else{
            head = list2;
            second = second->next;
        }
                
        third = head;
        
        while(first != nullptr && second != nullptr)
        {
            if(first->val <= second->val)
            {
                third->next = first;
                third = third->next;
                first = first->next;
            }
            else
            {
                third->next = second;
                third = third->next;
                second = second->next;
            }
        }
        
        
        if(first != nullptr)
        {
            third->next = first;
        }
        else if(second != nullptr)
        {
            third->next = second;
        }
        
        return head;
    }
};
