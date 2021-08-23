#ifdef HAVE_CONFIG_H
#include <qlo/config.hpp>
#endif

#include <qlo/interpolatedfxfwdpointstructure.hpp>
#include <qlo/forwardexchangerate.hpp>

#include <ql/math/interpolations/forwardflatinterpolation.hpp>
#include <ql/math/interpolations/backwardflatinterpolation.hpp>
#include <ql/math/interpolations/loginterpolation.hpp>
#include <ql/math/interpolations/cubicinterpolation.hpp>

#include <boost/algorithm/string/case_conv.hpp>

using boost::algorithm::to_upper_copy;

namespace QuantLibAddin {

    InterpolatedFxForwardPointTermStructure::InterpolatedFxForwardPointTermStructure(
        const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
        const QuantLib::Date& referenceDate,
        const std::vector<boost::shared_ptr<QuantLib::ForwardExchangeRate>>& fwdXRates,
        const QuantLib::DayCounter& dayCounter,
        const QuantLib::Calendar& calendar,
        const std::string& interpolatorID,
        bool permanent)
        : FxForwardPointTermStructure(properties, permanent),
        interpolatorID_(to_upper_copy(interpolatorID))
    {
        std::vector<QuantLib::ForwardExchangeRate> fwdExchangeRates;
        for (std::vector<boost::shared_ptr<QuantLib::ForwardExchangeRate>>::const_iterator i = fwdXRates.begin(); i != fwdXRates.end(); ++i)
            fwdExchangeRates.push_back(**i);

        if (interpolatorID_ == "BACKWARDFLAT") {
            libraryObject_ = boost::shared_ptr<QuantLib::Extrapolator>(
                new QuantLib::InterpolatedFxForwardPointTermStructure<QuantLib::BackwardFlat>(
                    referenceDate, fwdExchangeRates, dayCounter, calendar));
        }
        else if (interpolatorID_ == "FORWARDFLAT") {
            libraryObject_ = boost::shared_ptr<QuantLib::Extrapolator>(
                new QuantLib::InterpolatedFxForwardPointTermStructure<QuantLib::ForwardFlat>(
                    referenceDate, fwdExchangeRates, dayCounter, calendar));
        }
        else if (interpolatorID_ == "LINEAR") {
            libraryObject_ = boost::shared_ptr<QuantLib::Extrapolator>(
                new QuantLib::InterpolatedFxForwardPointTermStructure<QuantLib::Linear>(
                    referenceDate, fwdExchangeRates, dayCounter, calendar));
        }
        else if (interpolatorID_ == "LOGLINEAR") {
            libraryObject_ = boost::shared_ptr<QuantLib::Extrapolator>(
                new QuantLib::InterpolatedFxForwardPointTermStructure<QuantLib::LogLinear>(
                    referenceDate, fwdExchangeRates, dayCounter, calendar));
        }
        else if (interpolatorID_ == "CUBICNATURALSPLINE") {
            libraryObject_ = boost::shared_ptr<QuantLib::Extrapolator>(
                new QuantLib::InterpolatedFxForwardPointTermStructure<QuantLib::Cubic>(
                    referenceDate, fwdExchangeRates, dayCounter, calendar));
        }
        else if (interpolatorID_ == "LOGCUBICNATURALSPLINE") {
            libraryObject_ = boost::shared_ptr<QuantLib::Extrapolator>(
                new QuantLib::InterpolatedFxForwardPointTermStructure<QuantLib::LogCubic>(
                    referenceDate, fwdExchangeRates, dayCounter, calendar,
                    QuantLib::LogCubic(QuantLib::CubicInterpolation::Spline, false,
                        QuantLib::CubicInterpolation::SecondDerivative, 0.0,
                        QuantLib::CubicInterpolation::SecondDerivative, 0.0)));
        }
        else
            QL_FAIL("unknown interpolatorID: " << interpolatorID_);
    }


#define RESOLVE_TEMPLATE(NAME) \
        if (interpolatorID_=="BACKWARDFLAT") { \
            return boost::dynamic_pointer_cast<QuantLib::InterpolatedFxForwardPointTermStructure<QuantLib::BackwardFlat> >(libraryObject_)->NAME(); \
        } else if (interpolatorID_=="FORWARDFLAT") { \
            return boost::dynamic_pointer_cast<QuantLib::InterpolatedFxForwardPointTermStructure<QuantLib::ForwardFlat> >(libraryObject_)->NAME(); \
        } else if (interpolatorID_=="LINEAR") { \
            return boost::dynamic_pointer_cast<QuantLib::InterpolatedFxForwardPointTermStructure<QuantLib::Linear> >(libraryObject_)->NAME(); \
        } else if (interpolatorID_=="LOGLINEAR") { \
            return boost::dynamic_pointer_cast<QuantLib::InterpolatedFxForwardPointTermStructure<QuantLib::LogLinear> >(libraryObject_)->NAME(); \
        } else if (interpolatorID_=="CUBICNATURALSPLINE") { \
            return boost::dynamic_pointer_cast<QuantLib::InterpolatedFxForwardPointTermStructure<QuantLib::Cubic> >(libraryObject_)->NAME(); \
        } else if (interpolatorID_=="LOGCUBICNATURALSPLINE") { \
            return boost::dynamic_pointer_cast<QuantLib::InterpolatedFxForwardPointTermStructure<QuantLib::LogCubic> >(libraryObject_)->NAME(); \
        } else \
            QL_FAIL("unknown interpolatorID: " << interpolatorID_);

    const std::vector<QuantLib::Time>& InterpolatedFxForwardPointTermStructure::times() const {
        RESOLVE_TEMPLATE(times)
    }

    const std::vector<QuantLib::Date>& InterpolatedFxForwardPointTermStructure::dates() const {
        RESOLVE_TEMPLATE(dates)
    }

    const std::vector<QuantLib::Real>& InterpolatedFxForwardPointTermStructure::data() const {
        RESOLVE_TEMPLATE(data)
    }

    const std::vector<QuantLib::Real>& InterpolatedFxForwardPointTermStructure::forwardPointsVector() const {
        RESOLVE_TEMPLATE(forwardPointsVector)
    }


    InterpolatedFxForwardPointTermStructure::InterpolatedFxForwardPointTermStructure(
        const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
        const std::string& interpolatorID,
        bool permanent)
        : FxForwardPointTermStructure(properties, permanent),
        interpolatorID_(interpolatorID) {
    }

}