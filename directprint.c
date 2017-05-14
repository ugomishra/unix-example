#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char* argv[]) {

	DIR *dir = NULL;
	void printList(DIR *dir);

	if(argv[1] == NULL) {
		printf("Supply directoy\n");
		return 0;
	}

	if((dir = opendir(argv[1])) != NULL ) {
		printf("Printing files in directory %s\n", argv[1]);
		printList(dir);
	}
	else {
		printf("Supplied string %s is not a directory or whatever\n", argv[1]);
	}
	
	return 0;
}

void printList(DIR *dir) {

	struct dirent *dptr = NULL;
	char buf[PATH_MAX + 1];

	while((dptr = readdir(dir)) != NULL) {
		// if(dptr->d_name != '.' || dptr->d_name != '..') {
		// 	printf("file >> %s \t", dptr->d_name);
		// 	printf("file No >> %d \n", (int)dptr->d_fileno);
		// }
		realpath(dptr->d_name, buf);
		printf("%s\n", buf );
	}

	closedir(dir);

	exit(0);
}