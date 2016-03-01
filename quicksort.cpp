#include<iostream>
#include<cstdio>
using namespace std;
int a[10];
int partition(int left,int right)
{
	int i,j,swape;
	i=left;
	j=right;
	int pivot=a[(left+right)/2];
	while(i<=j)
	{
		while(a[i]<pivot)
		i++;
		while(a[j]>pivot)
		j--;
		if(i<=j)
		{
			swape=a[j];
			a[j]=a[i];
			a[i]=swape;
			i++;j--;
		}
		
	}
	int p=i-1;
	return p;
}
void quicksort(int left,int right)
{
	int p=partition(left,right);
	if(left<p)
	quicksort(left,p);
	if(right>p+1)
	quicksort(p+1,right);

}
int main()
{
	int left,right,temp;
	cout<<"enter the array";
	for(int i=0;i<10;i++)
	{
		cin>>a[i];
	}
	left=0;
	right=9;
	quicksort(left,right);
		
	for(int i=0;i<10;i++)
	{
		cout<<a[i];
	}
	return 0;
}
