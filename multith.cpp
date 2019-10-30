#include <fstream>
#include <iostream>
#include <string>
#include <thread>

using namespace std;

//Thread'ler tarafından calistirilacak fonksiyon
void func(string str) {

	cout << str + ": basladi" << endl;

	ofstream outfile;
	//dosyada var olan datanın uzerine yazması icin ios_base::app parametresini verdik
	outfile.open("ouput.txt", ios_base::app);

	cout << str + ": dosyaya yazdiriliyor.\n";
	outfile << str << endl;

	outfile.close();

	cout << str + ": bitti\n";
}


int main() {

	cout << "Main basladi" << endl;

	//Thread'leri tanımladık ilk parametre thread'in çalıştıracağı
	thread th1(func, "Thread 1");
	thread th2(func, "Thread 2");
	thread th3(func, "Thread 3");

	//join() fonksiyonu, thread'in fonksiyonu bitmeden direk thread'lerin çalışmasını engeller.
	if (th1.joinable())
		th1.join();
	if (th2.joinable())
		th2.join();
	if (th3.joinable())
		th3.join();

	cout << "Dosya okunuyor\n" << endl;

	//Dosyaya yazdırılan verileri okumak için
	string line;
	char data[100];
	ifstream infile;
	infile.open("ouput.txt");

	while (getline(infile, line)) {
		cout << line << '\n';
	}
	infile.close();

	cout << "Main bitti" << endl;

	return 0;
}
