#include <iostream>
using namespace std;


char str[30000];//����������p
int main(){

	char ss[30000] = "+++++++++[->++++++++>+++++++++++>+++++<<<]>.>++.+++++++.";//���������Ă���
	int i = 0;
	
	char* pStr = str;
	//int temp =0;

	
	while (ss[i]){
		switch (ss[i]){
		case '>':
			pStr++;
			break;
		case '<':
			pStr--;
			break;
		case '+':
			(*pStr)++;
			break;
		case '-':
			(*pStr)--;
			break;
		case '.':
			cout << (*pStr);
			break;
		case ',':
			cin >> (*pStr);
			break;
		case '[':
			if (*pStr == 0){

				while (ss[i]){
					static int temp = 0;
					i++;

					if (ss[i] == '['){
						temp++;
					}
					else if (ss[i] == ']' && temp > 0){
						temp--;
					}
					else if (ss[i] == ']' && temp == 0){
						break;
					}

					try{
						if (i == 79 && ss[i] != ']'){
							throw "�Ή�����]�����݂��܂���B";
						}
					}
					catch (char* err){
						cout << err << endl;
						return 0;
					}
				}
			}
			break;
		case ']':
			if (*pStr != 0){

				while (ss[i]){
					static int temp = 0;
					i--;

					if (ss[i] == ']'){
						temp++;
					}
					else if (ss[i] == '[' && temp){
						temp--;
					}
					else if (ss[i] == '[' && temp == 0){
						break;
					}

					try{
						if (i == 0 && ss[i] != '['){
							throw "�Ή�����[�����݂��܂���B";
						}
					}
					catch (char* err){
						cout << err << endl;
						return 0;
					}
					
				}
			}
			break;
		}
		i++;
	}

	return 0;
}
