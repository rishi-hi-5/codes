import java.io.*;
import java.util.*;

class MuffinsThree{
	public static void main(String arg[]) throws IOException{
		int t,n;
		Scanner sc=new Scanner(System.in);
		t=sc.nextInt();
		while(t!=0){
			n=sc.nextInt();
			//int max=-1;
			//int max_res=-1;
			// for(int i=2;i<=n;i++){
			// 	if(max<n%i){
			// 		max=n%i;
			// 		max_res=i;
			// 	}
			// }
			// here if you take an example and try to package with numbers from 2 to n you will get to know that chef will get max cup cake at 
			// n/2+1 and other point the chef will be able to deliever max package but he wont be able to get max cake for him . Actually the question is not clearly stated. it is quite vague :D

			System.out.println(Math.round(Math.floor(n/2))+1);
			t--;
		}
	}
}