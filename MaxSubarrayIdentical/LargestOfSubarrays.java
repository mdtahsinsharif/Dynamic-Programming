import java.util.HashMap;
import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.*;

/* Return the largest of the first occurance of two identical subarrays*/

public class MyClass {
    
    public static int[] check_identical_subarrays(int[] arr){
        ArrayList<Integer> temp = new ArrayList<Integer>();
        ArrayList<Integer> max_list = new ArrayList<Integer>();
        HashMap<Integer, ArrayList<Integer>> map = new HashMap<Integer, ArrayList<Integer>>();
        for(int i=0; i<arr.length; i++)
        {
            if(map.containsKey(arr[i]))
            {
                ArrayList<Integer> list = map.get(arr[i]);
                
                list.add(i);
                
                int second_index = list.get(list.size()-1);
                int first_index = list.get(list.size()-2);
                
                while( first_index < arr.length && second_index < arr.length && arr[first_index] == arr[second_index])
                {
                    temp.add(arr[first_index]);
                    first_index++;
                    second_index++;
                }
                if(temp.size() > max_list.size())
                {
                    max_list = (ArrayList<Integer>)temp.clone();
                }
                temp.clear();
            } 
            else 
            {
                ArrayList<Integer> val = new ArrayList<Integer>();
                val.add(i);
                map.put(arr[i], val);
            }
        }
        return max_list.stream().mapToInt(Integer::intValue).toArray();
    }
    
    public static void main(String args[]) {
        int[] test = new int[]{1,8,9,2,3,4,5,6,7,10,90,80,50,40,55,6,74,98,3,4,1,10,90,2,3,4,5,6,7,80,50,40};
        int[] result = check_identical_subarrays(test);
        System.out.print("Identical subarray:  [" );
        for(int i=0; i<result.length; i++)
        {
            System.out.print(" " + result[i] );
            if(i!=result.length-1)
            {
                System.out.print(",");
            }
        }
        System.out.print(" ]");
    }
}
