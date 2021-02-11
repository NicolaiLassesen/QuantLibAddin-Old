#ifndef qla_interpolatedfxfwdpointstructure_hpp
#define qla_interpolatedfxfwdpointstructure_hpp

#include <qlo/termstructures.hpp>
#include <qlo/forwardexchangerate.hpp>

#include <ql/termstructures/fxforwardpointtermstructure.hpp>

namespace QuantLibAddin {

    class InterpolatedFxForwardPointTermStructure : public FxForwardPointTermStructure {
    public:
        // placeholders for QuantLib types of the same name.
        enum Interpolator {
            BackwardFlat,
            ForwardFlat,
            Linear,
            LogLinear,
            CubicNaturalSpline,
            LogCubicNaturalSpline
        };
        InterpolatedFxForwardPointTermStructure(
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            const QuantLib::Date& referenceDate,
            const std::vector<boost::shared_ptr<QuantLib::ForwardExchangeRate>>& fwdXRates,
            const QuantLib::DayCounter& dayCounter,
            const QuantLib::Calendar& calendar,
            const std::string& interpolatorID,
            bool permanent = false);
        const std::vector<QuantLib::Time>& times() const;
        const std::vector<QuantLib::Date>& dates() const;
        const std::vector<QuantLib::Real>& data() const;
        const std::vector<QuantLib::Real>& forwardPointsVector() const;
    protected:
        InterpolatedFxForwardPointTermStructure(
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            const std::string& interpolatorID,
            bool permanent);
        std::string interpolatorID_;
    };

}

#endif