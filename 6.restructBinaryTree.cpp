#include<iostream>
using namespace std;
struct binaryTreeNode
{
    int data;
    binaryTreeNode* leftChild;
    binaryTreeNode* rightChild;
    binaryTreeNode(int d)
    {
        data = d;
        leftChild = NULL;
        rightChild = NULL;
    }
};
void postOrderPrint(binaryTreeNode* node)
{
    if (node->leftChild != NULL)
      postOrderPrint(node->leftChild);
    if(node->rightChild!= NULL)
      postOrderPrint(node->rightChild);
    cout<<node->data<<" ";
}
void priOrderPrint(binaryTreeNode* node)
{
    cout<<node->data<<" ";
    if (node->leftChild != NULL)
      priOrderPrint(node->leftChild);
    if(node->rightChild!= NULL)
      priOrderPrint(node->rightChild);
}
void inOrderPrint(binaryTreeNode* node)
{
    if (node->leftChild != NULL)
      inOrderPrint(node->leftChild);
    cout<<node->data<<" ";
    if(node->rightChild!= NULL)
      inOrderPrint(node->rightChild);
}
binaryTreeNode* restructBinaryTree(int* preorder, int* inorder, int prestart, int preend, int instart, int inend)
{
    int node_data = preorder[prestart];
    int i = instart;
    int split;
    while(i<=inend)
    {
        if (node_data == inorder[i])
        {
            split = i;
            break;
        }
        i++;
    }
    int leftlen = split - instart;
    int leftprestart = prestart + 1;
    int leftpreend = leftprestart + leftlen - 1;
    int leftinstart = instart;
    int leftinend = split -1;

    int rightlen = inend - i;
    int rightprestart = leftpreend + 1;
    int rightpreend = preend;
    int rightinstart = split + 1;
    int rightinend =  inend;
    binaryTreeNode* nd = new binaryTreeNode(node_data);
    if (leftlen==0)
      nd->leftChild = NULL;
    else
      nd->leftChild  = restructBinaryTree( preorder, inorder, leftprestart, leftpreend, leftinstart, leftinend);
    if (rightlen == 0)
      nd->rightChild = NULL;
    else
      nd->rightChild = restructBinaryTree( preorder, inorder, rightprestart, rightpreend, rightinstart, rightinend );
    return nd;
}

int main()
{
    const int length = 8;
    int preorder[length] = { 1, 2, 4, 7, 3, 5, 6, 8 };
    int inorder[length] = { 4, 7, 2, 1, 5, 3, 8, 6 };
    int prestart = 0;
    int preend = length - 1;
    int instart = 0;
    int inend = length-1;
    binaryTreeNode* root = restructBinaryTree(preorder, inorder, prestart, preend, instart, inend);
    cout<<"postOrder: ";
    postOrderPrint(root);
    cout<<endl;
    cout<<"priOrder: ";
    priOrderPrint(root);
    cout<<endl;
    cout<<"inOrder: ";
    inOrderPrint(root);
    cout<<endl;
}
