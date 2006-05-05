
/*
 Copyright (C) 2005, 2006 Eric Ehlers
 Copyright (C) 2005 Plamen Neykov
 Copyright (C) 2005 Walter Penschke

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

#ifndef qla_fixedcouponbond_hpp
#define qla_fixedcouponbond_hpp

#include <qla/baseinstruments.hpp>

namespace QuantLibAddin {

    class FixedCouponBond : public Bond {
    public:
        FixedCouponBond(
            const QuantLib::Date& issueDate,
            const QuantLib::Date& datedDate,
            const QuantLib::Date& maturityDate,
            const long &settlementDays,
            const std::vector<double> &coupons,
            const std::vector<double> &nominals,
            const double &redemption,
            QuantLib::Frequency frequency,
            const QuantLib::DayCounter &dayCounter,
            QuantLib::BusinessDayConvention accrualConvention,
            QuantLib::BusinessDayConvention paymentConvention,
            const QuantLib::Calendar& calendar,
            const bool &startFromEnd,
            const bool &longFinal,
            const std::string &discCurveId);
    };
}

#endif

