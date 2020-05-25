/*Tyson M. Cruz
05/24/2020
CST221 - Operating Systems Concepts
Professor Michael Landreth*/

//Header Files
#include <stdio.h>
#include <stdlib.h>

//Global Variable declarations
int a[4], n=-1, i, j, rem, quotient;

//Function used to convert from decimal to binary.
//Accepts decimal number as an argument
void binary(int n){
    for(i=0; i<33; i++){//"33" creates the leading 0's on the array
        a[i]=n%2;
        n=n/2;
    }
    printf("\nIn binary, this is ");
    for(i=i-1; i>=0; i--){
        printf("%d", a[i]);
    }
}

//Function used to convert from decimal to hexadecimal.
//Accepts decimal number as an argument. Could not figure
//out how to create "leading 0's".
void hexadecimal(int n){
    i = 0;
    char hex[100];
    quotient = n;

    //While-loop used to convert integer >10 into A - F characters
    while(quotient!=0){
        rem = quotient % 16;
        if(rem < 10){
            hex[j++] = rem + 48;
        }
        else{
            hex[j++] = rem + 55;
        }
        quotient = quotient / 16;
    }

    printf("\nIn hexadecimal, this is ");
    for(i = j; i >= 0; i--){
        printf("%c", hex[i]);
    }
}

//Main driver function
int main(){
	//while loop used to ensure number is between 0 - 4095.
	//Otherwise asks user to enter a new value
    while(n < 0 || n > 4095){
        printf("Enter the number to convert between 0 and 4095: ");
        scanf("%d",&n);
        if(n < 0 || n > 4095){
            printf("Number must be between 0 and 4095\n");
        }
    }

	//Calls to the functions that convert the numbers
    binary(n);
    hexadecimal(n);

    return 0;
}
