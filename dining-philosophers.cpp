#include <pthread.h>
#include <iostream>
#include <unistd.h>

using namespace std;

const int NUM_FILOSOFI = 5;

pthread_t filosofi[NUM_FILOSOFI];
bool haPresoLaForchetta[NUM_FILOSOFI];
int pos;

void schermoIniziale();
void inizializza(bool arrayDiBool[NUM_FILOSOFI]);
void stampaStato(int pos, string messaggio);
void *prendiForchetta(void* numeroForchette);
void creaThread(pthread_t filosofi[NUM_FILOSOFI],int* numeroForchette);
void signal(int& s);
void wait(int& s);
void inizializza(bool haMangiato[NUM_FILOSOFI]);

int main(){
	int numeroForchette = NUM_FILOSOFI;
	schermoIniziale();
	inizializza(haPresoLaForchetta);
	bool continua = true;
	while(true){
		creaThread(filosofi,&numeroForchette);
	}
	return 0;
}

void inizializza(bool arrayDiBool[NUM_FILOSOFI]){
	for(int i = 0; i < NUM_FILOSOFI; i++){
		arrayDiBool[i] = false;
	}
}

void *prendiForchetta(void* numeroForchette){
	 int n;
	 int aspetta, segnale;
	 n = NUM_FILOSOFI/2;
	 pthread_join((long unsigned int)filosofi[pos],0);
	 //cout <<"Numero forchette: " << *(int*)numeroForchette << endl;
	 if(*(int*)numeroForchette >= n && haPresoLaForchetta[pos] == false){
		//*(int*)numeroForchette = *(int*)numeroForchette - 1;
		wait(*(int*)numeroForchette);
		haPresoLaForchetta[pos] = true;
		stampaStato(pos, "HA PRESO LA FORCHETTA");
		cout <<"Numero forchette: " << *(int*)numeroForchette << endl;
		pthread_join(filosofi[pos],0);
		pthread_exit(0);
		//cout << "POS:" << pos << endl;
	} else if(haPresoLaForchetta[pos] == true && *(int*)numeroForchette < n){
		stampaStato(pos,"STA MANGIANDO");
	    haPresoLaForchetta[pos] = false;
	    //*(int*)numeroForchette = *(int*)numeroForchette + 1;
	     signal(*(int*)numeroForchette);
	     cout <<"Numero forchette: " << *(int*)numeroForchette << endl;
	     pthread_exit(0);
	} else if(haPresoLaForchetta[pos] == false && *(int*)numeroForchette < n){
		stampaStato(pos,"STA PENSANDO");
		pthread_exit(0);
	}
	//cout <<"Numero forchette: " << *(int*)numeroForchette << endl;
	pthread_exit(0);
}


void creaThread(pthread_t filosofi[NUM_FILOSOFI],int* numeroForchette){
	for(pos = 0; pos < NUM_FILOSOFI; pos++){
		usleep(1000000);
		int thread = pthread_create(&filosofi[pos],NULL,prendiForchetta,(void*)numeroForchette);
		//cout << thread;
		pthread_join(filosofi[pos],0);
	}
}

void wait(int& s){
	while(s < 0)
		pthread_exit(0);
	s--;
}

void signal(int& s){
	s++;
}


void stampaStato(int pos, string messaggio){
	 cout <<"FILOSOFO: " << pos + 1 <<" " << messaggio << endl;
}

void schermoIniziale(){
	 cout <<"+-------------------------BENVENUTO--------------------------+" << endl;
	 cout <<"|Quest'applicazione gestisce il problema dei cinque filosofi.|" << endl;
	 cout <<"+------------------------------------------------------------+" << endl;
}