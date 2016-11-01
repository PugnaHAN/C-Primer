#include "functions.h"
#include <string>
#include <cctype>

using namespace std;

istream& displayInstream(istream& is)
{
	auto old_state = is.rdstate();
	is.clear();

	int data;
    while(is >> data || is.eof())
	{
		cout << data << " ";
	}

	cout << endl;

	is.setstate(old_state);

	return is;
}


vector<string> readFile(const string fileName, ReadType type)
{
	vector<string> result;
	ifstream infile(fileName.c_str(), ios::in);

	string line;
	while(getline(infile, line) || infile.eof()) {
		switch(type)
		{
			case readFile_type_line_e:
				result.push_back(line);
				break;
			case readFile_type_word_e:
				splitLine(result, line);
				break;
			default:
				cerr << "Not be supported yet!" << endl;
				return result;					
		}		
	}

	infile.close();

	return result; 
}

void splitLine(vector<string>& container, string line)
{
	int start = 0, end = 0;
	string word;
	do
	{
		end = line.find(' ', start);
		if(end > start)
		{
			// cout << "start = " << start << "; end = " << end << endl;
			word = line.substr(start, end - start);
			container.push_back(word);
		}
		if(end == -1)
		{
			word = line.substr(start, line.size() - start);
			container.push_back(word);
		}
		start = end + 1;		
	}
	while(end >= 0);
}

void trade(string infile, string outputFile)
{
	ifstream in(infile.c_str());
	ofstream out(outputFile.c_str());

	Sales_data total;
	if(read(in, total))
	{
		Sales_data trans;
		while(read(in, trans))
		{
			if(total.isbn() == trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				print(out, total) << endl;
				total = trans;
			}
		}
		print(out, total) << endl;
	}
	else
	{
		cerr << "Invalid data!" << endl;
	}
	in.close();
	out.close();
}

void read(vector<PersonInfo>& people)
{
	string line, word, name;

	while(getline(cin, line))
	{
		PersonInfo info;
		istringstream record(line);
		record >> name;
		info.setName(name);
		while(record >> word)
		{
			info.appendPhone(word);
		}
		people.push_back(info);
	}
}

void print(PersonInfo& pi, ostream& os)
{
	ostringstream formatted, badNums;
	vector<string> phones = pi.getPhones();
	// cout << phones[0] << endl;
	for(const auto phone : phones)
	{
		cout << phone << endl;
		if(!valid(phone))
			badNums <<" "<< phone;			
		else
			formatted << format(phone) << " ";
		
	}
	if(badNums.str().empty())
		os << pi.getName() << " "
		   << formatted.str() << endl;
	else
		cerr << "input error: " << pi.getName()
			 << " invalid number(s) " << badNums.str() << endl;
}


bool valid(const string& num)
{
	for(auto c : num)
	{
		if(!isdigit(c))
			return false;
	}

	return true;
}

string format(const string& num)
{
	string number(num);
	if(number[0] == '0')
	{
		if(number[1] <= '2' && number[1] >= '1')
		{
			number.insert(3, "-");
		}
		else if(number[1] > '2' && number[1] <= '9')
		{
			number.insert(4, "-");
		}
	}
	else
	{
		number.insert(3, "-");
		number.insert(8, "-");
	}
	
	return number;
}
