// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the COLUBRISLISTENER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// COLUBRISLISTENER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef COLUBRISLISTENER_EXPORTS
#define COLUBRISLISTENER_API __declspec(dllexport)
#else
#define COLUBRISLISTENER_API __declspec(dllimport)
#endif

// This class is exported from the Colubris.Listener.dll
class COLUBRISLISTENER_API CColubrisListener {
public:
	CColubrisListener(void);
	// TODO: add your methods here.
};

extern COLUBRISLISTENER_API int nColubrisListener;

COLUBRISLISTENER_API int fnColubrisListener(void);
