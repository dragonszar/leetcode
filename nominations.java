package leetcode;
import java.util.*;

public class nominations {
	
	static int[] nom = {25, 10, 5, 1}; //sorted from big to small
	public static void allnom(int n, ArrayList<Integer> tsol, int no){
		//ArrayList<Integer> tsol = new ArrayList<Integer>(sol);

		if(n==0)
		{
			System.out.println(tsol.get(0) + " " + tsol.get(1) + " " + tsol.get(2) + " " + tsol.get(3));
			return;
		}
		if(no >= nom.length-1)
			return;
		
		/*
		for(int i = no; i < nom.length; i++)
		{
			if(n>=nom[i]){
				tsol.set(i, tsol.get(i) + 1);
				allnom(n-nom[i], tsol, no);
				tsol.set(i, tsol.get(i) - 1);
			}else
				no++;
		}*/
		int k = no;
		while(nom[k]>n){
			k++;
		}
		if(k>=nom.length)
			return;
		
		for(int j = k; j<nom.length; j++){
			for(int i = 1; n >= nom[j]*i; i++){
				tsol.set(j, tsol.get(j) + i);
				allnom(n-nom[j]*i, tsol, j);
				tsol.set(j, tsol.get(j) - i);
			}
		}
		
		/*
		for(int i = 1; n >= nom[k]*i; i++){
			tsol.set(k, tsol.get(k) + 1);
			allnom(n-nom[k]*i, tsol, k);
			tsol.set(k, tsol.get(k) - 1);
		}
		*/
	}
	
	public static int allnom2(int n, int no){

		int next = 0;
		switch(no){
		case 25: 
			next = 10; break;
		case 10: 
			next = 5; break;
		case 5:
			next = 1; break;
		case 1:
			return 1;
		}

		int ways = 0;
		for(int i = 0; n >= no*i; i++){
			ways = ways + allnom2(n-no*i, next);
		}
		return ways;
	}
	
	public static void allnom3(int n, ArrayList<Integer> tsol, int no){
		
		if(n==0)
		{
			System.out.println(tsol.get(0) + " " + tsol.get(1) + " " + tsol.get(2) + " " + tsol.get(3));
		}		
		if(no >= nom.length)
			return;
	/*	
		int next = 0;
		switch(no){
		case 0: 
			next = 1; break;
		case 1: 
			next = 2; break;
		case 2:
			next = 3; break;
		case 3:
			return;
		}
		int k = no;
	*/
		for(int i = 0; n >= nom[no]*i; i++){	//Must start from 0
			tsol.set(no, tsol.get(no) + i);
			allnom3(n-nom[no]*i,tsol, no+1);	//no+1 Keep elements in solutions sorted, since it's combination not permutation
			tsol.set(no, tsol.get(no) - i);
		}
	}	
	
	public static void main(String [] args){
		ArrayList<Integer> sol = new ArrayList<Integer>(4);
		sol.add(0);
		sol.add(0);
		sol.add(0);
		sol.add(0);
		int tar = 26;
		//nominations.allnom(tar, sol, 0);
		System.out.println(nominations.allnom2(26, 25));
		nominations.allnom3(tar, sol, 0);
	}
}
