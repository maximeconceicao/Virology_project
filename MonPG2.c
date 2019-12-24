#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ( int argc, char** argv )
{
   
    
    int ans = 10;
    srand(time(NULL));
    


char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9','/','-','_','!','.'};



printf(",---.                                  | \n");    
printf("|---',---.,---.,---.. . .,---.,---.,---| \n");
printf("|    ,---|`---.`---.| | ||   ||    |   | \n");    
printf("`    `---^`---'`---'`-'-'`---'`    `---' \n");    
printf("                                         \n");    
printf("                                         \n");    
printf(",---.                         |          \n");    
printf("|  _.,---.,---.,---.,---.,---.|--- ,---.,---.\n");
printf("|   ||---'|   ||---'|    ,---||    |   ||    \n");
printf("`---'`---'`   '`---'`    `---^`---'`---'`  \n\n");


    do
    {	
        	
		if(ans>1){
		char password[ans];
		for(int i=0;i<ans;i++){
			password [i] = alphabet[(rand()%sizeof(alphabet))];
		}
        	
		printf("PASSWORD : %s\n\n",password);
		}
		printf("Veuillez saisir la longueur du password || '0' pour quitter \n\n");
        scanf("%d",&ans);
		
	
    } while (ans != 0);
    
    return 0;
}
