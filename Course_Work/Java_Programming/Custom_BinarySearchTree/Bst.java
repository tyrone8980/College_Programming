/* Binary Search Trees Spring 2017 version */

public interface Bst<T extends Comparable<T>>
{
    int size(); // number of vertices in tree
    int depth(); // length of longest branch, nil tree has depth 0
    boolean empty();  // nil or vertex
    boolean contains(T x); // determine if x is in tree
    Bst<T> insert(T x); // insert new node
    Bst<T> delete(T x); // delete node T

    // following may only apply to some subclasses
    T item();  // return value stored at non-empty node
    Bst<T> left(); // left subtree of non-empty node
    Bst<T> right(); // right subtree of non-empty node
    Bst<T> delmax(vertex<T> n); // delete max value vertex from vertex n
    void preorder();
    Bst<T> clone ();
    T min();
}// Bst interface

class nil<T extends Comparable<T>> implements Bst<T>
{
    public int size() { return 0; }
    public int depth() { return 0; }
    public boolean empty() { return true; }
    public boolean contains(T x) { return false; }
    public Bst<T> insert(T x)
    {
	return new vertex<T>(x);
    }
    public Bst<T> delete(T x)
    {
	return this; // nothing to delete
    }

    public T item()
    { throw new RuntimeException("nil has no item"); }
    public Bst<T> left()
    { throw new RuntimeException("nil has no left"); }
    public Bst<T> right()
    { throw new RuntimeException("nil has no right"); }
    public Bst<T> delmax(vertex<T> n)
    {
	throw new RuntimeException("delmax shoul never be called on nil node");
    }

    public String toString() { return ""; }
    public void preorder()
    {}
    public Bst<T> clone()
    {return this;}
    public T min()
    {return null; }//min;
    public void LL(){};
    public void RR(){};
}//nil

class vertex<T extends Comparable<T>> implements Bst<T>
{
    protected T item; // value stored at node
    protected Bst<T> left;
    protected Bst<T> right;  // left/right access

    // accessors  (required for graphical representation)
    public T item() { return item; }
    public Bst<T> left() { return left; }
    public Bst<T> right() { return right; }

    // constructors
    public vertex(T i, Bst<T> l, Bst<T> r)
    { item = i; left = l; right = r; }
    public vertex(T i)
    {
	item = i;
	left = right = new nil<T>();
    }

    // interface methods
    public  int size()
    { return 1 + left.size() + right.size(); }
    public int depth()
    {
	int ld = left.depth(), rd = right.depth();
	if (ld>rd) return ld+1; else return rd+1;
    }
    public boolean empty() { return false; }
    public boolean contains(T x)
    {
       int c = x.compareTo(item);
       return (c==0 || (c<0 && left.contains(x)) || (c>0 && right.contains(x)));
    }

    public Bst<T> insert(T x) // insert non-duplicate new node
    {
        int c = x.compareTo(item);
	if (c<0) // insert left
	    left = left.insert(x);
	else if (c>0) // insert right
	    right = right.insert(x);
	return this; // this pointer not changed.
    }
    public Bst<T> delete(T x)
    {
	// first find x:
       int c = x.compareTo(item);
       if (c<0) left = left.delete(x);
       if (c>0) right = right.delete(x);
       if (c==0) // found it
	   {
	       if (left.empty()) return right; // right subtree replaces this
	       else  // replace node with max on left
		   left = left.delmax(this);
	   }
       return this;
    }//delete

    public Bst<T> delmax(vertex<T> modnode)
    {
	if (right.empty())  // largest node found
	    {
		modnode.item = this.item;
		return left; // left-tree may still be non-empty!
	    }
	else right = right.delmax(modnode);
	return this;
    }

    public String toString() // inorder traversal of tree
    {
	return left + " " + item + " " + right;
    }

public void preorder()
{
  System.out.println(item);
  left.preorder();
  right.preorder();
}
public Bst<T> clone()
{
  return new vertex<T>(this.item,left.clone(),right.clone());

}//clone

//the below need some work
public T min()
{
  Bst<T> Min = this;
  while(left.empty()!= true)
  {
    Min.left = Min.min();
  }
  return Min.left;
}//min
public void LL()
{
    vertex<T> lvert = (vertex<T>)left;
    right = new vertex<T>(item,lvert.right,right);
    item = lvert.item;
    left = lvert.left;
    right = rvert.right;
}//LL
public void RR()
{
  vertex<T> rvert = (vertex<T>)right;
  left = new vertex<T>(item,rvert.left,left);
  item = rvert.item;
  right = rvert.right;

}//RR
}//vertex
