// Colubris.Console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Colubris.Listener.hpp"
#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>

extern std::map <std::string, std::function<bool(std::vector<std::string>&)>> _dispatch_table;

int strsplit(std::vector<std::string> &toks, std::string &str, char sep = ' ')
{
	for (auto it = str.begin(), pos = str.begin(); it != str.end(); it++)
	{
		if (*it == sep && it - pos > 0)
		{
			toks.push_back(std::string(pos, it));
			pos = it + 1;
		}
	}

	return toks.size();
}

int _tmain(int argc, _TCHAR* argv[])
{

//	auto listener = new colubris::webhost_listener(webhost);
//	/*if (!listener->start())
//	{
//		
//	}
//*/
	auto webhost = new colubris::webhost_default();

	std::string cmd;
	std::cout << "> ";
	while (std::cin >> cmd)
	{
		std::vector<std::string> args;
		if (strsplit(args, cmd) > 0)
		{
			auto it = _dispatch_table.find(args[0]);
			if (it != _dispatch_table.end())
			{
				it->second(args);
			}
		}

		std::cout << "> ";
	}

	return 0;
}

