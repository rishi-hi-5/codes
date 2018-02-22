while(True):
	l=int(input())
	if(l==0):
		break
	li=list(map(int,input().strip().split(" ")))
	res=[0 for i in range(0,l)]
	f=0
	for i in range(0,l):
		res[li[i]-1]=i+1
	for i in range(0,l):
		if(res[i]!=li[i]):
			f=1
			break
	if(f==0):
		print("ambiguous")
	else:
		print("not ambiguous")