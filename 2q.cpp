#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to apply monoalphabetic substitution cipher
void monoalphabeticCipher(char text[], char cipherMap[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) { // Check if the character is a letter
            char offset = islower(text[i]) ? 'a' : 'A'; // Determine case
            text[i] = cipherMap[text[i] - offset]; // Substitute using cipherMap
        }
    }
}

int main() {
    char text[100]; // Input text buffer
    char cipherMap[26] = "QWERTYUIOPLKJHGFDSAZXCVBNM"; // Example cipher mapping

    printf("Enter plaintext: ");
    if (fgets(text, sizeof(text), stdin) != NULL) {
        // Remove newline character added by fgets
        size_t len = strlen(text);
        if (len > 0 && text[len - 1] == '\n') {
            text[len - 1] = '\0';
        }
        monoalphabeticCipher(text, cipherMap); // Apply cipher
        printf("Ciphertext: %s\n", text); // Output the ciphertext
    } else {
        printf("Error reading input.\n"); // Handle input error
    }

    return 0;
}
