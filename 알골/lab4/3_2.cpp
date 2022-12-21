#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

struct info
{
    string str;
    int count;
};

vector <info*> infos;   //구조체의 포인터 담고있는 벡터

int findWords(const string& s) {
    for(int i = 0; i < infos.size(); i++) {
        if(infos[i]->str == s)
            return i;
    }
    return -1;
}

void countWords(const string& s) {
    int index = findWords(s);

    if(index == -1) {
        info *pinfo = new info;
        pinfo->str = s;
        pinfo->count = 1;
        infos.push_back(pinfo);
    }
    else {
        infos[index]->count++;
    }
}

void my_strtok(string s, string sep) {
	char* c = strtok((char*)s.c_str(), sep.c_str());
	while (c) {
        countWords(c);
        c = strtok(NULL, sep.c_str());
	}
}

void readFile() {
    ifstream rf;
    string str;

    rf.open("C:\\Users\\dkdlw\\Desktop\\2학년 2학기 코딩\\알골\\lab4\\datafile.txt");
    if(rf.is_open()) {
        while(getline(rf, str, '\n')) {
            my_strtok(str, " ~!@#$%^&*()-_=+[]{};:\'\",.<>/?\n");
        }
        rf.close();
    }
    else
    {
        cout << "No such file!!\n";
    }
}

void bubble_sort() {
	int n = infos.size();
	int ctmp;
    string stmp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (infos[j]->count < infos[j + 1]->count) {
				ctmp = infos[j]->count;
				infos[j]->count = infos[j + 1]->count;
				infos[j + 1]->count = ctmp;
                stmp = infos[j]->str;
                infos[j]->str = infos[j+1]->str;
                infos[j+1]->str = stmp;
			}
            else if(infos[j]->count == infos[j + 1]->count) {
                if(strcmp(infos[j]->str.c_str(), infos[j+1]->str.c_str()) > 0) {
                ctmp = infos[j]->count;
				infos[j]->count = infos[j + 1]->count;
				infos[j + 1]->count = ctmp;
                stmp = infos[j]->str;
                infos[j]->str = infos[j+1]->str;
                infos[j+1]->str = stmp;
                }

            }
		}
	}
}

int main() 
{
    readFile();   
    bubble_sort();

    for(int i = 0; i < infos.size(); i++)
        cout << infos[i]->str << " : " << infos[i]->count << endl;
}