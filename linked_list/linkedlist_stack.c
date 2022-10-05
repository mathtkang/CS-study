#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 연결리스트 스택 구조체 선언
typedef struct node
{
    int data;
    struct node *next;
} stack;

stack *top = NULL;

void push(int data)
{
    stack *new_node = (stack *)malloc(sizeof(stack)) //new_node에 메모리 할당

        if (new_node == NULL)
    {
        printf("stack is full");
        exit(1);
    } // error handling

    new_node->data = data; // data를 new_node.data에 넣어줌
    new_node->next = top;  //next주소를 넣어줌
    top = new_node;        //top(stack 맨 위에 있는 노드)에 new_node 추가
};

int pop()
{
    stack *del;
    int value;

    if (top == NULL)
    {
        printf("stack is empty");
        exit(1);
    }

    value = top->data; //연결리스트 맨 위에 있는 노드(top)의 데이터 (아래에서 출력하기 위해)
    del = top;
    top = top->next;
    free(del); //연결리스트 맨 위에 있는 노드(top) 삭제

    return value;
};

void print_stack()
{
    stack *i;
    stack *count = top;

    i = count;

    while (i != NULL)
    {
        if (i->next == NULL)
            printf("%d\n", i->data);
        else
            printf("%d --> ", i->data);

        i = count->next;
        count = count->next;
    }
};

int main()
{
    printf("----PUSH----\n");
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    print_stack();

    printf("----POP----\n");
    pop();
    pop();

    print_stack();
}