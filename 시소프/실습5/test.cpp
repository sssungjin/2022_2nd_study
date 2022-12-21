#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
using namespace std;

void readFile(string fname);

int main(int argc, char **argv)
{
    if(argc == 2) {
	readFile(argv[1]);
    }
}

void readFile(string fname) {
	ifstream rf(fname);
	string str;
	if (rf.is_open())
	{
		while (getline(rf, str))
		{
			unsigned char inCodes[30] = { 0 };

			if (str.at(0) == 'H') {
				cout << "Tag = " << str.at(0) << ", ProgName = " << str.substr(1, 6) << ", Addr = " << str.substr(7, 6) << ", Size = " << str.substr(13, 6) << endl;
			}
			else if (str.at(0) == 'T') {
				cout << "Tag = " << str.at(0) << ", Addr = " << str.substr(1, 6) << ", Length = " << str.substr(7, 2) << ", Codes = " << str.substr(9, 61) << endl;
				string Codes = str.substr(9, 61);
				int length = Codes.length();
				unsigned char tmp = 0;
				int idx = 0;
				int flag = 0;
				for (int i = 0; i < length; i++) {
					if (Codes[i] >= '0' && Codes[i] <= '9') {
						tmp |= Codes[i] - 48;
						flag++;
					}
					else if (Codes[i] >= 'A' && Codes[i] <= 'F') {
						tmp |= Codes[i] - 55;
						flag++;
					}
					else
						continue;
					if(flag == 1)
					tmp <<= 4;
					else if (flag == 2) {
						inCodes[idx] = tmp;
						tmp = 0;
						flag = 0;
						idx++;
					}
				}

				cout << "--> ";
				for (int i = 0; i < idx; i++) {
					if(i == idx-1)
					cout << inCodes[i] / 16 << ", " << inCodes[i] % 16 << " ";
					else 
						cout << inCodes[i] / 16 << ", " << inCodes[i] % 16 << ", ";
				}
				cout << "\n";
			}


			else if (str.at(0) == 'M') {
				cout << "Tag = " << str.at(0) << ", Addr = " << str.substr(1, 6) << ", Length = " << str.substr(7, 2) << ", Others = " << str.substr(9, 61) << endl;
			}
			else if (str.at(0) == 'E') {
				cout << "Tag = " << str.at(0) << ", Addr = " << str.substr(1, 6) << endl;
			}
		}
		rf.close();
	}
	else
	{
		cout << "No such file!!\n";
	}
}
