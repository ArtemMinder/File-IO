#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class IOFiles {
public:
	IOFiles(string& newname, string& newtype) {
		name = newname;
		type = newtype;
	}
	void writeData() {
		string data;
		cout << "String to add: " << endl;
		cin >> data;
		if (type == ".csv") {
			string fileTypeName = name + type;
			ofstream file(fileTypeName, ios::out | ios::app | ios::binary);
			if (file.is_open())
			{
				//file << ";";
				file << data << std::endl;
			}
			file.close();
		}
		else if (type == ".tsv") {
			string fileTypeName = name + type;
			ofstream file(fileTypeName, ios::out | ios::app | ios::binary);
			if (file.is_open())
			{   
				file << data << std::endl;
			}
			file.close();
		}
		else {
			cout << " Sorry, unsupported format" << endl;
		}
	}
	void readData() {
		if (type == ".csv") {
			string fileTypeName =name + type;
			ifstream file(fileTypeName, ios::in | ios::binary);
			string buff;
			while (getline(file, buff))
			{
				cout << buff << endl;
			}
			file.close();
		}
		else if (type == ".tsv") {
			string fileTypeName = name + type;
			ifstream file(fileTypeName, ios::in | ios::binary);
			string buff;
			while (getline(file, buff))
			{
				cout << buff << endl;
			}
			file.close();
		}
		else {
			cout << " Sorry, unsupported format" << endl;
		}
	}
	void search() {
		if (type == ".tsv") {
			string fileTypeName = name + type;
			ifstream file(fileTypeName, ios::in | ios::binary);
			string s, find;
			char c;
			while (!file.eof()) {
				file.get(c);
				s.push_back(c);
			}
			file.close();
			cout << "enter a world for find: ";
			cin >> find;

			int pos = s.find(find);

			if (pos == -1)
				cout << "not finded" << endl;
			else
				cout << "finded in " << pos << " simvol position" << endl;
		}
		if (type == ".csv") {
			string fileTypeName = name + type;
			ifstream file(fileTypeName, ios::in | ios::binary);
			string s, find;
			char c;
			while (!file.eof()) {
				file.get(c);
				s.push_back(c);
			}
			file.close();
			cout << "enter a word for find: ";
			cin >> find;

			int pos = s.find(find);

			if (pos == -1)
				cout << "not finded" << endl;
			else
				cout << "finded in " << pos << " simvol position" << endl;
		}
	}
private:
	string type;
	string name;
};


int main() {
	string name1 = "file", type1 = ".csv";
	IOFiles f1(name1,type1);
	string name2 = "file", type2 = ".csv";
	IOFiles f2(name2, type2);
	f1.writeData();
	f2.writeData();
	f1.readData();
	f2.readData();
	f1.search();
	f2.search();
	system("pause");
	return 0;
}