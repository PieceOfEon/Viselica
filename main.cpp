////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include<chrono>
#include<thread>
#include<vector>
#include<conio.h>
#include <iomanip>
#include<fstream>
#include <string>
using namespace std;

////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
class Viselica
{
private:
	string str;
	string b;
	vector<string>word;
	vector<string>word2;
	//vector<string>word3;

public:

	void ENT()
	{
		std::cout << "Enter Word please: ";
		cin >> str;
		word.push_back(str);
		system("cls");
	}
	void Write()
	{
		ENT();
		if (!word.empty())
		{
			ofstream r1("Game.txt");
			for (int i = 0; i < word.size(); i++)
			{
				r1 << word[i];
				
			}
			cout << "Zapisano\n";
			r1.close();
		}
		else
		{
			cout << "Ne zapisano\n";
		}
	}
	void Read()
	{
		string q;
		ifstream r2("Game.txt");
		if (r2.is_open())
		{
			while (!r2.eof())
			{
				getline(r2, b);
				/*cout << b;*/
				b += q;
				word2.push_back(b);
			}
			r2.close();
		}
	}
	void Print()
	{
		int kol = 0;
		word2.push_back(word2[0]);
		for (int i = 0; i < word2[0].size(); i++)
		{

			cout <<"[" << i + 1 <<"]" << "\t";
		}
		cout << "\n\n";
		for (int i = 0; i < word2[0].size(); i++)
		{
			if (i % 2 == 0 && kol < 2)
			{
				kol++;
				word2[1][i] = word2[0][i];
				cout <<"[" << word2[0][i]<<"]" << "\t";
			}
			else
			{
				word2[1][i] ='*';
				cout << "[*]" << "\t";
			}
		}
	}

	void Ugadaika()
	{
		int kol = 0;
		int kol2 = 0;
		bool win=false;

		string u;
		while (win==false)
		{

			bool f = false;
			cout << "Enter bukvu[simvol]: ";
			cin >> u;

			for (int i = 0; i < word2[0].size(); i++)
			{
				if (i % 2 == 0 && kol < 2)
				{
					kol++;
					cout << "[" << word2[0][i] << "]" << "\t";
				}
				else if (word2[0][i] == u[0])
				{
					word2[1][i] = u[0];
					cout << "[" << word2[0][i] << "]" << "\t";
					f = true;
				}
				else if(word2[0][i]!=u[0])
				{
					cout <<"[" << word2[1][i] << "]" << "\t";
				}
			}
			if (f == false)
			{
				kol2++;
				cout << "\n";
				cout << kol2;
			}
			if (kol2 == 1&&f==false)
			{
				cout << "You have 1 lose\n";
			}
			if (kol2 == 2&&f==false)
			{
				cout << "You have 2 lose\n";
			}
			if (kol2 == 3)
			{
				win = true;
				cout << "Yo lose 0 shansov\n";
				break;
			}
			for (int i = 0; i < word2[1][i]; i++)
			{
				if (word2[1][i] != '*')
				{
					win = true;
					
				}
				else
				{
					win = false;
					break;
				}

			}
			if (win == true)
			{
				cout << "Yo Win\n";
			}
			
		}
	}


};

int main()
{
	Viselica Vis;
	Vis.Write();
	Vis.Read();
	Vis.Print();
	Vis.Ugadaika();


	return EXIT_SUCCESS;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
