public class functions
{//start of program ------------------------------------------------------------
  /*
  First function is a bollean function that determines whether or not
  a string is within an array
  */

  // Begining of inarray function-----------------------------------------------
  public static boolean inarray(String s, String[]SA)
  {
    int i = 0;
    boolean temp = false;
    while((i <SA.length) & (temp == false))
    {
      if(s.equals(SA[i])) temp = true;
      i++;
    }
    return temp;
  }//End of inarray function----------------------------------------------------
  public static int Sum(int[] A)
  {
    int total = 0;
    for(int i=0;i<A.length;i++)
    {
      total+=A[i];
    }
    return total;
  }//End of Sum function--------------------------------------------------------
  public static String Smallest(String[] SA)
  {
    String small = SA[0];
    for(int i=1;i<SA.length;i++)
    {
      if(small.compareTo(SA[i])<0)
      {
        small = SA[i];
      }
    }
    return small;
  }// End of Smallest function--------------------------------------------------
  public static boolean palindrome(String s)
  {
    boolean bool;
    String reverse = "";
    for(int i=s.length()-1;i>=0;i--)
    {
      reverse += s.charAt(i);
    }
    if(reverse.equals(s))
    {
      bool = true;
    }
    else
    {
      bool = false;
    }
    return bool;
  }//End of palindrome function
  public static boolean duplicate(String[] SA)
  {
    boolean bool=true;
    for(int i = 0;i<SA.length;i++)
    {
      for(int j = i+1;j<SA.length;j++)
      {
        if((SA[i]).equals(SA[j]))
        {
          bool = true;
          break;
        }
        else
        {
          bool = false;
        }
      }
    }
    return bool;
  }

  //Start of main---------------------------------------------------------------
  public static void main(String[] args)
  {
    //variables
    String[] SA = {"ab","bc","de","ef","ab"};
    String test = "ab";
    int[] A = {61,98,456,15896,345};
    String s = "racecar";

    //function calls
    if(inarray(test,SA)== true)
    {
      System.out.println(test + " Is in array the array");
    }
    else
    {
      System.out.println(test + " Is not in array the array");
    }
    System.out.println(Sum(A));
    System.out.println(Smallest(SA));
    if(palindrome(s)==true)
    {
      System.out.println(s + " Is a palindrome ");
    }
    else
    {
      System.out.println(s + " Is not a palindrome ");
    }
    if(duplicate(SA)==true)
    {
      System.out.println(" The array does contain duplicates ");
    }
    else
    {
      System.out.println("The array does not contain duplicates ");
    }
  }//end of main ---------------------------------------------------------------


}// end of program--------------------------------------------------------------
