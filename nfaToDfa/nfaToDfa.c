#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void main(){
	int states,inputs;
	int transitions[10][10][10];
	char nfa_table[10][10][10];
	
	printf("Enter no. of states: ");
    scanf("%d", &states);
    printf("Enter no. of input symbols: ");
    scanf("%d", &inputs);
    
    for (int i = 0; i < inputs; i++){
        printf("Enter NFA matrix for input %d:\n", i + 1);
        for (int j = 0; j < states; j++){
            for (int k = 0; k < states; k++){
                scanf("%d", &transitions[i][j][k]);
            }
        }
        print("\n")
    }
    
}
