
package program1;

public class Program1 {

    public static void main(String[] args) {
        String filename = "oliver.txt";
        Parse file = new Parse();
        Parse.readFile(filename);
        chartoInt("ass");
        
    }//main
     public static int chartoInt(String x){
         String[]wordArray= new String [x.toCharArray().length];
         int wordSum=0;
         for (int i = 0; i < wordArray.length; i++) {
            wordSum+=(int)x.toCharArray()[i];
             
         }
        return wordSum;
     }//charToInt
    
}//class
/*
run:
Reading file 

Total number of words: 1011628

Total number of lines 101168

Average words per line: 9

Longest word is : POLYPHYSIOPHILOSOPHIQUES
BUILD SUCCESSFUL (total time: 0 seconds)
*/
