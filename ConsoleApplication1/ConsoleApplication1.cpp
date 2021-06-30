/*
This is a practice program for c++ class implementation.
The first class is called Student, it has 3 string data and a vector of int
The second class is called Section which include multiple students with size of an int
*/


#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

//Student class
class Student {
private:
	string id, fname, lname;
	vector<int> grade;
public:
	//student class constructor
	Student(string inputid, string inputfname, string inputlname) {
		id = inputid;
		fname = inputfname;
		lname = inputlname;
	}
	//return all student information into a string variable
	string toString() {
		float gpanum = gpa();  //call gpa function
		string gpastr = to_string(gpanum).substr(0, 3);  //only want 1 digit decimal of gpa
		string toreturn = id + ": " + lname + ", " + fname + " " + gpastr;  //combine everything together
		return toreturn;
	}
	//add grade function
	void addgrade(int number) {
		grade.push_back(number);
	}
	//gpa function, loop through grade vector and compute the average
	float gpa() {
		float count = 0, sum = 0, result = 0;
		for (auto i = grade.begin(); i != grade.end(); i++) {
			sum += *i;
			count++;
		}
		result = sum / count;
		return result;
	}
};

//section class
class Section {
private:
	vector<Student> list;  //vector of students
	int size;  //section size
public:
	Section(int number) {  //section constructor, set up size of the section
		size = number;
	}
	//enroll function
	void enroll(Student students) {
		if (list.size() < size) {
			list.push_back(students);
		}
		else {  //error message if section is full
			cerr << "Section is full" << endl;;
		}
	}
	void display() { //loop through list vector to output the information of all the students
		for (auto i = list.begin(); i != list.end(); i++) {
			Student j = *i;
			cout << j.toString() << endl;
		}
	}
};

int main()
{
	//initialize section
	Section mysection = Section(2);
	cout << "Test driver for Section and Student classes" << endl;

	//initialize students id, names, and grades
	Student student1 = Student("aa1234", "Cano", "Alice");
	Student student2 = Student("bb2345", "Ali", "Zeke");
	Student student3 = Student("cc5566", "Oh", "No");
	student1.addgrade(2);
	student1.addgrade(4);
	student2.addgrade(3);
	student2.addgrade(4);
	student3.addgrade(4);
	student3.addgrade(5);

	//enroll students into section
	mysection.enroll(student1);
	mysection.enroll(student2);
	mysection.enroll(student3);

	//display information of the section
	mysection.display();

}