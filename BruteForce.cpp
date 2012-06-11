/* Search for a word in a given puzzle by brute force string matching
   algorithm. The search includes horizontal, vertical and diagonal search 
   from straight and reverse way.

   Author: Uday Subedi
   Cameron University, Fall 2010

*/ 

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

char puzzle[12][12];
string input;
bool found=false;

/*******/
void create_puzzle (){

/* Open the file and put into 2D array */
ifstream myFile;
myFile.open("word.text");
if (myFile.is_open()) {
	for(int i=0; i<12; i++)
	{
		for(int j=0; j<12; j++)
		    myFile >> puzzle[i][j];
	}
 }//if
 myFile.close();

/* Display the puzzle */
cout<<endl;
for(int i=0; i<13; i++) cout<<setw(3)<<i; cout<<endl;
for(int i=0; i<12; i++){
	cout<<setw(3)<<i+1;
	for(int j=0; j<12; j++)
	{
	cout<<setw(3)<<puzzle[i][j];
	}
	cout<<endl;
}
cout<<endl;
}/******/

/* Search the puzzle using bruteforce alogrithm*/

/* Left to right*/
int searchLR(string input, char puzzle[][12])
{
for(int i=0; i<12; i++)
{
	for(int j=0; j<=12-input.length(); j++)
	{
		int x=0;
		while(x<input.length() && puzzle[i][j+x]==input.at(x))
		{
			x++;
		}
		if(x==input.length())
		{
			cout<<input<<" found at: ["<<j+1<<","<<i+1<<"] "<<", L-R" <<endl;
			found=true;
		}
	}

}
}

/* Top to bottom */
int searchTB(string input, char puzzle[][12])
{
for(int i=0; i<12; i++)
{
        for(int j=0; j<=12-input.length(); j++)
        {
                int x=0;
                while(puzzle[j+x][i]==input[x] && x<input.length())
                {
                        x++;
                }
                if(x==input.length())
                {
                        cout<<input<<" found at: ["<<j+1<<","<<i+1<<"] "<<", T-B" <<endl;
			found=true;
                }
        }

}
}

/* Right to left */
int searchRL(string input, char puzzle[][12])
{
for(int i=0; i<12; i++)
{
        for(int j=12; j>input.length(); j--)
        {
                int x=0;
                while(puzzle[i][j-x]==input[x] && x<input.length())
                {
                        x++;
                }
                if(x==input.length())
                {
                        cout<<input<<" found at: ["<<j+1<<","<<i+1<<"] "<<", R-L" <<endl;
			found=true;
                }
        }

}
}

/* Bottom to top */
int searchBT(string input, char puzzle[][12])
{
for(int i=0; i<12; i++)
{
        for(int j=12; j>input.length(); j--)
        {
                int x=0;
                while(puzzle[j-x][i]==input[x] && x<input.length())
                {
                        x++;
                }
                if(x==input.length())
                {
                        cout<<input<<" found at: ["<<j+1<<","<<i+1<<"] "<<", T-B" <<endl;
                        found=true;
                }
        }

}
}

/* Diagonal from left to right*/

int searchDLR(string input, char puzzle[][12])
{
for(int i=0; i<12; i++)
{
        for(int j=0; j<=12-input.length(); j++)
        {
                int x=0;
                while(x<input.length() && puzzle[i+x][j+x]==input[x])
                {
                        x++;
                }
                if(x==input.length())
                {
                        cout<<input<<" found at: ["<<j+1<<","<<i+1<<"] "<<", L-R Diagonal" <<endl;
                        found=true;
                }
        }

}
}

/* Diagonal Right to left */
int searchDRL(string input, char puzzle[][12])
{
for(int i=0; i<12; i++)
{
        for(int j=12; j>input.length(); j--)
        {
                int x=0;
                while(puzzle[i-x][j-x]==input[x] && x<input.length())
                {
                        x++;
                }
                if(x==input.length())
                {
                        cout<<input<<" found at: ["<<j+1<<","<<i+1<<"] "<<", R-L Diagonal" <<endl;
                        found=true;
                }
        }

}
}

/* Diagonal Bottom to top */
int searchDBT(string input, char puzzle[][12])
{
for(int i=0; i<12; i++)
{
        for(int j=12; j>input.length(); j--)
        {
                int x=0;
                while(puzzle[j-x][i-x]==input[x] && x<input.length())
                {
                        x++;
                }
                if(x==input.length())
                {
                        cout<<input<<" found at: ["<<j+1<<","<<i+1<<"] "<<", B-T Digonal" <<endl;
                        found=true;
                }
        }

}
}



/* Diagonal Top to bottom */
int searchDTB(string input, char puzzle[][12])
{
for(int i=0; i<12; i++)
{
        for(int j=0; j<=12-input.length(); j++)
        {
                int x=0;
                while(puzzle[j+x][i+x]==input[x] && x<input.length())
                {
                        x++;
                }
                if(x==input.length())
                {
                        cout<<input<<" found at: ["<<j+1<<","<<i+1<<"] "<<", T-B Diagonal" <<endl;
                        found=true;
                }
        }

}
}

int main()
{

create_puzzle();

cout <<"Find the word: ";
cin >> input;

while (input!="Q"){

found=false;

searchLR(input, puzzle);
searchTB(input, puzzle);
searchRL(input, puzzle);
searchBT(input, puzzle);
searchDLR(input, puzzle);
searchDRL(input, puzzle);
searchDTB(input, puzzle);
searchDBT(input, puzzle);

if (!found)
cout <<"Oops! No match.\n";

cout <<"\nFind the word (Q to quit): ";
cin >> input;

}

}


