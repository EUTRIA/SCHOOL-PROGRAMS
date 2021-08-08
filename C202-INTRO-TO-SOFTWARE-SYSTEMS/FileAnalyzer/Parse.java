
package program1;
import java.io.File;
import java.util.Scanner;
public class Parse {

/**
 * @requires
 * ..
 * @ensures: File being read has no special characters or numerical numbers
 * and prints number of words, average number of words per line, and the longest
 * word found in file
 */
   public static void readFile(String filename){
       System.out.println("Reading file \n"); 
       int wordTotal=0;
       int lineTotal=0;
       String longestWord="";
       //int lineEcho=0;
       try{ 
           
           String [] parse=null;//array for da words
          
           File infile = new File(filename);//Open that file
           Scanner input = new Scanner(infile);//Open File Internally 
 
           while(input.hasNext())
           {
            
               String line = input.nextLine();
               line = line.replaceAll("[^a-zA-Z\\s]", " "); //replaces all non-alpha and non-space characters with a space
               line = line.replaceAll("\\s+", " ").trim(); //replaces all spaces two positions or more with one space
               parse= line.split(" ");/*splits line every time there is a space between characters making it so each index of parse has only one word*/
       
   
               wordTotal+=parse.length;/*adds the number of indexes in parse to word total*/
               lineTotal++;//every time this loops 1 is add to lineTotal 
              
               /*if(lineEcho==100000){//echoes output every 100,000 lines
                   lineEcho=0;//resets line echo to 0
                  System.out.println("Total number of words: "+wordTotal+"\n");
                  System.out.println("Total number of lines "+lineTotal+"\n");
                  System.out.println("Average words per line: "+wordTotal/lineTotal+"\n");
                  System.out.println("Longest word is : "+longestWord);
               } if */
               
               for (int i = 0; i < parse.length; i++) {
                if((parse[i].length())>longestWord.length()){
                   longestWord=parse[i];
                    }//if
                 }//for
              
           }//while
            System.out.println("Total number of words: "+wordTotal+"\n");
            System.out.println("Total number of lines "+lineTotal+"\n");
            System.out.println("Average words per line: "+wordTotal/lineTotal+"\n");
            System.out.println("Longest word is : "+longestWord);
           }//try
      catch(Exception ex){
          System.out.println("File error");
      }//catch
   }  //readFile
}//Class parse
