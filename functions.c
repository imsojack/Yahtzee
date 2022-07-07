/*
* Programmer: Jack Balster
* Class: CptS 121; Lab Section 4
* Programming Assignment: Programming Assignment 5
* Date: 3/8/2022
* Description: This program contains functions that allows two users to play a game of yahtzee
* 
*/


#include "header.h"

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

void print_rules(void)
{
	system("cls");

	printf("\n Rules of Yahtzee:\n\n");
	printf(" The scorecard used for Yahtzee is composed of two sections.\n");
	printf(" A upper section and a lower section. A total of thirteen boxes or thirteen\n");
	printf(" scoring combinations are divided amongst the sections. The upper section\n");
	printf(" consists of boxes that are scored by summing the value of the dice matching\n");
	printf(" the faces of the box. If a player rolls four 3's, then the score placed in\n");
	printf(" the 3's box is the sum of the dice which is 12. Once a player has chosen to\n");
	printf(" score a box, it may not be changed and the combination is no longer in play\n");
	printf(" for future rounds. If the sum of the scores in the upper section is greater\n");
	printf(" than or equal to 63, then 35 more points are added to the players overall\n");
	printf(" score as a bonus. The lower section contains a number of poker like combinations.\n");
}


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
void roll_dice(int die[5], int size)
{
	int position = 0;

	printf(" Press any key to roll the dice...\n");
	system("pause > nul");
	for (position = 0; position < size; position++)
	{
		die[position] = rand() % 6 + 1;
	}
}


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
void print_dice(int die[5], int size, int combos[13])
{
	int position = 0;
	int space = 1;

	while (space <= 2)
	{		
		switch (space)
		{
		case 1:
			
			while (position < size)
			{			
				position++;
			}
			printf("\n");
			space++;
			position = 0;
			break;
		case 2:
			while (position < size)
			{
				switch (die[position])
				{
				case 1:
					printf(" Die: 1	\n");
					break;
				case 2:
					printf(" Die: 2	\n");
					break;
				case 3:
					printf(" Die: 3	\n");
					break;
				case 4:
					printf(" Die: 4	\n");
					break;
				case 5:
					printf(" Die: 5	\n");
					break;
				case 6:
					printf(" Die: 6	\n");
					break;
				}
				position++;
			}
			printf("\n");
			space++;
			position = 0;
			break;
		}
	}
	print_combos(combos);
}


