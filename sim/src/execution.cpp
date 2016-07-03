#include <windows.h>
#include "main.h"
#include <time.h>
#include <qthread.h>
#include <qapplication.h>

extern "C"{
	#include "platform.h"
	#include "drivers/gpio.h"
	#include "drivers/exti.h"
	#include "drivers/system.h"
	int cf_main(void);
}

namespace{
	class FlightThread : public QThread{
	public:
		void run( ) override{
			setTerminationEnabled( true );
			
			cf_main();
		}
	};
	
	FlightThread thread;
}


void systemReset( ){
	QApplication::exit( 1 );
	
	for(;;){
		QThread::msleep(1000);
	}
}


void systemResetToBootloader( ){
	systemReset();
}


void exec_start ( ){
	thread.start();
}


void exec_stop( ){
	thread.terminate();
	thread.wait();
}



static uint32_t ticks( uint32_t div ){
	static unsigned long long startup = 0;

	FILETIME t;
	GetSystemTimePreciseAsFileTime(&t);
	unsigned long long r;

	r   = t.dwHighDateTime;
	r <<= 32;
	r  |= t.dwLowDateTime;
	r  /= 10;

	if( startup == 0 ){
		startup = r;
	}

	return (r - startup) / div;
}



void delayMicroseconds( uint32_t us ){
	timespec ts;
	ts.tv_sec  =  us / 1000000;
	ts.tv_nsec = (us % 1000000) * 1000;
	nanosleep( &ts , NULL );
}


void delay( uint32_t ms ){
	timespec ts;
	ts.tv_sec  =  ms / 1000;
	ts.tv_nsec = (ms % 1000) * 1000000;
	nanosleep( &ts , NULL );
}


uint32_t micros(){
	return ticks(1);
}


uint32_t millis(){
	return ticks(1000);
}


