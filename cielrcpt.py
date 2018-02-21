t=int(input())
while(t!=0):
	p=int(input())
	li=[]
	res=[]
	li.append(p)
	j=0
	#first we divide the element into fragments so that it lies in range of 2048 so that we can order an item from ciels restaurant
	while(j <len(li)):
		p=li[j]
		if(p>2048):
			a=2048
			b=p-a
			li.append(a)
			li.append(b)
		else:
			res.append(p)
		j+=1
	count=0
	for i in res:
		while(i!=0):
			if(i&1==1):
				count+=1
			i=i>>1
	print(count)
	t-=1