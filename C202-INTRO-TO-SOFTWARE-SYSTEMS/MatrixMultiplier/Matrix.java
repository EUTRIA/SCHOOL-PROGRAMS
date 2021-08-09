package program2;

public class Matrix  {
    
    
   /**
    *@requires
    *number of columns in the first matrix must be equal to the number of rows of the second matrix.
    *@ensures
    * matrix*matrix1=newMatrix
    * @param matrix
    * @param matrix1
    * @return newMatrix
    */
    public static double [][]  multiply(double [][] matrix, double [][] matrix1)throws Exception{
        int rows = matrix.length;
        int columns = matrix1[0].length;
        double [][]newMatrix = new double [rows][columns];
        
        for (int i = 0; i < rows; i++) {
               for (int j = 0; j < columns; j++) {
                   newMatrix[i][j]=0; //zero out the matrix
                   for (int k = 0; k <columns; k++) {
                  //adds multiplied values to the new matrix      
                 newMatrix[i][j] += matrix[i][k]*matrix1[k][j];
                      
                   }//k
                  
               }//j    
               
           }//i
           return newMatrix;
   }//multiply
    
    
   /**
    *@requires
    * ..
    *@ensures
    * [prints matrix in matrix style and returns "Output"]
    *@param matrix
    */
    public static String printMatrix(double [][] matrix){
        
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
            //prints row and uses only 3 numbers after the decimal and then tabs
               System.out.printf("%.3g \t",matrix[i][j]); 
            }//i
            System.out.println();
        }//j
        /*since type void cannot be used in the souts line in line 40, 52 and 55
        return String instead */
        return "Output";
    }//printMatrix
    
   /**
    *@requires
    *double [][] cola = new double [3][3]
    *@ensures
    *newCola =cola*newCola
    *@param cola
    *@return newCola 
    *[outputs newCola matrix results 50 times]
    */
    public static double[][]algorithm1(double [][] cola) throws  Exception{
        System.out.print("Algorithm 1\n Output#0\n");
        System.out.println("\n #1"+printMatrix(cola));
       
        double [][]newCola=cola;
        
        for (int i = 1; i <= 51; i++) {
           newCola=multiply(cola,newCola);
            
        if(i<5){
            // prints first 5 outputs
                System.out.print("\n#"+(i+1)+printMatrix(newCola)+"\n");
            }//if i<=5
        if(i>=46){//prints last 5 outputs
                System.out.print("\n#"+i+printMatrix(newCola)+"\n");
            }//if i>=45
        
    }//i
        return newCola;
  
}//algorithm1
    
   /**
    *@requires
    * double [][] cola = new double [3][3]
    *@ensures
    * oldCola = cola*oldCola and newCola = oldCola*newCola 
    * [outputs newCola results 10 times]
    * @param cola
    *@return newCola
    */
    
public static double[][]algorithm2(double [][] cola) throws  Exception{
     //Prints algorithm # and the orginal cola matrix 
      System.out.print("Algorithm 2\n Output#0\n");
      System.out.println("\n #1"+printMatrix(cola));

      double [][]oldCola= cola;
      double [][]newCola= cola;
      
      for (int i = 0; i < 10; i++) {
         /*
          Original cola multiplied by the Old cola produces the
          first value needed to produce Cola
          and algorithm 2 is first value needed to produce cola times the
          product cola
          */
        oldCola = multiply(cola,oldCola); // Q*Q 
        newCola=multiply(oldCola,newCola);//Q2*Q

        System.out.print("\n#"+(i+2)+printMatrix(newCola)+"\n");
        
      }//i
    return newCola; //returns newest result 
}//algorithm2

}//class
