#include<stdio.h>
#include<conio.h>
#include<math.h>

/*
	This just4fun algorithm multiplies 2 positiv/integer numbers.
	This algorithm comes from the Egyptians and is called Ancient Egyptian multiplication.
	For more Information about Ancient Egyptian multiplication: 
	http://en.wikipedia.org/wiki/Ancient_Egyptian_multiplication
	It's a warm up for "An algorithm a day, keeps the idiot away :)", because of a long break.
	(I program it without longer optimization)
	(You can optimize this program, if you want :))
*/

void my_swap(int * p1, int * p2)
{
	int temp;
	temp = *p1;	
	*p1 = *p2;	
	*p2 = temp;	
}

int find_max_multiple2(int num) {
	int max = 1;
	while(max < num) {
		max = max << 1;
		if(max > num) {
			max = max >> 1;
			break;
		}
	}
	return max;
}


int egyptian_multiplication(int factor1, int factor2) {
	int total_sum = 0;
	int multiple;
	//Find fastes way:
	if(factor2 < factor1) {
		my_swap(&factor1, &factor2);
	}
	while(factor1 > 0 ) {		
		multiple = find_max_multiple2(factor1);	//Get the max multiple of 2
		total_sum += multiple * factor2;		//Get the total result with a addition from all (multiple*factor2)
		factor1 -= multiple;					//Decrease factor1
	}
	return total_sum;	//Return the total result
}

int main(void) {
	int product = egyptian_multiplication(28, 3);
	printf("%i", product);
	getch();
	return 0;
}