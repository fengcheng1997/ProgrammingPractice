#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main ()
{

   char data[10];
   string str;

   ofstream outfile;
   outfile.open("afile.dat");

   cout << "Writing to the file" << endl;
   cout << "Enter your name: ";
 //  cin.getline(data, 4);
   cin >> data;
   outfile << data<< " ";

   cout << "Enter your age: ";
   cin >> data;
   outfile << data << endl;
 //  cin.ignore(1024, '\n');

   cout << "test" << endl;
   cin >> data;
   outfile << data << " ";

   outfile.put('1');

   outfile.close();

   fstream infile;
   infile.open("afile.dat");

   cout << "Reading from the file" << endl;

   getline(infile, str);
   cout << str << endl;

   infile >> data;
   cout << data << endl;

   infile >> data;
   cout << data << endl;

   infile >> data;
   cout << data << endl;

   infile >> data;
   cout << data << endl;

   infile >> data;
   cout << data << endl;

   infile >> data;
   cout << data << endl;
   infile >> data;
   cout << data << endl;

   infile.close();

   return 0;
}
