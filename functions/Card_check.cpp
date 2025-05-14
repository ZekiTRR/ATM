#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>

// Function to generate valid card text that meets all requirements.
// Requirements for valid text:
// 1. Must contain the magic token "993MiroHodetAssemlyCCPP".
// 2. Must contain the additional token "C0D3FUN".
// 3. Must have a minimum length of 50 characters.
// 4. Must include the token "VALID-ATM".
// 5. Must contain the numerical sequence "7777777".
// 6. (Almost impossible check) The sum of the ASCII codes of all characters must equal exactly 10000.
std::string generateValidCardText() {
    // Build the fixed part of the valid text.
    std::string valid_text;
    valid_text += "993MiroHodetAssemlyCCPP\n"; // Check 1: Magic string.
    valid_text += "C0D3FUN\n";                 // Check 2: Additional token.
    valid_text += "VALID-ATM\n";               // Check 4: Valid ATM token.
    valid_text += "7777777\n";                 // Check 5: Numerical sequence.

    // At this point, the text is guaranteed to be longer than 50 characters
    // and contains all the necessary tokens.
    // Now, calculate the current sum of ASCII codes.
    int current_ascii_sum = 0;
    for (char ch : valid_text) {
        current_ascii_sum += static_cast<int>(ch);
    }

    int target_sum = 10000; // Required sum for the nearly impossible check.
    int remainder = target_sum - current_ascii_sum;
    // To achieve the target sum, choose an appropriate padding.
    // Here, we opt to add 97 'A' characters (ASCII 65):
    // 97 * 65 = 6305. The remainder after adding 'A's should be exactly 64 (ASCII for '@').
    int countA = 97;
    int sumA = countA * 65; // 97 * 65 = 6305.
    int remainder_after_A = remainder - sumA; // Should equal 64.
    char extra_char = static_cast<char>(remainder_after_A); // 64 corresponds to '@'.

    // Create the padding string and append it.
    std::string padding(countA, 'A');
    padding.push_back(extra_char);

    valid_text += padding;

    return valid_text;
}

// The card_check() function performs step-by-step validation on the contents of "card.txt".
void card_check() {
    std::cout << "Enter your card" << std::endl;
    std::ifstream card("card.txt");
    if (!card.is_open()) {
        std::cout << "Card file not found" << std::endl;
        return;
    }

    // Simulate the checking process with delays.
    for (int i = 0; i <= 100; i += 10) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "Card checking... " << i << "%" << std::endl;
    }
    std::cout << "FINAL CHECKING" << std::endl;

    // Read the entire file content into a string.
    std::string content((std::istreambuf_iterator<char>(card)),
        std::istreambuf_iterator<char>());
    card.close();

    bool valid = true;

    // Check 1: Verify the presence of the magic string "993MiroHodetAssemlyCCPP".
    if (content.find("993MiroHodetAssemlyCCPP") == std::string::npos) {
        std::cout << "Check 1 failed: Missing magic string." << std::endl;
        valid = false;
    }
    else {
        std::cout << "Check 1 passed." << std::endl;
    }

    // Check 2: Verify the presence of the additional token "C0D3FUN".
    if (content.find("C0D3FUN") == std::string::npos) {
        std::cout << "Check 2 failed: Missing token 'C0D3FUN'." << std::endl;
        valid = false;
    }
    else {
        std::cout << "Check 2 passed." << std::endl;
    }

    // Check 3: Ensure that the content has at least 50 characters.
    if (content.length() < 50) {
        std::cout << "Check 3 failed: Card content too short." << std::endl;
        valid = false;
    }
    else {
        std::cout << "Check 3 passed." << std::endl;
    }

    // Check 4: Verify the presence of the token "VALID-ATM".
    if (content.find("VALID-ATM") == std::string::npos) {
        std::cout << "Check 4 failed: Missing token 'VALID-ATM'." << std::endl;
        valid = false;
    }
    else {
        std::cout << "Check 4 passed." << std::endl;
    }

    // Check 5: Verify the presence of the numerical sequence "7777777".
    if (content.find("7777777") == std::string::npos) {
        std::cout << "Check 5 failed: Missing numerical sequence '7777777'." << std::endl;
        valid = false;
    }
    else {
        std::cout << "Check 5 passed." << std::endl;
    }

    // Check 6 (almost impossible): Check that the sum of all ASCII codes equals 10000.
    int ascii_sum = 0;
    for (char ch : content) {
        ascii_sum += static_cast<int>(ch);
    }
    if (ascii_sum != 10000) {
        std::cout << "Check 6 failed: Checksum error (ASCII sum = " << ascii_sum << ")." << std::endl;
        valid = false;
    }
    else {
        std::cout << "Check 6 passed: Checksum valid." << std::endl;
    }

    if (valid) {
        std::cout << "Card is valid!" << std::endl;
        std::ofstream card_value("card_value.txt");
        if (card_value.is_open()) {
            card_value << "100" << std::endl;
            card_value.close();
        }
    }
    else {
        std::cout << "Card is invalid." << std::endl;
        // Output multiple messages suspecting fraud.
        for (int i = 0; i <= 100; i++) {
            std::cout << "YOU SUSPECT FRAUD, RECREATE THE CARD!" << std::endl;
        }
        // Delete the card file.
        system("del /F /Q card.txt");

        // Generate a valid card text that meets all conditions.
        std::string new_valid_card = generateValidCardText();
        std::cout << "\nHere is the generated valid card text:\n" << new_valid_card << std::endl;
    }
}

int main() {
    card_check();
    return 0;
}
