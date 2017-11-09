/* IMPORTANT: Multiple classes and nested static classes are supported */

/*
 * uncomment this if you want to read input.
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;
*/
//import for Scanner and other utility classes
import java.util.*;


// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

class TestClass {
    public static void main(String args[] ) throws Exception {
        /* Sample code to perform I/O:
         * Use either of these methods for input
        */
        //Scanner
        Scanner s = new Scanner(System.in);
        Integer size= s.nextInt();
        Integer searchnum= s.nextInt();
        List<Integer> l= new ArrayList<>();
        int maxInd=-1;
        for(int i=0;i<size;i++){
            l.add(s.nextInt());
        }
        for(int i=0;i<size;i++){
            if(l.get(i)==searchnum){
                maxInd=i;
            }
        }
        System.out.println(i);
    }
}
