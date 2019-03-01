#include <iostream>
#include <cmath>

//creating the struct with parameters name and age
//basically creating an object
struct newperson
{
	char name[20];
	int age;
};

int main()
{
	using namespace std;
	
  //creating a new person named "bob"
	newperson bob = 
	{
		"Bob",
		12
	};
	
  //command line to display output
	cout << bob.name << endl;
	
  //called a pause to review output
	system("pause");
  //exit program
	return 0;
}
