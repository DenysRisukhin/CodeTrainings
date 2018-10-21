#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <functional>
#include <list>
#include <set>
#include <map>
#include <iomanip>
#include <exception>

using namespace std;

class Employee
{
public:

	Employee(int _id,
		string _name
	)
	{
		id = _id;
		name = _name;
	}

	virtual float getSalary() = 0;

	virtual string getName() {
		return name;
	}

	virtual int getID() {
		return id;
	}

protected:

	string name;
	int id;
};

class HourlyEmployee : public Employee
{
public:

	HourlyEmployee(int _id, 
		           string _name, 
		           int _salary) : 
		           Employee(_id, _name), 
		           salaryHaurly(_salary) {}

	float getSalary()
	{
		return 20.8 * 8 * salaryHaurly;
	}

private:
	float salaryHaurly;
};

class fixedEmployee : public Employee
{
public:

	fixedEmployee(int _id, 
				  string _name, 
		          int _salary) : 
		          Employee(_id, _name),
		          salaryFixed(_salary) {}

	float getSalary()
	{
		return salaryFixed;
	}
private:

	float salaryFixed;
};

struct lessEmployee
{
	bool operator () (Employee * a,
		Employee * b
	 )
	{
		if (a->getSalary() == b->getSalary())
			return a->getName() < b->getName();
		else
			return a->getSalary() > b->getSalary();
	}
};

class myException : public exception
{
public:
	myException(char *_msg, 
		        int _dataState
	)
		: exception(_msg)
	{
		this->dataState = _dataState;
	}

	int getDataState()
	{
		return dataState;
	}

private:
	int dataState;
};

class Data {
public:
	Data(int _type, 
		int _id,
		string _name, 
		int _salary
	) :
		type(_type),
		id(_id),
		name(_name),
		salary(_salary) {}

	int getType() 
	{
		return type;
	}

	int getID() 
	{
		return id;
	}

	string getName()
	{
		return name;
	}

	float getSalary() 
	{
		return salary;
	}

private:
	int type;
	int id;
	string name;
	float salary;
};

int main() {

	vector<Data> reandomData;
	reandomData.push_back(Data(0, 1, "David", 8));
	reandomData.push_back(Data(1, 2, "Tom", 1200));
	reandomData.push_back(Data(0, 3, "Max", 9));
	reandomData.push_back(Data(0, 4, "Lisa", 110));
	reandomData.push_back(Data(1, 5, "Cannye", 8));
	reandomData.push_back(Data(1, 6, "Andrew", 900));

	srand((unsigned)time(NULL));

	random_shuffle(reandomData.begin(), reandomData.end());

	ofstream("foo.txt");

	ofstream file;

	file.open("foo.txt");

	if (!file.is_open())
	{
		cerr << "Error: File can't be opened \n";
		terminate();
	}

	for (auto iter = reandomData.begin(); iter != reandomData.end(); iter++)
		file << (*iter).getType() << " " << (*iter).getID() << " " << (*iter).getName().c_str() << " " << (*iter).getSalary() << endl;

	file.close();

	// read from file

	FILE *fileFoo;

	fileFoo = fopen("foo.txt", "r");

	if (!fileFoo)
	{
		cerr << "Error: File can't be opened \n";
		terminate();
	}

	list<Employee*> employee;

	char name[20];
	int type = 0;
	int id = 0;
	float salary = 0;
	int i = 0;

	while (fscanf(fileFoo, "%i %i %s %f \n", &type, &(id), name, &(salary)) != EOF)
	{
		if (type)
			employee.push_back(new fixedEmployee(id, name, salary));
		else
			employee.push_back(new HourlyEmployee(id, name, salary));
		i++;
	}

	fclose(fileFoo);

	for(auto iter = employee.begin(); iter != employee.end(); iter++)
		(*iter)->getSalary();

	employee.sort(lessEmployee());

	int counter = 0;

	for (auto iter = employee.begin(); iter != employee.end(); iter++)
	{
		if (counter < 5) {
			std::cout << (*iter)->getName().c_str() << endl;
		}
		counter++;
	}

	cout << endl;

	system("pause");

	return 0;
}

