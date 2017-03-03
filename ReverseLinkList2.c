/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reverseList(struct ListNode* head)
{
    struct ListNode* p1 = NULL, *p2 = NULL, *p3 = NULL;
    p1 = head;
    p2 = head->next;
    p3 = head->next->next;
    head = NULL;
    while(p3 != NULL)
    {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }
    p2->next = p1;
}
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) 
{
    struct ListNode* start = NULL, *end = NULL, *p = NULL, *end0 = NULL, *start1 = NULL;
    int i = 1;
    if(head == NULL || n <= m)
        return head;
    p = (struct ListNode*)malloc(sizeof(struct ListNode));
    p->next = head;
    head = p;
    while(i < n + 2)
    {
        if(i == m)
        {
            end0 = p;
            start = p->next;
            p = p->next;
            end0->next = NULL;
        }
        else if(i == n + 1)
        {
            end = p;
            p = p->next;
        }
        else
            p = p->next;
        i++;
    }
    start1 = end->next;
    end->next = NULL;
    
    reverseList(start);
    
    end0->next = end;
    start->next = start1;
    return head->next;
}