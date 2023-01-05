# The solution I came up with the first and the second time: 
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr){
            return head;
        }
        
        stack<ListNode*> nodes;
        ListNode* ptr = head;
        
        while (ptr->next != nullptr){
            nodes.push(ptr);
            ptr = ptr->next;
        }
        
        head = ptr;
        
        while (!nodes.empty()){
            ptr->next = nodes.top();
            nodes.pop();
            ptr = ptr->next;
        }
        
        ptr->next = nullptr;
        return head;
    }
};

# The iterative solution: 

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
    ListNode* reverseList(ListNode* head) {
        
        if (!head || !head->next){
            return head;
        }
        
        ListNode *prevHead = nullptr, *nextHead = head->next, *thisHead = head;
        
        while (nextHead){
            thisHead->next = prevHead;
            prevHead = thisHead;
            thisHead = nextHead;
            nextHead = nextHead->next;
        }
        
        thisHead->next = prevHead;
        
        return thisHead;
    }
};

# Recursive solution:
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
    ListNode* reverseList(ListNode* head, ListNode* nextNode = nullptr, ListNode* prevNode = nullptr) {
        
        if (!head){
            return prevNode;
        }

        nextNode = head->next;
        head->next = prevNode;
        prevNode = head;
        head = nextNode;
        
        return reverseList(head, nextNode, prevNode);
    }
};
