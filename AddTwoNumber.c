/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode* current1, * current2, *currentR;
    struct ListNode* Result = NULL;
    struct ListNode* new;
    int sum;
    int c = 0;
    
    for(current1 = l1, current2 = l2; (current1 != NULL) && (current2 != NULL); current1 = current1->next, current2 = current2->next)
    {
        sum = current1->val + current2->val + c;
        if(sum >= 10)
        {
            new = (struct ListNode*)malloc(sizeof(struct ListNode));
            new->val = sum - 10;
            c = 1;
        }
        else
        {
            new = (struct ListNode*)malloc(sizeof(struct ListNode));
            new->val = sum;
            c = 0;
        }
        if(Result == NULL)
        {
            Result = new;
            currentR = new;
        }
        else
        {
            currentR->next = new;
            currentR = new;
        }
    }
    if(current2 != NULL)
    {
        for(; current2 != NULL; current2 = current2->next)
        {
            sum = current2->val + c;
            if(sum >= 10)
            {
                new = (struct ListNode*)malloc(sizeof(struct ListNode));
                new->val = sum - 10;
                c = 1;
            }
            else
            {
                new = (struct ListNode*)malloc(sizeof(struct ListNode));
                new->val = sum;
                c = 0;
            }
            currentR->next = new;
            currentR = new;
        }
    }
    else if(current1 != NULL)
    {
        for(; current1 != NULL; current1 = current1->next)
        {
            sum = current1->val + c;
            if(sum >= 10)
            {
                new = (struct ListNode*)malloc(sizeof(struct ListNode));
                new->val = sum - 10;
                c = 1;
            }
            else
            {
                new = (struct ListNode*)malloc(sizeof(struct ListNode));
                new->val = sum;
                c = 0;
            }
            currentR->next = new;
            currentR = new;
        }
    }
    if(c)
    {
        new = (struct ListNode*)malloc(sizeof(struct ListNode));
        new->val = c;
        currentR->next = new;
        currentR = new;
        currentR->next = NULL;
    }
    else
    {
        currentR->next = NULL;
    }
    return Result;
}