#include "myglobal.h"
//This is Connor's source file.
// this is a test
//Worked on Android for lab 10 got button and swipe down to close functionality working.

Global::Global() {
		logOpen();
		done=0;
		xres=800;
		yres=600;
		showBigfoot=0;
		forest=1;
		silhouette=1;
		trees=1;
		showRain=0;
		showUmbrella=0;
		deflection=0;
	}
	~Global() {
		logClose();
	}
Global g;