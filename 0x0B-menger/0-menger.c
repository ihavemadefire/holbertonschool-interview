#include "menger.h"

/**
 * menger - implementaion of a 2d menger square
 * @level: passed level
 */
void menger(int level)
{
	int i, j, k;
	int size = pow(3, level);
	char print;

	if (level == 0)
		printf("#\n");
	if (level == 1)
		printf("###\n# #\n###\n");
	if (level > 1)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				print = '#';
				for (k = 1; k < size; k *= 3)
				{
					if ((i / k) % 3 == 1 && (j / k) % 3 == 1)
						print = ' ';
				}
				printf("%c", print);
			}
			printf("\n");
		}
	}
}
