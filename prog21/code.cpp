/*
«адание:    —колько слов в строке соотв услови€м: дл€ всех равноотсто€щих слов от середины последовательности слов 
			первый символ правого слова совпадает с последним символом левого слова
*/
#include <iostream>;
#include <iomanip>;
#include <fstream>;
using namespace std;
const int N = 100;
ifstream input; ofstream output;
struct structure
{
	char string[N + 1];
	char marker;
	char separator;
	char temp;
	int count;
	int size = -1;
	int result = 0;
};
void wordsCount(structure& text);
void readFile(structure& text);
void process(structure& text);
void out(structure text);
void files(int a);
void main()
{
	structure text;
	files(0);
	readFile(text);
	wordsCount(text);
	process(text);
	out(text);
	files(1);
}
void wordsCount(structure& text)
{
	int i = 0, j = 0; text.count = 0;
	if (text.string[i] == ' ' || text.string[i] == '\t')
	{
		while (text.string[i] == ' ' || text.string[i] == '\t') i++;
	}
	while(i <= text.size)
	{
		if (text.string[i] == ' ' || text.string[i] == '\t')
		{
			text.count++;
			while (text.string[i] == ' ' || text.string[i] == '\t') i++;
		}
		else i++;
	}
	return;
}
void readFile(structure& text)
{
	input >> text.temp;
	if (input.eof())
	{
		cout << "file is empty";
		return;
	}
	input.seekg(-1, ios::cur);
	input >> text.marker >> text.separator;
	for (int i = 0; text.temp != text.separator; i++)
	{
		input >> skipws >> text.temp;
	}
	do
	{
		text.size++;
		input >> noskipws >> text.temp;
		if (text.temp == text.separator || text.temp == text.marker || text.temp == '\n' || text.temp == input.eof()) break;
		text.string[text.size] = text.temp;
	} while (text.string[text.size] != text.separator && text.string[text.size] != text.marker && text.string[text.size] != '\n' && text.string[text.size] != input.eof() && text.size < N);
	text.string[text.size] = text.marker;
	return;
}
void process(structure& text)
{
	int count = text.count / 2;
	if (text.count % 2 != 0) count++;
	for (int k = 0; k < count; k++)
	{
		int size = 0;
		while (text.string[size] != text.marker) size++;
		char first, last; unsigned i = 0, j = size - 1;
		while (text.string[i] != ' ')
		{
			last = text.string[i];
			i++;
		}
		while (text.string[j] != ' ')
		{
			first = text.string[j];
			j--;
		}
		if (first == last) text.result++;
	}
	return;
}
void files(int a)
{
	if (a == 0)
	{
		input.open("InputFile.txt");
		if (!input.is_open())
		{
			cout << "input file is not open or does not exist. please, restart the programm";
			return;
		}
		output.open("OutputFile.txt");
		if (!output.is_open())
		{
			cout << "output file is not open or does not exist. please, restart the programm";
			return;
		}

	}
	else
	{
		input.close();
		output.close();
		return;
	}
	return;
}
void out(structure text)
{
	int i = 1;
	output << "marker: " << text.marker << "\tseparator: " << text.separator << endl << "readed text:" << endl;
	do
	{
		output << text.string[i-1];
		i++;
	} while (text.string[i] != text.marker);
	output << endl << "result (coupels of words): " << text.result << endl;
}
