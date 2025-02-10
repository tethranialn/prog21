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
void openFiles();
void main()
{
	structure text;
	openFiles();
	readFile(text);
	wordsCount(text);
	process(text);
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
	output << "marker: " << text.marker << "\tseparator: " << text.separator << endl;
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
		cout << text.string[text.size];
	} while (text.string[text.size] != text.separator && text.string[text.size] != text.marker && text.string[text.size] != '\n' && text.string[text.size] != input.eof() && text.size <= N);
	text.temp = '1';
	return;
}
void process(structure& text)
{
	int count = text.count / 2;
	if (text.count % 2 != 0) count++;
	for (int k = 0; k < count; k++)
	{
		char first, last; unsigned i = 0, j = text.size;
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
	cout << endl << text.result;
	return;
}
void openFiles()
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
	return;
}