import sleekxmpp
import re,urllib2
from BeautifulSoup import BeautifulSoup

def session_start(event):
	chatbox.send_presence()
	print 'session started'
	chatbox.get_roaster()
	
	
def message(msg):
	print 'message received from:'
	print msg['from']
	a=msg['body']
	print a
	
	url=urllib2.urlopen(r'http://dictionary.reference.com/browse/'+a)

	html=url.read()

	soup=BeautifulSoup(html)

	for i in soup.findAll('div',{'class':'dndata'}):			
		p=i.findAll(text=True)
		a=" ".join(p)
		msg.reply(a).send()
	
jid=raw_input("Username:\t")
password=raw_input("Password:\t")

server=('talk.google.com',5222)

chatbox=sleekxmpp.ClientXMPP(jid,password)

chatbox.add_event_handler('session_start',session_start)

chatbox.add_event_handler('message',message)

chatbox.autoconnect=True

chatbox.connect(server)
chatbox.process(block=True)

