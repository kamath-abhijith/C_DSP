#include "SignalStatistics.hpp"
#include <math.h>

SignalStatistics::SignalStatistics(double* _signal, int _sig_length)
{
	signal = _signal;
	sig_length = _sig_length;
}

double SignalStatistics::calc_signal_mean(){
	double _mean = 0.0;
	for (int i=0; i<sig_length; i++){
		_mean = _mean + signal[i];
	}
	_mean = _mean/ (double)sig_length;

	return _mean;
}

double SignalStatistics::calc_signal_variance(){
	double signal_mean = calc_signal_mean();
	double _variance = 0.0;
	for(int i=0; i<sig_length; i++){
		_variance = _variance + (signal[i]-signal_mean)*(signal[i]-signal_mean);
	}
	_variance = _variance/(sig_length-1);

	return _variance;
}