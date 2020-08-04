Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

Example 1:

Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5
Explanation: After sorting the given
linked list, the resultant matrix
will be 1->2->3->4->5.
Example 2:

Input:
N = 3
value[]  = {9,15,0}
Output: 0 9 15
Explanation: After sorting the given
linked list , resultant will be
0->9->15.
Your Task:
For C++ and Python: The task is to complete the function mergeSort() which sort the linked list using merge sort function.
For Java: The task is to complete the function mergeSort() and return the node which can be used to print the sorted linked list.

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(1)



Node *merge(Node *l1, Node *l2)
{
    if(l1 == NULL)
        return l1;
    if(l2 == NULL)
        return l2;
    Node *start = NULL;
    if(l1 -> data <= l2 -> data)
    {
        start = l1;
        l1 = l1 -> next;
    }
    else
    {
        start = l2;
        l2 = l2 -> next;
    }
    Node *head = start;
    while(l1 != NULL && l2 != NULL)
    {
        if(l1 -> data < l2 -> data)
        {
            start -> next = l1;
            l1 = l1 -> next;
        }       
        else
        {
            start -> next = l2;
            l2 = l2 -> next;
        }
        start = start -> next;
    }
    if(l1 != NULL)
        start -> next = l1;
    else if(l2 != NULL)
        start -> next = l2;
    return head;
}
Node *mergeSort1(Node *start)
{
    if(start == NULL || start -> next == NULL)
        return start;
    Node *ptr = start, *qtr = start -> next;
    while(qtr != NULL && qtr -> next != NULL)
    {
        ptr = ptr -> next;
        qtr = qtr -> next -> next;
    }
    qtr = ptr;
    ptr = ptr -> next;
    qtr -> next = NULL;
    Node *l1 = mergeSort1(start);
    Node *l2 = mergeSort1(ptr);
    Node *head = merge(l1, l2);
    return head;
}
Node* mergeSort(Node* head) {
    // your code here
    
    head = mergeSort1(head);
    return head;
}
