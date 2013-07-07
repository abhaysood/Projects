#WORKS ON FLIPKART,SAHOLIC,HOMESHOP18 sites : 22/march/2012


import urllib2
from BeautifulSoup import BeautifulSoup
import re

mobile=raw_input("enter mobile name\n")

url="http://www.flipkart.com/search/a/all?query="+mobile
var=urllib2.urlopen(url)
html=var.read()
soup=BeautifulSoup(html)
f=[]
print "----------------------------------------------"
for i in soup.findAll('div',{'class':'fk-price line rpadding3 n-dis'}):
	for j in i.findAll('span',{'class':'price final-price'}):
		f.append(" ".join(j.findAll(text=True)))
print 'Price of ' + mobile+' at FLIPKART is: '+str(f[0])
print "----------------------------------------------"


m=re.sub(r'\s','+',mobile)
url="http://www.saholic.com/search?q="+m
var=urllib2.urlopen(url)
html=var.read()
soup=BeautifulSoup(html)
s=[]
for i in soup.findAll('div',{'class':'productPrice'}):
	for j in i.findAll('div',{'class':'newPrice'}):
		s.append(" ".join(j.findAll(text=True)))
		
print 'Price of '+mobile+' at SAHOLIC is: '+str(s[0])
print "----------------------------------------------"


m=re.sub(r'\s','%20',mobile)
url="http://www.homeshop18.com/"+m+'/search:'+m
var=urllib2.urlopen(url)
html=var.read()
soup=BeautifulSoup(html)
h=[]

for i in soup.findAll('p',{'class':'product_price clearfix'}):
	for j in i.findAll('span',{'class':'product_new_price'}):
		h.append(" ".join(j.findAll(text=True)))
		
print 'Price of '+mobile+' at HOMESHOP18 is: '+str(h[0])

print "----------------------------------------------"

