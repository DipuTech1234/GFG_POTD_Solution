class Solution {
  public:
    char nthCharacter(int n) {
        long long digits = 1;
        long long start = 1;
        long long count = 9;

        while (n > count * digits) {
            n -= count * digits;
            digits++;
            start *= 10;
            count *= 10;
        }

        long long number = start + (n - 1) / digits;
        int index = (n - 1) % digits;

        return to_string(number)[index];
    }
};
