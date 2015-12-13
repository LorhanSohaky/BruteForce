#include<string.h>
#include<stdbool.h>
#include<stdio.h>

int main(int argc, char *argv[] ) {
	if(argc>1) {
		if(strcmp(argv[1],"123")==0) {
			return 1;
		} else {
			return 0;
		}
	}

	return 0;
}
