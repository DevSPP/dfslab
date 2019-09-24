define clear
shell clear
end
clear
#set pagination off
#set logging file gdb.output
#set logging on
#set loggin off
#----------------Execution---------
b main
r
define pn
p *($arg0)
end

