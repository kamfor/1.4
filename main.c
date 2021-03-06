#include <stdio.h>
#include <math.h>

double x; /*zmienna pelniaca role argumentu funkcji*/
double e; /*zmienna przechowujaca dokladnosc przyblizenia*/ 

double sin_taylor( double arg, int p){ /*funkcja obliczajaca wartosc sinusa z wzoru taylora dla prezyzji p*/ 
	
	double result  = arg; /*zmienna przechowujaca aktualny wynuk sumy*/ 
	double arg2 = arg*arg; /*kwadrat argumentu w celu unikniecia zbednych mnozen*/
	double temp = arg; /*tymczasowa zmienna stanowiaca dodatnia badz ujemna czesc sumy czescowej*/ 
	int i=0;
  
	for(i = 2; i <2* p; i+=2){/*petla wykonujaca sie p/2 razy zwiekszajaca licznik o 2*/

		temp=-temp*((arg2)/(i*(i+1))); /*poczatkowa wartosc argumentu domnazamy poprzez kolejne kwadraty i skladniki silni znak ujemny = -1^n*/
		result+= temp; /*dodajemy do siebie kolejne wyniki mnozen aby uzyskac sume*/
 
	}/*for*/
	
	return result; 
	
}/*sin_taylor*/

int main(){
	
	int aprox=0; 
	char c=0; 

	/*int i=0; 
	for(x=-1.57;x<1.57;x+=0.1){
	
		printf("x = %g\n",x);
	
		for(i=0; i<20; i++){
			
			e = fabs(sin(x)-sin_taylor(x,i));
			printf("sin(x)=%g sin_taylor(x)=%g blad=%g\n",sin(x),sin_taylor(x,i),e);
		}
	}blok odpowiedzialny za wygenerowanie wartosci testowych znajdujacych sie w pliku tests.txt*/
	

	for(;;){
 
		printf("-----------------------------------------\n");
		printf("podaj liczbe w formacie 'x'.'x'\n");
		printf("-----------------------------------------\n");

		if(scanf("%lf",&x)!=1){

			printf("blad odczytu danych\n");
			return 0; 
		}

		printf("-----------------------------------------\n");
		printf("wpisz rzad przybirzenia(l.calkowita)\n");
		printf("-----------------------------------------\n");
		
		if(scanf("%d",&aprox)!=1){

			printf("blad odczytu danych\n");
			return 0; 
		}	
			
		printf("-----------------------------------------\n");
		printf("sin(x) = %g\n",sin(x)); 
		printf("-----------------------------------------\n");
		printf("taylor_sin(x) = %g\n",sin_taylor(x,aprox)); 
 		printf("-----------------------------------------\n");

		e = fabs(sin(x)-sin_taylor(x,aprox));

		printf("blad jest rowny: %g\n",e);
 		printf("-----------------------------------------\n");
		printf("k(enter) - kontynuuj, z(enter) - zakoncz'\n");
 
		scanf(" %c",&c); 
		if(c=='z')return 0; 


	}/*for*/

	return 0;

}/*main*/
