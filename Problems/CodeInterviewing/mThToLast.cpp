//haoru zhao
//07/01/2013


#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

char GetMthToLast(string testCase){
    if(testCase.size() == 0)
        return NULL;
    vector<char> resultList;

    for(size_t i = 0; i < testCase.length(); ++i){
        if(testCase[i] != ' ')
            resultList.push_back(testCase[i]);
    }
    
    int m = resultList.back() - '0';
    if(m <= resultList.size() - 1)
        return resultList[resultList.size() - 1 - m];
    
}
#ifdef FFF_
int main(int argc, char* argv[]){
    ifstream testFile;
    string testCase ="";
    if(argc == 2)
        testFile.open("data.txt");
        
    if(testFile.is_open()){
        while(testFile.good()){
            getline(testFile, testCase);
            cout << GetMthToLast(testCase)<< endl;
            
        }
    }else
        cout << "can not open file";
    
    return 0;
}
#endif
