public class DNA extends FSM3<String>
{
  String instring;
  int ci,cx,dx;
  public DNA(String x)
  {
    instring = x;
    ci = 0;
    cx = 0;
    dx = 0;
    states = 5;
    maxinputs = 4; // C,A,T,G
    setHash();
    setStateTable();
  }//DNA constructor
  protected boolean acceptState(int s){return s==3;}// 3 is accept state
  protected void setHash()
  {
    Hash = new JHMadaptor<String,Integer>(10);
    Hash.set("C",0); Hash.set("A",1); Hash.set("T",2); Hash.set("G",3);
  }//setHash
  protected void setStateTable()
  {
    M = new action[states][maxinputs];
    M[0][0] = new action() { public int act() {cx++;return 0;}};//C
    M[0][1] = new action() { public int act() {if(cx>dx)dx++;return 1;}};//A
    M[0][2] = new action() { public int act() {return 4;}};//T
    M[0][3] = new action() { public int act() {return 4;}};//G

    M[1][0] = new action() { public int act() {return 4;}};//C
    M[1][1] = new action() { public int act() {if(dx<cx)dx++;return 1;}};//A
    M[1][2] = new action() { public int act() {dx=cx;dx--;return 2;}};//T
    M[1][3] = new action() { public int act() {return 4;}};//G

    M[2][0] = new action() { public int act() {return 4;}};//C
    M[2][1] = new action() { public int act() {return 4;}};//A
    M[2][2] = new action() { public int act() {if(dx>1)dx--; else dx=1;return 3;}};//T
    M[2][3] = new action() { public int act() {return 4;}};//G

    M[3][0] = new action() { public int act() {return 3;}};//C
    M[3][1] = new action() { public int act() {return 3;}};//A
    M[3][2] = new action() { public int act() {return 3;}};//T
    M[3][3] = new action() { public int act() {return 3;}};//G

    M[4][0] = new action() { public int act() {return 4;}};//C
    M[4][1] = new action() { public int act() {return 4;}};//A
    M[4][2] = new action() { public int act() {return 4;}};//T
    M[4][3] = new action() { public int act() {return 4;}};//G
  }//setStateTable

  protected String nextInput()
  {
    if(ci>instring.length()-1) return null;
    return ""+instring.charAt(ci++);
  }//nextInput

  public static void main(String[] argv)
  {
    DNA test = new DNA(argv[0]);
    test.trace = true;
    test.keeprunning = true;
    test.skipbadinput = false;
    boolean result = test.run();
    System.out.println(result);
  }//main
}//DNA class
