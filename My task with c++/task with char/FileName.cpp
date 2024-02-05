#include<iostream>
#include<cstring>

using namespace std;

int getWordCount(char* sentence, char* word) {
    int sentenceLength = strlen(sentence);
    int wordLength = strlen(word);
    int tempIndex = 0;
    int currentPosition;
    int wordCount = 0;
    for (int i = 0; i < sentenceLength; i++) {
        tempIndex = i;
        for (int j = 0; j < wordLength; j++)
        {
            if (sentence[i] == word[j])
                i++;
        }
        currentPosition = i - tempIndex;
        if (currentPosition == wordLength)
            wordCount++;
        i = tempIndex;
    }

    return wordCount;

}
int main() {
    char str[100], word[20];
    int i, j, ls, lw, temp, countW = 0, chk;
    printf("Enter the String: ");
    cin.getline(str, sizeof(str));
    printf("Enter a Word: ");
    cin.getline(word, sizeof(word));
    cout << "Word count = " << getWordCount(str, word) << endl;
    return 0;
}