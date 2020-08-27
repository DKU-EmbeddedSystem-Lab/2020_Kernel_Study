# File System Implementation

## Homework

- mkdir, creat, open, link 등 여러 동작들을 처리할 때 파일 시스템의 상태가 어떻게 변하는지 살펴보기

### Questions

1. 랜덤시드(17, 18, 19, 20으로)를 사용하여 시뮬레이터를 실행해보자. 그리고 각 상태가 변할 때마다 어떤 연산이 수행되었는지 알아보자.
```
    ./vsfs.py -n 6 -s 17
    ./vsfs.py -n 6 -s 18
    ./vsfs.py -n 6 -s 19
    ./vsfs.py -n 6 -s 20
```

2. 이번에는 랜덤 시드(21, 22, 23, 24)를 바꾸고 -r 플래그를 사용하여 실행해보자. 수행된 연산이 출력되면 상태가 어떻게 바뀔지 예상해보자. inode와 data block 할당 알고리즘이 어떤 블럭들을 할당하기를 선호할지의 측면에서 내릴 수 있는 결론은?
```
    ./vsfs.py -n 6 -s 21 -r
    ./vsfs.py -n 6 -s 22 -r
    ./vsfs.py -n 6 -s 23 -r
    ./vsfs.py -n 6 -s 24 -r
```

>   First available block.


3. 파일 시스템의 데이터 블럭의 수를 2로 줄이고 백여 개의 요청을 시뮬레이터에서 처리하여 보자. 이렇게 제약적인 batch에서 최종적으로 파일 시스템에 남는 파일의 종류는 무엇인가? 어떤 종류의 작업이 실패하게 될까?
```
    ./vsfs.py -d 2 -n 100 -p -c -s 21
```

>   Some empty files and links in the root directory. 
>   _makedir()_ and _write()_ fail. The last data block seems can't be used.


4. inode에 대해서 똑같이 실행해 보자. 매우 적은 수의 아이노드를 사용할 때 어떤 종류의 작업들이 성공할 수 있을까? 어떤 종류가 대체적으로 실패할까? 파일 시스템의 최종 상태는 어떻게 될까?
```
    ./vsfs.py -i 2 -n 100 -p -c -s 21
```
>   All operations except _unlink()_ will fail. Only the first inode is available.
>   Change to three inodes ends up with an empty directory or a small file.
