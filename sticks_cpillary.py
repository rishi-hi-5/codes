c1x,c1y=list(map(int,input().strip().split()))
c2x,c2y=list(map(int,input().strip().split()))
nloc=int(input())
xloc=list(map(int,input().strip().split()))
yloc=list(map(int,input().strip().split()))
rloc=list(zip(xloc,yloc))
q=int(input())
listq=list(map(int,input().strip().split()))
for i in range(0,q):
	res1=[]
	res2=[]
	r=[]
	q1=listq[i]
	min1=(c1x-q1,c1y-q1)
	min2=(c2x-q1,c2y-q1)
	max1=(c1x+q1,c1y+q1)
	max2=(c2x+q1,c2y+q1)

	for j in range(0,len(rloc)):
		if(min1[0]<rloc[j][0] and min1[1]<rloc[j][1] and max1[0]>rloc[j][0] and max1[1]>rloc[j][1]):
			res1.append(rloc[j])
		if(min2[0]<rloc[j][0] and min2[1]<rloc[j][1] and max2[0]>rloc[j][0] and max2[1]>rloc[j][1]):
			res2.append(rloc[j])
	res1=set(res1)
	res2=set(res2)
	r=res1.intersection(res2)
	if(i!=q-1):
		print(len(r),end=" ")
	else:
		print(len(r),end="\n")