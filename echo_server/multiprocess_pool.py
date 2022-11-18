from multiprocessing import Pool


def doubler(number):
    return number * 2


if __name__ == '__main__':
    numbers = [5, 10, 20]
    pool = Pool(processes=len(numbers))
    print(pool.map(doubler, numbers))
