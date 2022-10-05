# [참고]
# https://www.sanfoundry.com/python-program-implement-queue-data-structure-using-linked-list
# https://www.geeksforgeeks.org/queue-linked-list-implementation


# linked list 구조체 클래스 (인스턴스 변수 생성)
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Queue:
    def __init__(self):
        self.head = None  # 연결 목록의 첫번째 요소 가리킴
        self.last = None  # 연결 목록의 마지막 요소 가리킴

    def enqueue(self, data):
        # 연결리스트의 끝에 노드 추가
        if self.last is None:
            self.head = Node(data)
            self.last = self.head
        else:
            self.last.next = Node(data)
            self.last = self.last.next

    def dequeue(self):
        # 연결리스트의 맨 앞에 있는 노드를 반환 후, 해당 노드를 제거
        if self.head is None:
            return None
        else:
            to_return = self.head.data
            self.head = self.head.next
            return to_return


a_queue = Queue()
while True:
    print('enqueue <value>')
    print('dequeue')
    print('quit')
    do = input('What would you like to do? ').split()

    operation = do[0].strip().lower()
    if operation == 'enqueue':
        a_queue.enqueue(int(do[1]))
    elif operation == 'dequeue':
        dequeued = a_queue.dequeue()
        if dequeued is None:
            print('Queue is empty.')
        else:
            print('Dequeued element: ', int(dequeued))
    elif operation == 'quit':
        break
