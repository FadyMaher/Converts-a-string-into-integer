#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
};
int convertToInt(const string& s) throw (myexception)
{

    myexception myexc;
	int n = s.length() -1;
	if ( s.length()  == 1)
	{
		if(isdigit(s[0]))
			return s[0]- '0'; // convert the char if it's length is 1 to it's numeric value
		else{
            throw myexc;
		}

	}
	 return convertToInt(s.substr(s.length() - 1,1)) + convertToInt(s.substr(0, n--) ) * 10 ;
}
int main()
{

	string test = "1234";
try {
	cout<< convertToInt(test)<<endl;
}
catch (exception &e){
cout << e.what();
}

	return 0;
}
