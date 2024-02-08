#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class adress {
private:
	string town;
	string street;
	int number_house;
	int number_apartament;
public:
	adress() {}
	adress(string _town, string _street, int _numberHouse, int _numberApartament) : town(_town), street(_street), number_house(_numberHouse), number_apartament(_numberApartament) {}
	string getOutAdress() {
		return town + ", " + street + ", " + std::to_string(number_house) + ", " + std::to_string(number_apartament);
	}
};

void sort(adress* arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j].getOutAdress() > arr[j + 1].getOutAdress()) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}



int main() {
	setlocale(LC_ALL, "russian");
	ifstream file("in.txt");
	int n;
	if (!file.is_open()) {
		cout << "ERROR!" << endl;
		return 1;
	}
	int number;
	file >> number;
	adress* adressList = new adress[number];
	string town; string street;
	int numberHouse; int numberApartament;

	for (int i = 0; i < number; i++) {
		file >> town >> street >> numberHouse >> numberApartament;
		adressList[i] = adress(town, street, numberHouse, numberApartament);
	}
	file.close();
	sort(adressList, number);
	ofstream outFile("out.txt");
	for (int i = 0; i < number; i++) {
		outFile << adressList[i].getOutAdress() << endl;
	}
	return 0;
}