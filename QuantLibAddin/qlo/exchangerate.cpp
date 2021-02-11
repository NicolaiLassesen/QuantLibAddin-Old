#include <qlo/qladdindefines.hpp>
#include <qlo/exchangerate.hpp>

namespace QuantLibAddin {

    ExchangeRate::ExchangeRate(
        const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
        const QuantLib::Currency& base,
        const QuantLib::Currency& term,
        const QuantLib::Real rate,
        bool permanent) : ObjectHandler::LibraryObject<QuantLib::ExchangeRate>(properties, permanent) {
        libraryObject_ = boost::shared_ptr<QuantLib::ExchangeRate>(
            new QuantLib::ExchangeRate(base, term, rate));
    }

    const QuantLib::Currency& ExchangeRate::baseCurrency() const {
        return libraryObject_->source();
    }

    const QuantLib::Currency& ExchangeRate::quoteCurrency() const {
        return libraryObject_->target();
    }

    QuantLib::Real ExchangeRate::rate() const {
        return libraryObject_->rate();
    }

    QuantLib::ExchangeRate::Type ExchangeRate::type() const {
        return libraryObject_->type();
    }

    QuantLib::Money ExchangeRate::exchange(const QuantLib::Money& amount) const {
        return libraryObject_->exchange(amount);
    }

}