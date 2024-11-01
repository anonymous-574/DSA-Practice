import java.util.ArrayList;
class Solution {
    public int[] plusOne(int[] digits) {
         // if last digit is not 9
        if (digits[digits.length-1]!=9) {
            digits[digits.length-1]++; 
            return digits;
        }
        
        int is_all_9=0;
        for (int i = 0; i < digits.length; i++) {
         if (digits[i]==9) {
            is_all_9++;
         }
        }

        // if all digits are 9
        if (is_all_9== digits.length) 
        {
            ArrayList<Integer> cars = new ArrayList<Integer>();
            cars.add(1);
            for (int i = 0; i < digits.length; i++) {
                cars.add(0);
            }
            int[] digits2 = new int[digits.length+1];
            for (int i = 0; i < cars.size(); i++) {
                digits2[i]=cars.get(i);
            }
            return digits2;
        }
        else // if at least last digit is 9
        {
            for (int i = digits.length-1; i >0; i--) {
                if (digits[i]==9) {
                    digits[i]=0;
                    digits[i-1]++;
                    break;
                }

            }
            for (int i = digits.length-1; i >0; i--)
            {
                if (digits[i]==10) {
                    digits[i]=0;
                    digits[i-1]++;
                }
            }
            return digits;
        }
    }
}