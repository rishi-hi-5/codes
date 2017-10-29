l=int(input())
n=int(input())
while(n!=0):
    dim=[*map(int,input().split(" "))]
    if(dim[0]==dim[1] and dim[0]>=l and dim[1]>=l ):
        print("ACCEPTED")
    elif(dim[0]!=dim[1] and dim[0]>=l and dim[1]>=l):
        print("CROP IT")
    else:
        print("UPLOAD ANOTHER")
    n-=1
