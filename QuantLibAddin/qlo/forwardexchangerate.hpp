#ifndef qla_forward_exchangerate_hpp
#define qla_forward_exchangerate_hpp

#include <oh/libraryobject.hpp>

#include <ql/forwardexchangerate.hpp>
#include <qlo/exchangerate.hpp>

namespace QuantLibAddin {

    class ForwardExchangeRate : public ObjectHandler::LibraryObject<QuantLib::ForwardExchangeRate> {
    public:
        ForwardExchangeRate(
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            const QuantLib::ExchangeRate& spotRate,
            const QuantLib::Real forwardPoints,
            const QuantLib::Period& tenor,
            bool permanent);

        const QuantLib::Currency& baseCurrency() const;
        const QuantLib::Currency& quoteCurrency() const;
        QuantLib::Real spotRate() const;
        QuantLib::Real forwardPoints() const;
        QuantLib::Real forwardRate() const;
        const QuantLib::Period& tenor() const;
        QuantLib::ExchangeRate::Type type() const;

        QuantLib::Money exchange(const QuantLib::Money& amount) const;
    };
}

#endif
