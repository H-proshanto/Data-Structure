#include <bits/stdc++.h>
using namespace std;
#define maxn 10

int q[maxn];
int front,rear;

void Insert(int value){
    if(rear == maxn - 1 && front == rear+1)front = -1,rear = -1;
    if(rear==maxn-1)
        printf("The queue is Full!\n");
    else {
        rear++;
        q[rear]=value;
        if(front==-1)
            front = 0;
    }
}

void dlt(){
    if(front==-1 || front==rear+1)
        printf("The queue is Empty\n");
    else {
        q[front]=0;
        front++;
    }
}

void print(){
    if(front==-1 || front==rear+1) {
        printf("queue is empty\n");
        return;
    }

    for(int i=front;i<=rear;i++)
        printf("%d\t",q[i]);
    printf("\n");
}

int main(){
    front = -1,rear = -1;

    while(1){
        printf("1.Insert\n2.Delete\n3.Print\n4.Exit\n");

        int choice;
        printf("Enter choice : ");
        scanf("%d",&choice);
        if(choice==1){
            int val;
            printf("Enter value : ");
            scanf("%d",&val);
            Insert(val);
        }
        else if(choice==2) {
            dlt();
        }
        else if(choice==3) {
            print();
        }
        else
            return 0;
    }

    return 0;
}
