#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
	public:
	bool knew, stop;
	int id, touched;
	vector<Person *> friend_list;
	Person (int ID) {
		stop = false;
		knew = false;
		touched = 0;
		id = ID;
	}

	void Friend (Person* A) {
		friend_list.push_back (A);
	}

	void Spread () {
		if (! knew) {
			//cout << id << " is getting the news..." << endl;
			knew = true;
		}
		if (! stop) {
			for (auto i = friend_list.begin (); i != friend_list.end (); ++i) {
				if (! (*i)->knew)
					(*i) -> Spread ();
			}
		}
		else {
			//cout << id << " stopped the news..." << endl;
		}
	}
};

bool cmp (Person &A, Person &B) {
	if (A.touched != B.touched)
		return A.touched < B.touched;
	else
		return A.id < B.id;
}


int main ()
{
	vector<Person> man_list;
	
	int population, link;
	while (cin >> population >> link) {
		// input: man_list
		for (int i = 0;i < population; i++) {
			man_list.push_back (Person (i+1));	// FIXME
		}

		// input: friend_link
		int a, b;
		for (int i = 0;i < link; i++) {
			cin >> a >> b;
			man_list[a-1].Friend (&man_list[b-1]);
			man_list[b-1].Friend (&man_list[a-1]);
		}

		// try to spread news without blockage
		int target;	cin >> target;
		int effect = 0;
		man_list[target-1].Spread ();
		for (int j = 0;j < population; j++) {
			if (man_list[j].knew) {
				effect ++;
				man_list[j].knew = false;
				man_list[j].stop = false;
			}
		}



		// find the most effect blockage
		for (int i = 0; i < population ; i++) {
			//cout << "---------------------------" << endl;
			int counter = 0; 
			man_list[i].stop = true;
			
			// spread
			//cout << man_list[0].knew << endl;
			//cout << "Start spreading..." << endl;
			man_list[target-1].Spread ();
			
			for (int j = 0;j < population; j++) {
				if (man_list[j].knew) {
					counter ++;
					man_list[j].knew = false;
					man_list[j].stop = false;
				}
			}

			man_list[i].touched = counter;
		}

		// sort by blockage result
		sort (man_list.begin (), man_list.end (), cmp);
		
		// output
		int idx = 0;
		if (man_list[idx].id == target) idx++;
		if (man_list[idx].touched == effect)
			cout << 0 << endl;
		else
			cout << man_list[idx].id << " " << man_list[idx].touched << endl;
		// clean up
		man_list.clear ();
	}


}
