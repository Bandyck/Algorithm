#pragma once
class Stopwatch
{
	time_t startTime;
	time_t endTime;
public:
	Stopwatch();
	~Stopwatch();
	void start();
	void end();
	double getElapsedTime();
};