/*
* Function: reroll_dice()
* Date Created:
* Date Last Modified:
* Description: This function rerolls dice according to user input
* Input parameters: Dice array, player
* Returns:
* Preconditions:
* Postconditions:
*/
void reroll_dice(int die[5], int size, int combo[13], int player, int round)
{
	int number = 0;
	int position = 0;
	int reroll = 0;
	int die_reroll = 0;
	
	for (position = 0; position < 2; position++)
	{
		do
		{
			printf(" How many dice would you like to reroll? If you don't want to reroll, enter 0: ");
			scanf("%d", &number);

		} while ((number != 1) && (number != 2) && (number != 3) && (number != 4) && (number != 5) && (number != 0));

		if (number != 0)
		{
			for (reroll = 0; reroll < number; reroll++)
			{
				do
				{
					printf(" Enter ONE die you want to reroll 1-5 (top to bottom): ");
					scanf("%d", &die_reroll);
					die[die_reroll - 1] = rand() % 6 + 1;
				} while ((die_reroll != 5) && (die_reroll != 1) && (die_reroll != 2) && (die_reroll != 3) && (die_reroll != 4));

			}
		}
		else
		{
			break;
		}
		system("cls");
		printf(" Player %d\n", player);
		printf(" Round %d\n\n", round);
		print_dice(die, 5, combo);
	}
}

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
void print_combos(int combo[13])
{

	if (combo[0] == 0)
	{
		printf(" 1. Sum of 1s\n");
	}
	else { printf(" (Already used)\n"); }

	if (combo[1] == 0)
	{
		printf(" 2. Sum of 2s\n");
	}
	else { printf(" (Already used)\n"); }

	if (combo[2] == 0)
	{
		printf(" 3. Sum of 3s\n");
	}
	else { printf(" (Already used)\n"); }

	if (combo[3] == 0)
	{
		printf(" 4. Sum of 4s\n");
	}
	else { printf(" (Already used)\n"); }

	if (combo[4] == 0)
	{
		printf(" 5. Sum of 5s\n");
	}
	else { printf(" (Already used)\n"); }

	if (combo[5] == 0)
	{
		printf(" 6. Sum of 6s\n");
	}
	else { printf(" (Already used)\n"); }

	if (combo[6] == 0)
	{
		printf(" 7. Three of a kind\n");
	}
	else { printf(" (Already used)\n"); }

	if (combo[7] == 0)
	{
		printf(" 8. Four of a kind\n");
	}
	else { printf(" (Already used)\n"); }

	if (combo[8] == 0)
	{
		printf(" 9. Full house\n");
	}
	else { printf(" (Already used)\n"); }

	if (combo[9] == 0)
	{
		printf(" 10. Small Straight\n");
	}
	else { printf(" (Already used)\n"); }

	if (combo[10] == 0)
	{
		printf(" 11. Large Straight\n");
	}
	else { printf(" (Already used)\n"); }

	if (combo[11] == 0)
	{
		printf(" 12. Yahtzee\n");
	}
	else { printf(" (Already used)\n"); }

	if (combo[12] == 0)
	{
		printf(" 13. Chance\n\n");
	}
	else { printf(" (Already used)\n\n"); }
}


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
void choose_combo(int die[5], int size, int combo[13], int scores[13], int player, int round)
{
	int choice = 0, valid_choice = 0;

	system("cls");
	printf(" Player %d\n", player);
	printf(" Round %d\n\n", round);
	print_dice(die, 5, combo);
	do
	{
		printf(" Enter the combination you want to use: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			valid_choice = sum_of_ones(die, combo, scores);
			break;
		case 2:
			valid_choice = sum_of_twos(die, combo, scores);
			break;
		case 3:
			valid_choice = sum_of_threes(die, combo, scores);
			break;
		case 4:
			valid_choice = sum_of_fours(die, combo, scores);
			break;
		case 5:
			valid_choice = sum_of_fives(die, combo, scores);
			break;
		case 6:
			valid_choice = sum_of_sixes(die, combo, scores);
			break;
		case 7:
			valid_choice = three_kind(die, combo, scores);
			break;
		case 8:
			valid_choice = four_kind(die, combo, scores);
			break;
		case 9:
			valid_choice = full_house(die, combo, scores);
			break;
		case 10:
			valid_choice = small_straight(die, combo, scores);
			break;
		case 11:
			valid_choice = large_straight(die, combo, scores);
			break;
		case 12:
			valid_choice = yahtzee(die, combo, scores);
			break;
		case 13:
			valid_choice = chance(die, combo, scores);
			break;
		default:
			printf(" Please enter a valid selection\n\n");
			break;
		}
	} while (!valid_choice);
}


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
void print_score(int score[13], int player)
{
	int sum = 0, position = 0;
	for (position = 0; position < 13; position++)
	{
		sum = score[position] + sum;
	}
	printf(" Player %d's score: %d\n", player, sum);
}


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
int sum_of_ones(int die[5], int combo[13], int points[13])
{
	int position = 0, sum = 0, value = 0;

	if (combo[0] == 0)
	{
		combo[0] = 1;
		value = 1;
		for (position = 0; position < 5; position++)
		{
			if (die[position] == 1)
			{
				sum = sum + 1;
			}
		}
		points[0] = sum;
	}
	return value;
}

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
int sum_of_twos(int die[5], int combo[13], int points[13])
{
	int position = 0, sum = 0, value = 0;

	if (combo[1] == 0)
	{
		combo[1] = 1;
		value = 1;
		for (position = 0; position < 5; position++)
		{
			if (die[position] == 2)
			{
				sum = sum + 1;
			}
		}
		points[1] = sum * 2;
	}
	return value;
}


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
int sum_of_threes(int die[5], int combo[13], int points[13])
{
	int position = 0, sum = 0, value = 0;

	if (combo[2] == 0)
	{
		combo[2] = 1;
		value = 1;
		for (position = 0; position < 5; position++)
		{
			if (die[position] == 3)
			{
				sum = sum + 1;
			}
		}
		points[2] = sum * 3;
	}
	return value;
}

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
int sum_of_fours(int die[5], int combo[13], int points[13])
{
	int position = 0, sum = 0, value = 0;

	if (combo[3] == 0)
	{
		combo[3] = 1;
		value = 1;
		for (position = 0; position < 5; position++)
		{
			if (die[position] == 4)
			{
				sum = sum + 1;
			}
		}
		points[3] = sum * 4;
	}
	return value;
}

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
int sum_of_fives(int die[5], int combo[13], int points[13])
{
	int position = 0, sum = 0, value = 0;

	if (combo[4] == 0)
	{
		combo[4] = 1;
		value = 1;
		for (position = 0; position < 5; position++)
		{
			if (die[position] == 5)
			{
				sum = sum + 1;
			}
		}
		points[4] = sum * 5;
	}
	return value;
}

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
int sum_of_sixes(int die[5], int combo[13], int points[13])
{
	int position = 0, sum = 0, value = 0;

	if (combo[5] == 0)
	{
		combo[5] = 1;
		value = 1;
		for (position = 0; position < 5; position++)
		{
			if (die[position] == 6)
			{
				sum = sum + 1;
			}
		}
		points[5] = sum * 6;
	}
	return value;
}

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
int three_kind(int die[5], int combo[13], int points[13])
{
	int number = 0, result = 0, sum = 0;

	if (combo[6] == 0)
	{		
		combo[6] = 1; 
		for (number = 1; number < 7; number++)
		{
			sum = 0;
			if (die[0] == number)
			{
				sum = sum + 1;
			}
			if (die[1] == number)
			{
				sum = sum + 1;
			}
			if (die[2] == number)
			{
				sum = sum + 1;
			}
			if (die[3] == number)
			{
				sum = sum + 1;
			}
			if (die[4] == number)
			{
				sum = sum + 1;
			}
			if (sum >= 3)
			{
				points[6] = die[0] + die[1] + die[2] + die[3] + die[4];
				break;
			}
		}
		result = 1; 
	}
	return result;
}

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
int four_kind(int die[5], int combo[13], int points[13])
{
	int number = 0, result = 0, sum = 0;
	
	if (combo[7] == 0)
	{		
		combo[7] = 1;  
		for (number = 1; number < 7; number++)
		{
			sum = 0;
			if (die[0] == number)
			{
				sum = sum + 1;
			}
			if (die[1] == number)
			{
				sum = sum + 1;
			}
			if (die[2] == number)
			{
				sum = sum + 1;
			}
			if (die[3] == number)
			{
				sum = sum + 1;
			}
			if (die[4] == number)
			{
				sum = sum + 1;
			}
			if (sum >= 4)
			{
				points[7] = die[0] + die[1] + die[2] + die[3] + die[4];
				break;
			}
		}
		result = 1;
	}
	return result;
}

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
int full_house(int die[5], int combo[13], int points[13])
{
	int number = 0, result = 0, sum1 = 0, sum2 = 0, three = 0, two = 0, number2 = 0;
	
	if (combo[8] == 0)
	{
		combo[8] = 1; 
		result = 1;
		for (number = 1; number < 7; number++)
		{
			sum1 = 0;
			if (die[0] == number)
			{
				sum1 = sum1 + 1;
			}
			if (die[1] == number)
			{
				sum1 = sum1 + 1;
			}
			if (die[2] == number)
			{
				sum1 = sum1 + 1;
			}
			if (die[3] == number)
			{
				sum1 = sum1 + 1;
			}
			if (die[4] == number)
			{
				sum1 = sum1 + 1;
			}
			if (sum1 == 3)
			{
				break;
			}
		}
	
		for (number2 = 1; number2 < 7; number2++)
		{
			sum2 = 0;
			if (die[0] == number2)
			{
				sum2 = sum2 + 1;
			}
			if (die[1] == number2)
			{
				sum2 = sum2 + 1;
			}
			if (die[2] == number2)
			{
				sum2 = sum2 + 1;
			}
			if (die[3] == number2)
			{
				sum2 = sum2 + 1;
			}
			if (die[4] == number2)
			{
				sum2 = sum2 + 1;
			}
			if (number2 == number)
			{
				sum2 = 0;
			}
			if (sum2 == 2)
			{
				if (sum2 + sum1 == 5)
				{
					points[8] = 25;
				}
				break;
			}
		}
	}
	return result;
}

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
int small_straight(int die[5], int combo[13], int points[13])
{
	int position = 0, temp = 0, passes = 0, sum = 0, result = 0;

	if (combo[9] == 0)
	{
		result = 1;
		combo[9] = 1;
		for (passes = 1; passes < 5; passes++)
		{
			for (position = 0; position < 5 - passes; position++)
			{
				if (die[position] > die[position + 1])
				{
					temp = die[position];
					die[position] = die[position + 1];
					die[position + 1] = temp;
				}
			}
		}
		for (position = 4; position > 0; position--)
		{
			if (die[position] == die[position - 1] + 1)
			{
				sum++;
			}
		}
		if (sum >= 3)
		{
			points[9] = 30;
		}
	}
	return result;
}

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
int large_straight(int die[5], int combo[13], int points[13])
{
	int position = 0, temp = 0, passes = 0, sum = 0, result = 0;

	if (combo[10] == 0)
	{
		result = 1;
		combo[10] = 1;
		for (passes = 1; passes < 5; passes++)
		{
			for (position = 0; position < 5 - passes; position++)
			{
				if (die[position] > die[position + 1])
				{// swap
					temp = die[position]; 
					die[position] = die[position + 1];
					die[position + 1] = temp;
				}
			}
		}
		for (position = 4; position > 0; position--)
		{
			if (die[position] == die[position - 1] + 1)
			{
				sum++;
			}
		}
		if (sum >= 4)
		{
			points[10] = 30;
		}
	}
	return result;
}

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
int yahtzee(int die[5], int combo[13], int points[13])
{
	int number = 0, result = 0, sum = 0;

	if (combo[11] == 0)
	{
		combo[11] = 1; 

		for (number = 0; number < 5; number++)
		{
			sum = 0;
			if (die[0] == number)
			{
				sum = sum + 1;
			}
			if (die[1] == number)
			{
				sum = sum + 1;
			}
			if (die[2] == number)
			{
				sum = sum + 1;
			}
			if (die[3] == number)
			{
				sum = sum + 1;
			}
			if (die[4] == number)
			{
				sum = sum + 1;
			}
			if (sum == 5)
			{
				points[11] = 50;
			}
		}
		result = 1;
	}
	return result;
}

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
int chance(int die[5], int combo[13], int points[13])
{
	int result = 0, sum = 0;

	if (combo[12] == 0)
	{
		combo[12] = 1;
		result = 1;
		sum = die[0] + die[1] + die[2] + die[3] + die[4];

		points[12] = sum;
	}

	return result;
}

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
void end_game(int points1[13], int points2[13])
{
	int sum1 = 0, sum2 = 0, winner = 0, position = 0;

	printf("\n Game over\n");
	for (position = 0; position < 13; position++)
	{
		sum1 = points1[position] + sum1;
	}
	for (position = 0; position < 13; position++)
	{
		sum2 = points2[position] + sum2;
	}
	if ((points1[0] + points1[1] + points1[2] + points1[3] + points1[4] + points1[5]) > 63)
	{
		sum1 = sum1 + 35;
	}
	if ((points2[0] + points2[1] + points2[2] + points2[3] + points2[4] + points1[5]) > 63)
	{
		sum2 = sum2 + 35;
	}
	if (sum2 > sum1)
	{
		winner = 2;
	}
	if (sum1 > sum2)
	{
		winner = 1;
	}
	if (sum1 == sum2)
	{
		winner = -1;
	}

	switch (winner)
	{
	case 1:
		printf(" Player 1 wins!!!\n Player 1 had %d points\n Player 2 had %d points\n\n", sum1, sum2);
		break;
	case 2:
		printf(" Player 2 wins!!! \n Player 2 had %d points\n Player 1 had %d points\n\n", sum2, sum1);
		break;
	case -1:
		printf(" It's a tie! Both players have %d points\n\n", sum1);
		break;
	default:
		printf(" Error smh you broke my game");
	}
	system("pause");
	system("cls");

}

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
int run_app(void)
{
	int die[5] = { 0 }, score1[13] = { 0 }, score2[13] = { 0 },
		combo1[13] = { 0 }, combo2[13] = { 0 },
		player = 1, go = 0;
		srand((unsigned int)time(NULL));

	while (go < 13)
	{
		system("cls");
		printf(" Player 1\n");
		printf(" Round %d\n\n", go);
		roll_dice(die, 5);
		print_dice(die, 5, combo1);
		reroll_dice(die, 5, combo1, 1, go);
		choose_combo(die, 5, combo1, score1, 1, go);

		system("cls");
		printf(" Player 1\n");
		printf(" Round %d\n\n", go);
		print_score(score1, 1);
		printf("\n Press any key to switch to player 2...");
		system("pause > nul");
		system("cls");

		system("cls");
		printf(" Player 2\n");
		printf(" Round %d\n\n", go);
		roll_dice(die, 5);
		print_dice(die, 5, combo2);
		reroll_dice(die, 5, combo2, 2, go);
		choose_combo(die, 5, combo2, score2, 2, go);

		system("cls");
		printf(" Player 2\n");
		printf(" Round %d\n\n", go);
		print_score(score2, 2);

		system("pause\n");
		system("cls");
		go++;
	}
	end_game(score1, score2);
	printf(" \n\n Bye Bye!");
	return 0;
}
