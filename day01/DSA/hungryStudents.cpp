// TC - O(n)
// SC - O(1)
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> count = {0, 0};
        int i;
        int n = students.size();
        for(int i = 0; i < students.size(); i++){
            count[students[i]]++;
        }
        for(i = 0; i < sandwiches.size(); i++){
            if (count[sandwiches[i]] > 0){
                count[sandwiches[i]]--;
            } else {
                break;
            }
        }
        return n - i;
    }
};
