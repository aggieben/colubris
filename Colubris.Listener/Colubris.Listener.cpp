// Colubris.Listener.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Colubris.Listener.h"


// This is an example of an exported variable
COLUBRISLISTENER_API int nColubrisListener=0;

// This is an example of an exported function.
COLUBRISLISTENER_API int fnColubrisListener(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see Colubris.Listener.h for the class definition
CColubrisListener::CColubrisListener()
{
	return;
}
