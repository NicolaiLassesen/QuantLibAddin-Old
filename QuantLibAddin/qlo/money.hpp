#ifndef qla_money_hpp
#define qla_money_hpp

#include <oh/libraryobject.hpp>

#include <ql/money.hpp>

namespace QuantLibAddin {

    class Money : public ObjectHandler::LibraryObject<QuantLib::Money> {
    public:
        Money(
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            const QuantLib::Currency& currency,
            const QuantLib::Real value,
            bool permanent);

        const QuantLib::Currency& currency() const;
        QuantLib::Real value() const;
    };
}

#endif
