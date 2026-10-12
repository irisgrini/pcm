#include <stdio.h>
/* Name: Iris Grini, CS username: tfy26igi
Date for submission: 07.10.2026 v1.0
This program is a way to calculate judges score in a competition 
AI comment: */

//Write out the information for the program
void menu(void) {
	printf("Program information\n");
	printf("The program reads in the number of judges and the score from each judge.\n"
"Then it calculates the average score without regard to the lowest and\n"
"highest judge score. Finally it prints the results (the highest, the\n"
"lowest and the final average score).\n\n");
}


/*Ask the user for the number of judges, this will repeat if the number is not between 3 and 10. 
This funktion returns the number of judges to main*/
int nr_judges (void){
	int judge;
	do {
		printf("Number of judges (min 3 and max 10 judges)? ");
		scanf("%d", &judge);
	} while (judge>10 || judge <3);
	return judge;
}

/*The user fills our the attained scores from the judges. The program will ask for scores as many times as there are judges.
this funktion will return the scores to main in an array*/
void score_from_judge (double score[], int judge) {
	double score[judge];
	int i=0;
	
	for (int i=0; i<judge; i++) {
		printf("Score from judge %d? ", i+1);
		scanf("%lf", &score[i]);
	}
}

//This funktion writes out the scores from each judge
void loaded_score (int judge, double score[]){
	printf("Loaded socres:\n");
	for (int i=0; i<judge; i++) {
		printf("Judge %d: %lf", i+1, score[i]);
	}
}

/*Räkna fram resultat- I steg 5 ska en funktion användas där högsta, lägsta och medelpoäng ''returneras'' via
 tre separata pekarparametrar. Detta krav på programmet kan verka godtyckligt, 
 men ett av de viktigaste målen med denna uppgift är att ni ska testas på er förståelse av pekarparametrar
  och hur man använder dessa på ett korrekt sätt.*/
int calculate (double score[], int judge){
	int judge = score[];
		for(int i; i<judge; i++) {
			if (score[]>judge){
				judge=score[i];
			}
		}
}

// Skriv ut resultat

int main (void) {
	menu(); 

	int judge= nr_judges();

	score_from_judge(&judge);
	//gör en pekare
	double score[judge];

	loaded_score(judge, score);

	//Here we calculate the higghest score with our calculate funktion
	printf("Final result");
	int result;
	result = calculate(score, judge);
	printf("Highest judge score: %.1lf", result);

	return 0;
}