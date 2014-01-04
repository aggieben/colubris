#include "stdafx.h"
#include "context.hpp"
#include <map>
#include <functional>
#include <vector>
#include <string>
#include <iostream>

std::map<std::string, std::function<bool(colubris_context&, std::vector<std::string>&)>> _dispatch_table 
{
	{ 
		"exit", [](colubris_context &context, std::vector<std::string>& args) -> bool
		{ 
			exit(0);
		} 
	},
	{ 
		"help", [](colubris_context &context, std::vector<std::string>& args) -> bool
		{
			std::cout << "colubris cli v0.1 (c) 2013 Ben Collins" << std::endl;
			return true;
		} 
	},
	{
		"start", [](colubris_context &context, std::vector<std::string>& args) -> bool
		{
			try
			{
				std::cout << "starting...";
				context.listener->start();
				std::cout << "done." << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << "failed! (" << std::string(e.what()) << ")";
				return false;
			}

			return true;
		}
	},
	{
		"stop", [](colubris_context &context, std::vector<std::string>& args) -> bool
		{
			try
			{
				std::cout << "stopping...";
				context.listener->stop();
				std::cout << "done." << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << "failed! (" << std::string(e.what()) << ")";
				return false;
			}
			
			return true;
		}
	},
};