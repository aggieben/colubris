// Colubris.Console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Colubris.Listener.hpp"
#include "context.hpp"
#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>

extern std::map <std::string, std::function<bool(colubris_context&, std::vector<std::string>&)>> _dispatch_table;

int strsplit(std::vector<std::string> &toks, std::string &str, char sep = ' ')
{
	auto it = str.begin(), pos = str.begin();
	for (; it != str.end(); it++)
	{
		if (*it == sep && it - pos > 0)
		{
			toks.push_back(std::string(pos, it));
			pos = it + 1;
		}
	}

	if (it - pos > 0)
		toks.push_back(std::string(pos, it));

	return toks.size();
}

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		auto webhost = new colubris::webhost_default();
		auto listener = new colubris::webhost_listener(webhost);
		colubris_context context = { webhost, listener };

		std::string cmd;
		std::cout << "> ";
		BOOST_LOG_TRIVIAL(info) << "Hello!";
		while (std::getline(std::cin, cmd))
		{
			std::vector<std::string> args;
			if (strsplit(args, cmd) > 0)
			{
				auto it = _dispatch_table.find(args[0]);
				if (it != _dispatch_table.end())
				{
					it->second(context, args);
				}
			}



			std::cout << "> ";
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "fatal: " << std::string(e.what()) << std::endl;
	}

	return 0;
}

