#include<stdio.h>
#include "waveforms.cpp"		// Including the .cpp file with the signal

using namespace std;

#define SIG_LENGTH 320
extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];		// external definition
double calc_signal_mean(double *signal, int sig_length)
{	
	/*
	INPUT: Pointer to the first element of the signal, signal length
	OUTPUT: Mean of the signal in double
	*/

	double _mean = 0.0;
	for (int i=0; i<sig_length; i++){
		_mean = _mean + signal[i];
	}
	_mean = _mean/ (double)sig_length;

	return _mean;
}	

int main(){

	double signal_mean;
	signal_mean = calc_signal_mean(&InputSignal_f32_1kHz_15kHz[0], SIG_LENGTH);
	printf("%f\n", signal_mean);

	return 0;
}