
import java.io.*;

public class SUPERDNA
{
    public static String genseq(int n)
    {
	char[] A = new char[n];
	char[] DNA = {'A','C','G','T'};
	for (int i=0;i<n;i++) A[i] = DNA[(int)(Math.random()*4)];
	return new String(A);
    }

    public static void write(String file, String dna)
    {
      try
	  {
	      PrintWriter pw = new PrintWriter(new FileOutputStream(file));
	      pw.println(dna);
	      pw.close();
	  }
      catch (IOException ie) {System.out.println("IO Error"); System.exit(1); }
    }//write to file

    public static String read(String file)
    {
	String s = "";
	try
	    {
		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
		s = br.readLine();
		br.close();
	    }
        catch (IOException ie) {System.out.println("IO Error"); System.exit(1); }
	return s;
    }

    public static String mutate(String dna)
    {
	int n = dna.length();
	// generate random index
	int i = (int)(Math.random()*n);   // 0 to n-1
	// split strings
	String A = "";
	if (i>1) A = dna.substring(0,i);
	String B = "";
	if (i<n-1) B = dna.substring(i+1,n);
	// decide what to do at index i
	int act = (int)(Math.random()*3);
	switch (act)
	    {
	    case 0: // change
		dna = A + genseq(1) + B;  break;
	    case 1: // add a new symbol
		dna = A + dna.charAt(i) + genseq(1) + B;
	    default: // delete symbol
		dna = A + B;
	    }// switch<a href="gendna.java">lab 8c</a>,
	return dna;
    }//mutate

    // create dna seq of length len, write to file, then create three mutations.
    public static void create(String fn, int len)
    {
	String dna = genseq(len);
	write(fn+".dna",dna);
	for (int fi = 1;fi<files+1;fi++)
	    {
		String mutation = new String(dna); // make copy
		for(int i = 0;i<degree;i++) mutation = mutate(mutation);
		write(fn+fi+".dna",mutation);
	    }// fi loop
    }//create

    static int degree  = 30; // degree of mutation
    static int files = 5; // number of files (mutations)

    public static void main(String[] args)
    {
	int len = 2000;  degree = 30;
	if (args.length>0) len = Integer.parseInt(args[0]);
	if (args.length>1) degree = Integer.parseInt(args[1]);
	if (args.length>2) files = Integer.parseInt(args[2]);
	String prefix = "drooler";
	if (args.length>3) prefix = args[3];
	create(prefix,len);
    }
}//SUPERDNA
