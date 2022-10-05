#include <stdio.h>
#include <stdlib.h>

//step1. node_라는 이름을 가진 연결리스트 구조체 선언
typedef struct node_
{
    int value;
    struct node_ *next;
} node;

// 노드를 추가하는 함수
void append(node *list, int value)
{
    node *new_node = malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;

    
    list->next = new_node;
}

// list를 출력하는 함수
void print_list(node *list)
{
    for (node *node = list; node != NULL; node = node->next)
    {
        printf("%d\n", node->value);
    }
}

int main()
{
    node *list = malloc(sizeof(node));
    list->value = 10; // list => 10

    append(list, 10); // list => 10, 10
    print_list(list); // list => 10, 10

    append(list, 20); // list => 10, 20
    print_list(list); // list => 10, 20

    return 0;
}