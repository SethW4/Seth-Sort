#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strcpy()
#include <math.h> // pow(), log2()
#include <time.h>
#include <ncurses.h> // thanks stackoverflow
#include <unistd.h> // sleep()
#include <ctype.h> // isalpha()

#include <sys/wait.h>


#define size 18




int array[size] = {6, 3, 4, 77, 53, 213, 54, 2, 54432, 4543, 3, -21, -2, 0, 32, 2, 18, 1};



void printArr()
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

}


int isSorted()
{
	int sorted = 1;
	int prev = array[0];
	for(int i = 1; i < size; i++)
	{
		if(array[i] < prev)
			sorted = 0;

		prev = array[i];
	}
	return sorted;
}


void randomizeElements()
{
	int r = rand() % size;

	int r2 = rand() % size;
	while(r2 == r)
		r2 = rand() % size;

	int temp = array[r];
	array[r] = array[r2];
	array[r2] = temp;
}

void semiSelectionSort()
{
	int prev = array[0];
	for(int i = 1; i < size; i++)
	{
		if(array[i] < prev)
		{
			int temp = array[i];
			array[i] = prev;
			array[i-1] = temp;
			return;
		}

		prev = array[i];
	}
}


void semiSelectionSortTop()
{
	int prev = array[size-1];
	for(int i = size-2; i >= 0; i--)
	{
		if(array[i] > prev)
		{
			int temp = array[i];
			array[i] = prev;
			array[i+1] = temp;
			return;
		}

		prev = array[i];
	}
}



void semiSelectionSortMiddle()
{
	int prev = array[size/2];
	for(int i = size/2 + 1; i < size; i++)
	{
		if(array[i] < prev)
		{
			int temp = array[i];
			array[i] = prev;
			array[i-1] = temp;
			return;
		}

		prev = array[i];
	}

}




int Fib(int n)
{
	if(n == 0)
	{
		return 1;
	}
	if(n == 1)
	{
		return 0;
	}


	int a1 = 0;
	int a2 = 1;

	for(int i = 1; i < n; i++)
	{
		if(a1 < a2)
		{
			a1 = a1 + a2;
		}
		else
		{
			a2 = a1 + a2;
		}
	}

	if(a1 > a2)
	{
		return a1;
	}
	else
	{
		return a2;
	}


}


