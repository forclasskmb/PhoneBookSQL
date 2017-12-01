#include <iostream>
#include <string>
#include <map>

// Stuff for AJAX
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#include "PhoneBook.h"
#include "PhoneEntry.h"

#define XML_USE_STL

using namespace std;
using namespace cgicc; // Needed for AJAX functions.

int main() {
  Cgicc cgi;    // Ajax object
  char *cstr;

  PhoneBook pb; // Phone Book SQL Interface Object
  vector<PhoneEntry> pbResults;
  
  // Create AJAX objects to recieve information from web page.
  form_iterator op = cgi.getElement("operation");
  form_iterator searchString = cgi.getElement("find");

  string operation = **op;
  string search = **searchString;

  string output = "Error =- Operation not support yet!";
  if (operation == "Find Last") {
    pbResults = pb.findByLast(search);
    if (pbResults.size() > 0) {
      output = "success";
      for (int i = 0; i<pbResults.size(); i++) {
	output += "," + pbResults.at(i).first + ","
	  + pbResults.at(i).last + ","
	  + pbResults.at(i).phone + ","
	  + pbResults.at(i).type + ","
	  + pbResults.at(i).recnum;

      }
    } else {
      output = "No Match Found";
    }
  }
  /* send back the results */
  cout << "Content-Type: text/plain\n\n";

  cout << output << endl;
  
  
  return 0;
}

