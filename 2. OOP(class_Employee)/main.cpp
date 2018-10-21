#include <iostream>
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
		    string _name,
		    int _salary
	) 
	{
		id = _id;
		name = _name;
		salary = _salary;
	}

	virtual float getSalary() = 0;

	virtual string getName() {
		return name;
	}

	virtual int getID() {
		return id;
	}

protected:

	int salary;
	string name;
	int id;
};

class HourlyEmployee : public Employee
{
public:

	HourlyEmployee(int _id, string _name, int _salary) : Employee(_id, _name, _salary) {}

	float getSalary()
	{
		return 20.8 * 8 * salary;
	}
};

class fixedEmployee : public Employee
{
public:

	fixedEmployee(int _id, string _name, int _salary) : Employee(_id, _name, _salary) {}

	float getSalary()
	{
		return salary;
	}
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
	myException(char *_msg, int _dataState)
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

int main() {
		
	vector<Employee*> employee;

	employee.push_back(new HourlyEmployee(1, "David", 8));

	employee.push_back(new fixedEmployee(2, "Tom", 1200));

	employee.push_back(new HourlyEmployee(3, "Max", 9));

	employee.push_back(new fixedEmployee(4, "Lisa", 110));

	employee.push_back(new HourlyEmployee(5, "Cannye", 8));

	employee.push_back(new fixedEmployee(6, "Andrew", 900));

	for (int i = 0; i < employee.size(); i++)
		cout << employee[i]->getID() << ' ' << employee[i]->getName().c_str() << ' ' << employee[i]->getSalary() << endl;
	
	cout << endl << "sort" << endl;
	sort(employee.begin(), employee.end(), lessEmployee());

	for (int i = 0; i < employee.size(); i++)
		cout << employee[i]->getID() << ' ' << employee[i]->getName().c_str() << ' ' << employee[i]->getSalary() << endl;

	cout << endl;

	system("pause");

	return 0;
}

