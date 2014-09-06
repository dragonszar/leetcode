package leetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.lang.*;
import java.util.Arrays;

public class removeDupArr {
    public static ArrayList<Integer> removeDuplicates(int[] A) {
        HashMap<Integer, Boolean> h = new HashMap<Integer, Boolean>();
        ArrayList<Integer> narr = new  ArrayList<Integer>();
        for(int i = 0; i < A.length; i++)
        {
            int cur = A[i];
            if(h.get(cur)==null || !h.get(cur)) //null in java is not regarded as false
            {
                h.put(cur, true);
                narr.add(cur);
            }
        }

        //int[] a = new int[narr.size()];
        //for(int i=0; i<narr.size(); i++)
        	//a[i] = narr.get(i);
        //A = a;
        //return narr.size();
        return narr;
    }
    public static void main(String [] args)
    {
    	int[][] test = {{1,1,2}, {4,3,6,4,3,6,4,2,1,6}, {0}};
    	for(int i = 0; i< test.length; i++)
    		System.out.println(removeDupArr.removeDuplicates(test[i]));
    	String[] testt = {"", "" ,""};
    	ArrayList<String>  tt = new ArrayList(Arrays.asList(testt));
    	return;
    }
}