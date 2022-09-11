#include <stdio.h>
#include <string.h>

// Problem description: https://cs50.harvard.edu/x/2022/psets/2/substitution/
// Test cases available at the link above
int main (void){

    // Function declarations -->
    // Checks whether the entered key is a valid one
    int is_key(char []);
    // Main logic - returns an individual character by encrypting
    char encrypt (char ,char []);

    // Read the key from the console -->
    char key [256];
    printf("Enter the key:");
    scanf("%s", &key);

    // Does the key fulfill specifications? -->
    // 1. Is the length equal to 26?
    // 2. Does it consist of only capital letters?

    int true_or_false = is_key(key);
    // if there is a valid key, continue! -->
      if (true_or_false) {
          // Read the plain text from the console -->
          char plain_text[256];
          printf("%s", "Plain text:");
          scanf("%s", &plain_text);

          // Create another array for encrypted text
          int len_p_txt = strlen(plain_text);
          // Add space for '\0' marker -->
          char enc_txt [len_p_txt + 1];

          // Encrypt every character in the plain text originally and copy them to the new array -->
          for (int i = 0; i < len_p_txt; ++i) {
              // Return encrypted version
              char enc_char = encrypt(plain_text[i], key);
              // Assign the encrypted version to the string
              enc_txt[i] = enc_char;}
          // Add marker to indicate the end of string!!! -->
          enc_txt[len_p_txt] = '\0';
          printf("%s:%s", "Ciphertext", enc_txt);
      } else printf("%s", "No valid key was entered");

}
// 0 stands for false; 1 stands for true
int is_key(char user_var []){
    // first condition -->
    int bool = strlen(user_var) == 26 ? 1 : 0;
    // second condition -->
    if (bool) {
        int len = strlen(user_var);
        for (int i = 0; i < len; ++i) {
           char curr = user_var[i];
           if (!(curr >= 'A' && curr <= 'Z')){
               bool = 0;
               break;
           }
        }
    }
    return bool;
}


// Main logic -->
char encrypt (char c, char key []){
    int is_ltr_lwr_or_cpt(char );
    // 0. Make sure c is not anything other than a letter
    // 1. Find whether c is a lowercase or capital letter
    int is_letter = is_ltr_lwr_or_cpt(c);
    // 1.1. Return without changing anything if it is no letter
    if (is_letter == -1) return c;
    // 2. Make it capital if not already
    else if (is_letter == 0) c -= 32;
    // 3. Find its place in the array by implementing 'position' = 'c' - 65
    c -= 65;
    // 4. Find the letter ('l' at p) at 'position' in an array (key)
    int position = (int) c;
    char enc_ch = key[position];
    // 5. If c was originally a lowercase return 'l' + 32; else return l itself
    if (is_letter) return enc_ch;
    else return enc_ch + 32;
}


// -1 means --> c is no letter; 0 means --> it is a lowercase letter;
//  1 means --> it is a capital letter
int is_ltr_lwr_or_cpt(char c){
    if(c >= 'A' && c <= 'Z') return 1;
    else if (c >= 'a' && c <= 'z') return 0;
    else return -1;
}


