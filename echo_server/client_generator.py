import subprocess
import sys
import asyncio


# for i in range(100):
#     proc = subprocess.run(  # sync code
#         [
#             sys.executable,
#             'client.py',
#         ],
#     )


async def create_client():
    (
        await asyncio.create_subprocess_exec(
            sys.executable,
            'client.py',
            stdout=asyncio.subprocess.PIPE,
        )
    )


async def main():
    asyncio.gather(*[create_client() for _ in range(100)])
# 코루틴들을 한번에 실행시키는 것 (모든 메모리가 적재되어 있는 곳을 코루틴이라 하기로 함)
# gather함수가 : 100개 만들고 한번에 실행함! 이벤트루프를 생성하지 않음

asyncio.run(main())
# 이벤트루프(gather와 run의 차이)