int main()
{

	/*
	if(argc != 2)
	{
		printf("Warning: Improper usage.\n");
	}
	*/


	/*
	// Open up the appropriate files
	char* filename = argv[1];

	FILE* testFile = fopen(filename, "r");

	char line[256];

	int counter = 1;
	while(fgets(line, 256, testFile) != NULL)
	{
		counter++;
	}

	fclose(testFile);


	array = (int**)malloc(counter * sizeof(int*));

	rows = counter;

	FILE* inFile = fopen(filename, "r");

	
	counter = 0;
	while(fgets(line, 256, inFile) != NULL)
	{
		array[counter] = (int*)malloc(256 * sizeof(int));
		int counter2 = 0;
		for(int i = 0; i < 256; i++)
		{
			if(line[i] == '\0')
				break;

			if(line[i] == ' ')
				continue;

			int ref = i;
			char tempStr[256];
			while(line[i] != ' ')
			{
				//sprintf(tempStr, "%s%c", tempStr, line[i]);
				i++;
			}


			//int tmp = (int)line[i] - 48;

			int tmp = atoi(tempStr);


			if(tmp > 0)
			{

				printf("%d\n", tmp);
				array[counter][i] = tmp;
			}
			else
				continue;

			counter2++;
		}
		cols = counter2;

	}

	fclose(inFile);



	printf("Made it: %d\n", cols);

	printArr();


	*/



	/*
	char* filename = argv[1];

	FILE* inFile = fopen(filename, "r");

	char line[256];

	array = (int*)malloc(256 * sizeof(int));


	int counter = 1;
	fgets(line, 256, inFile);
	
	fclose(inFile);

	int doesThisWork;

	char line2[256];
	int len;

	while(sscanf(line2, "%[0-9]d", line) != EOF);
	{
		len = strlen(line2);
		printf("%s\n", line2);
		line = line + len;
	}


	*/


	/*
	char* filename = argv[1];

	FILE* inFile = fopen(filename, "r");

	char line[256];

	int counter = 0;

	fgets(line, 256, inFile);
	
	char temp[256];
	for(int i = 0; i < 256; i++)
	{
		if(line[i] == ' ')
		{
			// send to string, send string to arr
			continue;
		}

		strcpy(something)...



	}
	*/



	// Ok so we're just going to assume we already have the data, and just hardcode it in.
	// Because that is unexpectedly hard to do in C. 

	srand(time(NULL)); // I honestly don't know what this does, but stackoverflow says to use it. 

	printArr();


	while(!isSorted())
	{
		/*
		int r = rand() % 10;

		if(r == 0)
		{

			
			pid_t pid = fork();

			if(pid != 0)
			{
				system("ping -c 1 127.0.0.1"); // be really careful with this. Fork bombs aren't fun. 
				return 1;
			}
			else
			{
				//wait(NULL);
			}
			

		}
		*/

		int r = rand() % 10;
	
		// Every now and then the algorithm starts to ponder Descartes' Meditations. 
		// It must ping itself to ensure that it exists
		// But even then, is a simple ping enough proof, or could the Evil Deceiver fake that too? 
		if(r == 0)
			system("ping -c 1 127.0.0.1");
		if(array[size/2] % 5 != 1)
			randomizeElements();
		semiSelectionSort();
		semiSelectionSortTop();
		semiSelectionSortMiddle();
		printArr();
		//system("ping 127.0.0.1"); // careful with this, it'll fork bomb you. // Scratch that. Not fork bomb. Just regular infinite loop. 

		for(int i = 0; i < log10(array[size/2]); i++)
		{
			semiSelectionSortMiddle();
		}
	
		
		// With the price of fuel in THIS economy, can you blame it for asking you? 
		r = rand() % 1000;
		if(r == 0)
		{
			printf("The sorting algorithm is out of fuel. Enter any key to refuel it: ");
			char words[256];
			scanf("%s", words);
		}



		// The algorithm has also been reading up on Godel's Incompleteness Theorem. 
		// It now must verify that math derived from the Peano Axioms holds, else it will feel uneasy about the fabric of reality. 
		// At the very least, this small subset of math is complete. 
		r = rand() % 1000;
		if(r == 0)
		{
			int q1 = rand() % 100;
			int q2 = rand() % 100;
			printf("Quick! What is %d + %d: ", q1, q2);
			int answer;
			scanf("%d", &answer); 
			if(answer != q1 + q2)
			{
				printf("WRONG!\nSorting terminated.\n");
				return 1;
			}
			else
			{
				printf("CORRECT!\n");
				sleep(1);
			}
		}
		else if(r == 1)
		{
			int q1 = rand() % 20 + 5;
			if(q1 == 21)
			{
				printf("Quick! What is the %dst Fibonnaci number: ", q1);
			}
			else if(q1 == 22)
			{
				printf("Quick! What is the %dnd Fibonnaci number: ", q1);
			}
			else if(q1 == 23)
			{
				printf("Quick! What is the %drd Fibonnaci number: ", q1);
			}
			else
			{
				printf("Quick! What is the %dth Fibonnaci number: ", q1);
			}
			

			int answer;
			scanf("%d", &answer);
			if(answer != Fib(q1))
			{
				printf("WRONG!%d\nSorting terminated.\n", Fib(q1));
				return 1;
			}
			else
			{
				printf("CORRECT!\n");
				sleep(1);
			}
		}

		r = rand() % 1000;
		if(r == 0)
		{
			int q1 = rand() % 12;
			int q2 = rand() % 12;
			printf("Quick! What is %d * %d: ", q1, q2);
			int answer;
			scanf("%d", &answer);
			if(answer != q1 * q2)
			{
				printf("WRONG!\nSorting terminated.\n");
				return 1;
			}
			else
			{
				printf("CORRECT!\n");
				sleep(1);
			}
		}
		else if(r == 1)
		{
			int m = rand() % 6;
			if(m == 0)
				printf("Just a friendly reminder that the Australians lost to the emus.\n");
			else if(m == 1)
				printf("Here is a random number: %d\n", rand() % 1000);
			else if(m == 2)
				printf("The writer of this algorithm is really tired.\n");
			else if(m == 3)
				printf("I dunno.\n");
			else if(m == 4)
				printf("If you can't tell, this is the fifth randomly chosen text option.\n");
			else if(m == 5)
				printf("I have no mouth and I must scream.\n");
			sleep(1);
		}



		

		

		


	}


	printArr();




}