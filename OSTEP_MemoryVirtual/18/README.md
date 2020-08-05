# Paging: Introduction

## Homework

- 선형 페이지 테이블을 이용한 virtual-to-physical 주소 변환의 작동과정을 살펴보기

### Questions

1. 시뮬레이터를 이용해 매개변수가 바뀜에 따라 linear page table의 크기를 계산하시오. ('-v' flag: 얼마나 많은 
Page Table 항목이 채워지는지 알 수 있음)
먼저, Address space이 커짐에 따라 linear page table 크기의 변화를 이해하기 위하여: 

```
    ./paging-linear-translate.py -P 1K -a 1m -p 512m -v -n 0
    ./paging-linear-translate.py -P 1K -a 2m -p 512m -v -n 0
    ./paging-linear-translate.py -P 1K -a 4m -p 512m -v -n 0
```
그런 다음 page 크기가 커짐에 따라 linear page table 크기의 변화를 이해하기 위하여:

```
    ./paging-linear-translate.py -P 1K -a 1m -p 512m -v -n 0
    ./paging-linear-translate.py -P 2K -a 1m -p 512m -v -n 0
    ./paging-linear-translate.py -P 4K -a 1m -p 512m -v -n 0
```
실행 전 예상 경향에 대해 생각해 보아라. Address space가 커지면 page table 크기는 어떻게 변하는가? page 크기가 커지는 경우는? 일반적으로 큰 page 크기를 사용하면 안 되는 이유는?

>   page table 크기 = address space / page size

2. 이제 변환을 시작해보자. '-u' flag를 사용해 address space에 할당된 page 개수를 변경해 보아라.

```
    ./paging-linear-translate.py -P 1K -a 16k -p 32K -v -u 0
    ./paging-linear-translate.py -P 1K -a 16k -p 32K -v -u 25
    ./paging-linear-translate.py -P 1K -a 16k -p 32K -v -u 50
    ./paging-linear-translate.py -P 1K -a 16k -p 32K -v -u 75
    ./paging-linear-translate.py -P 1K -a 16k -p 32K -v -u 100

```

각 주소 공간에 할당된 page의 비율을 높인다면 어떤 일이 벌어지는가?
>   valid한 page들이 더 많아질 것이다.

```
    $ ./segmentation.py -a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -s 1 -A 19,108,20,107 -c
```
3. 몇 가지 random seed를 주고 다른 address space 매개변수를 이용해보자

```
    ./paging-linear-translate.py -P 8  -a 32   -p 1024 -v -s 1
    ./paging-linear-translate.py -P 8K -a 32k  -p 1m   -v -s 2
    ./paging-linear-translate.py -P 1m -a 256m -p 512m -v -s 3

```
위 조합 중 어느 것이 비현실적인가? 이유는?
>   

4. 다른 문제를 시험해 보기 위해 프로그램을 사용하라. 프로그램이 더 이상 작동하지 않는 제약을 찾을 수 있는가? 예를 들어, 만약 address space의 크기가 물리 메모리보다 크다면 어떤 일이 벌어지는가?

```
$ ./paging-linear-translate.py -a 65k -v -c
ARG address space size 65k
ARG phys mem size 64k
Error: physical memory size must be GREATER than address space size (for this simulation)

$ ./paging-linear-translate.py -a 0 -v -c
ARG address space size 0
Error: must specify a non-zero address-space size.

$  ./paging-linear-translate.py -p 0 -v -c
ARG phys mem size 0
Error: must specify a non-zero physical memory size.

$ ./paging-linear-translate.py -P 0 -v -c
Traceback (most recent call last):
File "./paging-linear-translate.py", line 85, in <module>
    mustbemultipleof(asize, pagesize, 'address space must be a multiple of the pagesize')
File "./paging-linear-translate.py", line 14, in mustbemultipleof
    if (int(float(bignum)/float(num)) != (int(bignum) / int(num))):
ZeroDivisionError: float division by zero

$ ./paging-linear-translate.py -P 32k -v -c
Traceback (most recent call last):
File "./paging-linear-translate.py", line 174, in <module>
    if pt[vpn] < 0:
IndexError: array index out of range
```
