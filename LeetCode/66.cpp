#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // if last digit is not 9
        if (digits[digits.size() - 1] != 9) {
            digits[digits.size() - 1]++;
            return digits;
        }

        int is_all_9 = 0;
        for (int i = 0; i < digits.size(); i++) {
            if (digits[i] == 9) {
                is_all_9++;
            }
        }

        // if all digits are 9
        if (is_all_9 == digits.size()) {
            vector<int> cars;
            cars.push_back(1);
            for (int i = 0; i < digits.size(); i++) {
                cars.push_back(0);
            }
            vector<int> digits2(digits.size() + 1);
            for (int i = 0; i < cars.size(); i++) {
                digits2[i] = cars[i];
            }
            return digits2;
        } else { // if at least last digit is 9
            for (int i = digits.size() - 1; i > 0; i--) {
                if (digits[i] == 9) {
                    digits[i] = 0;
                    digits[i - 1]++;
                    break;
                }
            }
            for (int i = digits.size() - 1; i > 0; i--) {
                if (digits[i] == 10) {
                    digits[i] = 0;
                    digits[i - 1]++;
                }
            }
            return digits;
        }
    }
};