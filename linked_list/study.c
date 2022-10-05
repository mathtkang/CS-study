#include <stdio.h>
#include <stdlib.h>

typedef struct node_
{
    int value;
    struct node_ *next;
} node;

void append(node *list, int value)
{
    node *new_node = malloc(sizeof(node)); // node =>  20 : 할당된 힙의 주소를 전달
    new_node->value = value;
    new_node->next = NULL;
    // list->next = new_node; // list => 10, 10 -> 10, 20

    node *node;
    // list: 파라미터로 들어온 값인데, 변하게 만들지 않는게 원칙 >따라서> 변할 수 있는 변수를 node 선언
    for (node = list; node->next != NULL; node = node->next)
        ;
    node->next = new_node;
}

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