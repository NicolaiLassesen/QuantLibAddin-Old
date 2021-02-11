#include <qlo/qladdindefines.hpp>
#include <qlo/money.hpp>

namespace QuantLibAddin {

    Money::Money(
        const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
        const QuantLib::Currency& currency,
        const QuantLib::Decimal value,
        bool permanent) : ObjectHandler::LibraryObject<QuantLib::Money>(properties, permanent) {
        libraryObject_ = boost::shared_ptr<QuantLib::Money>(
            new QuantLib::Money(currency, value));
    }

    const QuantLib::Currency& Money::currency() const {
        return libraryObject_->currency();
    }

    QuantLib::Real Money::value() const {
        return libraryObject_->value();
    }

}