#include <bits/stdc++.h>
using namespace std;
#define maxn 9

int Stack[maxn];
int top;

void push(int value) {
    if(top==-1) {
        Stack[maxn - 1] = value;
        top = maxn - 1;
    }
    else if(top==0) {
        printf("The Stack is full.\n");
    }
    else {
        Stack[top - 1] = value;
        top--;
    }
}
void pop() {
    if(top==-1)
        printf("The Stack is empty.\n");
    else
        printf("Element popped!\n");

    if(top==maxn-1)
        top = -1;
    else
        top++;
}

void print(){
    if(top==-1) {
        printf("Stack is empty\n");
        return;
    }

    for(int i=top;i<maxn;i++)
        printf("%d\t",Stack[i]);

    printf("\n");
}
int main(){

    top = -1;

    while(1){
        printf("1.Push\n2.Pop\n3.Print Stack\n4.Exit Program\n");

        int choice;
        printf("Enter choice: ");
        scanf("%d",&choice);

        if(choice==1) {
            int val;
            printf("Enter value : ");
            scanf("%d",&val);
            push(val);
        }
        else if(choice==2)
            pop();
        else if(choice==3)
            print();
        else
            return 0;

    }

    return 0;
}

