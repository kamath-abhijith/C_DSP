#ifndef SIGNALSTATISTICS_H
#define SIGNALSTATISTICS_H

class SignalStatistics{
private:
	double* signal;
	int sig_length;
public:
	SignalStatistics(double* _signal, int _sig_length);
	double calc_signal_mean();
	double calc_signal_variance();
};

#endif