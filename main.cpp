#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;



int main()
{
	string temp;
	string file_name;
	string out_file_name;
	int set_effect;
	cout << "What .ppm file should I open?" << endl;
	cin >> file_name;
	cout << endl;
	cout << "What file should be our destination?" << endl;
	cin >> out_file_name;
	cout << "What should I do to the image?" << endl;
	cout << "1. Remove Red" << endl << "2. Remove Blue" << endl;
	cout << "3. Remove Green" << endl << "3. Negate Red" << endl;
	cout << "5. Negate Blue" << endl << "6. Negate Green" << endl;
	cout << "7. Set to Grayscale" << endl;
	cin >> set_effect;

	ofstream fout;
	fout.open(out_file_name);
	ifstream fin;
	fin.open(file_name);
	
	fout.good();

	string starting_info;

	getline(fin, starting_info);
	fout << starting_info << endl;
	getline(fin, starting_info, ' ');
	fout << starting_info << ' ';
	getline(fin, starting_info);
	fout << starting_info << endl;	
	getline(fin, starting_info);
	fout << starting_info << endl;

	
	vector<string> data{};

	while (fin.good() == true)
	{
		getline(fin, temp);

		data.push_back(temp);
	}

	vector<string> numbers{};
	vector<string> separated{};
	int i = 0;
	string number;

	while (i < (data.size()-1))
	{
		stringstream ss;
		ss << data[i];
		while (ss.good() == true)
		{
			getline(ss, number, ' ');

			separated.push_back(number);
		}

		i++;
	}
	i = 0;

	while (i < (separated.size() -1))
	{
		if (separated[i] != " " && separated[i] != "")
		{
			numbers.push_back(separated[i]);
		}
		i++;
	}


	i = 0;
	if (set_effect == 1)
	{
		while (i < (numbers.size() - 1))
		{
			if (i % 3 == 0)
			{
				fout << '0' << ' ';
			}
			else
			{
				fout << numbers[i] << ' ';
			}

			i++;
		}
	}

	i = 0;
	if (set_effect == 2)
	{
		while (i < (numbers.size() - 1))
		{
			if ((i - 1) % 3 == 0)
			{
				fout << '0' << ' ';
			}
			else
			{
				fout << numbers[i] << ' ';
			}

			i++;
		}
	}

	i = 0;
	if (set_effect == 3)
	{
		while (i < (numbers.size() - 1))
		{
			if ((i - 2) % 3 == 0)
			{
				fout << '0' << ' ';
			}
			else
			{
				fout << numbers[i] << ' ';
			}

			i++;
		}
	}


	i = 0;
	if (set_effect == 4)
	{
		while (i < (numbers.size() - 1))
		{
			if ((i) % 3 == 0)
			{
				
				int temp_num = (255 - stoi(numbers[i]));
				fout << temp_num  << ' ';
			}
			else
			{
				fout << numbers[i] << ' ';
			}

			i++;
		}
	}



	i = 0;
	if (set_effect == 5)
	{
		while (i < (numbers.size() - 1))
		{
			if ((i - 1) % 3 == 0)
			{
				int temp_num = (255 - stoi(numbers[i]));
				fout << temp_num << ' ';
			}
			else
			{
				fout << numbers[i] << ' ';
			}

			i++;
		}
	}


	i = 0;
	if (set_effect == 6)
	{
		while (i < (numbers.size() - 1))
		{
			if ((i - 2) % 3 == 0)
			{
				int temp_num = (255 - stoi(numbers[i]));
				fout << temp_num << ' ';
			}
			else
			{
				fout << numbers[i] << ' ';
			}

			i += 1;
		}
	}


	i = 0;
	if (set_effect == 7)
	{
		while (i < (numbers.size() - 1))
		{
			if (i % 3 == 0)
			{
				int temp_num = ((stoi(numbers[i]) + stoi(numbers[i + 1]) + stoi(numbers[i + 2])) / 3);

				fout << temp_num << ' ' << temp_num << ' ' << temp_num << ' ';
			}

			i++;
		}
	}

	fin.close();
	fout.close();


	return 0;
}