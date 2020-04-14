/*
Konu:	Ikiye bolme metodu (Bisection Method)
Problem:	x^3 - 7x^2 + 14x - 6=0 fonksiyonunun [0, 1] kapali araliginda 0.01 hatadan az olacak sekilde yaklasik kokunu bulunuz.
	Denklemin gercek koki = 2-sqrt(2);		// 2-kok(2)
*/
#include<bits/stdc++.h>
using namespace std;
#define HATA 0.01

double f(double x){							// f(x) hesaplayan fonksiyon;
	return (x*x*x) - (7.0*x*x) + (14.0*x) - 6.0;
}

// Eger |x-xn| < HATA sa yaklasik koku bulmusuzdur;
bool durmaKontrolu(double xn){
	double x = 2.0 - (double)sqrt(2.0);				// gercek kok;
	if(abs(x-xn) < HATA) return true;				// abs() fonksiyonu mutlak deger anlamina gelir;
	else return false;
}

int main(){
	double a=0.0;		// alt sinir;
	double b=1.0;		// ust sinir;
	int iterasyon = 0;
	
	while(true){
		double fa = f(a);
		double fb = f(b);
		
// ikiye bolme metodunu kullanabilmemiz icin f(a)*f(b)<0 olmasi lazim;			// tek sayida x-eksenini kesmesi lazim;		
		if(fa*fb >= 0.0) break;
		double c = (a+b)/2.0;				// orta nokta;
		iterasyon++;
		
// Eger yaklasik kok bulunduysa ekrana basdir ve programi sonlandir; 
		if(durmaKontrolu(c)==true){
			printf("yaklasik kok = %lf\n%d.iterasyonda bulunmustur",c,iterasyon);
			return 0; 
		}

// Bir sonraki iterasyon icin aralik sinirlarini degistir;
		double fc = f(c);
		if(fc*fa < 0.0) b=c;
		else a=c;
	}
	
	printf("Denklemin koku bulunamadi. Lutfen denklemi ve araliklari kontrol ediniz");
	
	return 0;
}
