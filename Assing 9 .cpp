		#include <iostream> //
		#include <iomanip> //
		#include <fstream> //
		#include <string> //
		#include <cctype> //
		using namespace std;
		
		struct qbStats
		{ 
		  string first;
		  string last;
		  unsigned int completions;
		  unsigned int attempts;
		  unsigned int yards;
		  unsigned int td;
		  unsigned int interceptions;
		  double qbRating; 
		};
		
		const int QBS = 20;
		
		string Tolower(string);
		double qbr(int completions, int attempts, int yards, int td, int interceptions);
		void RatingLead (qbStats);
		void QBNames (string name, qbStats[]);
		void YardsLead (qbStats);
		void TdLead (qbStats);
		void IntLead (qbStats);
		
		
		int main(int args, char * argv[])
		{
			qbStats quarterBacks[QBS];
			ifstream in;
		 
			cout << fixed << setprecision(1);
		 
			in.open(argv[1]);
			if (!in.is_open())
			{
				cout << "FILE: " << argv[1] << " does not exist!" << endl;
				in.close();
				return 0;
			}
		 
			//YOUR CODE WOULD COME HERE
		 
		 while (!in.eof())
		 {   
		 for (int i=0; i < QBS; i++)
		 {
				in >> quarterBacks[i].first;
			  in >> quarterBacks[i].last;
			  in >> quarterBacks[i].completions;
			  in >> quarterBacks[i].attempts;
			  in >> quarterBacks[i].yards;
			  in >> quarterBacks[i].td;
			  in >> quarterBacks[i].interceptions;
			   quarterBacks[i].qbRating = qbr(quarterBacks[i].completions, quarterBacks[i].attempts, quarterBacks[i].yards, quarterBacks[i].td, quarterBacks[i].interceptions);
		 }
		}
		 cout << "Quarterback stats read in..." << endl;
	  char soq; //This character holds the decision of whether the user wants to search or quit "soq"
	  cout << "Enter 'q' to quit or 's' to search: ";
	  cin >> soq;
	  do {
		soq = tolower(soq);
		if (soq == 'q') {
		  cout << "Ok, done! Good luck to every qb for the MVP race!" << endl;
		  return 0;
		}
		else if (soq == 's') {
		  string choice; //This string will hold the choice the user wants to examine
		  cout << "Enter=> NAME, YARDS, TDS, INTS, RATING: ";
		  cin >> choice;
		  //All that is indented are the possible choices
			choice = Tolower(choice);
			if (choice == "name") {
			  string name; //This string will hold the name of the player the user is searching for
			  cout << "Enter last name: ";
			  cin >> name;
			  QBNames(name, quarterBacks);
			}
			else if (choice == "yards"){
			  YardsLead(quarterBacks);
			}
			else if (choice == "tds"){
			 TdLead(quarterBacks);
			}
			else if (choice == "ints"){
			  IntLead(quarterBacks);
			}
			else if (choice == "rating"){
			  RatingLead(quarterBacks);
			}
			else {
			  cin.clear();
			  cin.ignore(100, '\n');
			  cout << "Search characteristic not found." << endl << "Enter=> NAME, YARDS, TDS, INTS, RATING: ";
			  cin >> choice;
			}
		}
		else {
		  cin.clear();
		  cin.ignore(100, '\n');
		  cout << "Invalid option!" << endl;
		}
		cout << "\nEnter 'q' to quit' or 's' to search: ";
		cin >> soq;
	  } while (soq);
			return 0;
		}	
			
			// string too turn letters too lowercase
	string Tolower(string word) 
			{
		  int length = word.length();
		  for(int i = 0; i < length; i++)
			word[i] = tolower(word[i]);
		  return word;
		  }
		  
		  void QBNames(string name, qbStats quarterBacks[]) 
		  {
		  bool found = false; 
		  name[0] = toupper(name[0]);
		  int length = name.length(); 
		  for (int i = 1; i <= length; i++)
			name[i] = tolower(name[i]);
		  for (int i = 0; i < QBS; i++) 
		  {
			if (quarterBacks[i].last == name) 
			{
			  cout << quarterBacks[i].last << ", " << quarterBacks[i].first << endl;
			  cout << "Completions: " << quarterBacks[i].completions << endl;
			  cout << "Attempts: " << quarterBacks[i].attempts << endl;
			  cout << "Touchdowns: " << quarterBacks[i].td << endl;
			  cout << "Interceptions: " << quarterBacks[i].interceptions << endl;
			  cout << "Rating: " << quarterBacks[i].qbRating << endl;
			  found = true; //This sets the flag true
			  break;
			}
		  }
		  if (!found) 
		  {
			  cout << "Quarterback not in list" << endl;
		  }
		}
		  
		  
		  double qbr (int completions, int attempts, int yards, int td, int interceptions) 
		  {
		  double Rating ; 
		  double a, b, c, d; 
		  a = (static_cast<double>(completions) / attempts - 0.3) * 5;
		  b = (static_cast<double>(yards) / attempts - 3) * .25;
		  c = (static_cast<double>(td) / attempts) * 20;
		  d = 2.375 - (static_cast<double>(interceptions) / attempts * 25);
		  Rating = ((a + b + c + d) / 6) * 100;
		  return Rating;
		}
		
		void YardsLead(qbStats quarterBacks[]) 
		{
		   unsigned int max = quarterBacks[0].yards;
		   int max_index = 0; 
		   for (int i = 1; i < QBS; i++) 
		   {
			 if (quarterBacks[i].yards > max) 
			 {
			   max = quarterBacks[i].yards;
			   max_index = i;
			 }
		   }
		   cout << "Quarterback with the most yards" << endl;
		   cout << quarterBacks[max_index].last << ", " << quarterBacks[max_index].first << endl;
		   cout << "Yards: " << quarterBacks[max_index].yards << endl;
		}
		
		void RatingLead(qbStats quarterBacks[])
		{
		   unsigned int max = quarterBacks[0].qbRating; 
		   int mi = 0; 
		   for (int i = 1; i < QBS; i++) {
			 if (quarterBacks[i].qbRating > max) {
			   max = quarterBacks[i].qbRating;
			   mi = i;
			 }
		   }
		   cout << "Quarterback with highest rating" << endl;
		   cout << quarterBacks[mi].last << ", " << quarterBacks[mi].first << endl;
		   cout << "Rating: " << quarterBacks[mi].qbRating << endl;
		}
		void IntLead(qbStats quarterBacks[])
		{
		   unsigned int max = quarterBacks[0].interceptions; 
		   int mi; 
		   for (int i = 1; i < QBS; i++) {
			 if (quarterBacks[i].interceptions > max) 
			 {
			   max = quarterBacks[i].interceptions;
			   mi = i;
			 }
		   }
		   cout << "Quarterbacks with most interceptions" << endl;
		   cout << quarterBacks[mi].last << ", " << quarterBacks[mi].first << endl;
		   cout << "Interceptions: " << quarterBacks[mi].interceptions << endl;
		}
		
		  void TdLead(qbStats quarterBacks[])
		  {
		   unsigned int max = quarterBacks[0].td; 
		   int mi = 0; 
		   for (int i = 1; i < QBS; i++) 
		   {
			 if (quarterBacks[i].td > max)
			 {
			   max = quarterBacks[i].td;
			   mi = i;
			 }
		   }
		   cout << "Quarterback with most touchdowns" << endl;
		   cout << quarterBacks[mi].last << ", " << quarterBacks[mi].first << endl;
		   cout << "Touchdowns: " << quarterBacks[mi].td << endl;
		}
  
