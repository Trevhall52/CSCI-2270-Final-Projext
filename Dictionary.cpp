#include <iostream>
#include <string>
#include <ctime>
#include <queue>
#include <algorithm>
#include "Dictionary.hpp"

using namespace std;

HashTable::HashTable(int tableSize1) {
  this->tableSize= tableSize1;
  table = new word*[tableSize];
  for(int i=0;i<tableSize1;i++)
      table[i] = nullptr;
}

unsigned int HashTable::hashFunction(string key) {
  int seed = 131;
  unsigned long hash = 0;
  for(int i = 0; i < key.length(); i++)
  {
     hash = (hash * seed) + key[i];
  }
  return hash % tableSize;
}

void HashTable::insertWord(word* W1) {
  for(int i = 0; i < W1->word.length(); i++) {
    W1->word[i] = tolower(W1->word[i]);
  }
  int index = hashFunction(W1->word);
  if(table[index] == nullptr) {
    table[index] = W1;
    return;
  }
  else {
    word* crawler = table[index];
    while(crawler->next != NULL) {
      crawler = crawler->next;
    }
    crawler->next = W1;
    return;
  }
}

void HashTable::insertAllWordsFromFile(string fileName) {
  ifstream in_file;
  in_file.open(fileName);
  string line = "";
  while(getline(in_file,line))
  {
    word* W1 = new word;
    W1->next = nullptr;
    string word = "";
    bool wordfound = false;
    for(int i = 0; i < line.size(); i++) {
      if(line[0] == '"' && i == 0 || line[line.size()] == '"' && i == line.size()-1) {
        continue;
      }
      if(line[i + 1] == '(' && wordfound == false) {
        W1->word = word;
        wordfound = true;
        word = "";
      }
      if(i == line.size()-1) {
        W1->definition = word;
        insertWord(W1);
        continue;
      }
      word = word + line[i];
    }
  }
}

void HashTable::getDefinition(string key) {
  word* crawler = NULL;
  int i = 1;
  bool wordfound = false;
  string word = key;
  for(unsigned int i = 0; i < word.length(); i++) {
    word[i] = tolower(word[i]);
  }
  int index = hashFunction(word);
  if(table[index] == nullptr) {
    cout << "Word not found." << endl;
    crawler = NULL;
    delete crawler;
    return;
  }
  crawler = table[index];
  while(crawler->next != nullptr) {
    if(crawler->word == word) {
      cout << i << ":" << crawler->definition << endl;
      wordfound = true;
      i++;
    }
    crawler = crawler->next;
  }
  if(crawler->word == word) {
    cout << i << ":" << crawler->definition << endl;
    wordfound = true;
    crawler = NULL;
    delete crawler;
    return;
  }
  else if(wordfound == false) {
    cout << "Word not found." << endl;
    crawler = NULL;
    delete crawler;
    return;
  }
}

void HashTable::searchWord(string word) {
  int starttime1, endtime1;
  double exectime1;
  starttime1 = clock();
  getDefinition(word);
  endtime1 = clock();
  exectime1 = (double)(endtime1-starttime1)/CLOCKS_PER_SEC;
  cout << endl;
  cout << "-------------------------------------------" << endl;
  cout << "Search Time: " << exectime1 << " seconds." << endl;
  cout << "-------------------------------------------" << endl;
}

bool HashTable::deleteHashTable() {
  for(int i = 0; i < tableSize; i++) {
    word* node = table[i];
    while(node->next != nullptr)
    {
        word* toDelete = node;
        node = node->next;
        delete toDelete;
    }
    delete node;
  }
}


BSTletter::BSTletter() {
  root = nullptr;
}

letter* BSTletter::getRoot() {
  return root;
}

bool BSTletter::addLetter(char a, int size, string filename) {
  letter* L1 = new letter;
  L1->nodeLetter = a;
  L1->hashSize = size;
  L1->fileName = filename;
  L1->rightChild = nullptr;
  L1->leftChild = nullptr;
  if(root == nullptr) {
    root = L1;
    return true;
  }
  else {
    letter* crawler = root;
    while(true) {
      if(L1->nodeLetter > crawler->nodeLetter) {
        if(crawler->rightChild == nullptr) {
          crawler->rightChild = L1;
          return true;
        }
        else {
          crawler = crawler->rightChild;
        }
      }
      else if(L1->nodeLetter < crawler->nodeLetter) {
        if(crawler->leftChild == nullptr) {
          crawler->leftChild = L1;
          return true;
        }
        else {
          crawler = crawler->leftChild;
        }
      }
    }
  }
  return false;
}

letter* BSTletter::searchBST(char a) {
  letter* crawler = root;
  while(crawler->nodeLetter != a) {
    if(a > crawler->nodeLetter) {
      crawler = crawler->rightChild;
    }
    if(a < crawler->nodeLetter) {
      crawler = crawler->leftChild;
    }
  }
  return crawler;
}
