import java.io.*;
import java.util.Scanner;
import java.util.*;
class NiyoOne{
	
	void bfs(List<List<Integer>> graph,Integer root,List<Integer> vi,Boolean flag,Integer findNode,List<Integer> list){
		if(flag==true && !list.contains(root)){
			list.add(root);
		}
		for(Integer i=0;i<graph.get(root).size();i++){
			if(vi.get(graph.get(root).get(i)).equals(0)){
				vi.set(graph.get(root).get(i),1);
				if(graph.get(root).get(i).equals(findNode))
					flag=true;
				bfs(graph,graph.get(root).get(i),vi,flag,findNode,list);
			}
		}
	}

	public static void main(String arg[]) throws IOException{
		Scanner sc= new Scanner(System.in);
		NiyoOne ny= new NiyoOne();
		List<Integer> list;
		Integer n,q,u,v;
		n=sc.nextInt();
		q=sc.nextInt();
		List<List<Integer>> graph=new ArrayList<>();
		List<Integer>vi;
		for(Integer i=0;i<n;i++){
			List<Integer> zz=new ArrayList<>();
			graph.add(zz);
		}

		StringBuilder sb= new StringBuilder();
		for(Integer i=0;i<n;i++){
			sb.append(sc.next());
		}
		String s=sb.toString();

		for(Integer i=0;i<n-1;i++){
			u=sc.nextInt();
			v=sc.nextInt();
			u--;
			v--;
			graph.get(u).add(v);
			graph.get(v).add(u);
		}

		Integer node;
		StringBuilder mm;
		while(q--!=0){
			vi=new ArrayList<>();
			for(Integer i=0;i<n;i++){
				vi.add(0);
			}

			vi.set(0,1);
			list=new ArrayList<>();
			node=sc.nextInt();
			node--;
			mm=new StringBuilder(sc.next());
			ny.bfs(graph,0,vi,false,node,list);
			for(Integer i=0;i<list.size();i++){
				if(mm.indexOf(s.charAt(list.get(i))+"")>=0){
					mm.deleteCharAt(mm.indexOf(s.charAt(list.get(i))+""));
				}
			}
			System.out.println(mm.length());
		}
		
	}
}