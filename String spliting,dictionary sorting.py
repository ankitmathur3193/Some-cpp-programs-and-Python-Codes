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
total_no_of_reviews=int(raw_input())
mydict=dict()
for i in xrange(total_no_of_reviews):
	hotel_id=int(raw_input())
	hotel_review=raw_input()
	hotel_review=re.split(' |;|; |,|, |\.|\. ',hotel_review)
	count=0
	for r in hotel_review:
		if r in keywords:
			count=count+1
	
	if mydict.has_key(hotel_id):
		mydict[hotel_id]+=count
	else:
		mydict[hotel_id]=count	
#print s
	
to_sort_list_of_tuples = mydict.items()#list of tupples to sort
ans = sorted(to_sort_list_of_tuples,key = lambda x:(-x[1],x[0]))#revese sort on values,but if values is same
																 #then sort accoring to hotel_id
	
for p in ans:
	print p[0],	#printing hotel_id in descending order
