
public class Slidgb {
     Integer []arr;
	public Slidgb() {
		 System.out.println("----------GO Back-n Method---------\n");
		arr=new Integer[6];
		
	}
	
	public void sender()
	{  
		for (int i = 0; i < arr.length; i++) {
			arr[i]=i;
			
		}
	}
	
	public void error(Integer in,Integer in1)
	{
		arr[in]=in1;
	}
	
	public void receiver()
	{
		Integer count = 0;
		for (int i = 0; i < arr.length; i++) {
			if(i==arr[i])
			{
				System.out.println("Data Received without error at location "+i);
				
			}
			else
			{
				System.out.println("Data received with error at location "+i);
				goback();
				count++;
				i=0;
			}
			
		}
		System.out.println("\nResult:\nData transmitted again "+count+" times");
	}

	private void goback()
	{
		System.out.println("Retransmitting all data again..........");
		sender();//sending data again from begining
	}
	
	
	public static void main(String[] args) {
		Slidgb s=new Slidgb();
		s.sender();
		s.error(2, 3); //introducing error in transmitting data
		s.receiver();

	}

}

/*nl@amol:~$ javac Slidgb.java
nl@amol:~$ java Slidgb
----------GO Back-n Method---------

Data Received without error at location 0
Data Received without error at location 1
Data received with error at location 2
Retransmitting all data again..........
Data Received without error at location 1
Data Received without error at location 2
Data Received without error at location 3
Data Received without error at location 4
Data Received without error at location 5

Result:
Data transmitted again 1 times
*/
