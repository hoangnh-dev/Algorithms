/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode* low = head;
    struct ListNode* fast = head;
    int arrTemp[50001];
    int index = 0;
    while(fast != NULL&& fast->next != NULL){
        arrTemp[index] = low->val;
        index++;
        low = low->next;
        fast = fast->next->next;
    }
    if(fast != NULL){
        low = low->next;
    }
    while(low != NULL){
        if (arrTemp[index-1] != low->val) return false;
        index--;
        low = low->next;
    }
    return true;
}