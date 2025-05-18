#ifndef _MYTIME_H_
#define _MYTIME_H_
#include <stdio.h>


#define llu unsigned long long

#if _WIN64
#include <windows.h>
typedef struct myTime{
    LARGE_INTEGER freq, start, end;
}MYTIME;
MYTIME mytime[5];

void tic(int num){
    QueryPerformanceFrequency(&(mytime[num].freq));
    QueryPerformanceCounter(&(mytime[num].start));
}

void toc(int num){
    QueryPerformanceCounter(&(mytime[num].end));
	LONGLONG elapsed_ticks = (mytime[num].end).QuadPart - (mytime[num].start).QuadPart;
    double elapsed_seconds = (double)elapsed_ticks / (mytime[num].freq).QuadPart;
    long long elapsed_microseconds = (long long)(elapsed_seconds * 1e6);
    
    printf("경과 시간: %lld 마이크로초\n", elapsed_microseconds);
}
#endif // _WIN64

#if __linux__
#include <time.h>
typedef struct myTime{
    struct timespec start, end;
}MYTIME;
MYTIME mytime[5];
void tic(int num) {
    clock_gettime(CLOCK_MONOTONIC, &(mytime[num].start));
}

void toc(int num){
    clock_gettime(CLOCK_MONOTONIC, &(mytime[num].end));

    long seconds = mytime[num].end.tv_sec - mytime[num].start.tv_sec;
    long nanoseconds = mytime[num].end.tv_nsec - mytime[num].start.tv_nsec;
    long total_microseconds = seconds * 1000000 + nanoseconds / 1000;

    printf("경과 시간: %ld 마이크로초\n", total_microseconds);
}
#endif //__LINUX__


#endif //_MYTIME_H_