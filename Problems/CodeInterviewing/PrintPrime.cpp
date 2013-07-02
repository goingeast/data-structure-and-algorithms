
//haoru zhao
//07/01/2013


#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;


bool isPrime(unsigned int num){
    for(int i=2; i<=sqrt(num); i++){
        if(num%i == 0){
            return false;
        }
    }
    return true;
}

void printAllPrimes(string testCase){
    
    unsigned int num;
    istringstream input(testCase);
    input >> num;
    
    if(num >= 2)
        cout << 2;
    for(size_t i = 3; i < num; ++i){
        if(isPrime(i))
            cout << ','<< i;
    }
    cout << endl;
}
#ifdef PRIME
int main(int argc, char* argv[]){
    ifstream testFile;
    string testCase ="";
    if(argc == 2)
        testFile.open(argv[1]);
        
    if(testFile.is_open()){
        while(testFile.good()){
            getline(testFile, testCase);
            if(testCase.length() == 0)
                continue;
            else
                printAllPrimes(testCase);  
        }
    }else
        cout << "can not open file";
    
    return 0;
}
#endif
