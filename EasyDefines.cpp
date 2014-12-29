//__LICENCE

#include "EasyDefines.h"

//#include "../externalLibs/CImg.h"
#include <windows.h>
#include <fstream>

namespace EasyDefines
{
	//------------------------------------------------------//
	void showMessageBox(std::string pText)
	{
		/*
		typedef std::string TString;
		unsigned int maxcharwidth = 60;
		unsigned int nblines = 1;
		for(TString::size_type i = 0; i < pText.size(); i += (maxcharwidth+1))
		{
			pText.insert(i,"\n");
		}
		for(TString::size_type i = 0; i < pText.size(); ++i)
		{
			if('\n' == pText[i])
			{
				++nblines;
			}
		}
		cimg_library::CImg<unsigned char> lImage(maxcharwidth * 10, nblines * 11,1,1);
		unsigned char black = 0;
		unsigned char white = 255;
		lImage.draw_text(0,0, pText.c_str(), &black, &white, 1.0f, 10);
		cimg_library::CImgDisplay display(lImage);
		while(!display.is_closed)
		{
			display.wait();

			if(display.is_keyENTER || display.is_keyESC)
			{
				display.close();
			}
		}
		*/

		MessageBox(NULL, pText.c_str(), "Message!", MB_OK);
	}
	//------------------------------------------------------//
	void waitForUser()
	{
		showMessageBox("Press enter");
	}
	//------------------------------------------------------//
	std::string LogHlp::sLogName = "Log.log";
	void LogHlp::log(const std::string pString)
	{
		std::cout<<pString<<std::endl;
		static std::ofstream lOutputFile( LogHlp::sLogName.c_str() );
		if(lOutputFile)
		{
			lOutputFile << pString << std::flush;
		}
	}
	//------------------------------------------------------//
}
