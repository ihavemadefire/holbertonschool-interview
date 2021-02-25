#include "slide_line.h"

/**
 * slide_line - slides the line
 * @line: line
 * @size: size of the line
 * @direction: direction
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
    int line_size = size;

    /*While reading this code, sing the electric slide to yourself*/
    /* Now slide to the left */
    /* Now merge to thr Right */

    if (line == NULL)
        return (0);

    if (direction == SLIDE_LEFT)
    {
        /*Slide, merge, slide*/
        slide_to_the_left(line, line_size);
        merge_to_the_left(line, line_size);
        slide_to_the_left(line, line_size);
        return (1);

    }
    if (direction == SLIDE_RIGHT)
    {
        /*Slide, merge, slide*/
        slide_to_the_right(line, line_size);
        merge_to_the_right(line, line_size);
        slide_to_the_right(line, line_size);
        return (1);
    }
    return (0);
}

/**
  * slide_to_the_left - now slide to the left
  * @line: line
  * @size: size of line
  */
void slide_to_the_left(int *line, int size)
{
    int i, j;

	for (i = 0; i < size - 1; i++)
	{
		if (line[i] == 0)
		{
			j = i + 1;
			while (line[j] == 0 && j < size - 1)
			{
				j += 1;
			}
            /* flip the indices to move left */
			line[i] = line[j];
			line[j] = 0;
		}
	}
}

/**
  * merge_to_the_left - now merge to the left
  * @line: line
  * @size: size of line
  */
void merge_to_the_left(int *line, int size)
{
    int i;

	for (i = 0; i < size - 1; i++)
	{
		if (line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
		}
	}
}

/**
  * slide_to_the_right - now shift to the right 
  * @line: line
  * @size: size
  */
void slide_to_the_right(int *line, int size)
{
    int i, j;

	for (i = size - 1; i > 0; i--)
	{
		if (line[i] == 0)
		{
			j = i - 1;
			while (line[j] == 0 && j > 0)
			{
				j -= 1;
			}
            /* flip the indices to move right */
			line[i] = line[j];
			line[j] = 0;
		}
	}
}

/**
  * merge_to_the_right - now merge to the right...two times! (Not really, just once)
  * @line: line
  * @size: size
  */
void merge_to_the_right(int *line, int size)
{
    int i;

	for (i = size -1; i > 0; i--)
	{
		if (line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
		}
	}
}