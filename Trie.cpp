#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream.h>
#include<string.h>
#include<math.h>
#include<new.h>
struct node{
char data;
struct node *its;
struct node *nxt;
};
char dir[][10]={"abased",
"abasedly",
"abasement",
"abaser",
"abasers",
"abases",
"abash",
"abashed",
"abashedly",
"abashes",
"abashing",
"abashment",
"abashments",
"abasing",
"abatable",
"abate"


};

void main()
{
	clrscr();
	int i,fr,j;
	char str[10],str1[]="cbauses";
	struct node root,*curr,*frd[48],*prv;
	root.nxt=NULL;
	root.data=0;
	for(i=0,fr=0;i<11;i++)
	{
		curr=&root;
		strcpy(str,&dir[i][0]);
		for(j=0;j<strlen(str);j++)
		{
			prv=curr;
			curr=curr->nxt;
			while(1)
			{


				//if not equal and nxt==NULL then add
				if(curr==NULL)
				{
					// for adding to list at parent node
					curr=new struct node();
					prv->nxt=curr;
					frd[fr]=curr;
					fr++;
					//curr=curr->nxt;
					curr->data=str[j];
					curr->nxt=NULL;
					// then actual node
					curr->its=new struct node();//(struct node*)malloc(1);
					frd[fr]=curr->its;
					fr++;
					curr=curr->its;
					curr->data=str[j];
					curr->nxt=NULL;
					curr->its=NULL;
					break;
				}

				//if equal
				else if(curr->data==str[j])
				{
					curr=curr->its;
					break;
				}
				//if curr->nxt!=null and also not match then
				else if(curr->nxt==NULL)
				{
					curr->nxt=new struct node();
					curr=curr->nxt;
					frd[fr]=curr;
					fr++;
					//curr=curr->nxt;
					curr->data=str[j];
					curr->nxt=NULL;
					// then actual node
					curr->its=new struct node();//(struct node*)malloc(1);
					frd[fr]=curr->its;
					fr++;
					curr=curr->its;
					curr->data=str[j];
					curr->nxt=NULL;
					curr->its=NULL;
					break;
				}

				else if(curr->nxt!=NULL)
				{
					curr=curr->nxt;
				}

			}

		}
	}
	/*curr=root.nxt->nxt->nxt->its;

	for(i=0;i<8;i++)
	{
		printf("%c",curr->data);
		curr=curr->nxt->its;
	}*/
	//chk of existance
	curr=&root;
	printf("\nEnter what you want to enter    ");
	fflush(stdin);
	gets(str1);
	for(i=0;i<strlen(str1);i++)
	{
		while(1)
		{
			if(curr->data==str1[i])
			{
				curr=curr->its;
				break;
			}
			else if(curr->nxt!=NULL)
			{
				curr=curr->nxt;
			}
			else if(curr->nxt==NULL)
			{
				printf("\nNot present");
				goto thnks;
			}
		}
	}
	printf("\nPresent");

	thnks:printf("%d",fr);
	for(i=0;i<fr;i++)
		free(frd[i]);

	gets(str1);
}
