t=int(input())
while(t!=0):
	s=input()
	count=0
	for i in s:
		if i=='4':
			count+=1
	print(count)
	t-=1