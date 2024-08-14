#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 * A word is considered valid if:
 * 
 *     It contains a minimum of 3 characters.
 *     It contains only digits (0-9), and English letters (uppercase and lowercase).
 *     It includes at least one vowel.
 *     It includes at least one consonant.
 * 
 * You are given a string word.
 * 
 * Return true if word is valid, otherwise, return false.
 * 
 * Notes:
 * 
 *     'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
 *     A consonant is an English letter that is not a vowel.
 */

bool check_if_vowel(char vowel){
    // Constants
    char* vowels = "AEIOUaeiou";
    for (int i = 0; i < strlen(vowels); i++){
        if ((int) vowel == (int) vowels[i]) return true;
    }
    return false;
}

bool isValid(char* word) {

    // Flags
    bool contains_vowel = false;
    bool contains_consonant = false;

    // Collect information
    int len = strlen(word); // word length
    if (len < 3){
        // Invalid word, not long enough
        return false;
    }

    // Loop through word once
    for (int i = 0; i < len; i++){
        // Get ascii value as integer
        int val_ascii = (int) word[i];

        // Check if we found a consonant, vowel, or number
        //    65 to 90 are uppercase letters
        //    97 to 122 are uppercase letters
        //    48 to 57 are numbers
        if (val_ascii >= 48 && val_ascii <= 57){
            int x = 0;
        } else if ((val_ascii >= 65 && val_ascii <= 90) ||
            (val_ascii >= 97 && val_ascii <= 122)){
            // Check if value is vowel or consonant
            bool is_vowel = check_if_vowel(val_ascii);
            if (is_vowel) contains_vowel = true;
            else contains_consonant = true;
        } else {
            // Invalid word: contains non alpha-numeric value
            return false;
        }
    }

    // Evaluate
    if (contains_vowel && contains_consonant) return true;
    else return false;
}

int main(){
    char* word = "hello";

    bool out = isValid(word);

    printf("Output: %d\n", out);

    return out;
}