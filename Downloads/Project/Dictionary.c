#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{
	//variable deleartion
	int check=1,n,i,j;
	float count=0; 
	char word[20],meaning[200],search[300];
	printf("Enter Word\n");
	scanf(" %s",word);
	FILE *words;
	words=fopen("Words.txt","r+");
	fscanf(words," %s",search);
	//Searching For word In file
	while(strcmp(word,search)!=0)
	{
		fscanf(words," %s",search);
		check++;
		if(feof(words)){
			check=0;
			break;
		}	
	}
	fclose(words);
	words=fopen("Words.txt","r+");
	//If word is available then search for meaning
	if(check!=0)
	{
		FILE *meanings;
		meanings=fopen("Meanings.txt","r+");
		for(i=0;i!=check;i++)
		{
			fscanf(meanings," %[^\n]s",search);
		}
		printf("%s\n",search);
	}
	//giving suggestion words
	else if(check==0)
	{
		printf("Word Not Found\n");
		printf("Instead You Can Search For\n");
		//loop will search in whole file for simmilar words
		while(!(feof(words)))
		{
			count=0;
			fscanf(words," %s",search);
			if(strlen(word)==strlen(search))
			{
				for(i=0;i<strlen(word);i++)
				{
					if(word[i]==search[i])
					{
						count++;
					}
				}
				check=(count*100)/strlen(search);
				if(check>=60)
				{
					printf("%s\n",search);
				}
			}
			else if(strlen(word)<strlen(search))
			{
				for(i=0,j=0;i<strlen(search);i++)
				{
					if(search[i]==word[j])
					{
						count++;
						j++;
					}
				}
				check=(count*100)/strlen(search);
				if(check>=60)
				{
					printf("%s\n",search);
				}
			}
			else if(strlen(word)>strlen(search))
			{
				for(i=0,j=0;i<strlen(search);i++)
				{
					if(word[i]==search[j])
					{
						count++;
						j++;
					}
				}
				check=(count*100)/strlen(word);
				if(check>=60)
				{
					printf("%s\n",search);
				}
			}
		}
	}
}
