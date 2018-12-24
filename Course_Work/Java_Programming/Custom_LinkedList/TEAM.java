public class TEAM
{
  interface Playable
  {
    void win();
    void lose();
    void printrecord();
    void play(team x);
    double winningpercentage();
  }
  public static class team implements Playable
  {

    public String TeamName;
    public int winningstreak;
    public int losingstreak;
    public team(String n)
    {
      TeamName = n;
      winningstreak = 0;
      losingstreak = 0;

    }
    public void win()
    {
      winningstreak += 1;
    }
    public void lose()
    {
      losingstreak += 1;
    }
    public void printrecord()
    {
      System.out.println("W-L:" + winningstreak +"-" + losingstreak);
    }
    public void play(team x)
    {
      double gametime = (int)(Math.random());
      if(gametime<=0.5)
      {
        System.out.println("The " + this.TeamName + " win!!");
      }
      else
      {
        System.out.println("The " + x.TeamName + " win!!");
      }
    }
    public double winningpercentage()
    {
      int total = this.winningstreak + this.losingstreak;
      double percentage = (((this.winningstreak)/(double)total)*100+0.5)/100;
      return percentage;
    }


  }//end of team class----------------------------------------------------------

  public static void main(String args[])
  {
    team team1 = new team("knicks");
    team team2 = new team("nets");
    team1.lose();
    team2.win();
    team2.lose();
    team2.win();
    team2.win();
    team2.win();
    team2.win();
    team2.printrecord(); // should print "W-L: 1-1"
    team1.play(team2); // should print "knicks win" or "nets win"
    System.out.println(team1.winningpercentage()); // prints .000 to 1.00
    String[] Teamnames = {"knicks","nets","lakers","celtics","warriors","spurs","cavaliers"};
    team[] league = new team[Teamnames.length];
    for(int i = 0; i<league.length;i++)
    {
      league[i] = new team(Teamnames[i]);
    }
    for(int i= 0; i<league.length;i++)
    {
      for(int j=i+1; j<league.length;i++)
      {
        if(league[i].TeamName.equals(league[j].TeamName)!=true)
        {
          league[i].play(league[j]);
        }
      }
    }
    //for(int i = 0; i<league.length;i++)
    //{
      //league[i].printrecord();
    //}
  }
}
