// TC - O(N) 
// SC - O(N)
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1){
            int n = s.size();
            string ans = s;
            s += s;
            for(int i = 0; i < n; i++){
                ans = min(ans, s.substr(i, n));
            }
            return ans;
        } else {
            sort(s.begin(), s.end());
            return s;
        }
    }
};
