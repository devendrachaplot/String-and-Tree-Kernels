#include "suffix_tree.h"
#include <string.h>
#include <stdio.h>
// #define DEBUG

int calculate_val(char* buff, int buff_length, SUFFIX_TREE* tree){
	int i;
	char subbuff[buff_length];
	int matchsum = 0;
	int position;

	for (i = 0; i < buff_length; i++)
	{
		memcpy(subbuff, &buff[0], buff_length-i);
		subbuff[buff_length-i] = '\0';
		position = ST_FindSubstring(tree, subbuff, strlen(subbuff));
		if(position == ST_ERROR){
			matchsum += 0;
			#ifdef DEBUG
			printf("Matching %s = %d\n", subbuff, -1);
			#endif
		}
		else{
			matchsum += strlen(subbuff) * position;
			#ifdef DEBUG
			printf("Matching %s = %d\n", subbuff, (int)strlen(subbuff)*position);
			#endif
		}
	}

	return matchsum;
}

int main(int argc, char * argv[])
{

	int n;
	long elapsed_seconds;
	char data[3190][65];

	int trainsize = atoi(argv[1]);
	int testsize = atoi(argv[2]);

	int class[3190];

	FILE *fr;
	fr = fopen ("converted.data", "rt");  /* open the file for reading */
	/* elapsed.dta is the name of the file */
	/* "rt" means open the file for reading text */

	int l=0;
	while(fgets(data[l], 63, fr) != NULL)
	{
	 // get a line, up to 80 chars from fr.  done if NULL 
	// sscanf (ytr[i], "%ld", &elapsed_seconds);
		// printf("%s", data[l]);
		l++;
	/* convert the string to a long int */
	// printf ("%ld\n", elapsed_seconds);
	}
	fclose(fr);  /* close the file prior to exiting the routine */

	int ylength,xlength,matchsum;
	// return 0;
	char ystr[65];
 //    printf("Enter y: ");
 //    scanf("%s",ystr);

	char xstr[65];
 //    printf("Enter x: ");
 //    scanf("%s",xstr);
	int p,q,i,r;

	for(i=0;i<3190;i++){
		if(i<767)
			class[i] = 1;
		else if(i<1535)
			class[i] = 2;
		else
			class[i] = 3;
	}
	srand((unsigned)time(NULL)); 
	int train[trainsize],test[100];
	for(i=0;i<trainsize;i++){
	    r = rand()%3190;
	    train[i] = r;
	}
	for(i=0;i<testsize;i++){
	    r = rand()%3190;
	    test[i] = r;
	}

	fr = fopen ("traindata", "w");
	for (p = 0; p < trainsize; ++p)
	{
		fprintf(fr, "%d ",class[train[p]]);
		for (q = 0; q < trainsize; ++q)
		{
			for(r=0;r<65;++r){
				ystr[r] = data[train[p]][r];
				xstr[r] = data[train[q]][r];
			}

			ylength = strlen(ystr);
			xlength = strlen(xstr);

			matchsum = 0;

			SUFFIX_TREE* tree = ST_CreateTree(ystr,ylength);

			char subbuff[xlength];

			for (i = 0; i < xlength; i++)
			{
				memcpy(subbuff, &xstr[i], xlength-i+1);
				matchsum += calculate_val(subbuff, strlen(subbuff), tree);
				// printf("%d\n", matchsum);
			}
			
			/*Print the suffix tree.*/
			// ST_PrintTree(tree);

			/*Search for a substring in the tree and return its position if exists.*/
			// position = ST_FindSubstring(tree, "ssis", 4);
			
			/*Print the position of the substring*/
			fprintf(fr, "%d:%d ", q+1,matchsum);
			// fprintf(ofp, "%s %d\n", username, score+10);
			/*Delete the tree and all its nodes.*/
			ST_DeleteTree(tree);
			
		}
		fprintf(fr, "\n");
	}
	fclose(fr);

	fr = fopen ("testdata", "w");
	for (p = 0; p < testsize; ++p)
	{
		fprintf(fr, "%d ",class[test[p]]);
		for (q = 0; q < trainsize; ++q)
		{
			for(r=0;r<65;++r){
				ystr[r] = data[test[p]][r];
				xstr[r] = data[train[q]][r];
			}

			ylength = strlen(ystr);
			xlength = strlen(xstr);

			matchsum = 0;

			SUFFIX_TREE* tree = ST_CreateTree(ystr,ylength);

			char subbuff[xlength];

			for (i = 0; i < xlength; i++)
			{
				memcpy(subbuff, &xstr[i], xlength-i+1);
				matchsum += calculate_val(subbuff, strlen(subbuff), tree);
				// printf("%d\n", matchsum);
			}
			
			/*Print the suffix tree.*/
			// ST_PrintTree(tree);

			/*Search for a substring in the tree and return its position if exists.*/
			// position = ST_FindSubstring(tree, "ssis", 4);
			
			/*Print the position of the substring*/
			fprintf(fr, "%d:%d ",q+1,matchsum);
			
			/*Delete the tree and all its nodes.*/
			ST_DeleteTree(tree);
			
		}
		fprintf(fr, "\n");
	}
	fclose(fr);


 //    int matchsum = 0;
 //    int i;

	// /*Will hold the position of the substring if exists in the tree.*/
	// DBL_WORD position;
	
	// /*Create the suffix tree*/


	
}

