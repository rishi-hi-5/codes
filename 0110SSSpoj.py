a=1
b=1
n=input()
i=0
sum=0;
while(i<n):
	sum=a+b
	a=b
	b=sum
	i+=1
print sum,	
