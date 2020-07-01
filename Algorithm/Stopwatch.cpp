#include "stdafx.h"
#include "Stopwatch.h"
#include <time.h>

Stopwatch::Stopwatch()
{
	startTime = clock();
}
Stopwatch::~Stopwatch()
{
}
void Stopwatch::start()
{
	startTime = clock();
}
void Stopwatch::end()
{
	endTime = clock();
}
double Stopwatch::getElapsedTime()
{
	return ((double)endTime - (double)startTime)/1000;
}