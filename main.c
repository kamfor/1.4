#include <stdio.h>
#include <math.h>

double x; /*zmienna pelniaca role argumentu funkcji*/
double e; /*zmienna przechowujaca dokladnosc przyblizenia*/ 

double sin_taylor( double arg, int p){ /*funkcja obliczajaca wartosc sinusa z wzoru taylora dla prezyzji p*/ 
	
	double result  = arg; /*zmienna przechowujaca aktualny wynuk sumy*/ 
	double arg2 = arg*arg; /*kwadrat argumentu w celu unikniecia zbednych mnozen*/
	double temp = arg; /*tymczasowa zmienna stanowiaca dodatnia badz ujemna czesc sumy czescowej*/ 
	int i=0;
  
	for(i = 2; i < p; i+=2){/*petla wykonujaca sie p/2 razy zwiekszajaca licznik o 2*/

		temp=-temp*((arg2)/(i*(i+1))); /*poczatkowa wartosc argumentu domnazamy poprzez kolejne kwadraty i skladniki silni znak ujemny = -1^n*/
		result+= temp; /*dodajemy do siebie kolejne wyniki mnozen aby uzyskac sume*/
 
	}/*for*/
	
}/*sin_taylor*/

int main(){

	for(;;){

		printf("insert number like '0'.'0'\n");

		scanf("%lf",&x);

		printf("---------------------------\n");
		printf("sin(x) = %g\n",sin(x)); 
		printf("---------------------------\n");
		printf("taylor_sin(x) = %g\n",sin_taylor(x,3)); 
 		printf("---------------------------\n"); 
		e = fabs(sin(x)-sin_taylor(x,3));
		printf("error value =%g\n",e);
 		printf("---------------------------\n");
	}/*for*/

	return 0;

}/*main*/
