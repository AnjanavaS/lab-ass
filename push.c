#include <stdio.h>
#define MAX 100

int stack[MAX];
int push(int element) {
    int top = -1;
int maxsize;

    if(top == maxsize) {
        printf("stack is full");

    } else {
        stack[++top] = element;
    }

    

}

void displayElements() {
    int top ;
    if (top == -1) {
        printf("stack is empty");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}


int main() {

    int element;
    printf("enter element to be pushed");
    scanf("%d", &element);

    push(element);
    displayElements();



    }