#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    struct node *next;
    struct node *pre;

};

struct node *root = NULL;
struct node *tail = NULL;
int SIZE = 0;

void push(int data){
    if(root==NULL) {
        root = malloc(sizeof(struct node));
        root->val = data;
        root->next = NULL;
        root->pre = NULL;
        tail = root;
        SIZE++;
        return ;
    }

    struct node *new_node = malloc(sizeof(struct node));
    new_node->val = data;
    new_node->next = NULL;
    new_node->pre = tail;
    tail->next = new_node;
    tail = new_node;
    SIZE++;
}

void Insert(int data, int pos) {
    if(pos<1 || pos>SIZE) {
        printf("The position does not exist in Linked List\n");
        return ;
    }

    if(pos==1) {
        struct node *new_node = malloc(sizeof(struct node));
        new_node->val = data;
        new_node->next = root;
        new_node->pre = NULL;
        root->pre = new_node;
        root = new_node;
        SIZE++;
        return ;
    }

    struct node *cur = root;
    int node_cnt = 1;
    while(node_cnt!=pos) {
        cur = cur->next;
        node_cnt++;
    }

    struct node *prev = cur->pre;
    struct node *new_node = malloc(sizeof(struct node));
    new_node->val = data;
    new_node->next = cur;
    cur->pre = new_node;
    prev->next = new_node;
    new_node->pre = prev;
    SIZE++;
}

void dlt(int pos) {
    if(pos<1 || pos>SIZE) {
        printf("The position does not exist in Linked List\n");
        return ;
    }

    if(pos==1) {
        struct node *tmp = root;
        if(tail==root)tail = NULL;
        root = root->next;
        root->pre = NULL;
        free(tmp);
        SIZE--;
        return ;
    }
    if(pos==SIZE) {
        struct node *tmp = tail;
        if(tail==root)root = NULL;
        tail = tail->pre;
        tail->next = NULL;
        free(tmp);
        SIZE--;
        return ;
    }

    struct node *cur = root;
    int node_cnt = 1;
    while(node_cnt!=pos) {
        cur = cur->next;
        node_cnt++;
    }

    struct node *prev = cur->pre;
    struct node *nxt = cur->next;
    prev->next = nxt;
    nxt->pre = prev;
    free(cur);
    SIZE--;
}

void printLinkedList() {
    if(SIZE==0) {
        printf("The Linked List is Empty\n");
        return ;
    }

    struct node *cur = tail;

    if(tail==NULL)return ;

    printf("The Elements are : \n");
    while(cur->pre!=NULL) {
        printf("%d\t",cur->val);
        cur = cur->pre;
    }
    printf("%d\n",cur->val);
}

int main() {
    int n;

    printf("Enter how many Inputs : \n");
    scanf("%d",&n);

    printf("Enter the elements : \n");
    for(int i=0;i<n;i++) {
        int val;
        scanf("%d",&val);
        push(val);
    }

    while(1) {
        printf("Options : \n");
        printf("1.Insert\n2.Delete\n3.PrintLinkedList\n4.EXIT\n");

        int option;
        scanf("%d",&option);

        if(option == 1) {
            int val,pos;
            scanf("%d %d",&val,&pos);
            Insert(val,pos);
        }
        else if(option == 2) {
            int pos;
            scanf("%d",&pos);
            dlt(pos);
        }
        else if(option == 3)
            printLinkedList();
        else
            return 0;
    }

    return 0;
}

