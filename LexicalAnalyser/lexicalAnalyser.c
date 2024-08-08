#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
int operator(char c){
    switch (c){
        case '+':   
        case '-':   
        case '*':   
        case '/':   
        case '=':   
            printf("%c - Operator\n", c);
            return 1;
    }
    return 0;
}

int delim(char c){
	switch (c)
    {
        case '{':
        case '}':
        case '(':
        case ')':
        case '[':
        case ']':
        case ',':
        case ';':
            printf("%c - Delimiter\n", c);
            return 1;
    }

    return 0;
}
int keyword(char c[])
{
    if (strcmp(c, "void") == 0 || strcmp(c, "main") == 0 ||
        strcmp(c, "int") == 0 || strcmp(c, "long") == 0 ||
        strcmp(c, "float") == 0 || strcmp(c, "double") == 0 ||
        strcmp(c,"char") == 0)
    { 
        return 1;
    }

    return 0;
}
int constant(char c[]){
	for(int i=0;i<strlen(c);i++){
		if (isdigit(c[i]))
			continue;
		else
			return 0;
	}
	return 1;
}
int flag2 = 0; //For handling multiline comment
void main(){
	FILE *f1;
	f1 = fopen("input.txt","r");
	char line[100];
	while(fgets(line,sizeof(line),f1)){
		//printf("%s",line);
		int flag = 0;
		for(int i=0;i<strlen(line);i++){
			//printf("%c",line[i]);
			if (line[i]=='/' && line[i+1]=='/'){
				flag = 1;
				break;
			}
			
		}
		if (flag)
			continue; //Skips entire line	
		for(int i=0;i<strlen(line);i++){
			if (flag2==1 && (line[i]=='*' && line[i+1]=='/')){
				flag2 = -1;
				break;
			}
			else if (line[i]=='/' && line[i+1]=='*'){
				flag2 = 1;
				break;
            }
        }
        if (flag2==1)
            continue;
        else if (flag2==-1){
        	flag2 = 0;
        	continue;
        }
        printf("-----------------------------------\n");
        printf("Code : %s",line);
        printf("-----------------------------------\n");
        char c[100];
        int index = 0;
        strcpy(c,"");
        for (int i = 0; i < strlen(line); i++){
        	if (operator(line[i]) || delim(line[i]) || line[i] == ' ' || line[i] == '\t' || line[i] == '\n'){
        		if (strcmp(c,"") != 0){
        			if (constant(c))
        				printf("%s : Constant\n", c);
        			else if (keyword(c))
        				printf("%s : Keyword\n", c);
        			else
        				printf("%s : Identifier\n", c);
        			strcpy(c,"");
        			index = 0;	
        		}	
        	}
        	else{
        		c[index++] = line[i];
        		c[index] = '\0';
        	}
        }
        
        
        	
        
	}
			
}
