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
	int kol2 = 0;
	bool win = false;
	vector<string>word;
	vector<string>word2;

public:

	void ENT()
	{
		std::cout << "Enter Word please: ";
		cin >> str;
		word.push_back(str);
		system("cls");
	}
	int getKol2()
	{
		return kol2;
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
				/*cout << kol2;*/
			}
			if (kol2 == 1&&f==false)
			{
				cout << "You have 4 tries\n";
			}
			if (kol2 == 2&&f==false)
			{
				cout << "You have 3 tries\n";
			}
			if (kol2 == 3 && f == false)
			{
				cout << "You have 2 tries\n";
			}
			if (kol2 == 4 && f == false)
			{
				cout << "You have 1 try\n";
			}
			if (kol2 == 5)
			{
				win = true;
				cout << "You Lose!\n";
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

	void Test()
	{
		
		using namespace sf;
		RenderWindow window(VideoMode(900, 500), "SFML Works!"/*,Style::Fullscreen*/);

		Sprite spriteFon;
		Texture textureFon;
		textureFon.loadFromFile("resources\\WildWest2.png");
		spriteFon.setTexture(textureFon);

		spriteFon.setScale(0.15, 0.15);

		window.draw(spriteFon);
		
		Texture texture;
		texture.loadFromFile("resources\\Vis.png");

		Sprite sprite;

		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(20, 64, 210, 326));//x,y,x,y
		sprite.setPosition(350, 150);//x,y

		Texture texture2;
		texture2.loadFromFile("resources\\Over.png");
		Sprite sprite2;

		sprite2.setTexture(texture2);
	
		sprite2.setPosition(-525,-50);

		while (window.isOpen())
		{
			bool a = false;
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				window.close();
			}
			if (getKol2() == 1)
			{
				sprite.setTexture(texture);
				sprite.setTextureRect(IntRect(239, 64, 205, 326));
			}
			if (getKol2() == 2)
			{
				sprite.setTexture(texture);
				sprite.setTextureRect(IntRect(467, 64, 205, 326));
			}
			if (getKol2() == 3)
			{
				sprite.setTexture(texture);
				sprite.setTextureRect(IntRect(687, 64, 205, 326));
			}
			if (getKol2() == 4)
			{
				sprite.setTexture(texture);
				sprite.setTextureRect(IntRect(915, 64, 205, 326));
			}
			if (getKol2() == 5)
			{
				sprite.setTexture(texture);
				sprite.setTextureRect(IntRect(1130, 64, 215, 326));
				sprite2.setPosition(110, 15);
				sprite2.setScale(0.5,0.5);
				a = true;
			}
			
			window.clear(Color::White);
			window.draw(spriteFon);
			window.draw(sprite);
			window.draw(sprite2);

			window.display();

			if (win == true)
			{
				window.clear(Color::White);
				Texture Texture3;
				Texture3.loadFromFile("resources\\Win2.png");
				Sprite sprite3;
				sprite3.setPosition(66, -50);
				sprite3.setTexture(Texture3);
				sprite3.setScale(0.66, 0.66);
				window.draw(sprite3);
				window.display();
				a = true;
			}
			if (a==true)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(6000));
				window.close();
			}
		}
	}

};

int main()
{
	using namespace sf;
	Viselica Vis;
	thread t(&Viselica::Test, &Vis);
	Vis.Write();
	Vis.Read();
	Vis.Print();
	Vis.Ugadaika();
	t.join();

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
