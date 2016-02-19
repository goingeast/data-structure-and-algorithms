class Solution {
public:
    string intToRoman(int num) {
    	if(i <=0 || i > 3999)
    		return "";
    	string retStr;
        char digits[][3] = {{'', '','M'},
    					   {'M','D','C'},
    					   {'C','L','X'},
    					   {'X','V','I'}};
    	convertDigit(num/1000, digits[0], retStr);
    	convertDigit(num%1000/100, digits[1], retStr);
    	convertDigit(num%100/10, digits[2], retStr);
    	convertDigit(num%10, digits[3], retStr);
    	return retStr;
    }

    void convertDigit(int digit, char digits[], string& str){
    	switch(digit){
    		case 1:
    		case 2:
    		case 3:
    		
    			while(digit--){
    				str += digits[2];
    			}
    			break;
    		case 4:
    			str += digits[2];
    			str += digits[1];
    			break;
    		case 5:
    		case 6:
    		case 7:
    		case 8:
    			str += digit[1];
    			while(digit-5){
    				str += digit[2];
    				--digit;
    			}
    			break;
    		case 9:
    			str += digits[2];
    			str += digits[0];
    			break;
    		case 0:
    		default:
    			break;
    	}

    }
};