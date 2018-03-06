#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
using namespace std;

#define inputFile "./test.csv"

int tokenize(char *str, char chr, char **argz, int maxLen) {
	int n = 0;		// number of tokens found.

	char *p1 = str;
	char *p2 = str;
	int len = strlen(str);
	for (int i = 0; i < len; i++, p1++) {
		if (*p1 == chr) {
			*p1 = '\0';			// replace chr with nul.
			argz[n++] = p2;		// add start of token to array list.
			p2 = (p1 + 1);		// move p2 to start of next token.
		}

		if (n >= (maxLen -1))
			break;
	}

    if (n < (maxLen - 1))
	    argz[n++] = p2;				// pickup last token.

	argz[n] = (char *)0;		// set next pointer to null

	return n;
}

int main(int argc,char* argv[]){
  FILE *fp = fopen(inputFile, "r");  
  char *parts[4];
  char line[128];
  int i=0;
	//fgets(line, sizeof(line), fp);
  while (fgets(line, sizeof(line), fp) != NULL) {
		  
		tokenize(line, ',', parts, 4); 
   if(i<4){
      cout<<parts[0]<<":"<<parts[1]<<":"<<std::string(parts[2])<<endl;
      i++;
      }
   }
return 0;
}