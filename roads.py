k=int(input())#test cases
c=int(input())#total coins the traveller has
n=int(input())#total number of cities
nr=int(input())#number of roads
def print_my_list(l=[[]]):
    [print(list[i]) for i in range(0,n)]

while k >0 :
    list=[[[0,0] for i in range(0,n)] for j in range(0,n)]
    s,d,l,t=map(int,input().split())
    list[s-1][d-1][0]=l
    list[s-1][d-1][1]=t
    print_my_list(list)
    k-=1
