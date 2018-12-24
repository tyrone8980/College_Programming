public class myheap<T extends Comparable<T>> extends PriorityHeap<T>
{
  // constructors of the subclass should be written this way:
    public myheap(int max) { super(max); }
    public myheap(T[] A) {super(A);}
    public static <S extends Comparable<S>> void heapsort(S[] A)
    {
      myheap<S> NewHeap = new myheap<S>(A.length);
      for(int i = 0; i<A.length;i++)
      {
        NewHeap.insert(A[i]);
      }//for
      for(int i=0;i<A.length;i++)
      {
        A[i] = NewHeap.deleteMax();
      }//for
      heapdisplay W = new heapdisplay(1024,768);
      W.drawtree(A,A.length);
    }//heapsort

    public T deleteMax()
    {
      if (size<1) throw new RuntimeException("heap empty");
    	T answer = HA[0];
       // remember answer to be returned
    	// move last element of heap to root
    	size--;
    	HA[0] = HA[size];
    	int i = 0;  // current index of value
    	int si = 1; // must start with something not = -1
    	while (si != -1)
    	    {
    		si = -1; // default no swap
    		// see if left child exists and is larger than HA[i]
    		int lf = left(i);
    		if (lf<size && HA[lf].compareTo(HA[i])>0)  si = lf;
    		// see if right child exists and is larger than both H[i] and
    		// left child (no right without left)
    	        int rt = right(i);
    		if (rt<size && HA[rt].compareTo(HA[i])>0 && HA[rt].compareTo(HA[lf])>0)  si = rt;
    		// if swap candidate not -1, swap:
    		if (si != -1)
    		    {
    			T tmp = HA[i];  HA[i]=HA[si];  HA[si] = tmp;
    			i = si; // move down
    		    }
    	    }//while
      HA[size]= answer;
    	return answer;
    }//deleteMax


    public void makeheap(T[] A)
    {
      HA = A;
      size = A.length;
      myheap<T> NewHeap = new myheap<T>(A.length);
      for(int i = 0; i<A.length;i++)
      {
        NewHeap.insert(HA[i]);
      }//for
      for(int i = (A.length-1)/2;i>=0;i--)
      {
        swapdown(i);
      }//for
      heapdisplay W = new heapdisplay(1024,768);
      W.drawtree(HA,size);
    }//makeheap
    public void swapdown(int root)
    {
      if (root<0 || root>=size) return;
     // now propagate downwards.
     int i = root; // current position
     int c = 0; // swap candidate
     while (c != -1)
     {
	      int l = left(i);
	      int r = right(i);
	      c = -1; // swap candidate
	      if (l<size && HA[l].compareTo(HA[i])>0) c = l; // set candidate to left
	      if (r<size && HA[r].compareTo(HA[i])>0 && HA[r].compareTo(HA[l])>0) c=r;
	      if (c!= -1)
	       {
		         T temp = HA[i];  HA[i] = HA[c]; HA[c] = temp;
		          i = c;
	       }//if
     }//while
    }//swapdown
    protected boolean contains(T x, int index)
    {
      return index>= 0 && index<size && (HA[index].equals(x) || contains(x,left(index))||contains(x,right(index)) );
    }//contains
    public boolean contains(T x)
    {
      return contains(x,0);
    }
    // create a main to test
    public static void main(String[] args)
    {
      Integer[] array= new Integer[30];
      for(int i=0;i<array.length;i++)
      {
        array[i]= (int)(Math.random()*100);
      }
      myheap<Integer> test = new myheap<Integer>(array);
      test.makeheap(array);
      System.out.println(test.contains(98));
    }//main

}//myheap
