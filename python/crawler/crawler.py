from BeautifulSoup import BeautifulSoup
import redis
import sys
import urllib2
import urlparse
import html2text as htmlconverter
import re


url_base=raw_input("Enter the url you want to crawl:\n")
depth=raw_input("Enter the depth to which you want to crawl:\n")
linkHolder=[]
links_base=[]
links=[]
r=redis.StrictRedis()
current_depth=0
page_num=0


def fetch_html(url):  		
	try:	#return the html of any url
		html=urllib2.urlopen(url).read()
	except (urllib2.HTTPError,urllib2.URLError),e:
		return -1
	soup=BeautifulSoup(html)
	return soup

def extract_text(url):			#print the plain text from any url
	try:	#return the html of any url
		html=urllib2.urlopen(url).read()
	except (urllib2.HTTPError,urllib2.URLError),e:
		return -1
	try:	#return the html of any url
		print htmlconverter.html2text(html)
	except: pass
	
	
		
		
def extract_urls(soup,u):		#put all urls of page in a list
	linkHolder=[]
	for j in soup.findAll(href=True):
		j['href'] = urlparse.urljoin(u,j['href'])
		linkHolder.append(j['href'].encode('ascii', 'replace'))
	return linkHolder


def db(url,set_name):				#dump set into database
	if(r.sismember(url,set_name)):
		return
	else:
		r.sadd(set_name,url)
	
#def words_store:
	
def create_base_set():			#create a "base" set in DB
	bsoup=fetch_html(url_base)
	extract_text(url_base)
	links_base=extract_urls(bsoup,url_base)
	for i in links_base:
		db(i,"base")



def now_crawl(url):
	global page_num
	page_num=page_num+1
	
	bsoup=fetch_html(url)
	if (bsoup==-1):
		return
	
	else:
		extract_text(url)
		links=extract_urls(bsoup,url)
		for i in links:
			db(i,"page"+str(page_num))
		del links[0:len(links)]
	



def depth_one():
	for i in range(0,r.scard("base")-1):
		now_crawl(r.srandmember('base'))
		#print(r.srandmember("base"))
	current_depth=1
	
def ndepth():
	global current_depth,depth
	while(depth>current_depth):
		for j in range(1,page_num):
			for i in range(1,r.scard("page"+str(j))-1):
				now_crawl(r.srandmember("page"+str(j)))
		current_depth=current_depth+1

#def intersect():

create_base_set()
depth_one()

ndepth()

print "%d pages created"%(page_num)




