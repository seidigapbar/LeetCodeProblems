# Final proper solution:

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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *firstPart = head, *secondPart = nullptr;
        int cnt = 0;
        
        while(fast){
            fast = fast->next;
            cnt++;
            if(cnt % 2 == 0){
                slow = slow->next;
            }
        }
        
        secondPart = reverseList(slow);
        
        while(secondPart){
            if(firstPart->val != secondPart->val){
                return false;
            }
            firstPart = firstPart->next;
            secondPart = secondPart->next;
        }
        
        reverseList(slow);
        
        return true;
    }
    
    ListNode* reverseList(ListNode* head, ListNode* next = nullptr, ListNode* prev = nullptr){
        if(!head){
            return prev;
        }
        
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
        
        return reverseList(head, next, prev);
    }
};

# An improvement over the stupid soultion. I could get that we had to reverse the linked list but I did it quite inefficiently:

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
    bool isPalindrome(ListNode* head) {
        
        if(!head || !head->next){
            return true;
        }
        
        size_t size = 0;
        ListNode *firstHead = head, *secondHead = head, *tmp = nullptr, *nextNode = nullptr;
        
        while (secondHead){
            size++;
            secondHead = secondHead->next;
        }
        
        secondHead = head;

        for(auto i = 1; i <= size; i++){
            if(i > (size / 2 + size % 2)){
                secondHead = reverseList(secondHead, secondHead->next, nullptr);
                break;
            }
            secondHead = secondHead->next;
        }
        
        while(firstHead && secondHead){
            if(firstHead->val != secondHead->val){
                return false;
            } 
            firstHead = firstHead->next;
            secondHead = secondHead->next;
        }
        
        return true;
    }
    
    ListNode* reverseList(ListNode* head, ListNode* next = nullptr, ListNode* prev = nullptr){
        if(!head){
            return prev;
        }
        
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
        
        return reverseList(head, next, prev);
    }
};


# Very stupid but straightforward solution: 
# Complexity O(2n) (O(n)), space complexity is also O(n)
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
    bool isPalindrome(ListNode* head) {
        size_t size = 0;
        ListNode *ptr = head;
        queue<int8_t> firstPart;
        stack<int8_t> secondPart;
        
        while(ptr){
            ptr = ptr->next;
            size++;
        }
        
        ptr = head;
        for(auto i = 0; i < size / 2; i++){
            firstPart.push(ptr->val);
            ptr = ptr->next;
        }
        
        if (size % 2 == 1){
            ptr = ptr->next;
        }
        
        for(auto i = 0; i < size / 2; i++){
            secondPart.push(ptr->val);
            ptr = ptr->next;
        }
        
        while (!firstPart.empty()){
            if (firstPart.front() != secondPart.top()){
                return false;
            }
            firstPart.pop();
            secondPart.pop();
        }
        
        return true;
    }
};
