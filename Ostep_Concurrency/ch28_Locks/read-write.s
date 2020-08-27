#Reader-Writer code
#%cx
# Producer -> 0
# Consumer -> 1
# register
# Memory name : buffer (size 1)

.var buf
.var mutex

.var buf_max
.var condition

.main 
.top
test	$0, %cx
je	.producer 

.consumer
mov 	$1, %ax
xchg 	%ax, mutex	#atomic swap of 1 and mutex
test 	$0, %ax		# if we get 0 back : lock is free 
jne	.consumer	# if not, try again

# Critical Section
mov 	buf, %ax
sub	$1, %ax
mov 	%ax, buf

#release lock
mov	$0, mutex

#see if we're still looping
sub 	$1, %bx
test	$0, %bx
jgt	.consumer
halt


.producer
mov	$1, %ax
xchg	%ax, mutex	#also, atomic exchange
test	$0, %ax
jne	.producer	#if lock is not free : try again 

#Critical Section
mov 	buf, %ax
add 	$1, %ax
mov 	%ax, buf

#release lock
mov	$0, mutex
 
#see if we're still looping
sub	$1, %bx
test	$0, %bx
jgt	.producer
halt

