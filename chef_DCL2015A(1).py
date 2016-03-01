import collections
t=int(raw_input())
prime = [0]*1000
#prime[1]=1;
for i in xrange(2,1000):
	if(prime[i]==0):
		j=i*i;
		while(j<1000):
			prime[j]=1
			j=j+i
con=0
while t:
	ans=0
	l=raw_input()
	li=(collections.Counter(l).most_common())
	if(prime[li[0][1]]==0):
		con=0
	else:
		con=1
	for i in xrange (0,len(li)):
		if(li[i][1]==1):
			ans+=li[i][1]
		elif(prime[li[i][1]]==con):
			ans+=li[i][1]/2
		else:
			ans+=li[i][1]
	print ans
	t-=1