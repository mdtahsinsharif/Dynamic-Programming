/*
DP Problem. Given the length and width of a matrix, get the number of paths from bottom-left to bottom right. 
You may only walk into those 3 directions ➡ (right) ↗ (upper-right) ↘ (lower-right) at each point. 
*/

public class HelloWorld{

    static int V = 5;
    static int VM = 2;
    static int n = 0, m = 0, l = 0, q = 0;
    static int column = 5;
    static int row = 2;

    public static int max(int i, int j){
        return (i > j? i:j);
    }
    
    public static int number_of_ways(int[][] arr, int i, int j){
        
        if(i == 0 && j==V){
            return 1;
        }
        
        if( j == V && i >= 0){
            return 0;
        } 
        
        if( j < V && i > 0){
            m += 1 + number_of_ways(arr, i, j+1);    
        } 
        else if( i > 0 && j < V){
            m += 1 + number_of_ways(arr, i-1, j+1);    
        } 
        else if( i < VM && j < V){
            m += 1 + number_of_ways(arr, i+1, j+1);    
        } else if (j == V){
          m += 1 + number_of_ways(arr, i, j);    
          //System.out.println(" m = " + m + ", n = " + n + ", l = " + l);
          
        }
        return m;  
    }
    
    
     public static void main(String []args){
        int[][] arr = new int[VM][V];
        for(int i=0; i<VM; i++){
            for(int j = 0; j<V; j++){
                arr[i][j] = 1;
            }
        }
        System.out.println("My func: " + number_of_ways(arr, VM, 0));
     }
}