
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "PhoneBook.h"
#include "PhoneEntry.h"


using namespace std;

int main(){
    PhoneBook pb;
    vector<PhoneEntry> pbResults;

    cout << "Phone Book test program" << endl;

    cout << "Enter last name to find:";
    string lastMatch;
    cin >> lastMatch;
    
    pbResults = pb.findByLast(lastMatch);
    
    for (int i = 0; i<pbResults.size(); i++) {
	cout << pbResults.at(i).first << " "
	     << pbResults.at(i).last << " "
	     << pbResults.at(i).phone << " "
	     << pbResults.at(i).type << " "
	     << pbResults.at(i).recnum
	     << endl;
    }

    return 0;}

