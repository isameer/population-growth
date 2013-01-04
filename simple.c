#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>

using namespace std;

long double get_average(int* population,int max_age);
long double get_total(int* population,int max_age);

//Basic model : multiplication at r, deaths at d

//Age goes from 0 to d

int main(int argc, char** argv){

	int r = atoi(argv[1]);
	int d = atoi(argv[2]);
	int p = atoi(argv[3]);
	
	int population[d + 1];
	for(int i = 0; i <= d; i++)
		population[i] = 0;

	//Init
	population[0] = p;
	
	int T = atoi(argv[4]);
	//Time from 0 to T
	for(int i = 1; i <= T; i++){

		//Increment population's age by 1. 
		//People of age j become of age 'j+1'
		//People of age 'd' die
		for(int j = d;j >0 ; j--)
			population[j] = population[j - 1];
		//Population of 'r' reproduces to produce 2 offsprings/couple at age around 'r'
		population[0] = (int)(0.05*(long double)population[r-2] + 0.2*(long double)population[r-1] + 0.5*(long double)population[r] + 0.2*(long double)population[r+1] + 0.05*(long double)population[r+2]);
	//	cout << i << " " << population[0]  << endl;
		long double avg = get_average(population,d);
		//cout << i << " " << avg << endl; 
		long double total = get_total(population,d);
		cout << i << " " << total << endl; 
	}

//	for(int i = 0; i <= d; i++)
//		cout << i << " " << population[i] << endl;
}

long double get_average(int* population,int max_age){

	long double total_age = 0;
	long double total_population = 0;
	for(int i = 0; i <= max_age; i++){
		total_age += i*population[i];
		total_population += population[i];
	}
	return total_age/total_population;
}


long double get_total(int* population,int max_age){

	long double total_population = 0;
	for(int i = 0; i <= max_age; i++){
		total_population += population[i];
	}
	return total_population;
}
