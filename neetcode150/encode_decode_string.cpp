class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        // write your code here
        string encoded;
        for(string s : strs){
            encoded += to_string(s.size()) + "#" + s;
        }
        return encoded;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     * 4#happ16#yuckyuckyuckyuck
     */
    vector<string> decode(string &str) {
        vector<string> output;
        int i = 0;
        while(i < str.size()){
            int j = i;
            while(j != "#") j++;
            int len = stoi(str[i:j]);
            output.push_back(str[j+1:j+1+len]);
            i = j+1+len;
        }
        return output;
    }
};
