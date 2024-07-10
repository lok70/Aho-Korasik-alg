#include <iostream>
#include <vector>
#include <string>
#include "Header.h"

using namespace std;

int main() {
    // Пример использования с обычными шаблонами
    vector<string> patterns1 = { "he", "she", "his", "hers" };
    AhoCorasick ac1(patterns1);

    string text1 = "ahishers";
    cout << "Searching in text: " << text1 << endl;
    ac1.search(text1);

    cout << "Number of comparisons: " << ac1.getComparisons() << endl;

    cout << "------------------------" << endl;

    // Пример для демонстрации плохой работы
    vector<string> patterns2 = { "a", "aa", "aaa", "aaaa" };
    AhoCorasick ac2(patterns2);

    string text2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    cout << "Searching in text: " << text2 << endl;
    ac2.search(text2);

    cout << "Number of comparisons: " << ac2.getComparisons() << endl;

    return 0;
}
