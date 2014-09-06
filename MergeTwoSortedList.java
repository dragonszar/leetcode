package leetcode;

import leetcode.ListNode;

public class MergeTwoSortedList {

	    public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
	        ListNode head = null,precur = null,cur,l1cur = l1, l2cur = l2;

	        while(l1cur!=null || l2cur!=null)
	        {
	            int l1curval = Integer.MAX_VALUE, l2curval = Integer.MAX_VALUE;
	            if(l1cur!=null)
	                l1curval = l1cur.val;
	            if(l2cur!=null)
	                l2curval = l2cur.val;
	            if( l1curval<l2curval){
	                cur = l1cur;
	                l1cur = l1cur.next;
	            }else{
	                cur = l2cur;
	                l2cur = l2cur.next;               
	            }
	            if(head == null){
	            	head = cur;
	            }
	            if(precur != null)
	            	precur.next = cur;
	            precur = cur;
	        }
	        return head;
	    }

	
	public static void main(String [] args){
		ListNode head = MergeTwoSortedList.mergeTwoLists(new ListNode(2), new ListNode(1));
		
	}
}
