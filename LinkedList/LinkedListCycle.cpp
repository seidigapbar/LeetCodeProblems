# Tortoise and hare algorithm:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *tortoise = head, *hare = head;
        
        while(hare && hare->next){
            tortoise = tortoise->next;
            hare = hare->next->next;
            if(tortoise == hare){
                return true;
            }
        }
        
        return false;
    }
};

# Abused the constraints of the problem hahahah: 


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *ptr = head;
        uint32_t cnt = 0;
        
        for(auto i = 0; i < 10001; i++){
            if(!ptr){
                return false;
            }
            ptr = ptr->next;
        }
        return true;
    }
};
