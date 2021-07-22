#include <stdio.h>
#include <conio.h>
void sender();
void receiver();
void main()
{
	//Giving Choice 
	int choice;
	printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Enter Choice~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\t\n");
	printf("\n\t 1.\t Sending Message From Sender Side and Generating Parity Bits");
	printf("\n\t 2.\t Receiving Message and Checking for Error \n");
	scanf("%d",&choice);
	
	switch (choice)
	{
		case 1:
			sender();
			break;
		
		case 2:
		    receiver(); 	
	}
		
	
}

//Sender Function Implementation
void sender()
{
	int number_of_frames, frame_size, i, j;

printf("Enter Frame Size:");
scanf("%d", &frame_size);
printf("Enter number of frames in a message:");
scanf("%d", &number_of_frames);

int count_r[number_of_frames], count_c[frame_size];
int message[number_of_frames][frame_size];

for(i=0;i<number_of_frames;i++)
count_r[i] = 0;

for(i=0;i<frame_size;i++)
count_c[i] = 0;

printf("Enter Your Message:\t ");
for(i=0;i<number_of_frames;i++)
{
	for(j=0;j<frame_size;j++)
	scanf("%1d", &message[i][j]);
}
printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("Message to be sent:\t");
for(i=0;i<number_of_frames;i++)
{
	for(j=0;j<frame_size;j++)
	printf("%d", message[i][j]);
	printf("\t");
}

//counting number of 1 in rows
for(i=0;i<number_of_frames;i++)
{
	for(j=0;j<frame_size;j++)
	{
		if(message[i][j] == 1)
		count_r[i]++;
	}
}

//counting number of 1 in columns

for(j=0;j<frame_size;j++)
{
	for(i=0;i<number_of_frames;i++)
	{
		if(message[i][j] == 1)
		count_c[j]++;
	}
}

int row_parity[number_of_frames], column_parity[frame_size];

for(i=0;i<number_of_frames;i++)
{
	if(count_r[i]%2 == 0)
	row_parity[i] = 0;
	else
	row_parity[i] = 1;
}

for(i=0;i<frame_size;i++)
{
	if(count_c[i]%2 == 0)
	column_parity[i] = 0;
	else
	column_parity[i] = 1;
}
printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("Row Parity Bits:\t");
for(i=0;i<number_of_frames;i++)
printf("%d\t",row_parity[i]);
printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("Column Parity Bits:\t");
for(i=0;i<frame_size;i++)
printf("%d\t",column_parity[i]);
printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("Message with parity bits:\t");
for(i=0;i<number_of_frames;i++)
{
	for(j=0;j<frame_size;j++)
	printf("%d", message[i][j]);
	printf("%d",row_parity[i]);
	printf("\t");
}
printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

/*for(i=0;i<number_of_frames;i++)
printf("%d\t",row_parity[i]);
printf("\n");
for(i=0;i<frame_size;i++)
printf("%d\t",column_parity[i]);*/
//if(count_r[i]%2 == 0)

}

//Receiver Function Implementation

void receiver()
{
	
int number_of_frames, frame_size, i, j;

printf("Enter Frame Size Received:");
scanf("%d", &frame_size);
printf("Enter number of frames in a message Received:");
scanf("%d", &number_of_frames);

int count_r[number_of_frames], count_c[frame_size];
int message[number_of_frames][frame_size];

for(i=0;i<number_of_frames;i++)
count_r[i] = 0;

for(i=0;i<frame_size;i++)
count_c[i] = 0;

//Getting frames and storing in a message array
printf("Enter Your Message:\t ");

for(i=0;i<number_of_frames;i++)
{

	for(j=0;j<frame_size;j++)
	scanf("%1d", &message[i][j]);
}
printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

//counting number of 1 in rows
for(i=0;i<number_of_frames;i++)
{
	for(j=0;j<frame_size;j++)
	{
		if(message[i][j] == 1)
		count_r[i]++;
	}
}

//counting number of 1 in columns

for(j=0;j<frame_size;j++)
{
	for(i=0;i<number_of_frames;i++)
	{
		if(message[i][j] == 1)
		count_c[j]++;
	}
}

for(i=0;i<number_of_frames;i++)
{   
	if(count_r[i]%2 != 0)
	{
			printf("\nError Might Have Occured During Transmission of row number:\t%d\n",i+1);
	}

}

for(i=0;i<frame_size;i++)
{   if(number_of_frames > 1)
	if(count_c[i]%2 != 0)
    printf("\nError Might Have Occured During Transmission of column number\t%d\n",i+1);
}

printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
