/*               CSC 17 Hash Table Lab

NOTE: description modified since first post: see main and hints sections.

For this lab you are going to implement a variant of polymorphic
hash tables by adopting my closed hash table implementation (find
CIHash.java on homepage).  A structure similar to the hash tables I
implemented is called a Hash Map: here the key is not extracted from the
value but is stored separately.  For example, if I want to associate
"Monday" with 1 and "Tuesday" with 2, etc.
then my key type is String and
value type is Integer.  The key is not part of the value, which is just
an integer, and so we cannot extract the key using a getkey function.:
*/

interface Ihashmap<KT, DT>
{
    int size(); // return number of values currently in the table
    int remainingCapacity();  // return remaining capacity of the table

    boolean set(KT key, DT data); // insert new key,data pair
    // this function should return true if it replaced some existing data and
    // false if no data was previously associated with key.

    DT get(KT key); //search for data associated with key, null if not found

    boolean remove(KT key); // delete data associated with key.  This function
    // should return true if something was actually deleted, and false
    // if no data was previously associated with key.
}

/* Your class (assume it's called simap) must work with the following
   main.
*/
public class hmlab17s
{
    public static void main(String[] av)
    {
      // use a hash table to associate days of the week with numbers.
      Ihashmap<String,Integer> Dmap = new simap(7);
      String[] D = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
      for(int i=0;i<7;i++) Dmap.set(D[i],i);

      System.out.println(Dmap.get("Tuesday")); // should print 2
      System.out.println(Dmap.get("abcd"));    // should print null
      System.out.println(Dmap.set("Sunday",7)); // should print true
      // because it replaced an existing entry. (see interface specs)
      System.out.println(Dmap.remove("xyz")); // should print false
      // because nothing was deleted.
    }//main
}
class keypair<KT,VT>
{
    KT key;
    VT value;
    public keypair(KT k, VT v) { key=k;  value=v; }
}//keypair
abstract class Myhashmap<KT,VT> extends CIHash<KT,keypair<KT,VT>> implements Ihashmap<KT,VT>
{
  // GIVE AWAY FUNCTIONS THAT NEED TO IMPLEMENTED BECAUSE OF INTERFACE
  public abstract keypair getkey(keypair s);
  public abstract int hash(KT key);
  public int size()
	{
		return super.size();
	}//size

	public int remainingCapacity()
	{
		return super.remainingCapacity();
	}//remainingCapacity

	public boolean set(KT key, VT value)
	{
		 if(remove(key))
		 {
			 insert(key,value);
			 return true;
		 }//if
		 else
		 {
			 insert(key,value);
			 return false;
		 }//else
	}//set


	public VT get(KT key)
	{
		if(find(key)==null) return null;
		else
		return find(key).value;
	}//get

	public void insert(KT key, VT value)
	{
		super.insert(new keypair(key, value));
	}//insert

	public boolean remove(KT key)
	{
		int findbaby = findi(key);

		if(findi(key)!=-1)
		{
			H[findbaby]=null;
			size--;
			return true;
		}//if
		else
		{
			return false;
		}//else
	}//remove

}//Myhashmap
class simap extends Myhashmap<String,Integer>  //string to integer map
{
  public simap(int x)
	{
		H = new keypair[x];
		hcount = new int[x];
	}//simap

	public int hash(String s)
	{
		int hashbaby = 0;
		for(int i=0;i<s.length();i++)
		    hashbaby += (int)s.charAt(i);
		return hashbaby % H.length;
	}//hash

	public String getkey(keypair<String, Integer> keypair)
	{
		return keypair.key;
	}//getkey

}//simap


/*

Java prohibits generic array creation:

     DT[] H = new DT[100];

   this will result in a compiler error.  To get around this problem, do

     DT[] H = (DT[]) new Object[100];

   This will result in only a compiler warning.  A compiler warning indicates
   that java does not have enough information to determine if the code is
   safe, and therefore the programmer must pay special attention.  But it does
   not mean that the code is wrong.  You'll need to use this trick to write
   your polymorphic class constructor.

   EXTRA CREDIT

    Read about the "quadratic probing" method of implementing the
    rehash function.  One problem with this function is that you might not
    be able to find an open slot even if the array is not full.  So to make
    it practical, you should default to "linear" probing if an open slot
    cannot be found.  Implement this refinement in another subclass.
*/
