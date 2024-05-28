// iterative
// TC - O(logN)
// SC - O(1)
class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;
        int step = 1;
        bool left = true;

        while(n > 1){
            if (left || n % 2 == 1){
                head += step;
            }
            step *= 2;
            n /= 2;
            left = !left;
        }
        return head;
    }
};

// recursive
// TC - O(logN)
// SC - O(logN)
class Solution {
public:
    int lastRemaining(int n) {
        if (n == 1) return 1;

        return (1 + (n/2) - lastRemaining(n/2)) * 2;
    }
};
