#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char *point;
char *checker;
bool len=false;
int length=1;
int option=4;
char number[11]= {'0','1','2','3','4','5','6','7','8','9'};
char letter[54]= {' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char numlet[64]= {' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};


bool bruteForce(int leng, int opt, char *prog);
bool A();
bool B(int position);
bool check();

int main() {
	if(bruteForce(4,2,"testador")) {
	}
	return 0;
}

bool bruteForce(int leng, int opt, char *prog) {
	/*
		leng use when you know the length of the password
		-1 it's use when you don't know the length of the password

		----------------------------

		opt it's the option to
		if opt does not exists the default opt it's the 4

		opt-> 1 - Number
		opt-> 2 - Letter
		opt-> 3 - Number & Letter
		opt-> 4 - All

		----------------------------

		if prog!=null so prog matches the name of the program to check the combination with password
	*/
	if(leng!=-1) {
		length=leng;
		len=true;
	}

	if(opt>0 && opt<5) {
		option=opt;
	}
	if(prog!=NULL) {
		checker=prog;
	}

	if(A()) {
		printf("\nCOMBINATION: %s",point);
		printf("\nLENGTH: %d",length);
	} else {
		printf("\nError!\n");
	}
	free(point);
	return true;
}

bool A() {
	point=(char *)malloc((length+1)*sizeof(char));
	if(point!=NULL) {
		while(true) {
			if(!B(0)) {
				if(!len) {
					char *p=(char *)realloc(point,sizeof(char)*(length+1));
					if(p!=NULL) {
						point=p;
						length++;
					}else{
						break;
					}
				} else {
					break;
				}
			} else {
				return true;
			}
		}
	}
}

bool B(int position) {
	int i;
	switch(option) {
	case 1:
		for(i=0; i<=strlen(number); i++) {
			point[position]=number[i];
			point[position+1]='\0';
			if(strlen(point)==length) {
				if(check()) {
					return true;
				}
			} else if(position+1<length) {
				if(B(position+1)) {
					return true;
				}
			}
		}
		break;
	case 2:
		for(i=0; i<=strlen(letter); i++) {
			point[position]=letter[i];
			point[position+1]='\0';
			if(strlen(point)==length) {
				if(check()) {
					return true;
				}
			} else if(position+1<length) {
				if(B(position+1)) {
					return true;
				}
			}
		}
		break;
	case 3:
		for(i=0; i<=strlen(numlet); i++) {
			point[position]=numlet[i];
			point[position+1]='\0';
			if(strlen(point)==length) {
				if(check()) {
					return true;
				}
			} else if(position+1<length) {
				if(B(position+1)) {
					return true;
				}
			}
		}
		break;
	case 4:
		for(i=32; i<=125; i++) {
			point[position]=i;
			point[position+1]='\0';
			if(strlen(point)==length) {
				if(check()) {
					return true;
				}
			} else if(position+1<length) {
				if(B(position+1)) {
					return true;
				}
			}
		}
		break;
	}
	return false;
}

bool check() {
	char t[strlen(checker)+strlen(point)+2];
	sprintf(t,"%s %s",checker,point);
	int c=system(t);
	if(c!=-1 && c==1) {
		return true;
	} else {
		return false;
	}
}
