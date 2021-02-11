#include <qlo/qladdindefines.hpp>
#include <qlo/forwardExchangeRate.hpp>
#include <ql/time/period.hpp>

namespace QuantLibAddin {

    ForwardExchangeRate::ForwardExchangeRate(
        const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
        const QuantLib::ExchangeRate& spotRate,
        const QuantLib::Real forwardPoints,
        const QuantLib::Period& tenor,
        bool permanent) : ObjectHandler::LibraryObject<QuantLib::ForwardExchangeRate>(properties, permanent) {
        libraryObject_ = boost::shared_ptr<QuantLib::ForwardExchangeRate>(
            new QuantLib::ForwardExchangeRate(spotRate, forwardPoints, tenor));
    }

    const QuantLib::Currency& ForwardExchangeRate::baseCurrency() const {
        return libraryObject_->source();
    }

    const QuantLib::Currency& ForwardExchangeRate::quoteCurrency() const {
        return libraryObject_->target();
    }

    QuantLib::Real ForwardExchangeRate::spotRate() const {
        return libraryObject_->spotRate();
    }

    QuantLib::Real ForwardExchangeRate::forwardPoints() const {
        return libraryObject_->forwardPoints();
    }

    QuantLib::Real ForwardExchangeRate::forwardRate() const {
        return libraryObject_->forwardRate();
    }

    const QuantLib::Period& ForwardExchangeRate::tenor() const {
        return libraryObject_->tenor();
    }

    QuantLib::ExchangeRate::Type ForwardExchangeRate::type() const {
        return libraryObject_->type();
    }

    QuantLib::Money ForwardExchangeRate::exchange(const QuantLib::Money& amount) const {
        return libraryObject_->exchange(amount);
    }

}