#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char *argv[]) {

	openlog(NULL, 0, LOG_USER);
	if (argc != 3) {
		printf("Provide 2 arguments eg: ./writer path/to/file/filename string-to-write\n\r");
		syslog(LOG_ERR, "Invalid Number of arguments: %d.", argc-1);
		return 1;
	}

	FILE* ptr = fopen(argv[1], "w");
	char str[50];
	int sizeofstr = sprintf(str, "%s", argv[2]);
	if (ptr == NULL) {
//		printf("File could not be created.\n\r");
		syslog(LOG_ERR, "File could not be created.");
		return 1;
	}
	else {
//		printf("Text: %s of size %d is writen.\n\r", str, sizeofstr);
		syslog(LOG_DEBUG, "Writing %s to %s\n\r", argv[2], argv[1]);
		fwrite(str, 1, sizeofstr, ptr);
		fclose(ptr);
	}
	return 0;
}
