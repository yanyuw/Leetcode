/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    typedef struct ListNode ListNode;
    ListNode *p1 = l1, *p2 = l2, *l3 = (ListNode *)malloc(sizeof(ListNode)), *tail;
    l3->next = NULL;
    tail  = l3;
    int carry = 0;
    while(p1 || p2 || carry){
        ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
        // num = (p1 ? p1->val : 0) + (p2 ? p2->val : 0) + carry;
        int num = carry;
        if(p1){
            num += p1->val;
            p1 = p1->next;
        }
        if(p2){
            num += p2->val;
            p2 = p2->next;
        }
        if(num >= 10){
            num -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        tmp->val = num;
        tmp->next = NULL;
        tail->next = tmp;
        tail = tail->next;
    }
    
    l3 = l3->next;
    return l3;
}
//写了好久 看错题意了QwQ