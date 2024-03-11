/*Luc Gremillion
  March 31, 2023
  C Programming
  Rebecca Dewitt*/

/*
 10.12 (Packing Characters into an Integer)
 The left-shift operator can be used to pack 
 four character values into a four-byte 
 unsigned int variable. 
 This program inputs four characters from 
 the keyboard and passes them to function packCharacters.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

//Struct to store varaible 
//information to use in the file
struct bitsInfo
{
	//Define Variables
	char charArray[4];
	unsigned int packedBit;
};

//Function Prototypes
unsigned int packCharacters(struct bitsInfo Info);
void displayBits(struct bitsInfo Info);
void displayFinal(struct bitsInfo Info);

//Main function
int main(){
	//Define struct so we may use the variables
	struct bitsInfo Info;

	/*
	Using printf - Prompt to user, to enter "4 Characters" 
	four different chars will be inputed using 
	a scanf statementand will be added to the charArray in the Struct*/
	printf("Please enter 4 Characters: ");
	scanf("\n%c %c %c %c", &Info.charArray[0], &Info.charArray[1], &Info.charArray[2], &Info.charArray[3]);
	puts("");

	//Call to Fuctions
	displayBits(Info);
	Info.packedBit = packCharacters(Info);
	displayFinal(Info);

}/*packCharacters - packs a single bit using 4 different bits*/
unsigned int packCharacters(struct bitsInfo Info) {
	//Varaibel stores a copy of the packed bit
	unsigned int packed = 0;
	//For Loop packs a differnt bit into "packed" each loop
	for (size_t x = 0; x < sizeof(Info.charArray); x++) {
		packed = packed << 8;
		packed = packed | Info.charArray[x];
	}
	puts("");
	return packed;
}

/*displayBits - shows to the user what each char inputted look like as an int and a bit*/
void displayBits(struct bitsInfo Info) {
	//Stores the current postion in the bit we are looking for 
	//and is used for comparison
	unsigned int showBit = 1 << 31;

	//For loop to set through each part of charArray
	for (size_t t = 0; t < 4; t++) {
		//Define Variables
		unsigned int temp = Info.charArray[t];
		int size = sizeof(temp) * CHAR_BIT;
		//Using printf - Prompt user what each char is as an int and a bit
		printf("'%c' in bits as an unsigned int is:\n\t\t%5d = ",
			Info.charArray[t], temp);
		//for loop to display the bit using a putchar statment
		for (size_t x = 1; x <= size; x++) {
			putchar(temp & showBit ? '1' : '0');
			temp <<= 1;

			if (x % 8 == 0) {
				putchar(' ');
			}
		}
		puts("");
	}
}
 /*displayFinal - shows the user what the "packedBit" variable is as an int and a bit*/
void displayFinal(struct bitsInfo Info) {
	int size = sizeof(Info.packedBit) * CHAR_BIT;
	//Stores the current postion in the bit we are looking for 
	//and is used for comparison
	unsigned int showBit = 1 << 31;
	//Using printf - Prompt user what the packed char is as an int and a bit
	printf("'%c' '%c' '%c' and '%c' packed in an unsigned int is:\n\t%13d = ",
		Info.charArray[0], Info.charArray[1], Info.charArray[2], Info.charArray[3], Info.packedBit);
	//for loop to display the bit using a putchar statment
	for (size_t x = 1; x <= size; x++) {
		putchar(Info.packedBit & showBit ? '1' : '0');
		Info.packedBit <<= 1;

		if (x % 8 == 0) {
			putchar(' ');
		}
	}
}