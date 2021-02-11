#ifndef qla_exchangerate_hpp
#define qla_exchangerate_hpp

#include <oh/libraryobject.hpp>

#include <ql/exchangerate.hpp>

namespace QuantLibAddin {

    class ExchangeRate : public ObjectHandler::LibraryObject<QuantLib::ExchangeRate> {
    public:
        ExchangeRate(
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            const QuantLib::Currency& base,
            const QuantLib::Currency& term,
            const QuantLib::Real rate,
            bool permanent);

        const QuantLib::Currency& baseCurrency() const;
        const QuantLib::Currency& quoteCurrency() const;
        QuantLib::Real rate() const;
        QuantLib::ExchangeRate::Type type() const;

        QuantLib::Money exchange(const QuantLib::Money& amount) const;
    };
}

#endif
