#facebook Chat Application


import sleekxmpp
import re,urllib2
from BeautifulSoup import BeautifulSoup
#import logging
#logging.basicConfig(level=logging.DEBUG)

def session_start(event):
	chatbox.send_presence()
	print 'session started'
	chatbox.get_roaster()
	
	
	
def message(msg):
	print msg
	msg.reply('hello this msg is from python').send()
	
jid=raw_input("Username:\t")
password=raw_input("Password:\t")

server=('chat.facebook.com',5222)

chatbox=sleekxmpp.ClientXMPP(jid,password)

chatbox.add_event_handler('session_start',session_start)

chatbox.add_event_handler('message',message)

chatbox.autoconnect=True

chatbox.connect(server)
chatbox.process(block=True)

