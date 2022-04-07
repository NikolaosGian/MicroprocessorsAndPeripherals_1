#include <stdio.h>
#include <stdlib.h>


__asm void hash(char *value, int *result);


int main(){
	char *value = "sAr, PE 2!";
	int result;
	hash(value,&result);
	printf("result = %d" , result);
	return 0;
}


__asm void hash(char *value, int *result)
{
	PUSH{r4-r11,lr}
	MOV r5,#0 						// set R5 = 0 (r5 is counter)
	MOV r8,#0							// set R8 = 0 (r5 is counter)
				
LOOP 
		LDRB r4,[r0],#1 		// Load in r4 the fist byte of value and move the next one
					
		CMP r4,#0 					// end of String then jump at exit
		BEQ.W EXIT
		
		CMP r4,#'/'				// If the character is less from '0'
		BLT LOOP
		
		CMP r4,#':'				// If the character is greater or equal ':'
		BLT START						// if not then go to start 
		CMP r4,#'@'				// If the character is less or equal '@'
		BGT START						// if not then go to start 
		B LOOP							// If it's one of the invalid characters back in the loop for the next byte.
		
START
		CMP r4,#'['				// If the character is grater or equal '['
		BGT LOOP						// Then jump at LOOP is not valid characters
		
		CMP r4,#'A'					// Check if character is equal with 'A'
		BNE B1							// If not then jump to next character 'B' (label B1)
		MOVEQ r8,#10				// Hashing Table converting value
		ADD r5,r5,r8				// Update the counter
		B LOOP							// jump at the start of loop
				
B1
		CMP r4,#'B'					// The same as above
		BNE C
		MOVEQ r8,#42
		ADD r5,r5,r8
		B LOOP
				
C
		CMP r4,#'C'					// The same as above
		BNE D
		MOVEQ r8,#12
		ADD r5,r5,r8
		B LOOP
							
				
D
		CMP r4,#'D'					// The same as above
		BNE E
		MOVEQ r8,#21
		ADD r5,r5,r8
		B LOOP
							
E
		CMP r4,#'E'					// The same as above
		BNE F
		MOVEQ r8,#7
		ADD r5,r5,r8
		B LOOP
				
F
		CMP r4,#'F'					// The same as above
		BNE G
		MOVEQ r8,#5
		ADD r5,r5,r8
		B LOOP
				
G	
		CMP r4,#'G'					// The same as above
		BNE H
		MOVEQ r8,#67
		ADD r5,r5,r8
		B LOOP
					
H
		CMP r4,#'H'					// The same as above
		BNE I
		MOVEQ r8,#48
		ADD r5,r5,r8
		B LOOP
				
I			
		CMP r4,#'I'					// The same as above
		BNE J
		MOVEQ r8,#69
		ADD r5,r5,r8
		B LOOP
					
J		
		CMP r4,#'J'					// The same as above
		BNE K
		MOVEQ r8,#2
		ADD r5,r5,r8
		B LOOP
							
K			
		CMP r4,#'K'					// The same as above
		BNE L
		MOVEQ r8,#36
		ADD r5,r5,r8
		B LOOP
							
L			
		CMP r4,#'L'					// The same as above
		BNE M
		MOVEQ r8,#3
		ADD r5,r5,r8
		B LOOP
						
M				
		CMP r4,#'M'					// The same as above
		BNE N
		MOVEQ r8,#19
		ADD r5,r5,r8
		B LOOP
							
N				
		CMP r4,#'N'					// The same as above
		BNE O
		MOVEQ r8,#1
		ADD r5,r5,r8
						
O			
		CMP r4,#'O'					// The same as above
		BNE P
		MOVEQ r8,#14
		ADD r5,r5,r8
		B LOOP
							
P			
		CMP r4,#'P'					// The same as above
		BNE Q
		MOVEQ r8,#51
		ADD r5,r5,r8
		B LOOP
							
Q			
		CMP r4,#'Q' 				// The same as above
		BNE R
		MOVEQ r8,#71
		ADD r5,r5,r8
		B LOOP
				
R			
		CMP r4,#'R' 				// The same as above
		BNE S
		MOVEQ r8,#8
		ADD r5,r5,r8
		B LOOP
							
S				
		CMP r4,#'S'					// The same as above
		BNE T
		MOVEQ r8,#26
		ADD r5,r5,r8
		B LOOP
				
T				
		CMP r4,#'T'					// The same as above
		BNE U
		MOVEQ r8,#54
		ADD r5,r5,r8
		B LOOP
							
U			
		CMP r4,#'U'					// The same as above
		BNE V
		MOVEQ r8,#75
		ADD r5,r5,r8
		B LOOP
							
V			
		CMP r4,#'V'					// The same as above
		BNE W
		MOVEQ r8,#15
		ADD r5,r5,r8
		B LOOP
				
W			
		CMP r4,#'W'					// The same as above
		BNE X
		MOVEQ r8,#6
		ADD r5,r5,r8
		B LOOP
														
X			
		CMP r4,#'X'					// The same as above
		BNE Y
		MOVEQ r8,#59
		ADD r5,r5,r8
		B LOOP
													
Y			
		CMP r4,#'Y'					// The same as above
		BNE Z
		MOVEQ r8,#13
		ADD r5,r5,r8
		B LOOP
							
Z			
		CMP r4,#'Z' 				// The same as above but now we go to check if it is a number
		BNE NUMBER
		MOVEQ r8,#25
		ADD r5,r5,r8
		B LOOP
		
NUMBER
		CMP r4,#'0'
		BNE ONE
		MOVEQ r8,#0
		SUB r5,r5,r8
		B LOOP
		
ONE
		CMP r4,#'1'
		BNE TWO
		MOVEQ r8,#1
		SUB r5,r5,r8
		B LOOP
		
TWO
		CMP r4,#'2'
		BNE THREE
		MOVEQ r8,#2
		SUB r5,r5,r8
		B LOOP

THREE
		CMP r4,#'3'
		BNE FOUR
		MOVEQ r8,#3
		SUB r5,r5,r8
		B LOOP
		
FOUR
		CMP r4,#'4'
		BNE FIVE
		MOVEQ r8,#4
		SUB r5,r5,r8
		B LOOP
		
FIVE
		CMP r4,#'5'
		BNE SIX
		MOVEQ r8,#5
		SUB r5,r5,r8
		B LOOP		

SIX
		CMP r4,#'6'
		BNE SEVEN
		MOVEQ r8,#6
		SUB r5,r5,r8
		B LOOP

SEVEN
		CMP r4,#'7'
		BNE EIGHT
		MOVEQ r8,#7
		SUB r5,r5,r8
		B LOOP

EIGHT
		CMP r4,#'8'
		BNE NINE
		MOVEQ r8,#8
		SUB r5,r5,r8
		B LOOP

NINE
		MOVEQ r8,#9
		SUB r5,r5,r8
		B LOOP
		
EXIT
		STR r5,[r1]			// store at &result = (value of ) r5
		POP{r4-r11,pc}	// POP and return
}
	
