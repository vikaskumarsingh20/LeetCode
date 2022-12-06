 import java.util.*;
public class letterCombination {
    static String keypadKeys[] = {"","v" , "abc" , "def","ghi" , "jkl","mno" ,"pqrs","tuv","wxyz"};
 
    static ArrayList<String> keypad (String number){

        // base case
         if(number.length() == 0){
            ArrayList<String> empList = new ArrayList<>();
            empList.add("");
            return empList;
         }
     char currentChar = number.charAt(0); // for 2 index
     String remString = number.substring(1); // for 3 index
 
     int index = currentChar - '0'; // convert into integer
     String key = keypadKeys[index];
     ArrayList<String> result = new ArrayList<>();

     for(int i=0;i<key.length();i++){
        ArrayList<String> temp = keypad(remString);
        for(String s : temp){
            result.add(key.charAt(i) + s);
        }
     }
     return result;
    }

    public static void main(String[] args){
     
        ArrayList<String> list = keypad("23");
        System.out.println(list);
    }
}
