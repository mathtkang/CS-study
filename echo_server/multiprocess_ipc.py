from multiprocessing import Process, Queue

sentinel = -1


def creator(data: list[int], q: Queue):
    """
    Creates data to be consumed and waits for the consumer
    to finish processing
    """
    print('Creating data and putting it on the queue')
    for item in data:
        q.put(item)  # 데이터를 하나씩 큐에 넣어줌


def my_consumer(q: Queue):  # 데이터를 얻어온다 / 큐에 데이터가 들어오면 데이터가 들어오자마자 반응

    while True:
        data = q.get()  # get으로 큐에서 데이터를 가져옴(제거했음) 락을 건다
        print(f'data found to be processed: {data}')  # 데이터를 넣자마자 해당 코드 실행
        processed = data * 2
        print(processed)

        if data is sentinel:  # 더이상 가져올 데이터가 없다면
            break


# 파이썬에는 name이라는 전역변수가 실행된다. (추가 공부) 모듈 : 메인프로세스
if __name__ == '__main__':
    q: Queue = Queue()  # q에 대한 reference (접근할 수 있는 인터페이스를 넘겨준다는 의미)
    data = [5, 10, 13, -1]
    process_one = Process(target=creator, args=(data, q))
    # 큐를 넘겨준다 : (오브젝트 카피가 아닌)큐에 대한 레퍼런스를 넘겨줌 : 포인터 주솟값을 넘겨준다는 의미
    process_two = Process(target=my_consumer, args=(q,))
    process_one.start()
    process_two.start()

    q.close()
    q.join_thread()

    process_one.join()
    process_two.join()
