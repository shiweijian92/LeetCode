/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) 
{
    struct ListNode* p1 = head;
    struct ListNode* p2 = head;
    int i = 1;
    if(head == NULL || k == 0)
        return head;
    while(p1->next != NULL)
    {
        p1 = p1->next;
        i++;
    }
    k = k % i;    
    k = i - k - 1; // times of shift right
    p1->next = head;
    while(k != 0)
    {
        p2 = p2->next;
        k--;
    }
    p1 = p2->next;
    p2->next = NULL;
    p2 = p1;
    return p1;
}