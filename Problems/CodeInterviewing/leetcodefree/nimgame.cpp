class Solution {
public:
    bool canWinNim(int n) {
        return n%4;
    }
    bool canWinNimDP(int n){
    	if(n >= 134882061) return n%4 != 0;
    	boolean res = true;
	    boolean fir = true;
	    boolean sec = true;
	    boolean thir = true;
	    for(int i=4;i<=n;i++){
	        res = (fir && sec && thir) ? false:true;
	        fir = sec;
	        sec = thir;
	        thir = res;
	    }
	    return res;

    }
    bool canWinNimDFS(int n) {
    // 1 2 3 (4) 5 6 7 (8) 9 10 11 (12)
	    if(n <= 0) return false;
	    if(n == 1 || n == 2 || n== 3) return true;
	    if(canWinNimDFS(n-1) && canWinNimDFS(n-2) && canWinNimDFS(n-3)) return false;
	    return true;
	}
};