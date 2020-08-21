.var flag
.var count

.main
.top

.acquire
mov  flag, %ax      # get flag //1. load
test $0, %ax        # if we get 0 back: lock is free! //2. test!
jne  .acquire       # if not, try again //3. and
add  $1, %ax		#4-1. set 
mov  %ax, flag       # store 1 into flag //4.2 set

# critical section
mov  count, %ax     # get the value at the address
add  $1, %ax        # increment it
mov  %ax, count     # store it back

# release lock
mov  flag, %ax		#1. load 
sub  $1, %ax       # clear the flag now //2. sub, release lock
mov  %ax, flag		#3. store

# see if we're still looping
sub  $1, %bx
test $0, %bx
jgt .top	

halt

