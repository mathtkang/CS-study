# [참고] https://www.sanfoundry.com/python-program-implement-stack-using-linked-list

# linked list 구조체 클래스
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Stack:
    def __init__(self):
        self.head = None  # 연결 목록의 첫 번째 요소를 가리킴

    def push(self, data):
        if self.head is None:
            self.head = Node(data)
        else:
            # 연결리스트의 맨 앞의 노드를 추가
            new_node = Node(data)
            new_node.next = self.head
            self.head = new_node

    def pop(self):
        if self.head is None:
            return None
        else:
            popped_data = self.head.data  # 연결리스트 맨 앞에 있는 노드의 데이터를 반환+해당 노드 제거
            self.head = self.head.next
            return popped_data


a_stack = Stack()  # 인스턴스 생성
while True:
    print('push <value>')
    print('pop')
    print('quit')
    do = input('What would you like to do? ').split()

    operation = do[0].strip().lower()
    if operation == 'push':
        a_stack.push(int(do[1]))
    elif operation == 'pop':
        popped = a_stack.pop()
        if popped is None:
            print('Stack is empty.')
        else:
            print('Popped value: ', int(popped))
    elif operation == 'quit':
        break
