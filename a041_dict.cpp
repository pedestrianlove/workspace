#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

size_t num_of_employee;
int * salary;
unordered_map<string, int> min_map;
unordered_map<string, int> max_map;


// function area
int max (int x, int y) {
	if (x > y) return x;
	else return y;
}
int min (int x, int y) {
	if (x < y) return x;
	else return y;
}
string idx (int x, int y) {
	string tmp = ",";

	return to_string (x) + tmp + to_string (y);
}

// query functions
int query_max (int x, int y) {
	if (x == y) return salary[x];
	else if (max_map.find (idx (x, y)) != max_map.end ()) 
		return max_map[idx (x, y)];
	else {
		int mid = (x + y) / 2;
		int prev = query_max (x, mid);
		max_map[idx (x, mid)] = prev;
		int next = query_max (mid + 1, y);
		max_map[idx (mid, y)] = next;
		return max (prev, next);
	}
}
int query_min (int x, int y) {
	if (x == y) return salary[x];
	else if (min_map.find (idx (x, y)) != min_map.end ()) 
		return min_map[idx (x, y)];
	else {
		int mid = (x + y) / 2;
		int prev = query_min (x, mid);
		min_map[idx (x, mid)] = prev;
		int next = query_min (mid + 1, y);
		min_map[idx (mid, y)] = next;
		return min (prev, next);
	}
}




int main ()
{
	// variables
	int queries;
	cin >> num_of_employee >> queries;
	salary = new int[num_of_employee];
	
	// input employee salaries
	for (int k = 0; k < num_of_employee; k++) {
		cin >> salary[k];
	}
	
	
	// accept && answer queries
	int start, end;
	for (int k = 0; k < queries; k++) {
		cin >> start >> end;
		cout << query_max (start - 1, end - 1) -  query_min (start - 1, end - 1) << endl;
	}


	// free
	delete (salary);

	
}
