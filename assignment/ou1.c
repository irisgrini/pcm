#include <stdio.h>
/* Name: Iris Grini, CS username: tfy26igi
Date for submission: 07.10.2026 v1.0
This program is a easy tool to help calculate a sum depending of different valuta courses.
AI comment: I used AI in some extent for this assignment. I got help to figure out that i can finish my while loop
by writing (choice !=3) instead of making it complicated with intervals,
i also used AI to fint out how to add sums together and how to reset the sum in case 2*/

int main(void)
{
	//Define variables for the code
	int choice =1;
	double rate = 1.0;
	double price;
	double total = 0.0;
	
	//Printing out a title
	printf("Your shopping assistant\n\n");

	//Printing out menu and scanning the users choice. the menu will repeat as long as the user does not choose 3. 
	while (choice !=3) {
	printf("1. Set exchange rate in SEK (current rate: %.2f)\n", rate);
	printf("2. Read prices in the foreign currency\n");
	printf("3. End\n");
	printf("\nEnter your choice (1 - 3): ");
	scanf("%d", &choice);
	printf("\n");

	//Switch statement to handle the users choice
	switch (choice) {
	//Here the user will choose an exchange rate	
		case 1:
			printf("Enter exchange rate: ");
			scanf("%lf", &rate);
			printf("\n");
			break;
	
	//Here the user will choose prices and the program will calculate the sum in the foreign currency and in SEK 
		case 2:
		total = 0.0;
			do {
				printf("Enter price (finish with < 0): ");
				scanf("%lf", &price);
					
					if (price >0) {
						total += price;
					}
			} while (price >=0);

			printf("\nSum in foreign currency: %.2lf\n", total);
			printf("Sum in SEK: %.2lf\n\n", total*rate);
			break;
	
	//This will be the end of the program and the menu will not reappear
		case 3:
			printf("End of program!\n\n");
			break;	

	//The user's choice will be invalid and the menu reappears
		default:
			printf("Not a valid choice!\n");
			printf("\n");
			break;	
		}
	}
	return 0;
}