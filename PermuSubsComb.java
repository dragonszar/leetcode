package leetcode;

import java.util.HashMap;
import java.util.ArrayList;
import java.util.Stack;

public class PermuSubsComb {

	//private static int[] options = {1,2,3,4,5,6};
	private static int[] options = {1,2,3,4};
	public static void permu(int required, int path, int[] sln){
		if(path>=required){
			String toprint = "";
			for(int i=0; i<sln.length; i++)
				toprint = toprint + sln[i];
			System.out.println(toprint);
			return;
		}
		HashMap<Integer, Boolean> h = new HashMap<Integer, Boolean>();	//Use hashmap so that we only need to loop once
		for(int i=0; i<path; i++){
			h.put(sln[i], true);
		}
		for(int i=0; i<options.length; i++){
			if(h.get(options[i])==null){ //Cannot be if(!h.get(options[i]))
				sln[path] = options[i];
				permu(required, path+1, sln);	//not ++path
				//sln[path] = 0;	//previous choice will be overwrite by new choice, thus no need to maintain
			}
		}
			
	}
	
	public static void comb(int required, int path, int stt, int[] sln){
		if(path>=required){
			String toprint = "";
			for(int i=0; i<sln.length; i++)
				toprint = toprint + sln[i];
			System.out.println(toprint);
			return;
		}
		for(int i=stt; i<options.length; i++){
			sln[path] = options[i];
			comb(required, path+1, i+1, sln);	//i+1 is the key part, not stt+1
		}
	}
	public static void subset(int path, ArrayList<Integer> sln){	
		if(path>=options.length){
			String toprint = "";
			for(int i=0; i<sln.size(); i++)
				toprint = toprint + sln.get(i);
			System.out.println(toprint);
			return;
		}
		sln.add(options[path]);
		subset(path+1, sln);
		sln.remove(new Integer(options[path]));
		subset(path+1, sln);
	}
	
	
	public static void allValidBraces(int n, int nleft, int path, String sln, Stack<Boolean> sk){
		if(path >= n){
			System.out.println(sln);
			return;
		}
		if(!sk.isEmpty()){
			sk.pop();
			allValidBraces(n, nleft, path+1, sln+">", sk);
			sk.push(false);
		}
		if(nleft<n/2){
			sk.push(false);
			allValidBraces(n, nleft+1, path+1, sln+"<", sk);
		}
			
	}
	
	public static void allValidBraces2(int n, int nleft, int nright, int path, String sln){
		if(path >= n){
			System.out.println(sln);
			return;
		}
		if(nright<nleft){

			allValidBraces2(n, nleft, nright+1, path+1, sln+">");

		}
		if(nleft<n/2){
			allValidBraces2(n, nleft+1,nright, path+1, sln+"<");
		}
			
	}
	
	public static void main(String[] Args){
		int[] solutions = {0,0,0};
		//permu(solutions.length, 0, solutions);
		//comb(solutions.length, 0, 0, solutions);
		
		ArrayList<Integer> solns = new ArrayList<Integer>(options.length);
		//subset(0,solns);
		
		Stack<Boolean> sk = new Stack<Boolean>();
		//allValidBraces(6,0,0,"", sk);
		allValidBraces2(6,0,0,0,"");
	}
}
