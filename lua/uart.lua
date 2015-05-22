-- serial terminal software to show how sending serial data to the ESP826 under the nodeMCU-firmware works:

-- setup UART for receiving data
-- parameters UART.setup(UART-id, baud, databits, parity, stopbits, echo )
uart.setup(0,9600,8,0,1)

print ("UART.setup(0,9600,8,0,1) finished")
print ("waiting for serial data....")

-- You just send the NAME of a function with parameters and Lua knows what do to
-- Execute the defined function with parameters
-- example: sending the following string to the ESP makes the code execute function 'cmd_2' 
-- with parameter '78'    string to send towards ESP "cmd_2(78)"

function cmd_1(value)
  print("cmd_1("..value..") received")
end

function cmd_2(value)
  print("cmd_2("..value..") received")
end
