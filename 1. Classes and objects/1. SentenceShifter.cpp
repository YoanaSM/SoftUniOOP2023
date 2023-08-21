#include<iostream>
#include<vector>
#include<sstream>
#include<map>

using namespace std;

typedef vector<string> WordsVector;

class Shifter
{
  private:

    WordsVector words;

  public:

      Shifter(const WordsVector & words_): words(words_){}

      void shiftTimes(size_t times);

      const WordsVector & getShiftedSentence(void);

};

const WordsVector & Shifter :: getShiftedSentence(void)
{
    return words;
}

void Shifter::shiftTimes(size_t times)
{
    while(times)
    {
        string lastWord = words[words.size() - 1];
        words.pop_back();
        words.insert(words.begin(),lastWord);
        times--;
    }
}


int main()
{

    WordsVector words;

    string buf;

    getline(cin,buf);
    istringstream  istr(buf);

    string word;
    while(istr>>word)

        words.push_back(word);

    int shifts;
    cin >> shifts;

    Shifter s (words);

    s.shiftTimes(shifts);
    const WordsVector  & shifted = s.getShiftedSentence();

    for (auto word : shifted)
    {
        cout << word << endl;
    }


    return 0;
}