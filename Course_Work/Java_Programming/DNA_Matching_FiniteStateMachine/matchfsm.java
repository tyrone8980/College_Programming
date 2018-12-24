/* counter automaton that maches ()'s

3 states: 0 is both start and accept state
State 2 is dead state.
In state 0, on seeing (, sets counter to 1 and transition to state 1, else
goto state 2.
State 1 increments counter on seeing (, decrements on seeing ), making
sure that counter doesn't become negative by transitioning back to 0
when counter is 1.

*/
public class matchfsm extends FSM3<String>
{
    protected String instring;
    protected int inx=0;   // indexes instring
    protected int cx = 0; // counter for automaton
    LinkedList<Integer> stack;

    public matchfsm(String x)
	{
	    instring = x;
	    states = 3;
	    maxinputs = 6;
      stack = new LinkedList<Integer>();
	    setHash();
	    setStateTable();
	}
  public boolean opposite(int x, int y)
  {
    return (x+3)%6 == y;
  }
    protected String nextInput()
    {
	if (inx<instring.length()) return ""+ instring.charAt(inx++);
	else return null;
    }
    protected boolean acceptState(int s){return s==1;}
    protected void setHash()
    {
	Hash = new JHMadaptor<String,Integer>();
	Hash.set("(",0);  Hash.set(")",1);
  Hash.set("[",2);  Hash.set("]",3);
  Hash.set("{",4);  Hash.set("}",5);
    }
    // acceptState inherits default


    protected void setStateTable()
    {

	M = new action[states][maxinputs];
  M[0][0] = new action() { public int act() {stack.push(0);return 0;}};//
  M[0][1] = new action() { public int act() {stack.push(1);return 0;}};//
  M[0][2] = new action() { public int act() {stack.push(2);return 0;}};//
  M[0][3] = new action() { public int act() {if(stack.first!= null)
    {
      int y = stack.pop();
      if (opposite(3,y) == true){return 1;}
      else {return 2;}
    }
    else{return 2;}
  }};//
  M[0][4] = new action() { public int act() {if(stack.first!=null)
    {
      int y = stack.pop();
      if(opposite(4,y)== true){return 1;}
      else{return 0;}
    }
      else{return 2;}
    }};//
  M[0][5] = new action() { public int act() {if(stack.first!=null)
    {
      int y = stack.pop();
      if(opposite(5,y)==true){return 1;}
      else{return 0;}
    }
      else{return 2;}
    }};//

  M[1][0] = new action() { public int act() {stack.push(0); return 0;}};//
  M[1][1] = new action() { public int act() {stack.push(1); return 0;}};//
  M[1][2] = new action() { public int act() {stack.push(2); return 0;}};//
  M[1][3] = new action() { public int act() {if(stack.first!=null){return 1;} else {return 2;}}};//
  M[1][4] = new action() { public int act() {if(stack.first!=null){return 1;} else {return 2;}}};//
  M[1][5] = new action() { public int act() {if(stack.first!=null){return 1;} else {return 2;}}};//



  M[2][0] = new action() { public int act() {return 2;}};//finished
  M[2][1] = new action() { public int act() {return 2;}};//finished
  M[2][2] = new action() { public int act() {return 2;}};//finished
  M[2][3] = new action() { public int act() {return 2;}};//finished
  M[2][4] = new action() { public int act() {return 2;}};//finished
  M[2][5] = new action() { public int act() {return 2;}};//finished


    }//setStateTable

    public static void main(String[] av)
    {
	String x = "(){}[][]()(){}"; // command-line string
	matchfsm machine = new matchfsm(x);
	machine.trace = true;
	machine.keeprunning = true; // process entire input
	boolean r = machine.run();
	System.out.println(r);
    }
}
// run: java matchfsm "(()))"
