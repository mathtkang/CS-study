import multiprocessing
import logging
from multiprocessing import Process, Lock as lock_factory
from multiprocessing.synchronize import Lock
import os
from time import sleep
# 각각 다른 스코프에서 가져온거라 괜춘!


def doubler(number):
    result = number * 2
    proc = os.getpid()
    sleep(1)
    print(f'{number} doubled to {result} by process id: {proc}')


def printer(item: int, lock: Lock):
    # result = doubler(item)
    sleep(1)
    lock.acquire()  # lock을 걸겠다(lock이 풀릴 때까지 아무것도 못하고 기다리겠다)
    try:
        print(item)
        # doubler가 1초 기다리기 때문에, 기다리는 동안 락을 걸게 됨, printer함수는 다른 일을 수행할 수 없다.
    finally:
        lock.release()  # lock을 풀겠다


if __name__ == '__main__':
    lock = lock_factory()
    numbers = [5, 10, 15, 20, 25]
    procs: list[Process] = []
    multiprocessing.log_to_stderr()
    logger = logging.getLogger()
    logger.setLevel(logging.INFO)
    # instance를 생성하는 함수들을 factory라고 부름
    # 혹은 facotry pattern이라고도 부릅니다.

    for number in numbers:
        # Memory allocation for process (PCB)
        proc = Process(target=printer, args=(number, lock))
        procs.append(proc)
        proc.start()

    for proc in procs:
        proc.join()


# -------------------- 


# def printer(item, lock):
#     """
#     Prints out the item that was passed in
#     """
#     lock.acquire()
#     try:
#         print(item)
#     finally:
#         lock.release()


#  
# if __name__ == '__main__':
#     lock = Lock()
#     items = ['tango', 'foxtrot', 10]
#     multiprocessing.log_to_stderr()  # 로그를 생성하면 스텐다드 에러를 반환해라(터미널에서 stt에러 발생)
#     logger = multiprocessing.get_logger()
#     logger.setLevel(logging.INFO)
#     for item in items:
#         p = Process(target=printer, args=(item, lock))
#         p.start()
