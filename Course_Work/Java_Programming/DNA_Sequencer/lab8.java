class lab8
{
  String S1, S2; // Sequences to be alligned
  String A1, A2; // Alligned versions with gaps
  String VerticleBars; // String of VerticleBars
  int w = 0; //Gap Penalty
  int [][] D; // Dynamic programming matrix
  byte[][] F; //record of whiwch of the 3 values were chosen

  public lab8(String s1, String s2)
  {
    A1 = A2 = VerticleBars = "";
    S1 = s1; S2 = s2;
    initmatrix();
  }//lab8 constructor
  public void initmatrix()
  {
    S1 = "."+ S1;// Dummy character to fix coordniates to appropriate spot
    S2 = "."+ S2;// Dummy character to fix coordniates to appropriate spot
    D = new int [S1.length()][S2.length()];
    F =new byte [S1.length()][S2.length()];
    for(int x=0; x < S2.length(); x++)
    {
      F[0][x] = 1;
      D[0][x] = x*w;
    }
    for(int y=0; y < S1.length(); y++)
    {
      F[y][0] = 3;
      D[y][0] = y*w;
    }

  }//inintmatrix
  public void displaying()
	{
		System.out.println(A1 + "\n" + VerticleBars + "\n" + A2);
		System.out.println("Alignment Score: " + D[D.length-1][D[0].length-1]);
	}//solveMe

  public void fill()
  {
    int max=0;
    for(int i=1;i<D.length;i++)
    {
      for(int j=1;j<D[i].length;j++)
      {
        byte direction;
        max = D[i-1][j-1]+score(i,j);
        direction = 2;
        if(D[i][j-1]+ w> max) { max = D[i][j-1]+ w; direction = 1;}
        if(D[i-1][j]+ w > max) {max =  D[i-1][j] +w; direction = 3;}
        F[i][j]= direction;
      }//inner for loop
    }//outerfor loop
  }//fill

  public int score(int y, int x )
  {
    if(S1.charAt(y)==S2.charAt(x))
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }//score

  public void traceback()
  {
    int y = D.length - 1;
    int x = D[0].length - 1;
    while(x!= 0 || y!=0)
    {
      if(F[y][x]==2)
      {

        A1=  S1.charAt(y)+A1;
        A2= S2.charAt(x)+A2;
        if(score(y,x)>0)
        {
          VerticleBars = "|"+ VerticleBars;
        }//if
        else
        {
          VerticleBars = "."+ VerticleBars;
        }//else
        x--;
        y--;
      }//if
      else if(F[y][x]==1)
      {
        A2= S2.charAt(x)+A2;
        A1 = "_"+ A1;
        VerticleBars = "." + VerticleBars;
        x--;
      }//if
      else if(F[y][x]==3)
      {
        A1 = S1.charAt(y)+A1;
        A2 = "_"+ A2;
        VerticleBars = "."+ VerticleBars;
        y--;
      }//if

    }//while

  }//tracback
  public void pMatrix()
	{
		for(int i=0; i<D.length;i++)
		{
      for(int j=0;j<D[i].length;j++)
			   {
				    System.out.print(D[i][j]+ " ");
			   }//for
			System.out.println();
		}//for
	}//pmatric
  public static String randseq(int n)
  {
    char[] S = new char[n];  // faster than building string char by char
    String DNA = "ACGT";
    for(int i=0;i<n;i++)
    {
      int r = (int)(Math.random()*4);
      S[i] = DNA.charAt(r);
    }
    return new String(S); // constructor converts char[] to String
   } // randseq

   public static String conv(String arg)
  {
    int n = 20;
    String sequence="";
    try
    {
      n = Integer.parseInt(arg); // attempt convert 1st arg to integer;
      sequence = randseq(n);
    }
    catch (NullPointerException npe)
    {
      sequence = randseq(n);
    }
    catch (NumberFormatException nfe)
    {
      sequence = arg;
    }
    return sequence;
  }//conv
/*
  public static void main(String[] arg)
   {
     lab8 test = new lab8(arg[0],arg[1]);
     test.fill();
     test.traceback();
     test.pMatrix();
     test.displaying();

     advance tester = new advance(arg[0],arg[1]);
     tester.fill();
     tester.traceback();
     tester.pMatrix();
     tester.displaying();
  }//main
  */
  public static void main(String[] args) {
    String a = SUPERDNA.read("A.dna");
    String r = SUPERDNA.read("R.dna");
    String m = SUPERDNA.read("M.dna");
    String s = SUPERDNA.read("S.dna");
    String drooler = SUPERDNA.read("drooler.dna");
    lab8 tyrone = new advance(drooler, a);
    tyrone.fill();
    tyrone.displaying();
    lab8 chuck  = new advance(drooler, r);
    chuck.fill();
    chuck.displaying();
    lab8 liang = new advance(drooler, m);
    liang.fill();
    liang.displaying();
    lab8 rules = new advance(drooler, s);
    rules.fill();
    rules.displaying();

  }
}//lab8

class advance extends lab8
{
	public advance(String c, String d)
	{
		super(c,d);
		w =-2;
	}

	public int score(int y ,int x)
	{
		if(S1.charAt(y) == S2.charAt(x))
			return 2;
		else
			return -1;
	}//score
}
