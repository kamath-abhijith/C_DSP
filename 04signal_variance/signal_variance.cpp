#include <stdio.h>
#include <math.h>				// For sqrt() to compute the standard deviation
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

double calc_signal_variance(double *signal, double signal_mean, int sig_length)
{
	/*
	INPUT: Address of the first element of the signal, signal mean and signal length
	OUTPUT: Unbiased variance of the signal
	*/
	double _variance = 0.0;
	for(int i=0; i<sig_length; i++){
		_variance = _variance + (signal[i]-signal_mean)*(signal[i]-signal_mean);
	}
	_variance = _variance/(sig_length-1);

	return _variance;
}	

int main(){

	double signal_mean;
	signal_mean = calc_signal_mean(&InputSignal_f32_1kHz_15kHz[0], SIG_LENGTH);
	printf("%f\n", signal_mean);

	double signal_variance, std_dev;
	signal_variance = calc_signal_variance(&InputSignal_f32_1kHz_15kHz[0], signal_mean, SIG_LENGTH);
	std_dev = sqrt(signal_variance);
	printf("%f\n, %f\n", signal_variance, std_dev);

	return 0;
}