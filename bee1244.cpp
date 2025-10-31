#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(); // limpar o '\n' depois do número

    while (N--) {
        string line;
        getline(cin, line); // lê a linha inteira

        stringstream ss(line);
        vector<string> words;
        string word;

        while (ss >> word)
            words.push_back(word);

        // stable_sort mantém a ordem original em empates
        stable_sort(words.begin(), words.end(),
            [](const string &a, const string &b) {
                return a.size() > b.size(); // ordem decrescente
            });

        for (int i = 0; i < (int)words.size(); i++) {
            if (i > 0) cout << " ";
            cout << words[i];
        }
        cout << "\n";
    }

    return 0;
}
