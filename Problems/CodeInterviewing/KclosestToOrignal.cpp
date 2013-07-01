// find k points that closest to orgin of 2D plain


#include<iostream>
#include<queue>
using namespace std;

class Point{
public: 
    int x;
    int y;
    Point(int _x, int _y)
    :x(_x), y(_y){}
    ~Point();
};

class Comparision{
    bool reverse;
public:
    Comparision(const bool& revparam=true)
            :reverse(revparam)
    {
        
    }
            
    bool operator()(Point * &p1, Point * &p2) const
    {
        if(reverse)
            return ((p1->x*p1->x)+(p1->y* p1->y)) >= ((p2->x*p2->x)+(p2->y* p2->y));
        else
            return ((p1->x*p1->x)+(p1->y* p1->y)) < ((p2->x*p2->x)+(p2->y* p2->y));
    }
};

#ifdef K_CLOSEST
int main(){

    priority_queue< Point* , vector< Point* >, Comparision> points;
    Point* a = new Point(3,2);
    Point* b = new Point(1,2);
    Point* c = new Point(2,2);
    Point* d = new Point(3,3);
    points.push(a);
    points.push(b);
    points.push(c);
    cout << points.top()->x <<  points.top()->y;
    points.pop();
    cout << points.top()->x << points.top()->y;
}
#endif

//#include <iostream>
//#include <queue>
//#include <iomanip>
//
//using namespace std;
//
//struct Time {
//    int h; // >= 0
//    int m; // 0-59
//    int s; // 0-59
//};
//
//class CompareTime {
//public:
//    bool operator()(const Time& t1, const Time& t2) const
//    {
//       if (t1.h < t2.h) return true;
//       if (t1.h == t2.h && t1.m < t2.m) return true;
//       if (t1.h == t2.h && t1.m == t2.m && t1.s < t2.s) return true;
//       return false;
//    }
//};
//
//int main()
//{
//    priority_queue<Time, vector<Time>, CompareTime> pq;
//
//    // Array of 4 time objects:
//
//    Time t[4] = { {3, 2, 40}, {3, 2, 26}, {5, 16, 13}, {5, 14, 20}};
// 
//    for (int i = 0; i < 4; ++i)
//       pq.push(t[i]);
//
//    while (! pq.empty()) {
//       Time t2 = pq.top();
//       cout << setw(3) << t2.h << " " << setw(3) << t2.m << " " <<
//       setw(3) << t2.s << endl;
//       pq.pop();
//    }
//
//    return 0;
//}


