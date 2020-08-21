.main
.top
mov 2000,%ax
add $1,%ax
mov %ax,2000
mov 2000, %ax
test  %ax,2000
jgt .top
halt
