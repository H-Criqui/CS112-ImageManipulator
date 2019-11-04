#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<ctime>
using namespace std;



int main()
{

/*  
	srand(time(NULL));
	string temp;
	string file_name;
	string out_file_name;
	int set_effect;
	cout << "What .ppm file should I open?" << endl;
	cin >> file_name;
	cout << endl;
	cout << "What file should be our destination?" << endl;
	cin >> out_file_name;
	

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
	*/
	srand(time(NULL));
	string temp;
	string file_name;
	string out_file_name;
	int set_effect;
	cout << "What .ppm file should I open?" << endl;
	cin >> file_name;
	cout << endl;
	cout << "What file should be our destination?" << endl;
	cin >> out_file_name;


	ofstream fout;
	fout.open(out_file_name);
	ifstream fin;
	fin.open(file_name);

	fout.good();

	string file_type;
	string width;
	string height;
	string max_val;
	getline(fin, file_type);
	fout << file_type << endl;
	getline(fin, width, ' ');
	fout << width << ' ';
	getline(fin, height);
	fout << height << endl;
	getline(fin, max_val);
	fout << max_val << endl;

	vector<vector<string>> numbers{};
	string temp;
	int i = 1;
	int x = 0;
	string temporary;
	while (fin.good())
	{
		vector<string> data{};
		for (i = 1; i <= (stoi(width) * 3); i++)
		{
			getline(fin, temp);
			stringstream ss;
			ss << temp;
			while (ss.good())
			{
				getline(ss, temporary, ' ');
				if (temporary != " " && temporary != "")
				{
					data.push_back(temporary);
				}
			}
		}
		numbers.push_back(data);
	}


	
	bool _continue = true;
	char user_input = 'y';
	
	int j = 0;
	while (_continue)
	{
	
		cout << "What should I do to the image?" << endl;
		cout << "1. Remove Red" << endl << "2. Remove Blue" << endl;
		cout << "3. Remove Green" << endl << "4. Negate Red" << endl;
		cout << "5. Negate Blue" << endl << "6. Negate Green" << endl;
		cout << "7. Set to Grayscale" << endl << "8. Random noise" << endl;
		cout << "9. High contrast" << endl;
		cin >> set_effect;

		i = 0;
		j = 0;
		if (set_effect == 1)
		{
			while (i < (numbers.size() - 1))
			{
				while (j < (stoi(width) * 3))
				{
					if (j % 3 == 0)
					{
						numbers[i][j] = '0';
					}
					j++;
				}
				i++;
			}
		}

		i = 0;
		j = 0;
		if (set_effect == 2)
		{
			while (i < (numbers.size() - 1))
			{
				while (j < stoi(width) * 3)
				{
					if ((j - 1) % 3 == 0)
					{
						numbers[i][j] = '0';
					}
					j++;
				}

				i++;
			}
		}

		i = 0;
		j = 0;
		if (set_effect == 3)
		{
			while (i < (numbers.size() - 1))
			{
				while (j < stoi(width) * 3)
				{
					if ((j - 2) % 3 == 0)
					{
						numbers[i][j] = '0';
					}
					j++;
				}

				i++;
			}
		}


		i = 0;
		j = 0;
		if (set_effect == 4)
		{
			while (i < (numbers.size() - 1))
			{
				while (j < stoi(width) * 3)
				{
					if ((j) % 3 == 0)
					{

						int temp_num = (255 - stoi(numbers[i][j]));
						numbers[i][j] = to_string(temp_num);
					}
					j++;
				}
				i++;
			}
		}



		i = 0;
		j = 0;
		if (set_effect == 5)
		{
			while (i < (numbers.size() - 1))
			{	
				while (j < stoi(width) * 3)
				{
					if ((j - 1) % 3 == 0)
					{
						int temp_num = (255 - stoi(numbers[i][j]));
						numbers[i][j] = to_string(temp_num);
					}
					j++;
				}
				i++;
			}
		}


		i = 0;
		j = 0;
		if (set_effect == 6)
		{
			while (i < (numbers.size() - 1))
			{
				while (j < stoi(width) * 3)
				{
					if ((j - 2) % 3 == 0)
					{
						int temp_num = (255 - stoi(numbers[i][j]));
						numbers[i][j] = to_string(temp_num);
					}
					j++;
				}
				i += 1;
			}
		}


		i = 0;
		j = 0;
		if (set_effect == 7)
		{
			while (i < (numbers.size() - 1))
			{	
				while (j < stoi(width) * 3)
				{
					if (j % 3 == 0)
					{
						int temp_num = ((stoi(numbers[i][j]) + stoi(numbers[i][j + 1]) + stoi(numbers[i][j + 2])) / 3);

						numbers[i][j] = temp_num;
						numbers[i][j + 1] = temp_num;
						numbers[i][j + 2] = temp_num;
					}
					j++;
				}
				i++;
			}
		}

		int rand_num = 0;
		int num_1;
		int num_2;
		int num_3;

		i = 0;
		j = 0;
		if (set_effect == 8)
		{
			while (i < (numbers.size() - 1))
			{
				while(j < stoi(width)*3)
				{
					if (j % 3 == 0)
					{
						rand_num = ((rand() % 14) - 7);
						num_1 = stoi(numbers[i][j]) + rand_num;
						num_2 = stoi(numbers[i][j + 1]) + rand_num;
						num_3 = stoi(numbers[i][j + 2]) + rand_num;

						if (num_1 < 0)
						{
							num_1 = 0;
						}
						else if (num_1 > 255)
						{
							num_1 = 255;
						}

						if (num_2 < 0)
						{
							num_2 = 0;
						}
						else if (num_2 > 255)
						{
							num_2 = 255;
						}

						if (num_3 < 0)
						{
							num_3 = 0;
						}
						else if (num_3 > 255)
						{
							num_3 = 255;
						}

						numbers[i][j] = to_string(num_1);
						numbers[i][j + 1] = to_string(num_2);
						numbers[i][j + 2] = to_string(num_3);
					}
				j++;
			}
				i++;
			}
		}

		i = 0;
		j = 0;
		if (set_effect == 9)
		{
			while (i < (numbers.size() - 1))
			{
				while (j < stoi(width) * 3)
				{
					if (stoi(numbers[i][j]) > 127)
					{
						numbers[i][j] = "255";
					}
					else
					{
						numbers[i][j] = "0";
					}
					j++;
				}
				i++;
			}
		}

		cout << "would you like to continue? (y to continue anything else to quit)" << endl;
		cin >> user_input;

		if (user_input != 'y')
		{
			_continue = false;
		}

	}

	for (i = 0; i < numbers.size(); i++)
	{
		while (j < stoi(width) * 3)
		{
			fout << numbers[i][j] << " ";

			if (i % 3 == 0)
			{
				fout << endl;
			}
			j++;
		}
	}
	

	fin.close();
	fout.close();


	return 0;
}