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

namespace colubris {
	namespace expr = boost::log::expressions;

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

	void logging_init()
	{
		auto core = boost::log::core::get();
		core->remove_all_sinks();

		boost::shared_ptr<boost::log::sinks::asynchronous_sink<boost::log::sinks::debug_output_backend>> 
			dbg_out_sink(new boost::log::sinks::asynchronous_sink<boost::log::sinks::debug_output_backend>());

		dbg_out_sink->set_formatter
			(
				expr::stream
					<< "[" << expr::attr<logging::severity_level>("Severity") << "] "
					<< expr::smessage
			);

		core->add_sink(dbg_out_sink);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	colubris::logging_init();
	auto &lg = colubris::default_logger::get();

	try
	{
		auto webhost = new colubris::webhost_default();
		auto listener = new colubris::webhost_listener(webhost);
		colubris_context context = { webhost, listener };

		std::string cmd;
		std::cout << "> ";

		BOOST_LOG_SEV(lg, colubris::logging::trace) << "testing";

		while (std::getline(std::cin, cmd))
		{
			std::vector<std::string> args;
			if (colubris::strsplit(args, cmd) > 0)
			{
				auto it = colubris::_dispatch_table.find(args[0]);
				if (it != colubris::_dispatch_table.end())
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

