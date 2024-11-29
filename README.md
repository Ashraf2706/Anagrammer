
# UMBC Anagrammer

## Overview
UMBC Anagrammer is a C++ console application designed to check for anagrams from a given list of words. The program selects a random starting word and challenges the user to identify all valid anagrams from the provided word list.

## Files
- **proj1.cpp**: The main program file containing the logic for the anagram checker.
- **proj1_data.txt**: A text file containing the list of words used by the program.

## Features
- Loads a list of words from a file.
- Randomly selects a starting word of at least 8 characters.
- Validates user input for minimum length and checks against the word list.
- Identifies and counts anagrams for the starting word.
- Tracks guessed words to avoid duplicates.

## How to Run
1. Compile the program using a C++ compiler:
   ```bash
   g++ -o anagrammer proj1.cpp
   ```
2. Ensure `proj1_data.txt` is in the same directory as the compiled program.
3. Run the program:
   ```bash
   ./anagrammer
   ```

## User Instructions
- The program will display a random starting word and inform the user of the total number of possible anagrams.
- The user is prompted to input words they believe are anagrams.
- The program will validate each input and provide feedback:
  - If the word is a valid anagram, it increments the correct guess count.
  - If the word is not valid or has already been guessed, it will display an appropriate message.
- The game continues until all anagrams are guessed.

## Dependencies
- Standard C++ libraries:
  - `<iostream>`
  - `<string>`
  - `<fstream>`
  - `<ctime>`
  - `<iomanip>`
  - `<cmath>`
  - `<cstdlib>`

## Functions
The application includes the following key functions:
- **LoadFile**: Loads the word list from `proj1_data.txt`.
- **StartingWord**: Selects a random starting word with a minimum length of 8 characters.
- **IsAnagram**: Checks if two words are anagrams of each other.
- **GetInput**: Prompts the user for input.
- **TotalAnagrams**: Counts the total number of anagrams for the starting word.
- **CheckGuess**: Verifies if a word has already been guessed.
- **CheckValid**: Confirms if the word is present in the word list.

## Notes
- The word list (`proj1_data.txt`) contains a comprehensive set of English words for anagram checking.
- Ensure the word list file is formatted correctly with one word per line.

## Author
- **Ashraf Kawooya**
- Date: 9/16/2023
- Section: 13

## License
This project is for educational purposes and does not include any warranty or guarantee.
