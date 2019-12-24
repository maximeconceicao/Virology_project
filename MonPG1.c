#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ( int argc, char** argv )
{
    float piles = 0, faces = 0;
    
    int coin = 0, lancers =0;
    
    char ans = 'A';
    srand(time(NULL));
    

printf(" _____       _         _____  _  _           \n");
printf("|     | ___ |_| ___   |   __|| ||_| ___      \n");
printf("|   --|| . || ||   |  |   __|| || || . |     \n");
printf("|_____||___||_||_|_|  |__|   |_||_||  _|     \n");
printf("                                   |_|       \n");
printf("                                             \n");
printf(" _____  _              _       _             \n");
printf("|   __||_| _____  _ _ | | ___ | |_  ___  ___ \n");
printf("|__   || ||     || | || || .'||  _|| . ||  _|\n");
printf("|_____||_||_|_|_||___||_||__,||_|  |___||_|   \n");
printf("\n\n");


    do
    {
        
        
	coin = (rand()%2);
	lancers++;
	if(coin==0){
		printf("PILE !\n\n");
		piles++;
	}else{
		printf("FACE !\n\n");
		faces++;
	}
	printf("STAT PILE : %f || STAT FACE : %f \n Nombre de lancers : %d\n",piles/lancers,faces/lancers,lancers);

	printf("'ENTER' pour lancer || 'q' pour quitter \n\n");
        scanf("%c",&ans);
    } while (ans != 'q');
    
    return 0;
}
