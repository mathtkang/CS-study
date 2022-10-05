#include <stdio.h>
#include <stdlib.h>

// [참고] https://csforchrist.tistory.com/15
// https://leeyongjeon.tistory.com/entry/%ED%81%90Queues-%EC%97%B0%EA%B2%B0%EB%A6%AC%EC%8A%A4%ED%8A%B8%EB%A1%9C-%EA%B5%AC%ED%98%84The-implementation-with-the-linked-lists

// 연결리스트 큐 구조체 선언
typedef struct node
{
    int data;
    struct node *next;
} queue;

queue *rear = NULL;
queue *front = NULL;

void enqueue(int data)
{
    queue *new_node = (queue *)malloc(sizeof(queue)); //new_node에 메모리 할당

    new_node->data = data;
    new_node->next = NULL;

    if (rear == NULL && front == NULL)
    {
        front = new_node;
        rear = new_node;
        return;
    } // error handling

    rear->next = new_node;
    rear = new_node;
};

int dequeue()
{
    int value;
    queue *del = (queue *)malloc(sizeof(queue));

    if (front == NULL && rear == NULL)
    {
        printf("queue is empty!!\n");
        exit(1);
    }
    del = front;
    front = front->next;
    value = del->data;
    free(del);

    return value;
}

int main()
{
    printf("----ADD----\n");
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    print_queue();

    printf("----DELETE----\n");

    dequeue();
    dequeue();
    dequeue();

    print_queue();
}

void print_queue()
{
    queue *temp = front;
    while (temp != NULL)
    {
        if (temp == rear)
        {
            printf("%d", temp->data);
        }
        else
        {
            printf("%d --> ", temp->data);
        }
        temp = temp->next;
    }
    printf("\n");
}