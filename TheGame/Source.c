#include <stdio.h>
#include <string.h>
#include <time.h>

#pragma warning(disable:4996)
typedef enum { false, true } bool;

const char* colors[] = {
	"red","green","black","yellow","brown","purple","orange","white","grey","cyan","olive","navy","lavender","mint"
};

int numOfGuesses;
char mask[10];

char* chooseRandomColor() {
	srand(time(NULL));
	int i = rand() % (sizeof(colors) / sizeof(colors[0]));
	return colors[i];
}
   
void makeMask(char* color) {
	// Prompts user to enter the right color
	puts("Try to guess the right color: ^_^");

	// Make mask            
	for (int i = 0; i < strlen(color); i++) {
		mask[i] = '_';
	}

	// End mask with null terminator
	mask[strlen(color)] = '\0';
}

void encryptRandomColor(char* color) {
	for (int i = 0; i < strlen(color); i++) {
		printf("%s", "- ");
	}
	puts("");
}

int specifyNumberOfAttempts(char* color) {
	numOfGuesses = strlen(color) / 2 + 1;
	printf("You have %d guesses\n", numOfGuesses );
	return numOfGuesses;
}

void checkLetters(char c, char* color) {
	bool flag = false;

	// fill mask with right characters
	for (int i = 0; i < strlen(color); i++) {
		if (c == color[i]) {
			mask[i] = c;
			flag = true;
		}
	}

	// Check wrong attempts
	if (flag) {
		numOfGuesses--;
		printf("%s\n %d %s\n", "wrong attempt You just have", numOfGuesses, " attempts");
		flag = false;
	}
		// prints color
	for (int i = 0; i < strlen(color); i++)
	{
		printf("%c ", mask[i]);
	}
	puts("");

}

void enterLetters(char* color) {

	char c;
	bool check = false;
	int len = 0;

	puts("Enter your letters");
	while (numOfGuesses != 0) {
		// Enter character
		scanf(" %c", &c);									// A space before the %c option for consuming the new line character
		checkLetters(c, color);

		//  check winner or loser
		for (int i = 0; i < strlen(color); i++)
		{
			if (mask[i] == color[i] ) {
				check = true;
				len++;										// To indicate end of word
			}
		}

		// check winning
		if (check == true && len == strlen(color) ) {                    
			puts("\n************************* Winner *************************");
			break;
	    }
		len = 0;
	} 

	// check loss
	if (numOfGuesses == 0) {
		printf("%s %s", "\n************************* Loser *************************\n The color was: ",color);
	}
}

int main() {
	char* color = chooseRandomColor();
	makeMask(color);
	encryptRandomColor(color);                  
	specifyNumberOfAttempts(color);
	enterLetters(color);
	return 0;
}
// The most amazing project I have seen literally for months   ~ZA
