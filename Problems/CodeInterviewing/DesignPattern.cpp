//haoru zhao

#include<iostream>
using namespace std;
class singleton{
public:
    static singleton& getInstance(){
        static singleton S;
        return S;
    }
    void doSomething(){
        count+=2;
    }
    void print(){
        cout << count;
    }
private:
    int count;
    singleton(){};
    singleton(const singleton &);
    const singleton& operator=(const singleton &);

};

//int main(){

//    singleton::getInstance().doSomething();
 //   singleton::getInstance().print();
 //   singleton::getInstance().doSomething();
 //   singleton::getInstance().print();

//}
