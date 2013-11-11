#include "stdafx.h"
#include <map>
#include <functional>
#include <vector>
#include <string>
#include <iostream>

std::map<std::string, std::function<bool(std::vector<std::string>&)>> _dispatch_table 
{
	{ "exit", [](std::vector<std::string>& args) -> bool
		{ 
			exit(0);
		} 
	},
	{ "help", [](std::vector<std::string>& args) -> bool
		{
			std::cout << "colubris cli v0.1 © 2013 Ben Collins" << std::endl;
			return true;
		} 
	}
};