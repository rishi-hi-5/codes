t=input();
s="";
while t:
	s=raw_input();
	l=len(s);
	res=ord(s[l-1])-48;
	i=l-1;
	while 1:
		if i<=0: 
			break;
		i=i-1;
		op=s[i];
		i=i-1;
		temp2=ord(s[i])-48;
		if op=='+':
			res=res+temp2;
		elif op=='-':
			res=res-temp2;
		elif op=='*':
			res=res*temp2;
	print res;
	t=t-1;
