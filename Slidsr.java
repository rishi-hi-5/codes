
public class Slidsr {
     Integer []arr;
	public Slidsr() {
		 System.out.println("---------Selective Repeat Method----------\n");
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
				count++;
				selective_repeat(i);
				i--;
			}
			
		}
		System.out.println("\nResult:\nData transmitted again "+count+" times");
	}

	
	
	private void selective_repeat(Integer intr)
	{
		System.out.println("Transmite data of location "+intr+" again from sender");
		arr[intr]=intr;
		System.out.println("Data Transmitted from sender successfully for location "+intr);
		
	}
	public static void main(String[] args) {
		Slidsr s=new Slidsr();
		s.sender();
		s.error(2, 3); //introducing error in transmitting data
		s.receiver();

	}

}

/*
nl@amol:~$ javac Slidsr.java
nl@amol:~$ java Slidsr
---------Selective Repeat Method----------

Data Received without error at location 0
Data Received without error at location 1
Data received with error at location 2
Transmite data of location 2 again from sender
Data Transmitted from sender successfully for location 2
Data Received without error at location 2
Data Received without error at location 3
Data Received without error at location 4
Data Received without error at location 5

Result:
Data transmitted again 1 times
*/
