
/*!
 Copyright (C) 2004, 2005 Eric Ehlers

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it under the
 terms of the QuantLib license.  You should have received a copy of the
 license along with this program; if not, please email quantlib-dev@lists.sf.net
 The license is also available online at http://quantlib.org/html/license.html

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

#include <utilities.hpp>
#include <objectfoo.hpp>
#include <oh/logger.hpp>

using namespace ObjHandler;

const Properties& FOO_UPDATE(
        const std::string &handle,
        const std::string &s,
        const int &i) {
    boost::shared_ptr<ObjectFoo> object =
        boost::dynamic_pointer_cast<ObjectFoo>        
        (OH_OBJECT_GET(handle));
    if (!object)
        throw Exception("FOO_UPDATE: unable to retrieve object " + handle);
    object->update(s, i);
    return object->getProperties();
}

void OH_LOGFILE(const std::string &logFileName) {
    Logger::instance().setLogFile(logFileName);
}

void OH_LOGLEVEL(const int &logLevel) {
    Logger::instance().setLogLevel(logLevel);
}

void OH_CONSOLE(const int &console) {
    Logger::instance().setConsole(console);
}

void OH_LOGMESSAGE(
        const std::string &message,
        const int &level) {
    Logger::instance().logMessage(message, level);
}

