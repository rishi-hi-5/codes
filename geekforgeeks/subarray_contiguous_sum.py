t=int(input())
while(t!=0):
	n,s=list(map(int,input().strip().split(" ")))
	arr=list(map(int,input().strip().split(" ")))
	st=0
	et=0
	sum=0
	f=0
	while(et<len(arr)):
		sum+=arr[et]
		et+=1
		while(sum>s):
			sum-=arr[st]
			st+=1
		if(st>et):
			et=st
			sum=0
		if(sum==s):
			f=1
			print(st+1,et)
			break
	if(f==0):
		print("-1")
	t-=1