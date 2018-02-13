import math
seg_tree=[]
def construct_seg_tree(arr,st,et,pos):
	if(st==et):
		seg_tree[pos][0]+=arr[st]
		seg_tree[pos][1].append(st)
		return seg_tree[pos]
	mid=(st+et)//2
	left_tree=construct_seg_tree(arr,st,mid,2*pos)
	right_tree=construct_seg_tree(arr,mid+1,et,2*pos+1)
	seg_tree[pos][0]=left_tree[0]+right_tree[0]
	seg_tree[pos][1].extend(left_tree[1])
	seg_tree[pos][1].extend(right_tree[1])
	return seg_tree[pos]

t=int(input())
while(t!=0):
	n,s=list(map(int,input().strip().split(" ")))
	size=2*int(math.pow(2,(int(math.ceil(math.log2(n))))));
	seg_tree=[[0,[]] for i in range(0,size)]
	print(seg_tree)
	arr=list(map(int,input().strip().split(" ")))
	init=[0]
	init.extend(arr)
	arr=init
	construct_seg_tree(arr,1,n,1)
	print(seg_tree)