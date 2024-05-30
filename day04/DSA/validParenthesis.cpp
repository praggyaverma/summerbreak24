// TC - O(N)
// SC - O(N)

class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 1) return false;
        if (s[0] == ')' || s[0] == '}' || s[0] == ']'){
            return false;
        }
        stack<char> st;
        
        for (char c : s){
            if (c == '(' || c == '{' || c == '['){
                st.push(c);
            } else {
                if (st.empty() || // closing bracket mila hai but stack is empty
                    (c == ')' && st.top() != '(') ||
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')) {
                        return false;
                    }
                st.pop();
            }
        }
        return st.empty();
    }
};
