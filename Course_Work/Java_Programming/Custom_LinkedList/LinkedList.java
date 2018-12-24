import java.util.*; // Iterator, NoSuchElementException

class cell<T>
{
    T item;  /* this variable is public within the same package */
    cell<T> next;
    cell(T i, cell<T> n) { item=i;  next=n; }
    cell(T i) {item=i; next=null;}
}//cell

class celliterator<T> implements Iterator<T>
{
    protected cell<T> current; // points to current cell;
    public celliterator(cell<T> c) { current=c; } // constructor
    public boolean hasNext() { return current!=null; }
    public T next()
    {
	if (current==null) throw new NoSuchElementException();
	T answer = current.item;
	current = current.next;
        return answer;
    }
    public void remove(){}
}//cell iterator

public class LinkedList<T> implements Iterable<T>
{
    protected cell<T> first;
    protected cell<T> last;
    protected int size;

    public int size() { return size; }

    public cell<T> first() { return first; }

    public LinkedList()
    {
	first = last = null;
	size = 0;
    }

    // required by Iterable<T> interface:
    public Iterator<T> iterator() { return new celliterator<T>(first); }

    public void push(T x) // add x to front of list
    {
	first = new cell<T>(x,first);
	size++;
	if (size==1) last=first; // special case
    }
// Functions coded by Tyrone Harmon Jr. -------------------------------------





    public int count(T x)
    {
      int counter = 0;
      cell<T> current = first;
      while(current !=null)
      {
        if(current.item.equals(x)){counter++;}
        current = current.next;
      }
      return counter;
    }
    public void cut()
    {
      cell<T> current = first;
    //  cell<T> temp = first;
      while(current!= null)
      {
        if(current.item.equals(first.item))
          first.next = current.next;
        current= current.next;
      }

    }
    public LinkedList<T> cloned()
    {
      LinkedList<T> clone = new LinkedList<T>();
      for(cell<T> i = first;i!=null;i= i.next)
      {
        clone.add(i.item);
      }
      return clone;
    }
    public LinkedList<T> weakclone()
    {
      LinkedList<T> weakclone = new LinkedList<T>();
      weakclone.first = this.first;
      return weakclone;
    }




//End of functions coded by Tyrone Harmon Jr. ------------------------------
    public T pop()
    {
	if (size<1) return null;
	T answer = first.item;
	first = first.next;  // no need to garbage collect in Java
	size--;
	if (size==0) last = null;
	return answer;
    }
    public void add(T x) // add x to end of list
    {
	cell<T> xcell = new cell<T>(x);
	if (size==0)
	    {
		last = first = xcell;
	    }
	else
	    {
		last.next = new cell<T>(x);
		last = last.next;
	    }
	size++;
    }//add

    public T getAt(int i) // return element at position i (0 is front)
    {
	cell<T> current = first;
	while (i>0 && current!=null)
	    { current = current.next;  i--;}
        if (current==null) return null;
	else return current.item;
    }
    // write getlast


    // split list in two, returns pointer to second list.  Only lists
    // with size>=2 can be split
    public LinkedList<T> split()
    {
	if (size<2) return null;
	cell<T> current = first;
	for(int i=0;i<(size/2)-1;i++) current = current.next;
	// now, current points to last of first list
	LinkedList<T> B = new LinkedList<T>();
	B.size = this.size - (size/2);
	B.first = current.next;
	B.last = this.last;
	this.size = size/2;
	this.last = current;
	current.next = null;
	return B;
    }//split

    public void append(LinkedList<T> B) // append B onto current list
    {
	if (B==null || B.size < 1) return;
	this.last.next = B.first;
	this.last = B.last;
	this.size += B.size;
    }

    public String toString() // convert to String
    {
	String s = "";
	for(cell<T> i=first; i!=null; i=i.next)
	    s += i.item + " ";
	return s;
    }


    public static void main(String[] av)
    {
	    LinkedList<String> queue = new LinkedList<String>();
	    queue.add("louis");
	    queue.add("edward");
	    queue.push("anthony"); // cutting in front

      for(String x:queue) System.out.print(x+" "); // uses Iterator
      System.out.println(); // carriage return

	    while (queue.size()>0) System.out.println(queue.pop());
    }//main
}//LinkedList
