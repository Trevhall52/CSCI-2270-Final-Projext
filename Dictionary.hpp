#ifndef TEST_HPP
#define TEST_HPP

#include <string>

using namespace std;

struct word
{
    string word;
    string definition;
    struct word* next;
};

class HashTable
{
  private:
    int tableSize;
    word* *table;
  public:
    HashTable(int tableSize1);
    unsigned int hashFunction(string key);
    void insertWord(word* W1);
    void insertAllWordsFromFile(string filename);
    void getDefinition(string key);
    void searchWord(string word);
    bool deleteHashTable();
};

struct letter
{
  char nodeLetter;
  letter* rightChild;
  letter* leftChild;
  int hashSize;
  string fileName;
};

class BSTletter
{
  private:
    letter* root;
  public:
    BSTletter();
    letter* getRoot();
    bool addLetter(char a, int size, string filename);
    letter* searchBST(char a);
};

#endif
