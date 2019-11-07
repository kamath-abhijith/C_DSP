// Includes class definitions of the SignalStatistics class
// Defining:
// 1. Constructor to initialize the private variables
// 2. Mean
// 3. Variance
// All functions and variables including the class constructor must be defined

#include "SignalStatistics.hpp"
#include <math.h>

SignalStatistics::SignalStatistics(double* _signal, int _sig_length)
{
	// Initializes the signal array and the signal length
	signal = _signal;
	sig_length = _sig_length;
}

double SignalStatistics::calc_signal_mean(){
	/*
	INPUT: -none- only class variables, functions needed
	OUTPUT: Signal mean
	*/
	double _mean = 0.0;
	for (int i=0; i<sig_length; i++){
		_mean = _mean + signal[i];
	}
	_mean = _mean/ (double)sig_length;

	return _mean;
}

double SignalStatistics::calc_signal_variance(){
	/*
	INPUT: -none- only class variables, functions needed
	OUTPUT: Unbiased signal variance
	*/
	double signal_mean = calc_signal_mean();
	double _variance = 0.0;
	for(int i=0; i<sig_length; i++){
		_variance = _variance + (signal[i]-signal_mean)*(signal[i]-signal_mean);
	}
	_variance = _variance/(sig_length-1);

	return _variance;
}