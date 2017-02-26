#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
void flag ()
{
	int i=0;
	char a[50],cha,b[50];
	FILE *fp;
	for(i=0;i<20;i++)
		b[i]='0';
	i = 0;
	fp= fopen("flag.txt","r");
	do
	{
		fscanf(fp,"%c",&cha);
		a[i++]=cha;

	}
	while(!feof(fp));
	fclose(fp);
	time_t tim,del;
	tim=time(NULL);
	del=tim;
	for(i=0;i<=30000;i++)
	{
		printf(" %d. Ready to get the flag?\n",i);
		b[i%20]=b[i%20] ^ (del-tim);
		sleep(1);
		del = time(NULL);
	}
	tim = time(NULL);
	del = tim;
	for(i=0;i<=10000;i++)
	{
		printf(" %d. Ready to get the flag?\n",30000+i+1);
		a[i%20]=a[i%20] ^ (del-tim);
		sleep(1);
		del = time(NULL);
	}
	printf("You win\nFlag = iiita_%s\n",a);
}
int main()
{
	int pin,ctr=0,rem;
	printf("Enter the secret pin\n");
	scanf("%d",&pin);
	rem = pin%10;
	if(rem!=7)
		ctr=1;
	else
	{
		pin /= 10;
		rem = pin%10;
		if(rem!=3)
			ctr=1;
		else
		{
			pin /= 10;
			rem = pin%10;
			if (rem !=3)
				ctr=1;
			else 
			{
				pin /= 10;
				rem = pin%10;
				if(rem !=1)
					ctr=1;
				else
				{
					printf("You rock!!\n");
					flag();
				}
			}
		}
	}
	if(ctr==1)
		printf("You are just a noob!!\nFirst go and learn something\n");
	return 0;
}
