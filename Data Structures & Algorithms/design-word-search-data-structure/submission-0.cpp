class WordDictionary {
public:
    vector<string> store;

    WordDictionary() {
        
    }
    
    void addWord(string word) {
        store.push_back(word);    
    }
    
    bool search(string word) {
        int n = word.size();

        for (string s : store){
            if (s.size() != n) continue;
            int i = 0;
            while (i < n) {
                if (s[i] == word[i] || word[i] == '.') i++;
                else break;
            }
            if (i == n) return true;
        }
        return false;
    }
};
