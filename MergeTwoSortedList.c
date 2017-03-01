/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;
    struct ListNode* p3 = NULL;
    if(p1 == NULL)
        return l2;
    if(p2 == NULL)
        return l1;
    while(p1 != NULL && p2 != NULL)
    {
        if(p3 == NULL)
            p3 = result;
        else
        {
            p3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            p3 = p3->next;
            p3->next = NULL;            
        }
        if(p1->val < p2->val)
        {
            p3->val = p1->val;
            p1 = p1->next;
        }
        else
        {
            p3->val = p2->val;
            p2 = p2->next;
        }
    }
    while(p2 != NULL)
    {
        p3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        p3 = p3->next;
        p3->next = NULL;
        p3->val = p2->val;
        p2 = p2->next;
    }
    while(p1 != NULL)
    {
        p3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        p3 = p3->next;
        p3->next = NULL; 
        p3->val = p1->val;
        p1 = p1->next;
    }
    return result;
}