#include <iostream> 
#include <fstream> 
#include <cmath>
using namespace std;

int main () { 

ifstream fin ("datensumme.txt"); 

float sm=0;
int data;
for (int n=1; n<=234; ++n){
  fin >> data;
  sm += data;
}
float mittelwert=sm/234;
std::cout << "Mittelwert: "<< mittelwert << std::endl;
fin.close(); 

ifstream fin2 ("datensumme.txt"); 

float varianz=0;
int ai;
for (int n=1; n<=234; ++n){
  fin2 >> ai;
  varianz += (ai-mittelwert)*(ai-mittelwert);
}
varianz = varianz/234;
std::cout <<"Varianz: "<< varianz << std::endl;
fin2.close(); 

float std = sqrt(varianz);
std::cout << "Standardabweichung: "<< std << std::endl;




ofstream fout ("mittelwerte.txt");
ofstream fout2 ("varianzen.txt");
ifstream fin3 ("datensumme.txt");
ifstream fin4 ("datensumme.txt");

float mean_mean=0;
float mean_var=0;

int aj;
for (int n=1; n<=26; ++n){
  float mean=0;
  float var=0;
  for (int n=1; n<=9; ++n){
    fin3 >> aj;
    mean+=aj;
  }
  mean=mean/9;
  int ak=0;
  for (int n=1; n<=9; ++n){
    fin4 >> ak;
    var += (ak-mean)* (ak-mean);
  } 
  var=var/9;
  fout << mean << '\n';
  fout2 << var << '\n';

  mean_var += var;
  mean_mean += mean;
}
mean_mean=mean_mean/26;
mean_var=mean_var/26;
std::cout << "Mittelwert der Mittelwerte: "<< mean_mean << std::endl;
std::cout << "Mittelwert der Varianzen: "<< mean_var << std::endl;
fout.close();
fin3.close();
fin4.close();

}