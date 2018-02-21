t=int(input())
while(t!=0):
	s=input()
	l=''
	for j in range(0,len(s)):
		l+=s[len(s)-1-j]
	for i in range(0,len(l)):
		if(l[i]!='0'):
			l=l[i:len(l)]
			break
		else:
			continue
	print(l)
	t-=1