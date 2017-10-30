package level_order;


import java.util.*;

public class levelorder {
 static class node
{
	int data;
	node left;
	node right;
	node(int data)
	{
		this.data=data;
		this.left=null;
		this.right=null;
	}
}
 void printlevelorder(node root)
{
	if (root==null)
	{
		return;
	}
	Queue<node> q =new LinkedList<node>();
	q.add(root);
	while(!q.isEmpty())
	{
		node temp=q.remove();
		System.out.println(temp.data+" ");
		if(temp.left!=null)
			q.add(temp.left);
		if(temp.right!=null)
			q.add(temp.right);
	}
		
}

public static void main(String args[])
{
	node root=new node(1);
	root.left=new node(2);
	root.right=new node(3);
	root.left.left=new node(4);
	root.left.right=new node(5);
	levelorder s=new levelorder();
	s.printlevelorder(root);
}

	
	
}

