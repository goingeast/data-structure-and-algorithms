class Solution {
public:
    int romanToInt(string s) {
    	int ret = 0;
    	int length = s.size();
        for(int i = 0; i < length; ++i){
        	switch (s[i]){
        		case 'I':
        			if(i < length - 1 && (s[i+1] == 'V' || s[i+1] == 'X')){
        				ret = ret - 1;
        			}else{
        				ret = ret + 1;
        			}
        			break;
        		case 'V':
        			ret += 5;
        			break;
        		case 'X':
        			if(i < length - 1 && (s[i+1] == 'C' || s[i+1] == 'L')){
        				ret = ret - 10;
        			}else{
        				ret = ret + 10;
        			}
        			break;
        		case 'L':
        			ret += 50;
        			break;
        		case 'C':
        			if(i < length - 1 && (s[i+1] == 'M' || s[i+1] == 'D')){
        				ret = ret - 100;
        			}else{
        				ret = ret + 100;
        			}
        			break;
        		case 'D':
        			ret += 500;
        			break;
        		case 'M':
        			ret += 1000;
        			break;
        		default:
        			return 0;

        	} 
        }
        return ret;
    }
};