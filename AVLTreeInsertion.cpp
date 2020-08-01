Given a root of the tree you need to perform N AVL tree insertion operations on it. You need to complete the method insertToAVL which takes 2 arguments the first is the root of the tree and the second is the value of the node to be inserted.The function should return the root of the modified tree.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains 2 lines . The first line of each test case contains an integer N denoting the no of nodes to be inserted in the AVL tree and in the next line are N space separated values denoting the values of the nodes to be inserted to the tree.

Output:
The tree will be checked by driver code after each insertion. If after any insertion, the tree voilates the property of binary search tree or is not balanced, the driver code will print an error message informing about the voilation and print the inorder traversal of the tree at that moment. Further nodes will not be inserted to that tree.
If instead, all insertions are done properly, while maintaining the properties of a balanced BST, no error message will be printed and the inorder traversal will be printed at the end, when all insertions are made.

Your Task:
Your task is to complete the function insertToAVL(). Return the root node of tree after inserting new node.

Expected Time Complexity: O(log N) for inserting one new node, where N is the number of nodes in tree at that moment.

Expected Auxiliary Space: O(h) , where h = height of tree

Constraints:
1 <= T <= 100
1 <= N <= 500

Example(To be used only for expected output):
Input:
2
3
5 1 4
4
1 6 2 3
Output:
1 4 5
1 2 3 6




int height(Node* root)
{
    if(root == NULL)
        return 0;
    else
        return root -> height;
}
Node *leftRotate(Node *root)
{
    Node *newRoot = root -> right;
    root -> right = root -> right -> left;
    newRoot -> left = root;
    root -> height = 1 + max(height(root -> left), height(root -> right));
    newRoot -> height = 1 + max(height(newRoot -> left), height(newRoot -> right));
    return newRoot;
}
Node *rightRotate(Node *root)
{
    Node *newRoot = root -> left;
    root -> left = root -> left -> right;
    newRoot -> right = root;
    root -> height = 1 + max(height(root -> left), height(root -> right));
    newRoot -> height = 1 + max(height(newRoot -> left), height(newRoot -> right));
    return newRoot;
}
Node *createNode(int data)
{
    Node *temp = new Node(data);
    temp -> height = 1;
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

Node* insertToAVL(Node* node, int data)
{
    if(node == NULL)
        return createNode(data);
    if(node -> data < data)
    {
        node -> right = insertToAVL(node -> right, data); 
    }
    else if(node -> data > data)
    {
        node -> left = insertToAVL(node -> left, data);
    }
    else
        return node;
    node -> height = 1 + max(height(node -> left), height(node -> right));
    int bf = height(node -> left) - height(node -> right);
    if(bf > 1)
    {
        if(node -> left -> data > data)
            return rightRotate(node);
        else
        {
            node -> left = leftRotate(node -> left);
            return rightRotate(node);
        }
    }
    else if(bf < -1)
    {
        if(node -> right -> data < data)
            return leftRotate(node);
        else 
        {
            node -> right = rightRotate(node -> right);
            return leftRotate(node);
        }
    }
    return node;
}
