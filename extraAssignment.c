/* Author: Dinel Anthony
* Student Number: 20189775
* Email: dinela@student.ubc.ca
* Date: June 2, 2021
* Purpose: To encode and decode Whatsapp messages. I made lab 4 a bit more complex because it seemed
* like a really fun assignment. I added extra features, like a loop for more conversions, and the ability
* to enter your own message to decode, or encode.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//Set the maximum amount of characters or numbers to decode/encode
#define MAX_SIZE 100

//Function prototypes
void decode(int encoded[], char decoded[]);
void encode(char decoded[], int encoded[]);

int main(void)
{
	int input[MAX_SIZE];
	int output[MAX_SIZE];
	int choice;
	int repeat = 1;

	while (repeat == 1)
	{

		//Prompts user to choose whether they would like to encode or decode a message
		printf("Please choose an option below:\n");
		printf("Option 1: Decode Set of Numbers\n");
		printf("Option 2: Encode Message\n");
		printf("Choice: ");
		scanf("%d", &choice);

		//Calls the decode function
		if (choice == 1)
		{
			decode(input, output);
		}

		//Calls the encode function
		else if (choice == 2)
		{
			encode(input, output);
		}

		//Loop for an invalid input
		else
		{
			printf("ERROR: Invalid input\n");
		}

		//Prompts the use with the option to compute another encryption/decryption
		printf("Would you like to try another encryption/decryption?\n");
		printf("Enter 1 for YES and 0 for NO: ");
		scanf("%d", &repeat);

		//Repeats the program if the user chooses yes, and ends if the user chooses no
		if (repeat == 1)
		{
			continue;
		}

		else
		{
			printf("Understandable, have a nice day.\n");
			return 0;
		}

	}
	return 0;
}

//Function to decode numbers into ASCII text
void decode(int encoded[], char decoded[])
{
	int counter;

	//Prompts user to input the decoded message
	printf("Please enter the numbers to decode. \n");
	printf("Remember that entering 0 will mark the end of the message: \n");

	for (counter = 0; counter < MAX_SIZE; counter++)
	{
		//Checks for user input and stores it as a character
		scanf("%d", &encoded[counter]);
		decoded[counter] = encoded[counter];

		//Ends the loop as soon as the message is over (entering 0)
		if (decoded[counter] == 0)
		{
			counter = MAX_SIZE;
		}

	}

	printf("This translates to:\n");

	//Prints each character of the newly decoded message
	for (counter = 0; counter < MAX_SIZE; counter++)
	{

		//Ends loop as soon as the message is over (entering 0)
		if (decoded[counter] == 0)
		{
			counter = MAX_SIZE;
		}

		printf("%c", decoded[counter]^42);
	}

	printf("\n\n");
}

//Function to encode ASCII text to numbers
void encode(char decoded[], int encoded[])
{
	int counter;

	//Prompts user to type the message to be encoded
	printf("Please enter the message to encode. \n");
	printf("Remember to type 0 to end the message:\n");

	for (counter = 0;counter < MAX_SIZE;counter++)
	{

		//Checks for user input and stores each value as a number
		scanf("%c", &decoded[counter]);
		encoded[counter] = decoded[counter];

		//Ends loop early if the ASCII text "0" is entered
		if (encoded[counter] == 48)
		{
			counter = MAX_SIZE;
		}

	}

	printf("This translates to:\n");

	//Prints each number of the new encoded message
	for (counter = 0;counter < MAX_SIZE;counter++)
	{

		printf("%d ", encoded[counter]^5);

		//Ends the loop when the ASCII text "0" is detected
		if (encoded[counter] == 48)
		{
			counter = MAX_SIZE;
		}
	}

	printf("\n\n");
}