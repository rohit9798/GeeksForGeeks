Given two linked lists of size N and M, which are sorted in non-decreasing order. The task is to merge them in such a way that the resulting list is in decreasing order.

Input:
First line of input contains number of testcases T. For each testcase, first line of input conatains length of both linked lists N and M respectively. Next two lines contains N and M elements of two linked lists.

Output:
For each testcase, print the merged linked list which is in non-increasing order.

User Task:
The task is to complete the function mergeResult() which takes reference to the heads of both linked list and returns the pointer to the merged linked list.

Constraints:
1 <=T<= 50
1 <= N, M <= 1000

Example:
Input:
2
4 3
5 10 15 40 
2 3 20
2 2
1 1
2 4

Output:
40 20 15 10 5 3 2
4 2 1 1 



struct Node * mergeResult(Node *node1,Node *node2)
{
    Node *dummy = new Node();
    Node *start = dummy;
    while(node1 != NULL && node2 != NULL)
    {
        if(node1 -> data <= node2 -> data)
        {
            start -> next = node1;
            start = start -> next;
            node1 = node1 -> next;
        }
        else
        {
            start -> next = node2;
            start = start -> next;
            node2 = node2 -> next;
        }
    }
    if(node1 != NULL)
        start -> next = node1;
    else
        start -> next = node2;
    Node *qtr = dummy -> next, *ptr = NULL, *rtr = dummy -> next;
    while(qtr != NULL)
    {
        rtr = rtr -> next;
        qtr -> next = ptr;
        ptr = qtr;
        qtr = rtr;
    }
    return ptr;
}
