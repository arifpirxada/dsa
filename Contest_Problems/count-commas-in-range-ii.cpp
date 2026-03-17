class Solution {
public:
    long long countCommas(long long num) {
        long long count = 0;
        string str = to_string(num);

        while (num >= 1000) {
            string s = to_string(num);
            int n = s.size();
            int c = (n / 3) - 1;
            if (n % 3 != 0) {
                c++;
            }
            
            if (n < 4) {
                break;
            }
            if (n <= 6) {
                count += (num - 999) * c;
                break;
            }
            if (n <= 9) {
                count += (num - 999999) * c;
                num = 999999;
                continue;
            }
            if (n <= 12) {
                count += (num - 999999999) * c;
                num = 999999999;
                continue;
            }
            if (n <= 15) {
                count += (num - 999999999999) * c;
                num = 999999999999;
                continue;
            }
            if (n <= 16) {
                count += (num - 999999999999999) * c;
                num = 999999999999999;
            }
        }

        return count;
    }
};