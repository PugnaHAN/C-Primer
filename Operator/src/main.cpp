#include "common.h"
#include "StrLength.h"

using namespace std;

int main(int argc, char* argv[])
{
    ifstream infile("words");
    string line, word;
    vector<string> words;
    
    while(getline(infile, line))
    {
        istringstream line_word(line);
        while(line_word >> word)
            words.push_back(word);
    }
    cout << "Enter the length(min & max): ";
    unsigned int min, max;
    cin >> min >> max;
    auto b = words.begin();
    int count  = 0;
    do 
    {
        b = find_if(b + 1, words.end(), StrLength(min, max));
        ++count;
    }
    while(b != words.end());

    cout << "words number: " << count << endl;

    return 0;
}