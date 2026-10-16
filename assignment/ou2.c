#include <stdio.h>
/* Name: Iris Grini, CS username: tfy26igi
Date for submission: 16.10.2026 v1.0
This program is a way to calculate judges score in a competition 
AI comment: I used AI to learn how to use pointers and how to find out how to caclulate
my average score without including the highest and lowest score. I also used AI to 
find out what different bugs in the program came from.*/

/**
 * @brief Prints out the menu for the program
 * 
 * Input: Nothing
 * Output: Nothing
 */
void print_menu(void) {
	printf("Program information\n"
			"The program reads in the number of judges and the score from each judge.\n"
			"Then it calculates the average score without regard to the lowest and\n"
			"highest judge score. Finally it prints the results (the highest, the\n"
			"lowest and the final average score).\n\n");
}

/**
 * @brief User fills out number of judges
 * 
 * Inpout: Nothing
 * Output: judge = number of judges
 */
int number_of_judges (void){
	int judge;
	do {
		printf("Number of judges (min 3 and max 10 judges)? ");
		scanf("%d", &judge);
	} while (judge>10 || judge <3);
	printf("\n");
	return judge;
}

/**
 * @brief User fills out scores from the judges
 * 
 * Input: judge = number of judges
 * Output: score[] = array of scores
 */
void scan_score(int judge, double score[]){
	for(int i=0; i<judge; i++){
        printf("Score from judge %d? ", i+1);
        scanf("%lf", &score[i]);
	}
	printf("\n");
}

/**
 * @brief Prints scoring from judges
 * 
 * Input: judge = number of judges
 * 		score[] = array of scores
 * 
 * Output: Nothing
 */
void load_score(int judge, double score[]) {
	printf("Loaded scores:\n");
	for(int i=0; i<judge; i++){
        printf("Judge %d: %.1lf\n", i+1, score[i]);
	}
	printf("\n");
}

/**
 * @brief Calculates the highest, lowest and average score
 * 
 * Input: judge = number of judges
 * 			score[] = array of scores
 * 			average_score = pointer: average score, calculates without highest and lowest scores
 * 			highest_score = pointer:  highest score
 * 			lowest_score = pointer: lowest score
 * 
 * Output: Uppdates all the pointers
 */
void calculate_score (double*average_score, int judge, double score[], double *lowest_score, double *highest_score){

	for(int i=1; i<judge;i++){
		if (score[i]>*highest_score){
			*highest_score=score[i];
		}
	}

	for(int i=1; i<judge;i++){
		if (score[i]<*lowest_score){
			*lowest_score=score[i];
		}
	}
	double sum=0;
	for(int i=0; i<judge;i++){
		sum+=score[i];
	}
	sum= sum-*highest_score-*lowest_score;
	*average_score=sum /(judge-2);
}

/**
 * @brief Prints out result
 * 
 * Input: highest_score = highest score
 * 			lowest_score = lowest score
 * 			average_score = average score
 * Output: none
 */
void print_result(double highest_score, double lowest_score, double average_score){
	printf("Final result:\n");
	printf("Highest judge score: %.1lf", highest_score);
	printf("\nLowest judge score: %.1lf", lowest_score);
	printf("\nFinal average score: %.1lf\n", average_score);
}

// Calls on the functions to run the program
int main (void) {
	
	print_menu(); 
	int judge = number_of_judges();
	double score[judge];
	scan_score(judge, score);
	load_score(judge, score);

	double highest_score= score[0];
	double lowest_score= score[0];
	double average_score;

	calculate_score(&average_score, judge, score, &lowest_score, &highest_score);
	print_result(highest_score, lowest_score, average_score);
	
	return 0;
}