/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* merge(struct ListNode* headl, struct ListNode* headr)
{
    struct ListNode dummy;
    struct ListNode *head = &dummy;
    while(headl != NULL && headr != NULL)
    {
        if(headl->val < headr->val)
        {
            head->next = headl;
            head = head->next;
            headl = headl->next;
        }
        else
        {
            head->next = headr;
            head = head->next;
            headr = headr->next;
        }
    }
    if(headl != NULL)
        head->next = headl;
    else
        head->next = headr;
    return dummy.next;
}

struct ListNode* mergeSort(struct ListNode* head, int len)
{
    int lenl = 0, lenr = 0;
    struct ListNode* headl = head, *headr = head;
    int i = 1;
    if(len > 1)
    {
        lenl = len / 2;
        lenr = len - lenl;
        while(i < lenl)
        {
            i++;
            headl = headl->next;
        }
        headr = headl->next;
        headl->next = NULL;
        headl = head;
        headl = mergeSort(headl, lenl);
        headr = mergeSort(headr, lenr);
        head = merge(headl, headr);
//        return head;
    }
    return head;
}


struct ListNode* sortList(struct ListNode* head) 
{
    struct ListNode *p = head;
    int i = 1;
    if(head == NULL || head->next == NULL)
        return head;
    while(p != NULL)
    {
        p = p->next;
        i++;
    }
    head = mergeSort(head, i);
    return head;
}