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
string reverse2(string temp);
bool checkPermutation(string a, string b);

int main(int argv, char** argc){
	//testUnique();
	string a = "hello";
	string b = "hello";
	cout << checkPermutation(a,b) << endl;

	return 0;
}

bool checkPermutation(string a, string b){
	if(a.length() == 0 || b.length() == 0) //if empty string
		return false;
	else if(a.length() != b.length()) //permutations must have same length
		return false;
	else{
		unordered_multimap<char,int> storage;
		unordered_multimap<char,int>::const_iterator it; //use multimap in case of multiple similar char
		
		for(int i = 0 ; i < a.length(); i++) //store all of string a
			storage.insert(make_pair(a[i],(int)a[i]));
		
		for(int i = 0 ; i < b.length(); i++)
		{
			it = storage.find(b[i]);
			if(it == storage.end())//character has not been found
				return false;
			else
				it = storage.erase(it);
		}//for
	}//else
	return true;
}//checkPermutation


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
	//Reverse using O(n) space

	string back = temp;
	for(int i = temp.size()-1 ; i >= 0; i--)
		back[(temp.size()-1) - i] = temp[i];

	return back;

} //reverse

string reverse2(string temp){ // in place reversal, 0(1) space
	int ct = temp.size()/2;
	char hold;
	for(int i = 0  ; i < ct ; i++){ //loop to middle
		hold = temp[i];
		temp[i] = temp[temp.length()-i-1];
		temp[temp.length()-i-1] = hold; 
	}
	return temp;


}//reverse2


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
