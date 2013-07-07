import subprocess
import re
import filecmp
import sys
import threading
import time


#Receive the cmd line arguments in string variable
string=str(sys.argv[1])					
status=-1
#Split String to get Language,question number,username
language=string[0:2]
qnum=string[2:4]
username=string[4:]


f=open('user_data/out_'+username,'w') #output file


def loop_detector():
	time.sleep(10)
	status=5
			#time limit exceeded
	
t=threading.Thread(target=loop_detector)

#Run C code
def compileC():
	#global language,qnum,username,status
	compile = 'gcc files/' + username + '.c -o user_data/' + username + ' 2>' + ' user_data/err_' + username
	execute = "./user_data/" + username + " < in_files/in_" + qnum +" > user_data/out_" + username+"_" + qnum + ';'+'echo $? > '+'./user_data/' + username
	
	#File for dumping errors
	f1 = open('user_data/err_'+username,'w+')	
	
	#Compile code and check for compile time errors
	subprocess.call([compile],shell=True)	

	#If there is no compile error then run binary 
	if (f1.read() == ""):				
		subprocess.call([execute],shell=True)
	t.start()
	#Check for run time errors
	if(f1.read() == ""): 
		#If no Errors then compare files 
		if(filecmp.cmp('user_data/out_'+username+"_"+qnum, 'out_files/out_'+qnum)==True):
			status=1 #ca
		else:
			status=2 #wa
	else:
		#If run time error
		status=4	#re 
	print status
	
	
	

def compilePY:
	#open error file
	f1 = open('user_data/err_'+username,'w')
	cmd='python files/'+ username +'.py ' + '< in_files/in_'+qnum+' >user_data/out_'+username+'_'+qnum+' 2>user_data/err_'+username
	#start timer thread
	t.start()
	#run the code
	subprocess.call([cmd],shell=True)
	#close file
	f1.close()
	#open error file for read
	f1 = open('user_data/err_'+username,'r')
	#if there is an error put it in pyError
	if(f1.read()!=""):
		lineList=f1.readlines()
		pyError=lineList[-1].split(':')[0] 
	#else compare files
	else:	
		if(filecmp.cmp('user_data/out_'+username+"_"+qnum, 'out_files/out_'+qnum)==True):
			status=1 #ca
		else:
			status=2 #wa
	print status
		
		


def compileCPP():
	#global language,qnum,username,status
	compile = 'g++ files/' + username + '.c -o user_data/' + username + ' 2>' + ' user_data/err_' + username
	execute = "./user_data/" + username + " < in_files/in_" + qnum +" > user_data/out_" + username+"_" + qnum + ';'+'echo $? > '+'./user_data/' + username
	
	#File for dumping errors
	f1 = open('user_data/err_'+username,'w+')	
	
	#Compile code and check for compile time errors
	subprocess.call([compile],shell=True)	

	#If there is no compile error then run binary 
	if (f1.read() == ""):		
		t.start()		
		subprocess.call([execute],shell=True)
		
	#Check for run time errors
	if(f1.read() == ""): 
		#If no Errors then compare files 
		if(filecmp.cmp('user_data/out_'+username+"_"+qnum, 'out_files/out_'+qnum)==True):
			status=1 #ca
		else:
			status=2 #wa
	else:
		#If run time error
		status=4	#re 
	print status
	
	
	
	
	
	

#If language is C==01
if(language=="01"):
	compileC()
	
#If language is PY==02
if(language=="02"):
	compilePY()
#If language is C++==03
if(language=="03"):
	compileCPP()



subprocess.call(['rm user_data/out_'+username+"_"+qnum],shell=True)
subprocess.call(['rm user_data/out_'+username],shell=True)



