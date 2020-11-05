#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// class to manage card stack
class Card_Stack {
	private:
	// class to store basic card properties
	class Card {
		private:
		char ch_type;
		int int_type (char card_type) {
			switch (card_type) {
				case 'S':
					return 4;
				case 'H':
					return 3;
				case 'D':
					return 2;
				case 'C':
					return 1;
			}
			return 0;
		}
	
		public:
		int type;
		int number;
		Card (char card_type, int card_number) {
			number = card_number;
			type = int_type (card_type);
			ch_type = card_type;
		}
		void print () {
			cout << ch_type << number << " ";
		}
	};
	static bool cmp (Card X, Card Y) {
		if (X.type != Y.type)
			return X.type > Y.type;
		else
			return X.number > Y.number;
	}
	
	public:
	vector<Card> card_list;

	Card_Stack () {
		string tmp;
		getline (cin, tmp);
		
		size_t position = 0;
		
		string token, delim = " ";
		while ((position = tmp.find (delim)) != string::npos) {
			token = tmp.substr (0, position);
			Card card (token[0], stoi (token.substr (1, token.length() - 1)));
			card_list.push_back (card);
			tmp.erase (0, position + delim.length ());
//			cout << "Remaining string: " << tmp << endl;
		}
		Card card (tmp[0], stoi (tmp.substr (1, tmp.length() - 1)));
		card_list.push_back (card);
		
	}
	
	void qsort () {
		sort (card_list.begin (), card_list.end (), cmp);
	}

	void print () {
		for (int i = 0; i < card_list.size (); i++) 
			card_list[i].print ();
		cout << endl;
	}

};


// driver code
int main ()
{	
	int stack_count;
	cin >> stack_count;
	string tmp;
	getline (cin, tmp);
	for (int i = 0; i < stack_count; i++) {
//		cout << "Sorting the "  << i + 1 << "th stack of card." << endl;
		Card_Stack card_stack;
//		card_stack.print ();
		card_stack.qsort ();
		card_stack.print ();
	}	
}
