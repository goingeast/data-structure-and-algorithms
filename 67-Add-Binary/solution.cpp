class Solution {
public:
    string addBinary(string a, string b){
      int sum = 0;
      string res;
      int i = a.size()-1;
      int j = b.size()-1;  
      while( i >=0 || j >=0|| sum >0){
         if( i >=0){
         	sum += (a[i] - '0');
         }
         if(j >= 0){
            sum += (b[j] - '0');
         }
         //char temp = sum%2 +'0';
         res.push_back(sum%2 +'0');
         sum /= 2;
        i--;
        j--;
      }
     
      reverse(res.begin(), res.end());
      return res;
    }

};