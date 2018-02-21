def percolate_up(index):
	global pq
	if(index==0):
		return
	if(pq[index]<pq[index//2]):
		temp=pq[index]
		pq[index]=pq[index//2]
		pq[index//2]=temp
		percolate_up(index//2)

def percolate_down(index):
	global pq
	smallest=index
	if(len(pq)<index):
		return
	if(len(pq)>2*index+2 and pq[2*index+1]>pq[2*index+2]):
		smallest=2*index+2
	elif(len(pq)>2*index+2 and pq[2*index+1]<pq[2*index+2]):
		smallest=2*index+1
	elif(len(pq)<2*index+2 and len(pq)>2*index+1):
		smallest=2*index+1
	if(pq[index]>pq[smallest]):
		temp=pq[smallest]
		pq[smallest]=pq[index]
		pq[index]=temp
		percolate_down(smallest)

def insert_in_pq(ele):
	global pq
	pq.append(ele)
	percolate_up(len(pq)-1)

def pop_from_pq():
	global pq
	ele=pq[0]
	pq[0]=pq[len(pq)-1]
	pq=pq[0:len(pq)-1]
	if(len(pq)!=0):
		percolate_down(0)
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
