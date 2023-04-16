//Pranav Saran
//Period 4
import java.util.*;
public class main {
    public static void main(String[]args ){
        Scanner sc=new Scanner(System.in);
        //initial variables
        int racers;
        int racetime;
        int counter=0;
        String gender;

        ArrayList<racer> race=new ArrayList<racer>();
        System.out.println("How many racers are there?");
        System.out.println("Enter as: Time Gender");
        racers=sc.nextInt();
        sc.nextLine();

        //taking user input for racers

        for(int i=0;i<racers;i++){
            racetime=sc.nextInt();
            gender =sc.nextLine();
            racer p=new racer(racetime,gender);
            race.add(p);
        }
        for(int i=0;i<racers;i++){
            //sort out the times in order
            for(int j=0;j<racers-1;j++){
                if (race.get(j).getRt()>race.get(j+1).getRt()){
                    int p=race.get(j+1).getRt();
                    String ps=race.get(j+1).getG();
                    race.get(j+1).setRt(race.get(j).getRt());
                    race.get(j+1).setG(race.get(j).getG());
                    race.get(j).setRt(p);
                    race.get(j).setG(ps);
                }
            }
        }

        //big big winner
        System.out.println(race.get(0).getRt());


        //remove overall winners from list
        race.remove(0);
        race.remove(0);

        //Other Winners

        for(int i=0;i<race.size();i++){
            if (race.get(i).getG().equals(" F")){
                if (counter==0) {
                    //print out girl winner
                    System.out.println(race.get(i).getRt());
                }
                race.remove(i); //remove contestant from arraylist
                counter++;
                i--;
                if (counter==2) i=race.size(); //ends
            }
        }
        counter=0;
        for(int i=0;i<race.size();i++){
            if (race.get(i).getG().equals(" M")){
                //printing out the top 2 boys
                System.out.println(race.get(i).getRt());
                race.remove(i);//remove contestant from arraylist
                counter++;
                i--;
                if (counter==2) i=race.size(); //ends
            }
        }
    }
}