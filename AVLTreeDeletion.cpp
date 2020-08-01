Given a root of the tree you need to perform AVL tree deletion operations on it. You need to complete the method delelteNode which takes 2 arguments the first is the root of the tree and the second is the value of the node to be deleted. The function should return the root of the modified tree.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains 3 lines. The first line of each test case contains a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:
 
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N
Note: Assume that all input BSTs are balanced.

Second line of test case holds an integer n denoting the number of nodes to be deleted. Finally the last line of test case holds the n space separated integer values to be deleted from the tree.

Output:
The tree will be checked by driver code after each node deletion. If after any deletion, the tree voilates the property of binary search tree or is not balanced, the driver code will print an error message informing about the voilation and print the inorder traversal of the tree at that moment. Further deletions will not be done in the tree.
If instead, all expected nodes are deleted as expected while maintaining a balanced BST, no error message will be printed and the inorder traversal will be printed at the end.
Note: If every single node is deleted from tree, inorder traversal will simple print 'null'.

Your Task:
Your task is to complete the function deleteNode(). Return the root node of tree after deleteing the key node.

Constraints:
1 <= T <= 100
1 <= nodes in tree <= 500
1 <= n <= 500

Expected time complexity: O(h) for every deletion, where h is height of tree

Expected auxiliary space: O(h)

Example(To be used only for expected output):
Input:
3
4 2 6 1 3 5 7
4
4 1 3 6
2 1 3 N N N 4
4
1 2 3 4
61 40 94 19 44 N 95
2
44 95
Output:
2 5 7
null
19 40 61 94



Node *inorderSuccessor(Node *root)
{
    Node *curr = root;
    while(curr -> left != NULL)
        curr = curr -> left;
    return curr;
}
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

Node* deleteNode(Node* root, int data)
{
    if(root == NULL)
        return root;
    if(root -> data < data)
    {
        root -> right = deleteNode(root -> right, data);
    }
    else if(root -> data > data)
    {
        root -> left = deleteNode(root -> left, data);
    }
    else
    {
        if(root -> left == NULL && root -> right == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root -> left == NULL || root -> right == NULL)
        {
            Node *temp = root -> left ? root -> left : root -> right;
            *root = *temp;
            free(temp);
            return root;
        }
        else
        {
            Node * temp = inorderSuccessor(root -> right);
            root -> data = temp -> data;
            root -> right = deleteNode(root -> right, temp -> data);
        }
    }
    root->height = 1 + max(height(root->left), height(root->right));
    int bf = height(root -> left) - height(root -> right);
    if(bf > 1)
    {
        if(height(root -> left -> left) >= height(root -> left -> right))
            return rightRotate(root);
        else
        {
            root -> left = leftRotate(root -> left);
            return rightRotate(root);
        }
    }
    else if(bf < -1)
    {
        if(height(root -> right -> left) <= height(root -> right -> right))
            return leftRotate(root);
        else
        {
            root -> right = rightRotate(root -> right);
            return leftRotate(root);
        }
    }
    return root;
}
