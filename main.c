#include "header.h"

int main(void)
{ 
	int choice = 0, play_game = 0;
	do
	{
		do
		{
			printf("\n Choose an option by entering a number:\n\n 1. Display the rules of the game\n 2. Start game\n 3. Exit\n");
			scanf("%d", &choice);
		} while ((choice != 1) && (choice != 2) && (choice != 3));

		switch (choice)
		{
		case 1: //print game rules
			print_rules(); 
			break;
		case 2:
			run_app();
			break;
		case 3:
			play_game = 0;
			break;
		default:
			printf(" Please select a valid option\n");
		}
	} while ((choice != 2) && (choice != 3));
	system("cls");
	return 0;
}
