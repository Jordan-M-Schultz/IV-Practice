#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <unordered_map> // <Key,Val>

using namespace std; //Dont do this in practice
typedef struct {
	int nice;
	char* hello;
	//allocation of 
}data;

string reverse(string temp);
bool checkUnique(string temp);
void testUnique();
int main(int argv, char** argc){
	testUnique();
	return 0;
}

void testUnique(){
	string test[4] = {"abcdefg","hello","caedfnkic",""};
	for(int i = 0 ; i < 4 ; i++){
		bool cc = checkUnique(test[i]);
		if(!cc)
			cout << "duplicate char found within " << test[i] << endl;
		else
			cout << "no duplicates found within " << test[i] << endl;
	}//for
}

string reverse(string temp){
	string back;
	cout << temp.size() << endl;
	for(int i = temp.size()-1 ; i >= 0; i--)
		back[(temp.size()-1) - i] = temp[i];
	
	return back;

} //reverse

bool checkUnique(string temp){
	//Check if given string has unique characters throughout
	if(!temp.length())
	{
		cout << "no given string ";
		return false;
	}

	unordered_map<int,char> chars;
	for(int i = 0 ;i < temp.length() ; i++){
		unordered_map<int,char>::const_iterator it = chars.find(temp[i]);
		if(it == chars.end()) // not found
			//chars.insert({(int)temp[i],temp[i]});
			chars.insert(make_pair((int)temp[i],temp[i]));
		else
			return false;
	}//for
		return true;

}
