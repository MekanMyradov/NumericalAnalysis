/*
Topic:	Lineer Interpolasyon Metodu(Linear Interpolation Method)
Problem: x^3 - 2x^2 - 5 = 0 denklemini [2, 3] kapali aralikda hata degeri 0.40-dan az olacak sekilde yaklasik kokunu bulunuz.	
*/

#include<bits/stdc++.h>
using namespace std;
#define HATA 0.40

double f(double x){							// f(x) hesaplayan fonksiyon;
	return (x*x*x) - (2.0*x*x) - 5.0;
}

// Eger max{xn-an, bn-xn} < HATA sa yaklasik koku bulmusuzdur;
bool durmaKontrolu(double an, double xn, double bn){
	double hataN = (double)max(xn-an, bn-xn);
	if( hataN < HATA ) return true;		//max() -> "bits/stdc++.h" kutuphanesi ile gelen fonksiyondur ve iki sayinin buyugunu verir;
	else return false; 
}

int main(){
	double a = 2.00;			// alt sinir;
	double b = 3.00;			// ust sinir;
	int iterasyon = 0;
	
	while(true){
		double fa = f(a);
		double fb = f(b);
		
//Lineer interpolasyon metodunu kullanabilmemiz icin f(a)*f(b)<0 olmasi lazim;			// tek sayida x-eksenini kesmesi lazim;		
		if(fa*fb >= 0.0) break;

// xn = ( a*f(b) - b*f(a) )/( f(b)-f(a) ) formulu ile  [a, b] araliktan bir nokta belirliyoruz; 		
		double xn = ( (a*f(b)) - (b*f(a)) )/( f(b)-f(a) );
		iterasyon++;

// Eger yaklasik kok bulunduysa ekrana basdir ve programi sonlandir; 
		if(durmaKontrolu(a, xn, b)==true){
			printf("yaklasik kok = %lf\n%d.iterasyonda bulunmustur",xn,iterasyon);
			return 0; 
		}	

// Bir sonraki iterasyon icin aralik sinirlarini degistir;
		double fxn = f(xn);
		if(fxn*fa < 0.0) b=xn;
		else a=xn;

	}
		
	printf("Denklemin koku bulunamadi. Lutfen denklemi ve araliklari kontrol ediniz");
	
	return 0;
}
