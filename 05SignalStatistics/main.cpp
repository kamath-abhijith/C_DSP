#include <stdio.h>
#include <math.h>
#include "SignalStatistics.hpp"
//#include "SignalStatistics.cpp"
#include "waveforms.cpp"

#define SIG_LENGTH 320
extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];

int main()
{
	double mean;
	SignalStatistics *testSignal = new SignalStatistics(&InputSignal_f32_1kHz_15kHz[0], 320);

	mean = testSignal->calc_signal_mean();
	printf("%f\n", mean);

	return 0;
}