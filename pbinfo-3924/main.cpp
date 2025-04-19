/**
  *  Worg
  */
#include <set>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
std::ifstream fin("cripto1.in");
std::ofstream fout("cripto1.out");
int n, m, k, q;
std::set<std::string> dictionary;
std::vector<std::string> words;
int main() {
    fin >> n >> m >> k >> q;
    //  Read dictionary strings
    for (int i = 0; i < n; i++) {
        std::string s; fin >> s;
        dictionary.insert(s);
    }
    // Read words
    for (int i = 0; i < m; i++) {
        std::string s; fin >> s;
        words.push_back(s);
    }
    int max_matches = -1, best_id = -1;
    for (int id = 1; id <= q; id++) {
        std::vector<int> shift(k);
        for (int i = 0; i < k; i++) {
            fin >> shift[i];
        }
        int curr_matches = 0;
        for (auto& word : words) {
            std::string new_word;
            std::vector<int> transport(k, 0);
            for (int i = 0; i < k; i++) {
                int letter = word[i] + shift[i] + transport[i];
                if (letter <= (int)'z') {
                    new_word.push_back(letter);
                } else {
                    if (i == k - 1) {
                        new_word = ""; break;
                    } else {
                        letter -= 26;
                        new_word.push_back(letter);
                        transport[i + 1] = 1;
                    }
                }
            }
            if (dictionary.find(new_word) != dictionary.end()) {
                curr_matches += 1;
            }
        }
        if (id == 5430) {
            //fout << curr_matches << "\n";
        }
        if (curr_matches > max_matches) {
            max_matches = curr_matches;
            best_id = id;
        }
    }
    fout << best_id << " " << max_matches << "\n";
    fin.close(); fout.close();
    return 0;
}