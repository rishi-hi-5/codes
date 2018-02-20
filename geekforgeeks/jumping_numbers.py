#implementation of priority queue
pq=[]
def insert_in_pq(ele):
	global pq
	pq.append(ele)
def pop_from_pq():
	global pq
	ele=pq[0]
	pq=pq[1:len(pq)]
	return ele

def print_pq():
	global pq
	for i in pq:
		print(i,end=' ')

def pq_empty():
	global pq
	if(len(pq)==0):
		return True
	else:
		return False

#implementation ends
s="0123456789"
def check_if_jumping(num):
	for i in range(0,len(num)):
		if(i==0 and abs(int(num[i])-int(num[i+1]))==1):
			continue
		elif(i==len(num)-1 and abs(int(num[i-1])-int(num[i]))==1):
			continue
		elif(i!=0 and i!=len(num)-1 and (abs(int(num[i])-int(num[i+1]))==1 or abs(int(num[i-1])-int(num[i]))==1)):
			continue
		else:
			return False
	return True

t=int(input())
while t!=0:
	pq=[]
	li=[]
	n=int(input())
	if(n>0):
		li.append(0)
	j=1
	while(j<min(n,10)):
		insert_in_pq(j)
		j+=1
		while(pq_empty()==False):
			ele=pop_from_pq()
			if(ele not in li):
				li.append(ele)
			for i  in s:
				if(int(str(ele)+i)<=n and check_if_jumping(str(ele)+i)):
					li.append(int(str(ele)+i))
					insert_in_pq(int(str(ele)+i))
	for i in li:
		print(i,end=' ')
	print()
	t-=1