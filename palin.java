import java.io.*;
class checkpalin{
	String res,str;
	StringBuffer rev;
	boolean ret;
	String palcheck(int check){
		while (true){
			str=Integer.toString(check);
			rev=new StringBuffer(str);
			res=new String(rev.reverse());
			ret=str.equals(res);
			if(ret==true){
				return str;
			}
			else{
				check++;
			}
		}
	}
}
class palin{
	public static void main(String ar[]){
		int test,check;
		checkpalin ch=new checkpalin();
		String result=new String();
		BufferedReader x=new BufferedReader(new InputStreamReader(System.in));
		try{
				
				test=Integer.parseInt(x.readLine());
				while(test!=0){
					check=Integer.parseInt(x.readLine());
					if (check>=1000000 || check<0){
						test--;
						continue;
					}
					check++;	
					result=ch.palcheck(check);
					System.out.println(result);
					test--;
				}
		}
		catch(Exception e){
			return;
		}
	}
}