/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() == 0)
            return 0;
        
        int maxNumPoints = 0;
        for(int i = 0; i< points.size(); ++i){
            int samePoints = 0, sameX = 0, maxNumber = 0;
            unordered_map<double,int> slopeCount;
            for(int j = 0; j < points.size(); ++j){
                if(i == j){
                    continue;
                }else if( points[i].x == points[j].x && points[i].y == points[j].y){
                    ++samePoints;
                }else if( points[i].x == points[j].x && points[i].y != points[j].y){
                    ++sameX;    
                }else{
                    double slope = (double)(points[j].y - points[i].y)/( points[j].x - points[i].x );
                    int count = ++slopeCount[slope];
                    maxNumber = max(maxNumber, count);
                }
            }
            maxNumPoints = max(max(maxNumber,sameX)+samePoints,maxNumPoints);
        }
        return maxNumPoints+1;
    }
};