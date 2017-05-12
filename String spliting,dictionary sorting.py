'''
Task:
Ranking hotels based on the reviews
Sample test case
Input:
hotel good awesome food loving
5
2
your hotel food is good food
1
you hotel is good food
1
loving your hotel
3
awesome good food
4
hotel good awesome food loving

Output:
1 4 2 3

'''

import sys
import re
#sys.stdin=open('input.txt','r')
keywords=raw_input()
#print keywords
#keywords=re.split('; |, |\*|\n| ',keywords)
keywords=re.split(' |;|; |,|, |\.|\. ',keywords)
#print keywords
n=int(raw_input())
s=dict()
for i in xrange(n):
	p=int(raw_input())
	temp=raw_input()
	temp=re.split(' |;|; |,|, |\.|\. ',temp)
	count=0
	for r in temp:
		if r in keywords:
			count=count+1
	
	if s.has_key(p):
		s[p]+=count
	else:
		s[p]=count	
#print s
	
to_sort = s.items()#list of tupples to sort
ans = sorted(to_sort,key = lambda x:(-x[1],x[0]))
	
for p in ans:
	print p[0],	
