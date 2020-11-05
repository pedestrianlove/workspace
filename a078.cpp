#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// class to manage card stack
class Grade {
	private:
	// class to store basic card properties
	class Student {
		public:
		int number, english_grade, math_grade;
		Student (int num, int math, int english) {
			number = num;
			math_grade = math;
			english_grade = english;
		}
		void print () {
			cout << number << " " << math_grade << " " << english_grade << endl;
		}
	};
	static bool cmp (Student X, Student Y) {
		if (X.math_grade != Y.math_grade)
			return X.math_grade > Y.math_grade;
		else
			return X.english_grade > Y.english_grade;
	}
	vector<Student> student_list;
	
	public:
	Grade (int num_of_student) {
		int number, math_grade, english_grade;	
		for (int i = 0; i < num_of_student; i++) {
			cin >> number >> math_grade >> english_grade;
			Student student (number, math_grade, english_grade);
			student_list.push_back (student);
		}
	}
	
	void qsort () {
		sort (student_list.begin (), student_list.end (), cmp);
	}

	void print () {
		for (int i = 0; i < student_list.size (); i++) 
			student_list[i].print ();
	}

};


// driver code
int main ()
{	
	// input
	int student_count;
	cin >> student_count;

	// process
	Grade grade (student_count);
	grade.qsort ();

	// output
	grade.print ();
	
}
