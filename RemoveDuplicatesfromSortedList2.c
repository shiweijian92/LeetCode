/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) 
{
    struct ListNode *p1 = NULL, *p2 = NULL, *p3 = NULL;
    struct ListNode *temp = NULL;
    int n = 0;
    
    if(head == NULL || head->next == NULL)
        return head;
    p2 = head;
    p3 = p2->next;
    while(1)
    {
        while(p3 != NULL && p2->val == p3->val)
        {
            n++;
            p3 = p3->next;
        }
        if(n)
        {
            if(p1 == NULL)
                head = p3;
            else
                p1->next = p3;
            while(p2 != p3)
            {
                temp = p2->next;
                free(p2);
                p2 = temp;
            }
        }
        else
        {
            p1 = p2;
            p2 = p2->next;
        }
        if(p3 == NULL)
            break;
        p3 = p2->next;
        n = 0;
    }
    return head;
}