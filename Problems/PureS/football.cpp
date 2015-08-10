/*footgame  permutation*/

/*
6 points for the touchdown
1 point for the extra point (kicked)
2 points for the extro points (a conversion)

2 points for a safety 
3 points for a field goal
*/

//Given a target score, print all possible ways that the score could be reached in American football, where order is not important. 
// as we can see In American football, there are 5 possible ways to score, which give you 2, 3, 6, 7, and 8 points.

/* according to rule as above:
	2 is points for a safety
	3 is points for a field goal
	6 is points for the touchdown
	7 is points for the touchdown + extra point (kicked)
	8 is points for the touchdown + extra points(a conversion)
 
/*
  For example, for a target score of 6, you would print:
  6
  3+3
  2+2+2

  For a target score of 7, you would print:
  7
  3+2+2
  (but not 2+3+2 or 2+2+3, since order is not important)
*/

void footballScores_helper(vector<int>& rules, int curLevel, int remain, vector<int>& candidate, vector<vector<int>>& result){
    if(rules.size() == curLevel + 1){
        if(remain % rules[curLevel] == 0){
            
            candidate.push_back(remain/rules[curLevel]);
            result.push_back( candidate);
            candidate.pop_back();
        }
        return;
    }    
    for(int i = 0; i <= remain/rules[curLevel]; ++i){
        candidate.push_back(i);
        footballScores_helper(rules, curLevel+1, remain - i * rules[curLevel], candidate, result);
        candidate.pop_back();
    }
}

vector<vector<int>> footballScores( vector<int>& rules, int score){
    vector<vector<int>> result;
    vector<int> candidate;
    footballScores_helper(rules, 0, score, candidate,result);
    return result;
}

