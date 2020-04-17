/*
Topic:		Newton Raphson Method;
Problem:	x^3 + 2x - 4 = 0 denkleminin [1, 2] araliginda 0.001 hatadan az olacak sekilde yaklasik kokunu bulunuz.
			Baslangic noktasi x0 = 1;
*/
#include<bits/stdc++.h>
using namespace std;
#define HATA 0.001

//Eger |x1-x0| < HATA'sa yaklasik koku bulmusuzdur;
bool durmaKontrolu(double x1, double x0){
	if( abs(x1-x0) < HATA ) return true;	//abs() -> "bits/stdc++.h" kutuphanesi ile gelen fonksiyondur ve sayinin mutlak degerini verir;
	else return false;
}

double f(double x){				// f(x) hesaplayan fonksiyon;
	return (x*x*x) + (2.0*x) - 4.0;
}

double fTurev(double x){		// f'(x) hesaplayan fonksiyon;
	return (3.0*x*x) + 2.0;
}

int main(){
	int iterasyon = 0;
	double x0 = 1.0;
	
	while(true){
// yeni kok adayini x1 = x0- ( f(x0)/f'(x0) ) formulu ile hesapla;		
		double x1 = x0 - ( f(x0)/fTurev(x0) );
		iterasyon++;

// Eger yaklasik kok bulunduysa ekrana basdir ve programi sonlandir; 		
		if(durmaKontrolu(x1,x0)==true) {
			printf("yaklasik kok = %lf\n%d.iterasyonda bulunmustur",x1,iterasyon);
			return 0;
		}
		
// Bir sonraki iterasyon icin tegetin yerini degistir;
		x0 = x1;
	}
	
	return 0;
}
