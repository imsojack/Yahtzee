#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <time.h>
#include <math.h>,
#include <stdlib.h>


/*
* Function: run_app()
* Date Created:
* Date Last Modified:
* Description: This function calls all the functions to play the game of yahtzee
* Input parameters: Dice array, points array, combinations array, player
* Returns:
* Preconditions:
* Postconditions:
*/
int run_app(void);

/*
* Function: print_rules()
* Date Created:
* Date Last Modified:
* Description: This function displays the rules of yahtzee
* Input parameters:
* Returns:
* Preconditions:
* Postconditions:
*/
void print_rules(void); 

/*
* Function: roll_dice()
* Date Created:
* Date Last Modified:
* Description: This function randomly generates 5 dice
* Input parameters: Dice array
* Returns:
* Preconditions:
* Postconditions:
*/
void roll_dice(int dice_values[5], int num_items);

/*
* Function: print_die()
* Date Created:
* Date Last Modified:
* Description: This function prints the 5 dice values
* Input parameters: Dice array
* Returns:
* Preconditions:
* Postconditions:
*/
void print_dice(int die[5], int size, int c_combos[13]);

/*
* Function: reroll()
* Date Created:
* Date Last Modified:
* Description: This function rerolls dice according to user input
* Input parameters: Dice array, player
* Returns:
* Preconditions:
* Postconditions:
*/
void reroll_dice(int die[5], int size, int c_combo[13], int player, int round);

/*
* Function: choose_combo()
* Date Created:
* Date Last Modified:
* Description: This function chooses a combination and checks if it was used before
* Input parameters: Dice array, player, combination selection
* Returns:
* Preconditions:
* Postconditions:
*/
void choose_combo(int die[5], int size, int c_combo[13], int scores[13], int player, int round);

/*
* Function: print_score()
* Date Created:
* Date Last Modified:
* Description: This function prints score for the current player
* Input parameters: Player, score
* Returns:
* Preconditions:
* Postconditions:
*/
void print_score(int scores[13], int player);

/*
* Function: print_combos()
* Date Created:
* Date Last Modified:
* Description: This function prints all the combinations and the ones that have been used
* Input parameters: Dice array, player, combinations
* Returns:
* Preconditions:
* Postconditions:
*/
void print_combos(int c_combos[13]);

/*
* Function: sum_of_ones()
* Date Created:
* Date Last Modified:
* Description: This function adds the 1s from the current dice together
* Input parameters: Dice array, points array, combinations array
* Returns:
* Preconditions:
* Postconditions:
*/
int sum_of_ones(int die[5], int c_combo[13], int points[13]);

/*
* Function: sum_of_twos()
* Date Created:
* Date Last Modified:
* Description: This function adds the 2s from the current dice together
* Input parameters: Dice array, points array, combinations array
* Returns:
* Preconditions:
* Postconditions:
*/
int sum_of_twos(int die[5], int c_combo[13], int points[13]);

/*
* Function: sum_of_threes()
* Date Created:
* Date Last Modified:
* Description: This function adds the 3s from the current dice together
* Input parameters: Dice array, points array, combinations array
* Returns:
* Preconditions:
* Postconditions:
*/
int sum_of_threes(int die[5], int c_combo[13], int points[13]);

/*
* Function: sum_of_fours()
* Date Created:
* Date Last Modified:
* Description: This function adds the 4s from the current dice together
* Input parameters: Dice array, points array, combinations array
* Returns:
* Preconditions:
* Postconditions:
*/
int sum_of_fours(int die[5], int c_combo[13], int points[13]);

/*
* Function: sum_of_fives()
* Date Created:
* Date Last Modified:
* Description: This function adds the 5s from the current dice together
* Input parameters: Dice array, points array, combinations array
* Returns:
* Preconditions:
* Postconditions:
*/
int sum_of_fives(int die[5], int c_combo[13], int points[13]);

/*
* Function: sum_of_sixes()
* Date Created:
* Date Last Modified:
* Description: This function adds the 6s from the current dice together
* Input parameters: Dice array, points array, combinations array
* Returns:
* Preconditions:
* Postconditions:
*/
int sum_of_sixes(int die[5], int c_combo[13], int points[13]);

/*
* Function: three_kind()
* Date Created:
* Date Last Modified:
* Description: This function checks if you have 3 of a kind and then add points
* Input parameters: Dice array, points array, combinations array
* Returns:
* Preconditions:
* Postconditions:
*/
int three_kind(int die[5], int c_combo[13], int points[13]);

/*
* Function: four_kind()
* Date Created:
* Date Last Modified:
* Description: This function checks if you have 4 of a kind and then add points
* Input parameters: Dice array, points array, combinations array
* Returns:
* Preconditions:
* Postconditions:
*/
int four_kind(int die[5], int c_combo[13], int points[13]);

/*
* Function: full_house()
* Date Created:
* Date Last Modified:
* Description: This function checks if you have a full house and then add points
* Input parameters: Dice array, points array, combinations array
* Returns:
* Preconditions:
* Postconditions:
*/
int full_house(int die[5], int c_combo[13], int points[13]);

/*
* Function: small_straight()
* Date Created:
* Date Last Modified:
* Description: This function checks if you have a small straight and then adds points
* Input parameters: Dice array, points array, combinations array
* Returns:
* Preconditions:
* Postconditions:
*/
int small_straight(int die[5], int c_combo[13], int points[13]);

/*
* Function: large_straight()
* Date Created:
* Date Last Modified:
* Description: This function checks if you have a large straight and then adds points
* Input parameters: Dice array, points array, combinations array
* Returns:
* Preconditions:
* Postconditions:
*/
int large_straight(int die[5], int c_combo[13], int points[13]);

/*
* Function: yahtzee()
* Date Created:
* Date Last Modified:
* Description: This function checks if you have yahtzee and then adds points
* Input parameters: Dice array, points array, combinations array
* Returns:
* Preconditions:
* Postconditions:
*/
int yahtzee(int die[5], int combo[13], int points[13]);

/*
* Function: chance()
* Date Created:
* Date Last Modified:
* Description: This function adds all you current dice together and gives points
* Input parameters: Dice array, points array, combinations array
* Returns:
* Preconditions:
* Postconditions:
*/
int chance(int die[5], int combo[13], int points[13]);

/*
* Function: end_game()
* Date Created:
* Date Last Modified:
* Description: This function displays total points, winner, and ends the game
* Input parameters: Points array
* Returns:
* Preconditions:
* Postconditions:
*/
void end_game(int p1_points[13], int p2_points[13]);
