class Solution {
public:
    vector<string> addOperators(string num, int target) {

    	vector<string> result;

    	if(num.size() == 0){
    		return result;
    	}
    	addOperators_helper(result, target, num, "", 0, 0, 0);
    	return result;
        
    }

    void addOperators_helper(vector<string>& result, int target, string num, string candidate, int pos, long cur, long prev){

    	//base case
    	if(pos == num.size()){
    		if(target == cur){
    			result.push_back(candidate);
    		}
    		return;
    	}

    	for(int i = pos; i < num.size(); ++i){
    		if(i != pos && num[pos] =='0') break;
    		string temp = num.substr(pos, i -pos +1);
    		long value = stol(temp);

    		if(pos == 0){
    			addOperators_helper(result, target, num, temp, i+1, value, value);
    		}else{

    			addOperators_helper(result, target, num, candidate+'+'+temp, i+1, cur + value, value);
    			addOperators_helper(result, target, num, candidate+'-'+temp, i+1, cur - value, -value);
    			addOperators_helper(result, target, num, candidate+'*'+temp, i+1, cur - prev + prev*value,  prev* value);
    		}	

    	}

    }


};

// 1234