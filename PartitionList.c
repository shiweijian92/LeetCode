/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) 
{
    struct ListNode* p0 = head;
    struct ListNode* p1 = NULL, *p2 = NULL;
    struct ListNode* l1 = NULL, *l2 = NULL;
    if(p0 == NULL || p0->next == NULL)
        return head;
    while(p0 != NULL)
    {
        if(p0->val < x)
        {
            if(p1 == NULL)
            {
                p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
                l1 = p1;
            }
            else
            {
                p1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                p1 = p1->next;
            }
            p1->val = p0->val;
            p1->next = NULL;
        }
        else
        {
            if(p2 == NULL)
            {
                p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
                l2 = p2;
            }
            else
            {
                p2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                p2 = p2->next;
            }
            p2->val = p0->val;
            p2->next = NULL;
        }
        p0 = p0->next;
    }
    if(l1 == NULL)
        return l2;
    p1->next = l2;
    return l1;
}