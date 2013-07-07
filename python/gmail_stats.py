import email,re
import imaplib2,sys
from email.parser import HeaderParser
import operator


def folders():
	print "\nFolders:\n"
	t,data =mail.list()			#print gmail floders name
	for i in data:
		x=re.search(r'"(\w+)"',i)
		try:
			print x.group(1)
		except AttributeError as e:
			pass


def mail_count():			# number of mails in inbox
	count=data[0].split()
	print "Total Mails:"
	print count[-1]

def status():				#read and unread mail in a particular 						folder 		
	f=raw_input("\nEnter the name of folder:\n")				
	stat=[]
	stat.append("".join(str(mail.status(f, '(MESSAGES RECENT UIDNEXT UIDVALIDITY UNSEEN)'))))
	for i in stat:
		x=re.search(r'MESSAGES\s(\d+) RECENT (\d+) UIDNEXT (\d+) UIDVALIDITY (\d+) UNSEEN (\d+)',i)
		print "\nTOTAL Mails in INBOX:\n"+x.group(1)
		print "\nUNREAD Mails in INBOX:\n"+x.group(5)
	
def logout():
	mail.logout()

def search():
	r=raw_input("\nEnter the name of friend:\n")
	name="\'(FROM " + "\"" + r+"\")\'"
	
	typ, msg_ids = mail.search(None, name)
	print msg_ids

def get_mail_details():
	r=raw_input("\nEnter the mail number:\n")
	data = mail.fetch(r, '(BODY[HEADER])')
	header_data = data[1][0][1]
	parser = HeaderParser()
	msg = parser.parsestr(header_data)
	print "\nFrom: "+msg['From'],"\nTo: "+msg['To'],"\nSubject: "+msg['Subject'],"\nDate: "+msg['Date']+"\n"


def mail_number_stats():			#max mails,mail sender count
	from_list=[]
	from_count={}
	typ, data = mail.search(None, 'ALL')
	ids = data[0]
	id_list = ids.split()
	#get the most recent email id
	latest_email_id = int( id_list[-1] )

	for i in range( latest_email_id, latest_email_id-100, -1 ):
		typ, data = mail.fetch( i, '(RFC822)' )

		for response_part in data:
			if isinstance(response_part, tuple):
				msg = email.message_from_string(response_part[1])
				varSubject = msg['subject']
				varFrom = msg['from']

		#remove the brackets around the sender email address
		varFrom = varFrom.replace('<', '')
		varFrom = varFrom.replace('>', '')	
		from_list.append(varFrom)
	for i in from_list:
		if from_count.has_key(i):
			from_count[i]=from_count[i]+1
		else:
			from_count[i]=1
	#for j in from_count.keys():		
		#print j,":",from_count[j]
	max_mails_by= max(from_count.iteritems(), key=operator.itemgetter(1))[0]
	print max_mails_by,":",from_count[max_mails_by]


###############################################################################	
####################            M A I N              ########################
###############################################################################

mail=imaplib2.IMAP4_SSL('imap.gmail.com')
#username=raw_input("Enter the gmail username:\n")
#password=raw_input("Enter the gmail password:\n")
mail.login("soodabhay23","aanchalabhay")

mail.select('INBOX')

result,data=mail.search(None,"ALL")
#print result
#print data	# as list...prints the mail numbers
#print data[0]   # as string


querry=int(raw_input("Enter Your Choice:\n0. EXIT\n1. Total Mails \n2. List Of Floders\n3. Status of Mails in any Folder\n4. Search mail by sender's name\n5. Get the mail details\n6.Mail sender stats\n"))


if(querry==0):
	logout()
	sys_exit()
elif(querry==1):
	mail_count()
elif(querry==2):
	folders()
elif(querry==3):
	status()
elif(querry==4):
	search()
elif(querry==5):
	get_mail_details()
elif(querry==6):
	mail_number_stats()


logout()











