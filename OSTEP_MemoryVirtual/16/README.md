# Segmentation
## Homework
- 세그멘테이션 시스템에서의 주소 변환
### Questions
1. 작은 주소 공간(2개의 segments)을 사용하여 주소를 변환하여 보자. 아래는 여러 가지 랜덤 시드와 함께 간단한 매개변수의 집합이다.
```
    > segmentation.py -a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -s 0
    > segmentation.py -a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -s 1
    > segmentation.py -a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -s 2
```
2. 세그먼트 0의 valid한 가상 주소의 최댓값은? 세그먼트 1의 합법적인 가상 주소의 최저값은? 이 전체 주소 공간의 잘못된 주소 중 가장 큰 주소와 가장 작은 주소는? flag -A와 함께 실행한
segmentation.py의 정확성을 어떻게 확인할 수 있을까?
```
    The highest legal virtual address in segment 0: 19

    The lowest legal virtual address in segment 1: 128 - 20 = 108

    Segment 0 physical addresses: 0-19

    Segment 1 physical addresses: 492-511

    The lowest illegal physical address: 20

    The highest illegal physical address: 491
```
```
    $ ./segmentation.py -a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -s 1 -A 19,108,20,107 -c
```
3. 16바이트 주소 공간과 128바이트의 물리 메모리가 있다. 다음과 같은 변환 결과를 생성하기 위해서는 베이스와 바운드를
어떤 값으로 설정해야 하는가: valid, valid, violation, ..., violation, valid? 아래와 같은 매개변수를 가정한다.
```
    segmentation.py -a 16 -p 128
        -A 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
        --b0 ? --l0 ? --b1 ? --l1 ?
```

```
    $ ./segmentation.py -a 16 -p 128 -A 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 --b0 0 --l0 2 --b1 16 --l1 2 -c
```
4. random하게 생성된 VA 중 약 90%가 유효한 시스템에서 문제를 만들고 싶다고 가정하자. 시뮬레이터를 어떻게 설정해야 하는가? 어떤 매개변수가 중요한가?
    -l = 0.9 * -a
5. 모든 가상 주소가 유효하지 않도록 시뮬레이터를 실행할 수 있는가? 어떻게? 
    ```
    -l 0 -L 0
    ```
