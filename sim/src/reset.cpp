/*
#include <qapplication.h>
#include <qprocess.h>
#include <qdir.h>
#include <qthread.h>

extern "C"{

}


void systemReset( ){
	QApplication::exit( 1 );
	QThread::exit
	QString exe = QApplication::applicationFilePath();

	QProcess::startDetached( exe , QStringList() , QDir::currentPath() );
	exit(0);
}


void systemResetToBootloader( ){
	systemReset();
}

*/
