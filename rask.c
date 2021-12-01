#include <stdio.h>
#include <string.h>

unsigned long hash(unsigned char *str)
{
	unsigned long hash = 5383;
	int c;
	while (c= *str++)
		hash = ((hash<<5) +hash)+c;
	return hash;
}

int main () 
{
   char var[50];
   scanf("%s",var);
      char *lek= var;
	long passordH = hash(lek);
char passord55[50];
sprintf(passord55, "%ld", passordH);
printf("%s",passord55);
	return (0);
}



