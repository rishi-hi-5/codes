t=input();
a=[None]*t;
i=0;
k=0;
j=t;
count=-1;
while(t!=0):
	fact=1;
	a[i]=input();
	k=2;
	while(k<=a[i]):	
		fact=fact*k;	
		k=k+1;
	a[i]=fact;
	i=i+1;
	t=t-1;
i=0;
while(i!=j):
	#print(""+str(a[i]));
	#count=-1;
	#k=a[i]%10;
	#while(k==0):
	#	count=count+1;
	#	k=a[i]%10;
	#	a[i]=a[i]/10;
	#	print(str(k));
	#print(""+str(count));
	#i=i+1;
	strr="";	
	strr=str(a[i]);
	ls=[];
	ls=strr.split
	print(ls);
	i=j;		
