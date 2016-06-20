class Solution {
public:
    string countAndSay(int n) {
        string countString;
        string sayString;
        if(n <= 0){
            return countString;
        }
        countString = "1";
        sayString = "1";
        for(int i= 2; i<=n; i++){
            int j = 1, count = 1;
            countString = sayString;
            sayString = "";
            char temp = countString[0];
            
            while(j < countString.size()){
                if(temp != countString[j]){
                    char counts =('1'+count-1) ;
                    sayString = sayString+ counts + temp;
                    
                    temp = countString[j];
                    count = 1;
                }else  {
                    count++;
                    
                }
                j++;
            }
            char counts =('1'+count-1) ;
            sayString =  sayString + counts + temp;
           
        }
        return sayString;
    }
};