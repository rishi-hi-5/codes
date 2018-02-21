t=int(input())
while(t!=0):
	a,b=list(map(int,input().strip().split()))
	print(a%b)
	t-=1