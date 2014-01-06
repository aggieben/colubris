
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/async_frontend.hpp>
#include <boost/log/sinks/debug_output_backend.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/sources/severity_channel_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <ostream>

namespace colubris {
	namespace logging {
		enum severity_level { trace, debug, info, warning, error, fatal };

		const char* to_string(severity_level lvl);
		
		template< typename CharT, typename TraitsT >
		inline std::basic_ostream< CharT, TraitsT >& operator<< (std::basic_ostream< CharT, TraitsT >& strm, severity_level lvl)
		{
			const char* str = to_string(lvl);
			if (str)
				strm << str;
			else
				strm << static_cast< int >(lvl);
			return strm;
		}

		typedef boost::log::sources::severity_channel_logger<severity_level> default_logger_type;
		typedef boost::log::sources::severity_channel_logger_mt<severity_level> default_logger_type_mt;
	}

	BOOST_LOG_INLINE_GLOBAL_LOGGER_CTOR_ARGS(default_logger, logging::default_logger_type_mt,
		(boost::log::keywords::severity = logging::trace)(boost::log::keywords::channel = "default"));
}