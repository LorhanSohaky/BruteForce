#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <BruteForce.h>

char * bruteForce(int leng, int opt, char *prog) {
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
    Settings sets;
    sets.checker=NULL;
    sets.point=NULL;
    sets.length=-1;
    sets.len=false;
    sets.option=4;

	if(leng>-1) {
		sets.length=leng;
		sets.len=true;
	}

	if(opt>0 && opt<5) {
		sets.option=opt;
	}
    sets.checker=prog;
	if(A(&sets)) {
		return sets.point;
	} else {
		free(sets.point);
		return NULL;
	}
}

bool A(Settings *sets) {
	(*sets).point=(char *)malloc((((*sets).length)+1)*sizeof(char));
	if((*sets).point!=NULL) {
		while(true) {
			if(!B(sets,0)) {
				if(!(*sets).len) {
					char *p=(char *)realloc((*sets).point,sizeof(char)*((*sets).length+1));
					if(p!=NULL) {
						(*sets).point=p;
						(*sets).length++;
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
	return false;
}

bool B(Settings *sets,int position) {
    unsigned imin,imax;
    //ASCII TABLE
    if((*sets).option==1){//NUMBERS
        imin=48;
        imax=57;
    }else if((*sets).option==2){//LETTERS
        imin=64;
        imax=122;
    }else if((*sets).option==3){//NUMBERS AND LETTERS
        imin=47;
        imax=122;
    }else if((*sets).option==4){//ALL
        imin=32;
        imax=126;
    }
	unsigned int i;

	for(i=imin; i<=imax; i++) {
            if(imax==122 && i==33){
                i=imin+1;
            }else if(imax==122 && i==imin){
                i=32;
            }else if(imin==47 && imax==122 && i==58){
                i=65;
            }
            else if(imax==122 && i==91){
                i=97;
            }
			(*sets).point[position]=i;
			(*sets).point[position+1]='\0';
			if(strlen((*sets).point)==(*sets).length) {
				if(check((*sets).point,(*sets).checker)) {
					return true;
				}
			} else if(position+1<(*sets).length) {
				if(B(sets,position+1)) {
					return true;
				}
			}
		}
	return false;
}

bool check(char *point, char *checker) {
    if(checker!=NULL){
        char t[strlen(checker)+strlen(point)+2];
        sprintf(t,"%s %s",checker,point);
        int c=system(t);
        if(c!=-1 && c==1) {
            return true;
        } else {
            return false;
        }
    }
	return false;
}
