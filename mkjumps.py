#(r-2,c-1), (r-2,c+1), (r-1,c-2), (r-1,c+2), (r+1,c-2), (r+1,c+2), (r+2,c-1), or (r+2,c+1)
from copy import deepcopy

X=[-2,-2,-1,-1,1,1,2,2]
Y=[-1,1,-2,2,-2,2,-1,1]

stack=[]
#stack push procedure
def stack_push(ele):
	global stack
	stack=[ele] + stack

#stack pop procedure
def stack_pop():
	global stack
	ret_val=stack[0]
	stack=stack[1:len(stack)]
	return ret_val
def clear_stack():
	global stack
	stack=[]
def stack_empty():
	global stack
	if len(stack)==0:
		return 1
	else :
		return 0

visited=[[0 for i in range(0,10)] for j in range(0,10)]

def valid(adj_mat,ele,a,b):
	visited=ele[3]
	global X
	global Y
	if not(a>=0 and a<10 and b>=0 and b<10):
		return False
	elif adj_mat[a][b]==1 and visited[a][b]!=1:
		return True

def print_visited(visited):
	for i in range(0,10):
		print visited[i]

def backtrack(adj_mat,x,y):
	visited=[[0 for i in range(0,10)] for j in range(0,10)]
	global X
	global Y
	max_tiles=0
	ele=[x,y,0,visited]
	stack_push(ele)
	while stack_empty()!=1 :
		visit=[]
		ele=stack_pop()
		visit=deepcopy(ele[3])
		visit[ele[0]][ele[1]]=1
#		print 'vertex visited is'
#		print ele[0:3]
#		print 'visited matrix is'
#		print_visited(visit)
		if(max_tiles<ele[2]):
			max_tiles=ele[2]

		for i in range(0,8):
			a=ele[0]+X[i]
			b=ele[1]+Y[i]
			c=ele[2]+1
			if valid(adj_mat,ele,a,b):
				new_visit=deepcopy(visit)
				new_ele=[a,b,c,new_visit]
				stack_push(new_ele)

	return max_tiles
	
clear_stack()
l=raw_input()
val=map(int,l.split(" "))
adj_mat=[[0 for i in range(0,10)] for j in range(0,10)]
total=0
for i in range(0,val[0]):
	for j in range(val[2*i+1], val[2*i+2]+val[2*i+1]):
		adj_mat[i][j]=1
		total=total+1

#back track the jumps on board with given x and y which is the starting point of the piece
print (total-backtrack(adj_mat,0,val[1]))