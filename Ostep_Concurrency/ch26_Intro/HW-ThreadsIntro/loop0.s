.main
.top
mov %ax,%dx
sub  $1,%dx
test $0,%dx 
mov %dx,%ax    
jgte .top         
halt
