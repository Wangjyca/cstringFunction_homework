#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>


using namespace std;

char *strstr_ptr=NULL; /// for _strstr function return a null address when s2 not in s1

void _strcpy(char *dest, const char *src);

void _strcpy2(char *dest, const char *src);

int _strlen(const char* str);

int _strcmp(const char* str1, const char* str2);
int _strncmp(const char* str1, const char* str2, int n);

char* _strstr(char *str1, char *str2);

void _strcat(char* str1, const char* str2);
void _strncat(char* str1, const char* str2,int n );
void _strncpy(char* dest,  char* src, int n);


int main() {


	const char* mysource = "demon king";
	  
	char mydestination[100];
	char mydestination2[100];
 	 _strcpy(mydestination, mysource);

	 cout << "_strcpy " << mydestination << endl;


	_strcpy2(mydestination, mysource);

	cout << "_strcpy2 " << mydestination << endl;


	int l = _strlen(mydestination);

	cout << "_strlen " << l << endl;


 	_strcat(mydestination, mysource); //ADD *****************
	cout << "mydestination: " << mydestination << endl;//ADD *****************

	
	_strncat(mydestination, mysource, 9);//ADD *****************
	cout << "mydestination add 9 chars: " << mydestination << endl;//ADD *****************

	const char *s1 = "tricksters";

	const char *s2 = "trickster";


	_strcpy(mydestination, s1); //ADD *****************
	_strcpy(mydestination2, s2);//ADD *****************
	 

	 if (strstr(mydestination, mydestination2))//ADD *****************
	 {
	 	cout << "S2 is contained in S1! " << endl;//ADD *****************
	 }
	 else//ADD *****************
	 {
         cout << "S2 is not contained in S1!"  << endl;//ADD *****************
	 }
	

	_strncpy(mydestination, mydestination2, 6);//ADD *****************
	cout << "Copy 6 characters: " << _strstr(mydestination, mydestination2) << endl;//ADD *****************



	cout << "S1 & S2 compare as follows : " << (_strcmp(s1, s2)==0? "Equal": " Not equal") << endl; //ADD *****************


 
	cout << "S1 & S2 compare 5 characters as follows : " <<  (_strncmp(s1, s2, 5) == 0 ? "Equal" : " Not equal") << endl;//ADD *****************

	 

	int stop;
	cin >> stop;
	return 0;

}


// example of string copy operation

void  _strcpy(char *destination, const char *source) {


	int i = 0;

	while (source[i]) {

		destination[i] = source[i];

		i++;

	}

	destination[i] = '\0';

}


//more elegant implementation of string copy

void _strcpy2(char *destination, const char *source) {


	//check if source is not null and destination is not null

	while (*source) {
		*destination++ = *source++;
	}
		

}


//example implementation of string length.

int _strlen(const char* str) {


	int len = 0;

	while (*str++) len++;



	return len;

}

//example implementation of string compare

int _strcmp(const char* s1, const char* s2) {


	while (*s1 && (*s1 == *s2))

	{

		s1++;

		s2++;

	}

	return *(const unsigned char*)s1 - *(const unsigned char*)s2;

}


//Fill in this method so that calling _stracat can append s2 contents to s1

void _strcat(char* s1, const char* s2) {

	int s1length; //ADD *****************
	s1length = _strlen(s1);//ADD *****************
	s1 = s1 + s1length; // get end address of s1//ADD *****************
	while (*s2) {//ADD *****************
		*s1 = *s2; // asign *s2 content to end address of s1 //ADD *****************
		s1++;//ADD *****************
		s2++;//ADD *****************
	}//ADD *****************
	*s1 = '\0'; //ADD *****************
}

//check if string s2 is inside or embedded within string s1

char* _strstr(char *s1, char *s2) {
	  
	int s1lenght,s2lenght;//ADD *****************
	int matchcounter=0;//ADD *****************
	s1lenght = _strlen(s1);//ADD *****************
	s2lenght= _strlen(s2) ; //ADD *****************
	
	for (int i = 0; i < s1lenght; i++) {//ADD *****************
		matchcounter = 0;//ADD *****************
		for (int j = 0; j < s2lenght; j++) {//ADD *****************
			if ((i + s2lenght) > s1lenght) {return strstr_ptr;}//{return s1+ s1lenght;}//ADD *****************
			if (*(s1 + i + j) == *(s2 + j)) { matchcounter++; }//ADD *****************
		}//ADD *****************
		
		if (matchcounter == s2lenght) {return  s1 + i;}//ADD *****************
	}//ADD *****************
	return strstr_ptr; //return s1 + s1lenght;//ADD *****************
}

// _strcpy for specified number of characters n.

void _strncpy(char *s1, char* s2, int n) {
	
	while (*s2 || n==0) {//ADD *****************
		*s1++ = *s2++;//ADD *****************
		n--;//ADD *****************
	}//ADD *****************
	*s1 = '\0';//ADD *****************
}

// _strcmp for specified number of characters n.

 
int _strncmp(const char* s1, const char*s2, int n) {

	while (*s1 && (*s1 == *s2))//ADD *****************

	{//ADD *****************
 
		s1++;//ADD *****************
		s2++;//ADD *****************
		n--;//ADD *****************
		
		 if (n == 1) { break; }//ADD *****************

	}

	return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

// _strcat for specified number of characters n.

void _strncat(char* s1, const char *s2, int n) {
	int s1length; //ADD *****************
	s1length = _strlen(s1);//ADD *****************
	s1 = s1 + s1length; // get end address of s1//ADD *****************
	while (n) {//ADD *****************
		*s1 = *s2; // asign *s2 content to end address of s1 //ADD *****************
		s1++;//ADD *****************
		s2++;//ADD *****************
		n--;
	}//ADD *****************
	*s1 = '\0'; //ADD *****************
}

