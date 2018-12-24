// Name:  Farma Nimal
import java.util.*;

public class myastar extends astar
{
  public myastar(int r, int c) { super(r,c); }
  public coord search(int sy, int sx, int ty, int tx)
  {

    PriorityQueue<coord> frontier= new PriorityQueue<coord>(20*ROWS*COLS);
		boolean stop=false;
		coord current=  new coord(sy,sx);
		current.knowndist = 0;
		current.estcost=current.knowndist+hexdist(sy,sx,ty,tx);
		frontier.add(current);
		int x = sx, y = sy;
		coord[][] interior = new coord[ROWS+1][COLS+1];
		int tempY=-1;
		int tempX=-1;
		while( stop!=true && frontier.size()!=0)
		{
			current= frontier.poll();
			current.interior=true;
			x = current.x;
			y = current.y;
			tempX =x;
			tempY= y;
			if(current.x==tx && current.y==ty)
					{
						stop=true;
						break;
					}//if
			for(int i=0; i<6;i++)
			{
					tempX =x+DX[y%2][i];
					tempY=y+DY[i];
					coord neigh= new coord(tempY,tempX);
					if(tempY>=0 && tempX>=0 &&tempY<ROWS && tempX<COLS && neigh.interior== false)
					{
					neigh.knowndist= current.knowndist+costof[M[tempY][tempX]];
					neigh.estcost=neigh.knowndist + hexdist(tempY,tempX,ty,tx);
					neigh.prev=current;
					if(interior[tempY][tempX]==null ||(interior[tempY][tempX].compareTo(neigh)>0 && interior[tempY][tempX].interior != true))
						{
							interior[tempY][tempX]=neigh;
							frontier.add(neigh);
						}//if
					}//outerif
				}//for
		}//while

		return current;
	}//search


//PREVIOUS IMPLEMENTION, HOWEVER, NOT AS GOOD BECAUSE OF FORCED SEARCH
// BUT STILL WORKS JUST AS WELL
    /*
    public coord search(int sy, int sx, int ty, int tx)
    {
      coord next = null;
      int x = sx, y = sy;
      PriorityQueue<coord> frontier = new PriorityQueue<coord>(200*ROWS*COLS);
      coord current = new coord(sy,sx);
      boolean stop= false;
      coord[][] interior = new coord[ROWS+1][COLS+1];
      frontier.add(current);

      while(stop!=true && frontier.size()!=0)
      {
        current = frontier.poll();
        current.interior = true;
        x = current.x;
        y = current.y;
        int tempX, tempY;
        tempX =x;
        tempY= y;

        for(int i=0; i<6;i++)
  			{
            tempX =x+DX[y%2][i];
            tempY =y+DY[i];

            if(tempY<0) tempY++;
            if(tempX<0) tempX++;
            if(tempY>=ROWS) tempY= tempY%ROWS;
            if(tempX>=COLS) tempX= tempX%COLS;

  					coord neigh = makeneighbor(current,tempY,tempX,ty,tx);
  					if(interior[tempY][tempX] == null || (interior[tempY][tempX].compareTo(neigh)>0) && interior[tempY][tempX].interior != true)
  					{
  						interior[tempY][tempX]= neigh;
  						frontier.add(neigh);
  					}//if
  					if(current.x== tx && current.y== ty)
  					{
  						stop=true;
  					}//if
  				}//for
  			}//while
  		return current;

    }//search


*/

}//myastar class
