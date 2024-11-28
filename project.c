#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEXT_LENGTH 256
#define NUM_ATTEMPTS 3  // Number of attempts to help users improve
#define AVG_WORD_LENGTH 5  // Average word length

const char *texts[] = {
    "The quick brown fox jumps over the lazy dog.",
    "Practice makes perfect.",
    "Learning to type fast is a valuable skill.",
    "Consistency is the key to improvement."
};
const int numTexts = sizeof(texts) / sizeof(texts[0]);

void calculateStats(char *originalText, char *userInput, int timeTaken) {
    int correctChars = 0;
    int i;

    // Calculate correct characters
    for (i = 0; i < strlen(originalText); i++) {
        if (originalText[i] == userInput[i]) {
            correctChars++;
        }
    }

    int totalChars = strlen(originalText);
    double accuracy = ((double)correctChars / totalChars) * 100;
    double wpm = ((double)correctChars / AVG_WORD_LENGTH) / ((double)timeTaken / 60);

    printf("\n--- Typing Statistics ---\n");
    printf("Time Taken: %d seconds\n", timeTaken);
    printf("Words Per Minute (WPM): %.2f\n", wpm);
    printf("Accuracy: %.2f%%\n", accuracy);

    // Give feedback to the user
    if (accuracy < 80) {
        printf("Keep practicing to improve your accuracy.\n");
    } else if (wpm < 30) {
        printf("Try to increase your speed.\n");
    } else {
        printf("Great job! Keep up the good work.\n");
    }
}

void typingTutor() {
    char userInput[MAX_TEXT_LENGTH];
    time_t startTime, endTime;
    int timeTaken;

    for (int attempt = 1; attempt <= NUM_ATTEMPTS; attempt++) {
        // Pick a random text
        srand(time(NULL));
        const char *originalText = texts[rand() % numTexts];

        printf("\n--- Attempt %d ---\n", attempt);
        printf("Type the following text:\n\n%s\n\n", originalText);

        // Get start time
        time(&startTime);

        // Get user input
        printf("Start typing: ");
        fgets(userInput, MAX_TEXT_LENGTH, stdin);

        // Get end time
        time(&endTime);

        // Calculate time taken
        timeTaken = (int)difftime(endTime, startTime);

        // Calculate and display statistics
        calculateStats((char *)originalText, userInput, timeTaken);

        // Offer encouragement to continue practicing
        if (attempt < NUM_ATTEMPTS) {
            printf("\nPractice and try again to improve your typing speed and accuracy!\n");
        }
    }
}

int main() {
    printf("Welcome to the Typing Tutor!\n\n");
    printf("This program will help you improve your typing speed and accuracy.\n");
    typingTutor();
    printf("\nThank you for using the Typing Tutor! Keep practicing!\n");
    return 0;
}