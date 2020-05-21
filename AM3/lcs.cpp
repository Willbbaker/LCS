//This program was created by William Baker in April of 2020. 
//Its function is to find the LCS of 2 strings of characters. Driver code to feed strings is needed. 
//Resources used: https://www.geeksforgeeks.org/printing-longest-common-subsequence/
//https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

#include <iostream> 
#include <fstream> 
#include <cstring> 
#include <cstdlib> 
#include <vector> 
#include <string>
using namespace std; 

string lcs(string string1, string string2, int len1, int len2) //accepts strings and lengths as inputs 
{
	int L[len1 + 1][len2 + 1]; // making 2d table 
	
	//Filling L? L[i][j] = length of LCS of string1[0...i-1] and string2[o..j-1] 
	for(int i = 0; i <= len1; i++) 
	{
		for(int j = 0; j <= len2; j++) 
		{
			if(i == 0 || j == 0) 
			{
				L[i][j] = 0; 
			}
			else if(string1[i - 1] == string2[j - 1]) //are the characters the same? Increment the length...
			{										//Why not just use a vector and pull the character now?? 
				L[i][j] = L[i - 1][j - 1] + 1; 
			}
			else
			{
				L[i][j] = max(L[i-1][j], L[i][j-1]); 
			}
		}
	}
	
	int index = L[len1][len2]; //index = length of lcs
	char lcs[index+1]; //array to store lcs in 
    //string lcs[index + 1]; 
	lcs[index] = '\0';
	
	int i = len1;
	int j = len2; 
	
	//Iterating through L 
	while(i > 0 && j > 0) 
	{
		
		if(string1[i-1] == string2[j-1]) 
		{
			lcs[index-1] = string1[i-1]; 
			i--; 
			j--; 
			index--; 
		}
		
		else if(L[i-1][j] > L[i][j-1]) 
			i--; 
		else
			j--; 
	}
	
	string lcss = lcs; 
	
	//cout << "LCS of " << string1 << " and " << string2 << " is " << lcs; 
	//cout << "LCS is " << lcs << endl; 
	return lcss; 
}

void printvec(vector<string> input)
{
	for(int i = 0; i < input.size(); i++) 
	{
		cout <<input.at(i) << endl; 
	}
	
} 

void compareall(vector<string> names, vector<string> seqs)
{
	for(int i = 0; i < seqs.size() - 1; i++)
	{
		for(int j = i + 1; j < seqs.size() - 1; j++) 
		{
			//cout << "The LCS of " << names[i] << " and " << names[j] << " is..." << endl; 
			string lcsx = lcs(seqs[i], seqs[j], seqs[i].size(), seqs[j].size()); 
			//cout << "The LCS of " << names[i] << " and " << names[j] << " is \n" << locs << endl;
			cout << "Species 1 : " << names[i] << endl; 
			cout << "Species 2 : " << names[j] << endl; 
			cout << "LCS size  : " << lcsx.size() << endl;  
			cout << "LCS       : " << lcsx << '\n' << endl; 
		}
	}
}

int main(int argc, char* argv[])
{
	if(argc < 2) 
	{
		cerr << "Usage: ./a.out <filename.txt>" << endl; 
	}
	//create 2 vectors, one for names and one for character arrays 
	vector<string> names; 
	vector<string> seqs; 
	//open file 
	ifstream file; 
	file.open(argv[1]);
	//while not at end of file 
	while(!file.eof())
	{
		string line; 
		//store line in name vector 
		getline(file, line); 
		names.push_back(line); 
		//store line in dna vector (vector of vectors?) 
		getline(file, line); 
		seqs.push_back(line); 
		//blank line 
		getline(file, line); 
	}
	//iterate through dna vector comparing each sequence? 
	//printvec(names); 
	//printvec(seqs); 
	compareall(names, seqs); 
}

