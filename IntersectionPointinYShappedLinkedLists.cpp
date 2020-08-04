Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

Y ShapedLinked List
Above diagram shows an example with two linked list having 15 as intersection point.

Example 1:

Input:
LinkList1 = {10,20,5,10}
LinkList2 = {30,40,50,5,10}
Output: 5
Explanation:The point of intersection of
two linked list is 5, means both of them
get linked (intersects) with each other
at node whose value is 5.
Your Task:
The task is to complete the function intersetPoint() which finds the point of intersection of two linked list. The function should return data value of a node where two linked lists merge. If linked list do not merge at any point, then it should return -1.

Challenge : Try to solve the problem without using any extra space.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)


int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
        int len1 = 0, len2 = 0;
        Node *ptr = head1, *qtr = head2;
        while(ptr != NULL)
        {
            ptr = ptr -> next;
            len1++;
        }
        while(qtr != NULL)
        {
            qtr = qtr -> next;
            len2++;
        }
        ptr = head1; qtr = head2;
        if(len1 > len2)
        {
            while(len1 - len2 != 0)
            {
                ptr = ptr -> next;
                len1--;
            }
        }
        else
        {
            while(len2 - len1 != 0)
            {
                qtr = qtr -> next;
                len2--;
            }
        }
        while(ptr != qtr)
        {
            ptr = ptr -> next;
            qtr = qtr -> next;
        }
        return qtr -> data;
}
