#include <string>
using namespace std;

#ifndef PHONEENTRY_H
#define PHONEENTRY_H

class PhoneEntry {
public:
     PhoneEntry();
     PhoneEntry(string f, string l, string p, string t, string r);
     string first;
     string last;
     string phone;
     string type;
     string recnum;

private:

};

#endif /* PHONEENTRY_H */

