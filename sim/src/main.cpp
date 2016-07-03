#include "cMainWindow.h"
#include <qthread.h>
#include <qtimer.h>
#include <qprocess.h>
#include <qdir.h>
#include "main.h"

#ifdef _WIN32
	#include <windows.h>
#endif



static cMainWindow*      mw;

void gui_toggle_led( int id , int direction ){
	QMetaObject::invokeMethod( mw , "toggle_leds" , Q_ARG(int,id) , Q_ARG(int,direction) );
}


void gui_lcd_put( int x , int y , char ch ){
	mw->ui.lcd->put( x , y , ch );
}


void gui_lcd_clear( ){
	mw->ui.lcd->clear( );
}


#undef main

int main( int argc , char* argv[] ){

	QApplication app( argc , argv );

	QApplication::setApplicationName ( "Cleanflight" );
	QApplication::setOrganizationName( "Cleanflight" );

	#if _WIN32
		//AllocConsole( );
		//freopen( "CONOUT$" , "w" , stdout );
	#endif

	mw = new cMainWindow();
	mw->show();

	FLASH_Load();
	xplane_start( );
	exec_start  ( );

	int exitcode = app.exec();
	
	exec_stop  ( );
	xplane_stop( );
	serial_stop( );
	FLASH_Save();

	delete mw;
	
	if( exitcode == 1 ){//restart
		QString exe = QApplication::applicationFilePath();

		QProcess::startDetached( exe , QStringList() , QDir::currentPath() );
	}

puts( "app exit 3" );
	return 0;
}


