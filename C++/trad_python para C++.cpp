#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){
	
	float Ts = 10e-5;
	float Fs = 1 / Ts;
	int T_sim = 1;
	int L = ceil(T_sim / Ts);  // Até aqui tá funcionando
	
	float * trig1 = (float*) calloc(L, sizeof(float));
	float * trig2 = (float*) calloc(L, sizeof(float));
	float * trig = (float*) calloc(L, sizeof(float));
	float * trig_n = (float*) calloc(L, sizeof(float));
	float * vref = (float*) calloc(L, sizeof(float));
	float * cmd = (float*) calloc(L, sizeof(float));
	float * v = (float*) calloc(L, sizeof(float));

	trig1[0] = 0;
	trig2[0] = 0;
	
	for (int k=1;k<L;k++){
		
		v[k] = 0.4 * sin(2 * M_PI * Ts * k);
		
		trig1[k] = trig1[k-1] + 1; //OK
		
		if (trig1[k] > 100){
			trig1[k] = 1;
		}

		trig2[k] = 100 - trig1[k];

		if (trig1[k] < 50){
			trig[k] = trig1[k];
		}
		else{
			trig[k] = trig2[k];
		}
		
		trig_n[k] = trig[k] / 50;
		
		vref[k] = 0.5 + v[k];
		
		if(vref[k] > trig_n[k]){
			cmd[k] = 1;
		}
		else{
			cmd[k] = 0;
		}
		cout << cmd[k] << endl;
	}
	
	t = NULL;
	trig1 = NULL;
	trig2 = NULL;
	trig = NULL;
	trig_n = NULL;
	vref = NULL;
	cmd = NULL;
	v = NULL;
	
	free(t);
	free(trig1);
	free(trig2);
	free(trig);
	free(trig_n);
	free(vref);
	free(cmd);
	free(v);
	
	return 0;
}
