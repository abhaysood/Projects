import socket
import threading
objects=[]
def sendMsg(l):
	
	for i in range(1,100):
		o=int(raw_input("enter the client number:  "))
		var=raw_input("enter the message SERVER:  ")
		objects[o].send(var)
		print objects[o].recv(1024)
	objects[o].close()

s=socket.socket() 
host=socket.gethostname() 
port=2254
s.bind((host,port)) 
s.listen(3)  

while True:
	c,addr = s.accept()
	objects.append(c)
	t=threading.Thread(target=sendMsg,args=(objects,))	
	t.start()
	print objects
	

