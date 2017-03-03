/**Iterative
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) 
{
    struct ListNode* p1 = NULL, *p2 = NULL, *p3 = NULL;
    if(head == NULL || head->next == NULL)
        return head;
    p1 = head;
    p2 = head->next;
    p3 = head->next->next;
    p1->next = NULL;
    while(p3 != NULL)
    {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }
    p2->next = p1;
    head = p2;
    return head;
}

/**Recursive
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) 
{
    struct ListNode* first = head;
    struct ListNode* rest = NULL;
    if(head == NULL)
        return head;
    rest = first->next;
    if(rest == NULL)
    {
        return first;
    }
    head = reverseList(rest);
    first->next->next = first;
    first->next = NULL;
    return head;
}