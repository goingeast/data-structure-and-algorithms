//// haoru zhao
//// 07/03/2013
//
//
#include<iostream>
#include<sstream>
#include<queue>
#include<map>
#include<cmath>
#include<tr1/unordered_map>

using namespace std;
using namespace std::tr1;

class Point{
public:
    Point(int _x, int _y)
    :x(_x),y(_y){
    }
    ~Point(){};
    
    int x;
    int y;
};

bool isAccessible(int x, int y){
    int xSum = 0, ySum = 0;
    x = abs(x);
    y = abs(y);
    while(x){
        xSum += x%10;
        x/=10;
    }
    while(y){
        ySum += y%10;
        y/=10;
    }
    if(xSum + ySum <= 19)
        return true;
    else 
        return false;
}
string makeString(Point* p){
    stringstream s;
    s << p->x << ':'<<p->y;
    return s.str();
    
}
void addNeighbors(int x, int y, unordered_map<string,Point*>& pointsQueue){
    Point* p1 = new Point(x+1, y);
    string key1 = makeString(p1);
    
    if(isAccessible(x+1,y) && pointsQueue.count(key1)== 0){
        pointsQueue.insert(make_pair<string, Point*>( key1,p1));
        addNeighbors(p1->x, p1->y, pointsQueue);
    }else
        delete p1;
    
    Point* p2 = new Point(x-1, y);
    string key2 = makeString(p2);
    if(isAccessible(x-1,y) && pointsQueue.count(key2)== 0){
        pointsQueue.insert(make_pair<string, Point*>(key2,p2));
        addNeighbors(p2->x, p2->y, pointsQueue);
    }else
        delete p2;
    
    Point* p3 = new Point(x, y + 1);
    string key3 = makeString(p3);
    if(isAccessible(x,y +1) && pointsQueue.count(key3)== 0){
        
        pointsQueue.insert(make_pair<string, Point*>(key3, p3));
        addNeighbors(p3->x, p3->y, pointsQueue);
    }else
        delete p3;
    
    Point* p4 = new Point(x, y - 1);
    string key4 = makeString(p4);
    if(isAccessible(x,y-1) && pointsQueue.count(key4)== 0){
        pointsQueue.insert(make_pair<string, Point*>(key4, p4));
        addNeighbors(p4->x, p4->y, pointsQueue);
    }else
        delete p4;
}

Point* getValueAt(unordered_map<string,Point*>& pointsQueue, size_t i){
    
    unordered_map<string,Point*>::iterator temp = pointsQueue.begin();
    size_t j;
    for(j =0; j < i; ++j){
        temp++;
    }
    return temp->second;
}
#ifdef GRID_JUMP
int main(){
    Point* p = new Point(0,0);
    //test(startPoint);
    string key = makeString(p);
    pair<string, Point*> it(key, p);
    unordered_map<string, Point*> pointsQueue;
    
    pointsQueue.insert(it);
    unordered_map<string, Point*>::iterator temp = pointsQueue.begin();
    
    addNeighbors(temp->second->x, temp->second->y, pointsQueue);
        
    
    cout << pointsQueue.size();
}

#endif

//#include<iostream> 
//#include<set> 
//
//
//using namespace std; 
//
//int sumDigits(int x) { 
//    x = abs(x); 
//    int sum = 0; 
//    while (x) sum += x % 10, x /= 10; 
//        return sum; 
//} 
//
//bool isValid(int x, int y) { 
//    return (sumDigits(x) + sumDigits(y) <= 19); 
//} 
//
//void monkeyJump(int x, int y, set<pair<int, int> >& s) { 
//    for (int i = -1; i < 2; ++i) { 
//        for (int j = -1; j < 2; ++j) { 
//            if (abs(i + j ) == 1) { 
//                int x1 = x + i; 
//                int y1 = y + j; 
//                if (isValid(x1, y1) && s.find(make_pair(x1,y1)) == s.end()) { 
//                    s.insert(make_pair(x1, y1)); 
//                    monkeyJump(x1, y1, s); 
//                } 
//            } 
//        } 
//    } 
//} 
//
//int main() { 
//    set<pair<int,int> > s; 
//    s.insert(make_pair(0,0)); 
//    monkeyJump(0,0,s); 
//    cout << s.size(); 
//    return 0; 
//}