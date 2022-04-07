#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left, *right;
};

struct node* createNode(int value){
    struct node* tmp = new node();
    tmp->data = value;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
};

struct node* insertNode(struct node* parent, int value){
    if(parent == NULL)
        return createNode(value);

    if(value < parent->data)
        parent->left = insertNode(parent->left,value);
    else
        parent->right = insertNode(parent->right, value);
    return parent;
}

struct node* searchInTree(struct node* parent, int searchValue)
{
    if(parent==NULL)
        return NULL;
    if(parent->data == searchValue)
        return parent;
    else if(parent->data > searchValue)
        return searchInTree(parent->left, searchValue);
    else
        return searchInTree(parent->right, searchValue);
}
struct node* minValueSearch(struct node *parent)
{
    struct node *current = parent;
    while(current->left!=NULL)
    {
        current = current->left;
    }
    return current;
}

struct node* deleteInBST(struct node*parent, int deleteValue){
    if(parent == NULL)
        return parent;
    if(parent->data == deleteValue){
        if(parent->left == NULL && parent->right == NULL){
            free(parent);
            return NULL;
        }
        else if(parent->left == NULL || parent->right == NULL)
        {
            if(parent->left == NULL){
                 struct node* tmp = parent->right;
                 free(parent);
                 return tmp;
            }
            else if(parent->right == NULL){
                struct node* tmp = parent->left;
                free(parent);
                return tmp;
            }
        }
        else
        {
            struct node* tmp = minValueSearch(parent->right);
            parent->data = tmp->data;
            parent->right = deleteInBST(parent->right, tmp->data);
        }
    }
    else if(parent->data > deleteValue){
        parent->left = deleteInBST(parent->left, deleteValue);
    }
    else{
        parent->right = deleteInBST(parent->right, deleteValue);
    }
    return parent;
}

void preorderTraversal(struct node* parent) {
    if(parent==NULL)
        return;

    cout << parent->data << endl;
    preorderTraversal(parent->left);
    preorderTraversal(parent->right);
}

void inOrder(struct node *parent) {
    if(parent != NULL) {
        inOrder(parent->left);
        cout << parent->data << endl;
        inOrder(parent->right);
    }
}
void postOrder(struct node *parent) {
    if(parent!=NULL) {
        postOrder(parent->left);
        postOrder(parent->right);
        cout << parent->data << endl;
    }
}


int main()
{
    struct node * root = NULL;
    root = insertNode(root, 25);
    root = insertNode(root, 16);
    root = insertNode(root, 34);
    root = insertNode(root, 10);
    root = insertNode(root, 21);
    root = insertNode(root, 31);
    root = insertNode(root, 61);
    root = insertNode(root, 14);
    root = insertNode(root, 8);
    root = insertNode(root, 23);
    root = insertNode(root, 32);
    root = insertNode(root, 56);
    root = insertNode(root, 12);
    root = insertNode(root, 33);

    cout << "Preorder Traverse: " << endl;
    preorderTraversal(root);

    return 0;
}
