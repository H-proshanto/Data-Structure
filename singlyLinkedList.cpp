#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node* next;
};

node *root = NULL;
node *tail = NULL;

struct node *createNewNode(int data) {
    struct node *newNode = new node();
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}

void push(int data) {
    if(root == NULL) {
        root = new node();
        root->val = data;
        root->next = NULL;
        tail = root;
        return ;
    }

    tail->next = createNewNode(data);
    tail = tail->next;
}

void insertAt(int data, int pos) {
    if(pos == 1) {
        struct node *temp = createNewNode(data);
        temp->next = root;
        root = temp;
    }

    struct node *cur = root->next;
    struct node *pre = root;
    int cnt = 2;
    while(cnt != pos) {
        cur = cur->next;
        pre = pre->next;
        ++cnt;
    }

    struct node *temp = createNewNode(data);
    pre->next = temp;
    temp->next = cur;
}

void deleteAt(int pos) {
        if(pos == 1) {
            struct node *temp = root;
            root = root->next;
            free(temp);
            return ;
        }

        struct node *cur = root->next;
        struct node *pre = root;
        int cnt = 2;
        while(cnt != pos) {
            cur = cur->next;
            pre = pre->next;
            ++cnt;
        }

        pre->next = cur->next;
        if(cur == tail)tail = pre;
        free(cur);
}

void pop() {
    if(root == NULL) {
        cout << "The List is Empty" << endl;
        return ;
    }
    if(root == tail) {
        free(root);
        root = NULL;
        tail = NULL;
        return ;
    }
    struct node *cur = root;

    while(cur->next != tail) {
        cur = cur->next;
    }
    cur->next = NULL;
    free(tail);
    tail  = cur;
}

int numberOfNodes() {
    if(root==NULL)return 0;

    struct node *cur = root;
    int node_num = 0;
    while(cur!=NULL) {
        cur = cur->next;
        node_num++;
    }

    return node_num;

}

void printLinkedList() {
    if(root==NULL) {
        cout << "The linked list is empty" << endl;
        return ;
    }

    struct node *cur = root;
    cout << "Number of Nodes in Linked List is : " << numberOfNodes() << endl;

    cout << "The Elements are : " << endl;
    while(cur!=NULL) {
        cout << cur->val << "\t";
        cur = cur->next;
    }
}


int main() {
    push(2);
    push(5);
    push(1);
    push(7);
    push(3);
    pop();
    pop();
    insertAt(7,3);
    insertAt(3,2);
    deleteAt(1);
    printLinkedList();

    return 0;
}
