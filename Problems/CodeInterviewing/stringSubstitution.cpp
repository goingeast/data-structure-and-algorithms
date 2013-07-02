// haoru zhao
// 07/01/2013

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;


string StringParse(string testStr, vector<string> & fn, vector<string>& rn){
    size_t pos1 = testStr.find(';');
    string originStr = testStr.substr(0, pos1); // parse string befew ';'
     
    string temp = testStr.substr(pos1 + 1) + ',';
    
    size_t delimiterPos  = temp.find(',');
    int i = 1;
    
    while(delimiterPos != string::npos && i){    // get replace string info
        if(i%2 == 1)
            fn.push_back(temp.substr(0, delimiterPos));
        else
            rn.push_back(temp.substr(0, delimiterPos));
        
        i++;
        temp = temp.substr(delimiterPos + 1);
        delimiterPos  = temp.find(',');
    }
    return originStr;
}

string StringSubstitute(string testCase){

    //string origin;
    string modified;
    vector<string> rn;
    vector<string> fn;
    
    modified = StringParse(testCase, fn, rn);     // parse string, get string will be modified
                                                  // and strings to be used
    string temp = modified;           
    
    if(fn.size() != rn.size())                    // check FN has RN corresponding
        return modified;
    else{
        for(size_t i =0; i < fn.size(); ++i){
            
            size_t replacePos = temp.find(fn[i]); // temp str will replaced with '.' rn[i].length() times
                                                  // So in modified str, we have right position to replace.  
            while(replacePos != string::npos){    // this will not let later replacement overwrite the previous changes  
                
                temp.replace(replacePos, fn[i].length(), rn[i].length(), '.');
                modified.replace(replacePos, fn[i].length(), rn[i]);
                replacePos = temp.find(fn[i]);
            }
        }
    }
    return modified;
}
#ifdef STRING_
int main(int argc, char* argv[]){
    ifstream testFile;
    string testCase;
    if(argc == 2)
        testFile.open(argv[1]);
        
    if(testFile.is_open()){
        while(testFile.good()){
            getline(testFile, testCase);
            if(testCase.length() == 0)
                continue;
            else
                cout << StringSubstitute(testCase) << endl;
        }
    }else
        cout << "can not open file";
    
    return 0;
}

#endif