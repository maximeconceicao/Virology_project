#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ( int argc, char** argv )
{
    int defaites = 0, victoires = 0;
    
    int computer = 0;
    
    char ans = ' ';
    srand(time(NULL));
    

printf(" ______    _______  _______  ___   _        \n");                          
printf("|    _ |  |       ||       ||   | | |          \n");                       
printf("|   | ||  |   _   ||       ||   |_| |                                 \n");
printf("|   |_||_ |  | |  ||       ||      _|                                 \n");
printf("|    __  ||  |_|  ||      _||     |_                                  \n");
printf("|   |  | ||       ||     |_ |    _  |                                 \n");
printf("|___|  |_||_______||_______||___| |_|                                 \n");
printf(" _______  _______  _______  _______  ______                           \n");
printf("|       ||   _   ||       ||       ||    _ |                          \n");
printf("|    _  ||  |_|  ||    _  ||    ___||   | ||                          \n");
printf("|   |_| ||       ||   |_| ||   |___ |   |_||_                         \n");
printf("|    ___||       ||    ___||    ___||    __  |                        \n");
printf("|   |    |   _   ||   |    |   |___ |   |  | |                        \n");
printf("|___|    |__| |__||___|    |_______||___|  |_|                        \n");
printf(" _______  _______  ___   _______  _______  _______  ______    _______ \n");
printf("|       ||       ||   | |       ||       ||       ||    _ |  |       |\n");
printf("|  _____||       ||   | |  _____||  _____||   _   ||   | ||  |  _____|\n");
printf("| |_____ |       ||   | | |_____ | |_____ |  | |  ||   |_||_ | |_____ \n");
printf("|_____  ||      _||   | |_____  ||_____  ||  |_|  ||    __  ||_____  |\n");
printf(" _____| ||     |_ |   |  _____| | _____| ||       ||   |  | | _____| |\n");
printf("|_______||_______||___| |_______||_______||_______||___|  |_||_______|\n");
printf("\n\n");


    do
    {
        
        printf("'R', 'P', ou 'S' pour jouer || 'q' pour quitter \n\n");
        scanf("%c ",&ans);
	if(ans=='R' || ans=='P' || ans=='S'){
	computer = (rand()%3);
	
	if(computer==0){
		printf("COMPUTER : ROCK !\n\n");
		
	}else{
		if(computer==1){
			printf("COMPUTER : PAPER !\n\n");
		}
		else{
			printf("COMPUTER :  SCISSORS !\n\n");
		}
	}

	if(computer==0 && ans=='S' || computer==1 && ans=='R' || computer ==2 && ans=='P'){
printf("Défaite !\n\n");
defaites+=1;
}else{
	if(computer==0 && ans=='R' || computer==1 && ans=='P' || computer ==2 &&ans=='S'){
		printf("Egalité !\n\n");
	}else{
		printf("Victoire !\n\n");
		victoires+=1;
	}
	
}
printf("DEFAITES : %d || VICTOIRES : %d \n\n",defaites,victoires);
}
    } while (ans != 'q');
    
    return 0;
}
