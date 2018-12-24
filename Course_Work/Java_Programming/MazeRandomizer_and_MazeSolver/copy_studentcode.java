class studentcode extends mazedfs
{
    public studentcode(int bh0, int mh0, int mw0) // don't change constructor
    {
	super(bh0,mh0,mw0);
    }


    //THIS IS  A COPY OF PART 3 for trace and solve, without PLAY

public void digout(int y, int x)   // modify this function
 {
     // The following is a skeleton program that demonstrates the mechanics
     // needed for the completion of the program.
     // We always dig out two spaces at a time: we look two spaces ahead
     // in the direction we're trying to dig out, and if that space has
     // not already been dug out, we dig out that space as well as the
     // intermediate space.  This makes sure that there's always a wall
     // separating adjacent corridors
     //***************************Dig out without recursion*****************
/*
     int[] DX = {0,0,1,-1}; //N,S,E,W
     int[] DY={-1,1,0,0};
     int direction = (int)(Math.random()*4);//creates radnom direction
     coordinate_Stack R = new coordinate_Stack(y, x, null);
     while( R != null)
     {
       y = R.y;
       x = R.x;
       R = R.next;
       int dx= DX[direction], dy = DY[direction];
       int nx = x+ dx*2;
       int ny = y + dy*2;
       M[y][x]= 1;// dignifies the space as dug out
       drawblock(y,x);//draws on the digout spot
       for(int i=0;i<10;i++)
       {
         if(nx>=0 && ny>=0 && nx<mw-1 && ny<mh-1 && M[ny][nx]==0)
        {
          drawblock(y+dy, x+dx);
          delay(5);
          direction = (int)(Math.random()*4);
          R = new coordinate_Stack(ny,nx,R);
        }// if
        else
        {
        direction =(1+direction)%4;
        dx = DX[direction];
        dy = DY[direction];
        nx = x + dx*2;
        ny = y+ dy*2;
        R = new coordinate_Stack(ny,nx, R);
        }//else
       }//for
     }//while

      */













     //********************Dig out with recursion***************************
     //--------------------------------------------------------------------

     int[] DX = {0,0,1,-1}; //N,S,E,W
     int[] DY={-1,1,0,0};
     int direction = (int)(Math.random()*4);
     int dx= DX[direction], dy = DY[direction];
     int nx = x+ dx*2;
     int ny = y + dy*2;
     M[y][x]=1;
     drawblock(y,x);
     for(int i=0;i<4;i++)
     {
       if(nx>=0 && ny>=0 && nx<mw && ny<mh && M[ny][nx]==0)
      {

        drawblock(y+dy, x+dx);
        M[y+dy][x+dx]=1;
        //delay(20);
        digout(ny,nx);
      }
      direction =(1+direction)%4;
      dx = DX[direction];
      dy = DY[direction];
      nx = x + dx*2;
      ny = y+ dy*2;
    }




    // poopy code
    //  if (x-2>=0) digout(y,x-1);
      //if (x+2<mw && M[y][x+2]==0) // always check for maze boundaries
 	    //{
 	      //M[y][x+1] = 1;
 	      //drawblock(y,x+2);
 	      //digout(y,x+2);
        //direction = (1 + direction)%4;
 	  // }


  /*
     M[y][x] = 1;  // digout maze at coordinate y,x
     drawblock(y,x);  // change graphical display to reflect space dug out
     delay(40); // slows animation

     // But the following won't work (but will compile)

     // sample code that tries to digout one space to the left:
     if (x-1>=0) digout(y,x-1);
     // sample code that tries to digout TWO space to the right IF it's not
     // already dug out:
     if (x+2<mw && M[y][x+2]==0) // always check for maze boundaries
	 {
	     M[y][x+1] = 1;
	     drawblock(y,x+1);
	     digout(y,x+2);
	 } */


}//digoout
public void customize()
{
  showvalue = true;
}
public void solve()
{
  int x=1, y=1;
  CoordinateStack CORD = new CoordinateStack(y, x, null);
  while(y !=mh-2 || x!=mw-2)
  {
      int[] DX = {0,0,1,-1}; //N,S,E,W
      int[] DY={-1,1,0,0};
      int n=y-1, s=y+1,w=x-1,e=x+1;
      byte min= 127;
      int direction=0;
      if(x>=0 && y>=0 && x<mw && y<mh && M[y][x]>=1)
      {
        drawdot(y,x);
        //delay(50);
        drawblock(y,x);
        if (n>=0 && M[n][x]!=0 && M[n][x]<min){min=M[n][x];direction=0;}
        if (s<mh && M[s][x]!=0 && M[s][x]<min){min=M[s][x];direction=1;}
        if (e<mw && M[y][e]!=0 && M[y][e]<min){min=M[y][e];direction=2;}
        if (w>=0 &&M[y][w]!=0 && M[y][w]<min){min=M[y][w];direction=3;}
        x += DX[direction];
        y += DY[direction];
        CORD = new CoordinateStack(y,x, CORD);
        M[y][x]++;
      }//if


  }//while
//  trace();
  while(CORD!=null)
  {
    CORD.cut();
    drawdot(CORD.y,CORD.x);
    CORD = CORD.next;
  }
}// End of Solve
//public void trace()
//{
  //draw dot without erasing it along optimal path
//}//trace



/* POSSIBILITY
public void solve()
{
  int x=1, y=1;
  while(y !=mh-2 && x!=mw-2)
  {
    change_direction(y,x);

  }//while
}// End of Solve
public void change_direction(int y, int x)
{
  int[] DX = {0,0,1,-1}; //N,S,E,W
  int[] DY={-1,1,0,0};
  int direction = (int)(Math.random()*4);
  int dx = DX[direction];
  int dy = DY[direction];
  int nx = x+ dx;
  int ny = y + dy;
  for(int i = 0; i<4;i++)
  {
    if(nx>=0 && ny>=0 && nx<mw && ny<mh && M[y][x]>=1)
    {
      drawdot(y,x);
      //(50);
      M[y][x]++;
      drawblock(y,x);
      //delay(50);
      y = ny;
      x=nx;
      change_direction(y,x);
    }//if
    else
    {
      direction = (1+direction)%4;
      dx = DX[direction];
      dy = DY[direction];
      ny= y+dy;
      nx=x+dx;
    }
  }
}





*/
class CoordinateStack extends LinkedList
{
  int y, x ;
  CoordinateStack next;
  public <LinkedList>CoordinateStack(int y, int x, CoordinateStack z)
  {this.y = y; this.x = x; next=z;}
  public void cut()
  {
    CoordinateStack current = this;
    while(current!=null)
    {
      if(current.y == this.y && current.x ==this.x)
        this.next = current.next;
      current = current.next;
    }
  }
}//coordinate_Stack class
}//studentcode subclass
