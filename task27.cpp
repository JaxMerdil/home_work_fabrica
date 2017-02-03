#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <algorithm>
//#include <map>
//#include <set>
//#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> words_count;
    multimap<int, string> sortMap;
    set <string> str = {"i", "or", "and", "that", "the", "of", "not", "to", "is", "a", "in", "with", "at", "an", "as",
                        "for", "but", "his", "he", "are", "has", "who", "by", "about", "which" };
    ifstream file("D:/test2.txt");
    if (!file.is_open())
    {
        cout << "File is not open!" << endl;
    }
    string word;
    while (file >> word)
    {
        transform (word.begin(), word.end(), word.begin(), ::tolower);
        if( binary_search(str.begin (), str.end(), word))
        {
            continue;
        }
        transform(word.begin(), word.end(), word.begin(), [](char ignore)
        {
            if( ispunct(ignore))
            {
                return '\0';
            }
            return ignore;
        });
        words_count[word]++;
    }
    for (auto it = words_count.begin(); it != words_count.end(); ++it)
    {
        sortMap.insert(pair<int, string>((*it).second, (*it).first));
    }
    int top=0;
    for (auto it = sortMap.rbegin(); it != sortMap.rend() && top < 10; ++it, ++top)
    {
        cout << setw(15) <<(*it).second << " | " <<  (*it).first<< endl;
    }
    return 0;
}
