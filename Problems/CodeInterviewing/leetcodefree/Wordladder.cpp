class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        
        queue<string> beingVisited;
        wordList.insert(endWord);

        addword(beginWord, wordList, beingVisited);
        int level = 0;
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

        return level;

    }

    void addword(string word, unordered_set<string>& wordList, queue<string>& beingVisited ){
    	wordList.erase(word);
    	for(int i = 0; i < word.size(); ++i){
    		char letter = word[i];
    		for(int j = 0; j < 26; ++j){
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