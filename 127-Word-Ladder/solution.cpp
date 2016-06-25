class Solution {
public:
    int ladderLength_1(string beginWord, string endWord, unordered_set<string>& wordList) {
        
        queue<string> beingVisited;
        wordList.insert(endWord);

        addword(beginWord, wordList, beingVisited);
        int level = 2;
        while(!beingVisited.empty()){

        	int size = beingVisited.size();
        	for(int i = 0; i < size; ++i){
        		string word = beingVisited.front();
	        	beingVisited.pop();
	        	if(word == endWord){
	        		return level;
	        	}
	        	addword(word, wordList, beingVisited);
        	}
        	++level;
        }

        return 0;

    }
    
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // use unordered_set as queue
        unordered_set<string> startSet, endSet, *set1, *set2;

        startSet.insert(start);
        endSet.insert(end);
        int dis = 1, len = start.length();
        while (!startSet.empty() && !endSet.empty()) {
            if (startSet.size() > endSet.size()) {
                set1 = &startSet;
                set2 = &endSet;
            } else {
                set1 = &endSet;
                set2 = &startSet;
            }

            ++dis;

            unordered_set<string> newset1;
            for (auto itr = set1->begin(); itr != set1->end(); itr++) {
                string old = *itr;
                for (int i = 0; i < len; ++i) {
                    char tmp = old[i];
                    for (int j = 0; j < 26; ++j) {
                        old[i] = 'a' + j;
                        auto f = set2->find(old);
                        if (f != set2->end())
                            return dis;
                        f = dict.find(old);
                        if (f != dict.end()) {
                            newset1.insert(old);
                            dict.erase(f);
                        }
                    }
                    old[i] = tmp;
                }
            }
            swap(newset1, *set1);
        }
        return 0;
    }
 
    void addword(string word, unordered_set<string>& wordList, queue<string>& beingVisited ){
    	wordList.erase(word);
    	for(int i = 0; i < word.size(); ++i){
    		char letter = word[i];
    		for(int j = 1; j < 26; ++j){
    			word[i] = 'a' + j;
    			if(wordList.find(word) != wordList.end()){
    				beingVisited.push(word);
    				wordList.erase(word);
    			}
    		}
    		word[i] = letter;
    	}
    }
};