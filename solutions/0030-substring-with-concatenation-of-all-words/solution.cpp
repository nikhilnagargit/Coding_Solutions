class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(words.empty() || s.empty()) return result;

        int word_len = words[0].length();
        int num_words = words.size();
        int concat_len = word_len * num_words;

        if(s.length() < concat_len) return result;

        unordered_map<string, int> word_count;
        for(const string& word : words) {
            word_count[word]++;
        }

        // try every offset within a word length
        for(int i = 0; i < word_len; ++i) {
            int left = i, right = i;
            unordered_map<string, int> curr_map;
            int count = 0;

            while(right + word_len <= s.length()) {
                string word = s.substr(right, word_len);
                right += word_len;

                if(word_count.count(word)) {
                    curr_map[word]++;
                    count++;

                    while(curr_map[word] > word_count[word]) {
                        string left_word = s.substr(left, word_len);
                        curr_map[left_word]--;
                        left += word_len;
                        count--;
                    }

                    if(count == num_words) {
                        result.push_back(left);
                    }
                } else {
                    curr_map.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};

