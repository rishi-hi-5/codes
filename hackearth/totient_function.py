import math
isprime=[0 for i in range(0,1000001)]
t=int(input())
cnt=0
primes=[]
for i in range(2,t+1):
	if(isprime[i]!=0):
		continue
	else:
		primes.append(i)
	for j in range(2,t+1):
		if(i*j>t):
			break
		isprime[i*j]=1
result=t
for i in primes:
	if(t%i==0):
		result*=(1-(1/i))

print(int(result))