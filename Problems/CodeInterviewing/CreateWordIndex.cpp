/* Haoru Zhao, 07/04/2013, 45min
 * Solution: I use STL map to store those word objects. when I encounter a new
 * word, make a word object and insert it to the map. Or when I encounter a old
 * word, update count, sentence number information.
 * 
 * Problems: For the bonus, there is a key problems that how can we decide it is the
 * end of a sentence. if there is an abbreviation in the sentence, like i.e., problem
 * becomes more complex. I just make a simple solution which can decide most cases,
 * however, there are still some case, I didn't handle it. 
 * 
 * bad case: This is Prof. Jim. He is my teacher.
 * other case: The amount of money is 3,300 dollars; I don't count the numbers(3,300);
 * 
 */

#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include <iomanip>
using namespace std;

/* 
 * word class, Represents a word of the English alphabet
 */

class word{
public:
    word(string word)
    :_word(word),_count(0){
    
    }
    
    string getWord(){
        return _word;
    }
    int getCount(){
        return _count;
    }
    
    vector<int>& getSentenceNum(){
        return sentenceNums;
    }
    
    void increaseCount(){
        _count++;
    }
    void addSentenceNum(int sNum){
        sentenceNums.push_back(sNum);
    }
private:
    
    string _word;               /*word string*/
    int _count;                 /*word count number*/
    vector<int> sentenceNums;   /*sentence numbers of the word*/
};

/*
 * concordance class, generate concordance of a string
 */
class concordance{
public:
    concordance(string& testStr)
    :_testStr(testStr),currentIndex(0),sentenceNum(0){
      
    }
    ~concordance(){             /* clean memory */
        for (map<string, word* >::iterator it = _concordance.begin(); it != _concordance.end(); ++it)
            delete it->second;
    }
    
    void getConcordance(){
        while(currentIndex<_testStr.length()){ /*current character index in string*/
            string current = readNextWord();   /*get a word from string*/
            
            if(_concordance.count(current) != 0) { /* if the word is already in map, update word info*/
                map<string, word* >::iterator iter;
                iter = _concordance.find(current);
                iter->second->increaseCount();
                iter->second->addSentenceNum(sentenceNum);
            }else{                                 /* if the word is not in map, add new entry into map*/
                word* w = new word(current);
                w->increaseCount();
                w->addSentenceNum(sentenceNum);
                _concordance.insert(make_pair<string, word*>(current, w));
            }
                
        }
    }
    /*print result with formatting*/
    void print(){
        size_t labelNum = 0;
        for (map<string, word* >::iterator it = _concordance.begin(); it != _concordance.end(); ++it){
            cout<< std::setw(6) << std::left << getLabel(labelNum); 
            cout<< std::setw(20) << std::left<< it->second->getWord() <<" {"<< it->second->getCount()<<':';
            for(size_t i=0; i < it->second->getSentenceNum().size(); ++i){
                if(i == 0)
                    cout << it->second->getSentenceNum()[i];
                else 
                    cout <<','<<it->second->getSentenceNum()[i];
                
            }
            cout <<'}'<< endl;
            labelNum++;
        }
    }
private:
    /*helper function, get a word from string*/
    string readNextWord(){
        string nextWord;
        while(currentIndex<_testStr.length()){
            char ch = _testStr[currentIndex];
            currentIndex++;
            if(ch == ' '){             /*end of word*/
                break;
            }else if(ch == '.'){       /* handle abbreviation, just handle simple case, i.e.*/
                if(currentIndex < _testStr.length() && isalpha(_testStr[currentIndex]) || _testStr[currentIndex - 3] == '.')
                    nextWord.push_back(ch);
            }else if(isalpha(ch)){ 
                nextWord.push_back(tolower(ch));
            }

            /* simply solution,  a new sentence if we find a period followed by an uppercase letter*/
            if((currentIndex > 2 && _testStr[currentIndex - 3] == '.') && isupper(ch)){
                sentenceNum++;
            } 
        }
        return nextWord;
    }
    /*generate label for word*/
    string getLabel(int num) {
        string result;
        
        int remainder = (num) % 26;
        char digit = (char) (remainder + 97); /*add to value of 'a'*/
        for(int i = num/26; i>=0; i--) {
            result.push_back(digit);          /*keep inserting the same digit*/
        }
        return result+". ";
    }
    map<string, word* > _concordance;  /*words map to store word object*/
    string& _testStr;                  /*file string*/
    int currentIndex;                  /*the index currently processed*/
    int sentenceNum;                   /*sentence number state*/
    
};
#ifdef CREATE_WORD_INDEX
int main(int argc, char* argv[]){
    
    ifstream testFile;
    string testStr;
    string buffer;
    if(argc == 2)
        testFile.open(argv[1]);
    else{
        cout << "run program with file path argument!";
        return -1;
    }
        
    if(testFile.is_open()){            /*read file*/
        while(testFile.good()){
            getline(testFile, buffer);
            if(buffer.length() == 0)
                continue;
            else
                testStr+=buffer;
        }
    }else{
        cout << "can not open file";
        return -1;
    }
    concordance newConcordance(testStr);
    newConcordance.getConcordance();
    newConcordance.print();
    return 0;
}
#endif