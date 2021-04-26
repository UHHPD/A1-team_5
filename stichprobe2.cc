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
std::cout << mittelwert << std::endl;
fin.close(); 

ifstream fin2 ("datensumme.txt"); 

float varianz=0;
int ai;
for (int n=1; n<=234; ++n){
  fin2 >> ai;
  varianz += (ai-mittelwert)*(ai-mittelwert);
}
varianz = varianz/234;
std::cout << varianz << std::endl;
fin2.close(); 

float std = sqrt(varianz);
std::cout << std << std::endl;
}