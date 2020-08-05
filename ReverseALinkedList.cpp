Given a linked list of N nodes. The task is to reverse this list.

Example 1:

Input:
N = 6
value[] = {1,2,3,4,5,6}
Output: 6 5 4 3 2 1
Explanation: After reversing the list, 
elements are 6->5->4->3->2->1.
Example 2:

Input:
N = 5
value[] = {2,7,8,9,10}
Output: 10 9 8 7 2
Explanation: After reversing the list,
elements are 10->9->8->7->2.
Your Task:
The task is to complete the function reverseList() with head reference as the only argument and should return new head after reversing the list.



struct Node* reverseList(struct Node *head)
{
    // code here
    // return head of reversed list
    
    Node *ptr = NULL, *qtr = head, *rtr = head;
    while(qtr != NULL)
    {
        rtr = rtr -> next;
        qtr -> next = ptr;
        ptr = qtr;
        qtr = rtr;
    }
    return ptr;
}
