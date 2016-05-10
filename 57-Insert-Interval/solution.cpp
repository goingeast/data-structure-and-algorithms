/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        // Start typing your C/C++ solution below  
      // DO NOT write int main() function  
      vector<Interval> result;  
      result.push_back(newInterval);  
      for(int i=0; i< intervals.size(); i++)  
      {  
        Interval newInt = result.back();  
        result.pop_back();  
        Interval* cur = &intervals[i];  
        if(cur->end < newInt.start)  
        {  
          result.push_back(*cur);  
          result.push_back(newInt);          
        }        
        else if(cur->start > newInt.end)  
        {  
          result.push_back(newInt);  
          result.push_back(*cur);          
        }  
        else  
        {          
          newInt.start = min(cur->start, newInt.start);  
          newInt.end = max(cur->end, newInt.end);  
          result.push_back(newInt);  
        }  
      }  
      return result; 
    }
};