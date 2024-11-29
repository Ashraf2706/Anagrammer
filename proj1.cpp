/*
File: proj1.cpp
Author: Ashraf Kawooya
Date: 9/16/2023
Section: 13
Description: The program is a word anagram checker
*/

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <cstdlib>


using namespace std;

const int MAX_WORDS = 9578;
const int START_NUM = 8;
const int ASCII_TABLE_SIZE = 256;
const int MIN_NUM = 3;


void LoadFile(string wordList[MAX_WORDS]);
string StartingWord(string wordList[MAX_WORDS]);
bool IsAnagram(string word1, string word2);
string GetInput();
int TotalAnagrams(string wordList[MAX_WORDS], string startWord);
bool CheckGuess(string guess, int guessCount, string guessedList[]);
bool CheckValid(string guess, string wordList[MAX_WORDS]);

int main(){
  string wordList[MAX_WORDS];
  int guessCount = 0;
  int correctGuess = 0;

  // Initialize the random seed
  srand(time(NULL));
  // Load the list of words from the file into the wordList array
  LoadFile(wordList);
  // Choose a random starting word
  string word = StartingWord(wordList);
  // Calculate the total number of anagrams for the starting word
  int totAnagram = TotalAnagrams(wordList, word);
  cout << "Welcome to UMBC Anagrammer!" << endl;
  cout << "There are " << totAnagram << " anagrams available in this puzzle." << endl;
  cout << "Starting Word is: " << word << endl;
  string guessedList[totAnagram];
  
  //As long as number of correct guesses does not reach the total anagrams
  while(correctGuess < totAnagram){
    string trialWord;
    trialWord = GetInput();
    //If the guessed word is too short
    if(trialWord.length() < MIN_NUM){
      cout << "Minimum of 3 characters" << endl;
    }else{
      //If the word has already been guessed
      if(!CheckGuess(trialWord, guessCount, guessedList)){
        // as long as the word is valid and in the word list
        if(CheckValid(trialWord, wordList)){
          //if the guessed word is an anagram of the starting word
          if(IsAnagram(word, trialWord)){
            correctGuess++; 
            cout << trialWord << " is a anagram of " << word << endl;
            cout << "You've guessed " << correctGuess << " of " << totAnagram <<
            " anagrams available. " << endl;
            guessedList[guessCount] = trialWord;
            guessCount++;
          }
          else{
            // if it is not valid but in the word list
            cout << trialWord << " is not a valid word." << endl;
          }
        }else{
          // if it is not valid and is not in the list of words
          cout << "Word is invalid" << endl;
        }
      }
      else{
          cout << "Already guessed" << endl;
      }
    }
  }
  return 0;
}

// Function to load words from a file into the wordList array
void LoadFile(string wordList[MAX_WORDS]){
  string word;
  int num_words = 0;
  ifstream myfile;
  // Attempt to open the file
  myfile.open("proj1_data.txt");

  if (myfile.is_open()){
    while (myfile >> word){
      if (num_words < MAX_WORDS){
        wordList[num_words] = word;
        num_words += 1;
      }
    }
  }else{
    // Display an error message if the file couldn't be opened
    cout << "Unable to open the file. Try again" << endl;
  }
  myfile.close();
}

// Function to get user input for word guesses
string GetInput(){
  string guess;
  cout << "What word would you like to try? " << endl;
  cin >> guess;

  return guess;
}


// Function to check if two words are anagrams of each other
bool IsAnagram(string word1, string word2){
  int charCount[ASCII_TABLE_SIZE] = {0};

  for(int i = 0; i < word1.length(); i++){
    int index = word1[i];
    charCount[index]++;
  }

  for (int i = 0; i < word2.length(); i++){
    char index2 = word2[i];
    if (charCount[index2] == 0){
      return false;
    }
    charCount[index2]--;
  }

  return true;
}

// Function to calculate the total number of anagrams of a starting word
int TotalAnagrams(string wordList[MAX_WORDS], string startWord){
  int count = 0;
  for(int i = 0; i < MAX_WORDS; i++){
    if (IsAnagram(startWord, wordList[i])){
      count++;
    }
  }
  return count;
}

// Function to choose a random starting word from the wordList array
string StartingWord(string wordList[MAX_WORDS]){
  string eightLetterWord;
  int index = rand() % MAX_WORDS;

  // Find the first word in the list that has at least START_NUM (8) characters
  while(wordList[index].length() < START_NUM){
    if(index + 1 == MAX_WORDS){
      index = 0;
    }
    index++;
  }
  eightLetterWord = wordList[index];
  return eightLetterWord;
}

// Function to check if a word has already been guessed
bool CheckGuess(string guess, int guessCount, string guessedList[]){
  for(int i = 0; i < guessCount; i++){
    if(guess == guessedList[i]){
      return true;
    }
  }
  return false;
}


// Function to check if a word is in the wordList array
bool CheckValid(string guess, string wordList[MAX_WORDS]){
  for(int i = 0; i < MAX_WORDS; i++){
    if(guess == wordList[i]){
      return true;
    }
  }
  return false;
}