#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <queue>
#include <algorithm>
#include "Dictionary.cpp"

using namespace std;

void introSequence() {
cout << "Welcome to..." << endl;
cout << endl;
cout << "Trevor Hall's" << endl;
cout << "  _____ _     _ _       _    _____ _     _   _ " << endl;
cout << " |     |_|___|_| |_ ___| |  |     |_|___| |_|_|___ ___ ___ ___ _ _" << endl;
cout << " |  |  | | . | |  _| .'| |  |  |  | |  _|  _| | . |   | .'|  _| | |" << endl;
cout << " |____/|_|_  |_|_| |__,|_|  |____/|_|___|_| |_|___|_|_|__,|_| |_  |" << endl;
cout << "         |___|                                       CSCI 2270|___|" << endl;
cout << "-------------------------------------------" << endl;
}

int dictionaryChoice() {
  cout << "Will you be searching using:" << endl;
  cout << "1: BST / Multiple-Hash Approach" << endl;
  cout << "2. Single Hash Table Approach" << endl;
  string choice;
  cin >> choice;
  while(choice != "1" && choice != "2") {
    cout << "Please type '1' or '2' as your choice.'" << endl;
    cin >> choice;
  }
  cout << "-------------------------------------------" << endl;
  if(choice == "1") {
    return 1;
  }
  if(choice == "2") {
    return 2;
  }
}

int main() {
  int startTime, endTime;
  double execTime;
  introSequence();
  int choice = dictionaryChoice();
  if(choice == 1) {
    int startTime2, endTime2;
    double execTime2;
    BSTletter B1;
    startTime2 = clock();
    B1.addLetter('m', 20000, "M.csv");
    B1.addLetter('g', 20000, "G.csv");
    B1.addLetter('s', 20000, "S.csv");
    B1.addLetter('d', 20000, "D.csv");
    B1.addLetter('j', 20000, "J.csv");
    B1.addLetter('p', 20000, "P.csv");
    B1.addLetter('w', 20000, "W.csv");
    B1.addLetter('b', 20000, "B.csv");
    B1.addLetter('e', 20000, "E.csv");
    B1.addLetter('i', 20000, "I.csv");
    B1.addLetter('k', 20000, "K.csv");
    B1.addLetter('o', 20000, "O.csv");
    B1.addLetter('q', 20000, "Q.csv");
    B1.addLetter('u', 20000, "U.csv");
    B1.addLetter('y', 20000, "Y.csv");
    B1.addLetter('a', 20000, "A.csv");
    B1.addLetter('c', 20000, "C.csv");
    B1.addLetter('f', 20000, "F.csv");
    B1.addLetter('h', 20000, "H.csv");
    B1.addLetter('l', 20000, "L.csv");
    B1.addLetter('n', 20000, "N.csv");
    B1.addLetter('r', 20000, "R.csv");
    B1.addLetter('t', 20000, "T.csv");
    B1.addLetter('v', 20000, "V.csv");
    B1.addLetter('x', 20000, "X.csv");
    B1.addLetter('z', 20000, "Z.csv");
    endTime2 = clock();
    execTime2 = (double)(endTime2-startTime2)/CLOCKS_PER_SEC;
    cout << "BST Construction Time: " << execTime2 << " seconds." << endl;
    cout << "-------------------------------------------" << endl;
    cout << endl;
    cin.ignore();
    while(true) {
      int startTime3, endTime3;
      double execTime3;
      string wordSearch = "";
      cout << "What word would you like the definition for?: ";
      getline(cin,wordSearch);
      cout << endl;
      startTime3 = clock();
      HashTable H1(B1.searchBST(tolower(wordSearch[0]))->hashSize);
      H1.insertAllWordsFromFile(B1.searchBST(tolower(wordSearch[0]))->fileName);
      endTime3 = clock();
      execTime3 = (double)(endTime3-startTime3)/CLOCKS_PER_SEC;
      cout << "-------------------------------------------" << endl;
      cout << "Hash Table Construction Time: " << execTime3 << " seconds." << endl;
      cout << "-------------------------------------------" << endl;
      cout << endl;
      H1.searchWord(wordSearch);
      string choice2;
      cout << endl;
      cout << "Would you like to search for another word? (Y/N): ";
      getline(cin,choice2);
      while(choice2 != "Y" && choice2 != "y" && choice2 != "N" && choice2 != "n") {
        cout << "Please enter Y or N.";
        getline(cin,choice2);
      }
      if(choice2 == "Y" || choice2 == "y") {
        continue;
      }
      else {
        cout << endl;
        cout << "Thanks for using Trevor's Digital Dictionary!" << endl;
        cout << "Goodbye!" << endl;
        break;
      }
    }
  }
  else if(choice == 2) {
    HashTable H1(200000);
    startTime = clock();
    H1.insertAllWordsFromFile("A.csv");
    H1.insertAllWordsFromFile("B.csv");
    H1.insertAllWordsFromFile("C.csv");
    H1.insertAllWordsFromFile("D.csv");
    H1.insertAllWordsFromFile("E.csv");
    H1.insertAllWordsFromFile("F.csv");
    H1.insertAllWordsFromFile("G.csv");
    H1.insertAllWordsFromFile("H.csv");
    H1.insertAllWordsFromFile("I.csv");
    H1.insertAllWordsFromFile("J.csv");
    H1.insertAllWordsFromFile("K.csv");
    H1.insertAllWordsFromFile("L.csv");
    H1.insertAllWordsFromFile("M.csv");
    H1.insertAllWordsFromFile("N.csv");
    H1.insertAllWordsFromFile("O.csv");
    H1.insertAllWordsFromFile("P.csv");
    H1.insertAllWordsFromFile("Q.csv");
    H1.insertAllWordsFromFile("R.csv");
    H1.insertAllWordsFromFile("S.csv");
    H1.insertAllWordsFromFile("T.csv");
    H1.insertAllWordsFromFile("U.csv");
    H1.insertAllWordsFromFile("V.csv");
    H1.insertAllWordsFromFile("W.csv");
    H1.insertAllWordsFromFile("X.csv");
    H1.insertAllWordsFromFile("Y.csv");
    H1.insertAllWordsFromFile("Z.csv");
    endTime = clock();
    execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
    cout << "Hash Table Construction Time: " << execTime << " seconds." << endl;
    cout << "-------------------------------------------" << endl;
    cin.ignore();
    while(true) {
      string wordSearch = "";
      cout << "What word would you like the definition for?: ";
      getline(cin,wordSearch);
      cout << endl;
      H1.searchWord(wordSearch);
      string choice2;
      cout << endl;
      cout << "Would you like to search for another word? (Y/N): ";
      getline(cin,choice2);
      while(choice2 != "Y" && choice2 != "y" && choice2 != "N" && choice2 != "n") {
        cout << "Please enter Y or N.";
        getline(cin,choice2);
      }
      if(choice2 == "Y" || choice2 == "y") {
        continue;
      }
      else {
        cout << endl;
        cout << "Thanks for using Trevor's Digital Dictionary!" << endl;
        cout << "Goodbye!" << endl;
        break;
      }
    }
  }
  return 0;
}
