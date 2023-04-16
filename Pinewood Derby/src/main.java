//Pranav Saran
//Period 4

import java.util.*;
public class main {
    public static void main(String[] args) {

        System.out.println("Enter the race data: (all in one)");

        Scanner sc = new Scanner(System.in); //make scanenr
        int n = sc.nextInt();
        sc.nextLine();

        //taking inputs of racers from the pasted in heat list
        int[][] heats = new int[n][5];
        int[][] places = new int[n][5];
        for(int i = 0; i < n * 2; i++){
            sc.next();
            if(i < n){
                for(int j = 0; j < 5; j++){
                    heats[i][j] = sc.nextInt();
                }
            }
            else{
                for(int j = 0; j < 5; j++){
                    places[i - n][j] = sc.nextInt();
                }
            }
            sc.nextLine();
        }


        //using 2d arrays to store in the form of cards
        int[][] racers = new int[n][2];
        for(int i = 0; i < n; i++){
            racers[i][0] = i + 1;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < 5; j++){
                racers[heats[i][j] - 1][1] += places[i][j];
            }
        }

        //determine placements using baby recursion
        boolean finished = false;
        int placement = 0;
        int oldMin = -1;
        while(finished==false){
            int index = 0;
            int min = 100000000;
            for(int i = 0; i < n; i++){
                if(racers[i][1] < min){
                    min = racers[i][1];
                    index = i;
                }
            }
            racers[index][1] = 1000000;
            if(oldMin != min){
                placement++;
                if(placement == 6){
                    finished = true;
                }
                else{
                    System.out.println();
                    System.out.print(placement + ": " + racers[index][0]);
                }
            }
            else{
                System.out.print(" " + racers[index][0]);
            }
            oldMin = min;
        }
    }
}