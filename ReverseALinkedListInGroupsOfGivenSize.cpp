Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

Input:
First line of input contains number of testcases T. For each testcase, first line contains length of linked list and next line contains the linked list elements.

Output:
For each testcase, there will be a single line of output which contains the linked list with every k group elements reversed.

User Task:
The task is to complete the function reverse() which should reverse the linked list in group of size k.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(1)

Example:
Input:
2
8
1 2 2 4 5 6 7 8
4
5
1 2 3 4 5
3

Output:
4 2 2 1 8 7 6 5
3 2 1 5 4



struct node *reverse (struct node *head, int k)
{ 
    // Complete this method
    node *end = head, *ptr = NULL, *head1 = NULL, *qtr = head, *rtr = head, *save = NULL;
    int temp = k;
    node *head2 = NULL;
    while(rtr != NULL)
    {
        temp = k;
        save = qtr;
        while(qtr && temp--)
        {
            rtr = rtr -> next;
            qtr -> next = ptr;
            ptr = qtr;
            qtr = rtr;
        }
        if(head1 == NULL)
            head1 = ptr;
        if(head2 != NULL)
            head2 -> next = ptr;
        head2 = save;
        ptr = NULL;
        
    }
    return head1;
}
