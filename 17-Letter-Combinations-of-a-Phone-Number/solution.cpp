class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> numberPad = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> rets;
        string candidate;
        
        if(digits.size() != 0)
            _letterCombinations(digits, 0, candidate, numberPad, rets);
        return rets;
    }
    void _letterCombinations(string digits, int currPosition, string& candidate, vector<string>& numberPad, vector<string>& rets){
       if(digits.size() == currPosition){
           rets.push_back(candidate);
           return;
       }
       int tempPos =  (digits[currPosition] - '0');
       
       for(int i = 0; i< numberPad[tempPos].length(); ++i){
           candidate.push_back(numberPad[tempPos][i]);
           _letterCombinations( digits, currPosition+1, candidate, numberPad, rets);
           candidate.pop_back();
       }
    }
};