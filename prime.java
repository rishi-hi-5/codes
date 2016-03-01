import java.io.*;
import java.util.Scanner;
class prime{
	public static void main(String arg[]){
		BufferedReader x=new BufferedReader(new InputStreamReader(System.in));
		Scanner scn=new Scanner(System.in);
		int t,flag,a,b;
		try{
			t=Integer.parseInt(x.readLine());
			while(t!=0){		
				a=scn.nextInt();
				b=scn.nextInt();
				for(int i=a;i<=b;i++){
					flag=1;
					for(int j=2;j<i;j++){
						if (i%j==0){
							flag=0;
							break;
						}
					}
					if (i<=1){
						continue;
					}
					if (flag==1){
						System.out.println(i);
					}
				}
				t--;
			}
		}
		catch(Exception e){
			return;
		}
	}
}