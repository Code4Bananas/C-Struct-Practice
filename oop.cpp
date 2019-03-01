#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>

class Animal {
protected: 
	std::string name;
	double height;
	double weight;
	
	//share same value for all objects of the Animal class,
	//if the value changes it changes for every object of the Animal class
	static int numOfAnimals;
	
//accessible anywhere where the object itself is accessible	
public:
	//function created to get name outside of the object class
	std::string GetName(){return name;}
	//assigns the name to the object using a pointer operator and this
	void SetName(std::string name){this->name = name;}
	double GetHeight(){return height;}
	void SetHeight(double height){this->height = height;}
	double GetWeight(){return weight;}
	void SetWeight(double weight){this->weight = weight;}
	
	//function to allow user to set all the values or reset them
	//names not needed for prototypes
	void SetAll(std::string, double, double);
	
	//constructor, called each time an object is created
	Animal(std::string, double, double);
	//overload constructor for no attributes passed
	Animal();
	//destructor, to release memory or conserve system resources
	~Animal();
	static int GetNumberOfAnimals(){return numOfAnimals;}
	//for overriding
	void ToString();
};

int Animal::numOfAnimals = 0;
void Animal::SetAll(std::string name, double height, double weight)
{
	this->name = name;
	this->weight = weight;
	this->height = height;
	Animal::numOfAnimals++;
}

//constructor
Animal::Animal(std:string name, double height, double weight)
{
	this->name = name;
	this->height = height;
	this->weight = weight;
	Animal::numOfAnimals++;
}

//constructor for default
Animal::Animal()
{
	this->name = "";
	this->height = 0;
	this->weight = 0;
	Animal::numOfAnimals++;
}

//deconstructor
Animal::Animal()
{
	std::cout << "Animal " << this->name << " destroyed\n";
}

void Animal::ToString()
{
	std::cout << this->name << " is " << this->height << "cms tall and" <<
				this->weight << "kgs in weight\n";
}

class Dog: public Animal {
private:
	std::string sound = "Woof";
public:
	void MakeSound() {
		std::cout << "The dog " << this->GetName() << " says " << this->sound <<
				endl;
	}
	Dog(std::string, double, double, std::string);
	Dog(): Animal(){};
	void ToString();
}

//inheriting from Animal class
Dog::Dog(std::string name, double height, double weight, std::string sound) :
Animal(name, height, weight) {
	this->sound = sound;
}

void Dog::ToString()
{
	std::cout << this->GetName() << " is " << this->GetHeight() << "cms tall and" <<
				this->GetWeight() << "kgs in weight and says " << this->sound << endl;
}

int main()
{
	Animal fred;
	fred.ToString();
	fred.SetHeight(33);
	fred.SetWeight(10);
	fred.SetName("Fred");
	fred.ToString();
	
	//using constructor
	Animal tom("Tom", 36, 15);
	tom.ToString();
	
	Dog spot("Spot", 38, 16, "Woooooooooooooof");
	spot.ToString();
	
	std::cout << "Number of Animals " << Animal::GetNumOfAnimals() << "\n";
	
	return 0;
}