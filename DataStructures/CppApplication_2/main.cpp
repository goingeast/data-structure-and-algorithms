/* 
 * File:   main.cpp
 * Author: haoruzhao
 *
 * 
 * 
 * Created on April 26, 2013, 3:35 PM
 */

#include<iostream>
#include <string>
#include<hash_map.h>
#include<sstream>
#include<vector>
using namespace std;

void reverse(char* a){
    char temp;
    char * end = a;
    if(a){
        while(*end != '\0'){
            end++;
        }
        end--;
        while(a < end){
            temp = *a;
            *(a++) = *end;
            *(end--) = temp;
        }
    }

}
// check whether a is a permutation of b
bool isPermutation(string a, string b){
    int temp[256] = {0};
    if(a.size() == b.size()){
        for(int i=0; i < a.size(); ++i){
            temp[a[i]] ++;
        }
        for(int i=0; i < b.size(); ++i){
            if(--temp[b[i]] < 0)
                return false; 
        }
        return true;
    }
        return false;
}

void stringencode(string& a){
    
    while(a.find(' ') != string::npos){
        size_t pos = a.find(' ');
        a.replace(pos, 1, "%20");
    };    
}
string itos(int i){
    stringstream s;
    s << i;
    return s.str();
}
string compressString(string a){
    int count = 1, times = 0;
    char pre = a[0];
    char c;
    string compressedStr;
    for(int i=1; i < a.size(); ++i){
        if(a[i] == pre){
            count++;
        }else{
            
            times++; // check if the compressed string is longer than original
            if(times * 2 > a.size()){
                return a;
            }
            //c = '0'+ count; //convert int to char number
            
            compressedStr.push_back(pre);
            compressedStr.append(itos(count));
            if(compressedStr.size() > a.size())
                return a;
            pre = a[i];
            count = 1;
        }
    }
    //c = '0'+ count;
    compressedStr.push_back(pre);
    compressedStr.append(itos(count));
    return compressedStr;
}

void rotateMatrix(vector< vector<int> >& a){
    int n = a.size();
    for(int layer = 0; layer < n/2; ++layer ){
        int first  = layer;
        int last = n - layer -1;
        for(int i = first; i < last; ++i){
            int offset = i - first;
            int temp = a[first][i];
            a[first][i] = a[last - offset][ first];
            a[last - offset][ first] = a[last][last - offset];
            a[last][last - offset] = a[i][last];
            a[i][last] = temp;
        }
    }
}

void setRowColToZero(vector< vector<int> >& a){
    bool* row = new bool[a.size()];
    bool* col = new bool[a[0].size()];
    
    for(int i =0; i < a.size(); ++i){
       for(int j = 0; j < a[i].size(); ++j)
           if(a[i][j] == 0){
               row[i] = true;
               col[j] = true;
           }
    }
    
    for(int i =0; i < a.size(); ++i){
       for(int j = 0; j < a[i].size(); ++j)
           if(row[i] || col[j]){
               a[i][j] = 0;
           }
    }
    
    delete row;
    delete col;
    
}

vector<int> palindromes(string a){
    int seqLen = a.size();
    vector<int> l;
    int i = 0;
    int palLen = 0;
    while(i < seqLen){
        if(i > palLen && a[i - palLen - 1] == a[i] ){
            palLen += 2;
            i += 1;
            continue;
        }
        l.push_back(palLen);
        int s = l.size() - 2;
        int e = s - palLen;
        int j = 0;
        for(j= s; j > e; --j){
            int d = j - e - 1;
            if(l[j] == d){
                palLen = d;
                break;
            }
            l.push_back(min(d,l[j]));
        }
        if(j <= e){
            palLen = 1;
            i +=1;
        }
    }
    l.push_back(palLen);
    int lLen = l.size();
    int s = lLen - 2;
    int e = s - (2 * seqLen + 1 - lLen);
    for(int k = s; k > e; --k){
        int d = k-e -1;
        l.push_back(min(d,l[i]));
    }
    return l;
}
int main(int argc, char** argv) {

    string a2 = "abcdedfafadf";
    string a = "abababababa";
    string b1 = "yyyyyyybcadddddddddddddddddeett";
    //cout << min(15, 2);
    //cout << isPermutation(a, b);
    //stringencode(a);
    //cout << compressString(b);
    vector<int> a1;
//    a1.push_back(1);
//    a1.push_back(2);
//    a1.push_back(0);
//    a1.push_back(4);
//    
//    vector<int> a2;
//    a2.push_back(1);
//    a2.push_back(2);
//    a2.push_back(2);
//    a2.push_back(4);
//    
//    vector< vector<int> > b;
//    b.push_back(a1);
//    b.push_back(a2);
//    b.push_back(a2);
//    b.push_back(a2);
//    
//    for(int i =0; i < b.size(); ++i){
//       for(int j = 0; j < b[i].size(); ++j)
//           cout << b[i][j];
//       cout << endl;
//   }
//    
//   //rotateMatrix(b);
//    setRowColToZero(b);
    a1 = palindromes(a);
    for(int j = 0; j < a1.size(); ++j)
           cout << a1[j];
//   for(int i =0; i < b.size(); ++i){
//       for(int j = 0; j < b[i].size(); ++j)
//           cout << b[i][j];
//       cout << endl;
//   }
    return 0;
}

