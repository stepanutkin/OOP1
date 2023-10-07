#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Adress {

private:
	std::string name_of_city;
	std::string name_of_street;
	int number_of_house;
	int number_of_flat;

public:
	Adress(std::string name_of_city, std::string name_of_street, int number_of_house, int number_of_flat) {
		this->name_of_city = name_of_city;
		this->name_of_street = name_of_street;
		this->number_of_house = number_of_house;
		this->number_of_flat = number_of_flat;
	}

	std::string input_file() {
	  return name_of_city + ", " + name_of_street + ", " + std::to_string(number_of_house) + ", " + std::to_string(number_of_flat);
	}
};



int main() {

	std::vector <Adress> adress;
	std::string s;
	std::vector<std::string> info;


	std::ifstream in;
	in.open("C:\\in.txt");
	

	if (in.is_open()) {
		getline(in, s);
	}

	
	int y = stoi(s);
	while (y > 0) {
		
		getline(in, s);
		info.push_back(s);

		getline(in, s);
		info.push_back(s);

		getline(in, s);
		info.push_back(s);

		getline(in, s);
		info.push_back(s);

		adress.push_back({info[0],info[1],stoi(info[2]),stoi(info[3])});
		y--;
		info.clear();
	}

	in.close();

	std::ofstream out;          
	out.open("C:\\out.txt");      
	if (out.is_open())
	{
		out << std::to_string(adress.size())<<std::endl;
		for (int i = adress.size()-1; i >= 0; --i) {
			s = adress[i].input_file();
			out << s << "\n";
		}

	}
	out.close();

	return 0;
}