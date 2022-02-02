//    cd /var/www/html/remFile/
//    g++ -o remFile remFile.c $(mysql_config --libs) 
//   ./remFile                                         - Executar programa
//   chmod +x /var/www/html/sendMail/processaEmail     - Dar Permissão de execução para o agendador 


using namespace std;

#include <sys/stat.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "/usr/include/mysql/mysql.h"
#include <iostream>
#include <dirent.h>
#include <cstdlib>
#include <sstream>


#define aDirPai "/var/www/html/chamado/uploads";

template <typename T>
string NumberToString(T pNumber)
{
 ostringstream oOStrStream;
 oOStrStream << pNumber;
 return oOStrStream.str();
}

double seconds(struct tm * timeinfo){
	double sec = timeinfo->tm_sec;
	double min = timeinfo->tm_min;
	double hor = timeinfo->tm_hour;
	double day = timeinfo->tm_yday;
	double yea = timeinfo->tm_year;
	
	sec += min*60;
	sec += hor*3600;
	sec += day*86400;
	sec *= yea;
	
	return sec;
}







int listaArquivos (string nomeDir) {
	struct stat t_stat;
	struct tm * timeinfo;
	struct dirent **namelist;
	int n;
	string aNomObj;

	n = scandir(nomeDir.c_str(), &namelist, 0, alphasort);
	if (n < 0)
		perror("scandir");
	else {
		while(n--) {
			aNomObj  = nomeDir + "/";
			aNomObj += namelist[n]->d_name;
			
			
			printf("%s\n", aNomObj.c_str());
			
			stat(aNomObj.c_str(), &t_stat);
			timeinfo = localtime(&t_stat.st_ctime);
			printf("File time and date: %s", asctime(timeinfo));
			
			
			int a;
			string c;
			
			c = NumberToString(seconds(timeinfo));
			
			printf(c.c_str());
			
			free(namelist[n]);
		}
		free(namelist);
	}
	
	return 0;
	/*
	
	
	
    DIR *dir = 0;
    struct dirent *entrada = 0;
    unsigned char isDir = 0x4;
    unsigned char isFile = 0x8;
	
    dir = opendir (nomeDir.c_str());
 
    if (dir == 0) {
        printf("Nao foi possivel abrir diretorio.");
        exit (1);
    }
 
    //Iterar sobre o diretorio
    while (entrada = readdir (dir)){
        if (entrada->d_type == isFile)
            printf( entrada->d_name );
	}
 
    closedir (dir);
     
    return 0;*/
}




main () {
	string aLocArc = "";
	aLocArc += aDirPai;
	//aLocArc += "/arquivo.txt";
	listaArquivos (aLocArc);
	//remove(aLocArc.c_str());
	
}