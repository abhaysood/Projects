#client side control
import socket
	

s=socket.socket() #socket = computers
host=socket.gethostname()  #ip address
port=2254#any no > 1023
s.connect((host,port)) #tuple
while True:
        print s.recv(1024) #1024 size of text/or whatever recieved send from server
        s.send(raw_input("enter the msg"))
 
s.close()

 

