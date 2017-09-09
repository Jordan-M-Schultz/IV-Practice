#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>

using namespace std;
typedef struct {
	int nice;
	char* hello;
	//allocation of 
}data;

string reverse(string temp);

int main(int argv, char* argv){

	return 0;
}

string reverse(string temp){
	string back;
	cout << temp.size() << endl;
	for(int i = temp.size()-1 ; i >= 0; i--)
		back[(temp.size()-1) - i] = temp[i];
	
	return back;

} //reverse