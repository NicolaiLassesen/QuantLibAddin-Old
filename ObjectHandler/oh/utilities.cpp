/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
Copyright (C) 2007, 2008 Ferdinando Ametrano
Copyright (C) 2004, 2005, 2006, 2007 Eric Ehlers
Copyright (C) 2006 Plamen Neykov

This file is part of QuantLib, a free-software/open-source library
for financial quantitative analysts and developers - http://quantlib.org/

QuantLib is free software: you can redistribute it and/or modify it
under the terms of the QuantLib license.  You should have received a
copy of the license along with this program; if not, please email
<quantlib-dev@lists.sf.net>. The license is also available online at
<http://quantlib.org/license.shtml>.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

#if defined(HAVE_CONFIG_H)     // Dynamically created by configure
#include <oh/config.hpp>
#endif
#include <oh/utilities.hpp>
#include <oh/logger.hpp>
#include <oh/repository.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <sstream>
#include <ctime>

using boost::algorithm::token_compress_off;
using boost::algorithm::token_compress_on;
using boost::algorithm::is_any_of;

namespace ObjectHandler {

	std::string boostVersion() {
		return BOOST_LIB_VERSION;
	}

	std::string version() {
		return OBJHANDLER_VERSION;
	}

	std::string setLogFile(const std::string &logFileName,
		const int &logLevel) {
			Logger::instance().setLogFile(logFileName, logLevel);
			return logFileName;
	}

	DLL_API void logMessage(const std::string &message,
		const int &level) {
			Logger::instance().logMessage(message, level);
	}

	void setLogLevel(const int &logLevel) {
		Logger::instance().setLogLevel(logLevel);
	}

	void setConsole(const int &console,
		const int &logLevel) {
			Logger::instance().setConsole(console, logLevel);
	}

	void logObject(const std::string &objectID) {
		std::ostringstream msg;
		Repository::instance().dumpObject(objectID, msg);
		Logger::instance().logMessage(msg.str());
	}

	void logAllObjects() {
		std::ostringstream msg;
		Repository::instance().dump(msg);
		Logger::instance().logMessage(msg.str());
	}

	std::vector<std::string> split(const std::string& line,
		const std::string& delim,
		bool token_compress) {
			std::vector<std::string> ret;
			return boost::algorithm::split(ret, line, is_any_of(delim),
				token_compress ? token_compress_on : token_compress_off);
	}

	std::string concatenate(const std::vector<std::string>& symbols,
		const std::string& delim) {
			if (symbols.empty())
				return std::string();

			std::ostringstream ret;
			for (size_t i=0; i<symbols.size()-1; ++i)
				ret << symbols[i] << delim;
			ret << symbols[symbols.size()-1];
			return ret.str();
	}

	double getTime(){

		time_t rawtime;
		struct tm * timeinfo;

		time ( &rawtime );
		timeinfo = localtime ( &rawtime );

		return ((timeinfo->tm_sec + 60 * (timeinfo->tm_min + 60 * (timeinfo->tm_hour))) / (double)SECS_PER_DAY);

	}

	std::string formatTime(double tm){

		int t = (int)(tm * 86400);
		int dHour = t / 3600; 
		int dMinute = (t - (dHour * 3600)) / 60;
		int second = (t - (dHour * 3600) - (dMinute * 60)) ;
		char buffer[80];
		sprintf(buffer, "%02d:%02d:%02d", dHour, dMinute, second);

		return buffer;
	}


}
