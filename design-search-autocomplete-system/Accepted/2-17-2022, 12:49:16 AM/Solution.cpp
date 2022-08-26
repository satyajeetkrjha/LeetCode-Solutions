// https://leetcode.com/problems/design-search-autocomplete-system

class Node {
public:
    unordered_map<char, Node*> children;
    unordered_map<string, int> counter;
    Node() {};
};

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        for (int i = 0; i < sentences.size(); i++) {
            add(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            add(prefix, 1);
            prefix.clear();
            return {};
        }
        prefix += c;
        Node* node = root;
        for (char ch : prefix) {
            if (!node -> children[ch]) {
                return {};
            }
            node = node -> children[ch];
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;
        for (auto p : node -> counter) {
            pq.push({p.second, p.first});
        }
        vector<string> autocomplete;
        for (int i = 0; i < 3 && !pq.empty(); i++) {
            autocomplete.push_back(pq.top().second);
            pq.pop();
        }
        return autocomplete;
    }
private:
    Node* root = new Node();
    string prefix;
    
    struct compare {
        bool operator()(pair<int, string>& l, pair<int, string>& r) {
            return l.first < r.first || (l.first == r.first && l.second.compare(r.second) > 0);
        }
    };
    
    void add(string sentence, int time) {
        Node* node = root;
        for (char c : sentence) {
            if (!node -> children[c]) {
                node -> children[c] = new Node();
            }
            node = node -> children[c];
            node -> counter[sentence] += time;
        }
    }
};