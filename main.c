#include <stdio.h>
#include <math.h>

double s; //zmienna przechowujaca wynik fwbudowanej funkcji ssin()
double t; //zmienna przechoujaca wynik funkcji sin_taylor
double x; //zmienna pelniaca role argumentu funkcji
double e; //zmienna przechowujaca dokladnosc przyblizenia 

double sin_taylor( double arg, int p){ // funkcja obliczajaca wartosc sinusa z wzoru taylora dla prezyzji p 
	
	double result  = arg; //zmienna przechowujaca aktualny wynuk sumy 
	double arg2 = arg*arg; // kwadrat argumentu w celu unikniecia zbednych mnozen
	double temp = arg; // tymczasowa zmienna stanowiaca dodatnia badz ujemna czesc sumy czescowej 
 
	for(int i = 2; i < p; i+=2){// petla wykonujaca sie p/2 razy zwiekszajaca licznik o 2 w celu unikniecia mnozenia przez 2 

		temp=-temp*((arg2)/(i*(i+1))); //poczatkowa wartosc argumentu domnazamy poprzez kolejne kwadraty i skladniki silni znak ujemny = -1^n
		result+= temp; // dodajemy do siebie kolejne wyniki mnozen aby uzyskac sume
 
	}//for
	
}

int main(){

	printf("insert number like 0.0 and integer precision\n");
	scanf("%lf", &x);
        

	//for(double i =-1.570; i<=1.571; i+= 0.2)printf("sin(%lf)=%lf\n", i, sin(i)); 
	s = sin(x);
	t = sin_taylor(x,10); 
	e = fabs(s-t); 
 

	printf("%lf\n",s);

	

	return 0;
}//main
