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
	getline(fin, height);
	getline(fin, max_val);
	

	int tot_width = stoi(width) * 3;

	vector<vector<string>> numbers{};
	temp = "";
	int i = 1;
	int x = 0;
	string temporary;
	vector<string> data{};
	while (fin.good())
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

				if (data.size() == tot_width)
				{
					numbers.push_back(data);
					data = vector<string>{};
				}
				
			}
		}
		
	}


	int flip_width;
	bool _continue = true;
	char user_input = 'y';
	int flip_counter = 0;
	int j = 0;
	while (_continue)
	{

		cout << "What should I do to the image?" << endl;
		cout << "1. Remove Red" << endl << "2. Remove Blue" << endl;
		cout << "3. Remove Green" << endl << "4. Negate Red" << endl;
		cout << "5. Negate Blue" << endl << "6. Negate Green" << endl;
		cout << "7. Set to Grayscale" << endl << "8. Random noise" << endl;
		cout << "9. High contrast" << endl << "10. Flip horizontally" << endl;
		cout << "11. Flip vertically" << endl;
		cin >> set_effect;

		i = 0;
		j = 0;
		if (set_effect == 1)
		{
			while (i < (numbers.size() - 1))
			{
				j = 0;
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
				j = 0;
				while (j < tot_width)
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
				j = 0;
				while (j < tot_width)
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
				j = 0;
				while (j < tot_width)
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
				j = 0;
				while (j < tot_width)
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
				j = 0;
				while (j < tot_width)
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
				j = 0;
				while (j < tot_width)
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
				j = 0;
				while (j < tot_width)
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
				j = 0;
				while (j < tot_width)
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

		i = 0;

		if (set_effect == 10)
		{
			while (i < (numbers.size() - 1))
			{
				j = 0;
				vector<string> tp;
				while (j < tot_width)
				{
					if (j % 3 == 0)
					{
						tp.push_back(numbers[i][tot_width - (j + 3)]);
						tp.push_back(numbers[i][tot_width - (j + 2)]);
						tp.push_back(numbers[i][tot_width - (j + 1)]);
					}

					j++;
				}
				numbers[i] = tp;
				i++;
			}
		}


		i = 0;
		int p = 0;
		if (set_effect == 11)
		{
			vector<vector<string>> other;
			while (i < numbers.size())
			{
				j = 0;
				vector<string> tp;
				while (j < tot_width)
				{
					tp.push_back(numbers[numbers.size() - (i + 1)][j]);
					j++;
				}
				other.push_back(tp);
				i++;
			}
			i = 0;
			while (i < numbers.size())
			{
				numbers[i] = other[i];
				i++;
			}
		}

		i = 0;
		j = 0;
		if (set_effect == 12)
		{
			while (i < numbers.size())
			{
				j = 0;
				while (j < tot_width)
				{
					if (j <= 2)
					{
						numbers[i][j] = to_string((stoi(numbers[i][j]) + stoi(numbers[i][3])) / 2);
					}
					else if (j > tot_width - 4)
					{
						numbers[i][j] = to_string((stoi(numbers[i][j]) + stoi(numbers[i][j - 3])) / 2);
					}
					else
					{
						numbers[i][j] = to_string( (stoi(numbers[i][j]) + stoi(numbers[i][j + 3]) + stoi(numbers[i][j - 3])) / 3);
					}
					j++;
				}
				i++;
			}

			i = 0;
			while (i < numbers.size())
			{
				j = 0;
				while (j < tot_width)
				{
					if (i == 0)
					{
						numbers[i][j] = to_string((stoi(numbers[i][j]) + stoi(numbers[1][j])) / 2);
					}
					else if (i == numbers.size() - 1)
					{
						numbers[i][j] = to_string( (stoi(numbers[i][j]) + stoi(numbers[i - 1][j]) ) / 2);
					}
					else
					{
						numbers[i][j] = to_string( (stoi(numbers[i][j]) + stoi(numbers[i - 1][j]) + stoi(numbers[i + 1][j])) / 3);
					}
					j++;
				}
				i++;
			}
		}
	


		i = 0;
		j = 0;
		if (set_effect == 13)
		{
			while (i < numbers.size())
			{
				if (i % 2 == 0)
				{
					j = 0;
					while (j < tot_width - 1)
					{
						if (j % 6 == 0)
						{
							string pix_val=numbers[i][j];
							string pix_val2 = numbers[i][j + 1];
							string pix_val3 = numbers[i][j + 2];
							numbers[i][j + 3] = pix_val;
							numbers[i][j + 4] = pix_val2;
							numbers[i][j + 5] = pix_val3;
							numbers[i + 1][j] = pix_val;
							numbers[i + 1][j + 1] = pix_val2;
							numbers[i + 1][j + 2] = pix_val3;
							numbers[i + 1][j + 3] = pix_val;
							numbers[i + 1][j + 4] = pix_val2;
							numbers[i + 1][j + 5] = pix_val3;
						
						}
						j++;
					}
				}
				i++;
			}
		}

		vector<vector<string>> temp_;
		j = 0;
		if (set_effect == 14)
		{
			flip_width = numbers.size();
			
			while (j < tot_width)
			{
				vector<string> rot_;
				i = 0;
				
					while (i < numbers.size())
					{
						if (j % 3 == 0) 
						{
							rot_.push_back(numbers[i][j]);
							rot_.push_back(numbers[i][j + 1]);
							rot_.push_back(numbers[i][j + 2]);
						}
						i++;
					}
					if (j % 3 == 0)
					{
						temp_.push_back(rot_);
					}
					j++;
			}

			numbers = temp_;
			flip_counter++;
		}
		cout << "would you like to continue? (y to continue anything else to quit)" << endl;
		cin >> user_input;

		if (user_input != 'y')
		{
			_continue = false;
		}

	}

	i = 0;


	if (flip_counter % 2 == 0)
	{
		fout << width << " " << height;
		for (i = 0; i < numbers.size(); i++)
		{
			j = 0;
			while (j < tot_width)
			{
				fout << numbers[i][j] << " ";


				j++;
			}
			fout << endl;
		}
	}
	else
	{
		fout << height << " " << width << endl;
		fout << max_val << endl;
		for (i = 0; i < numbers.size(); i++)
		{
			j = 0;
			while (j < flip_width)
			{
				fout << numbers[i][j] << " ";
				j++;
			}
		fout << endl;
		}
	}

	





	fin.close();
	fout.close();


	return 0;
}