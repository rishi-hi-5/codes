n=int(input())
al=[[] for i in range(0,n)]
v=[0 for i in range(0,n)]
q=[]
def push_back(e):
	global q
	q.append(e)
def pop():
	global q
	q=q[1:]
def front():
	global q
	return q[0]
def is_empty(): 
	if(len(q)==0):
		return True
	return False

def bfs(al,x):
	global v
	cnt=0
	e=[0,1]
	v[0]=1
	push_back(e)
	while is_empty()!=True:
		e=front()
		pop()
		if(e[1]==x):
			cnt+=1
		else:
			i=0
			while(i<len(al[e[0]])):
				if(v[al[e[0]][i]]!=1):
					v[al[e[0]][i]]=1
					newe=[al[e[0]][i],e[1]+1]
					push_back(newe)
				i+=1
	return cnt
n=n-1
while(n!=0):
    a,b=input().strip().split()
    a=int(a)
    b=int(b)
    al[a-1].append(b-1)
    al[b-1].append(a-1)
    n=n-1
#print(al)
x=int(input())
print(bfs(al,x))