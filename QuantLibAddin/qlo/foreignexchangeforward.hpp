#ifndef qla_foreignexchangeforward_hpp
#define qla_foreignexchangeforward_hpp

#include <qlo/baseinstruments.hpp>
#include <qlo/exchangeRate.hpp>
#include <qlo/money.hpp>

#include <ql/handle.hpp>
#include <ql/instruments/ForeignExchangeForward.hpp>

namespace QuantLibAddin {

    class ForeignExchangeForward : public Instrument {
    public:
        ForeignExchangeForward(
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            const QuantLib::Date& deliveryDate,
            const QuantLib::Money& baseNotionalAmount,
            const QuantLib::ExchangeRate& contractAllInRate,
            const QuantLib::ForeignExchangeForward::Type& forwardType,
            bool permanent);

        const QuantLib::ForeignExchangeForward::Type forwardType() const;
        const QuantLib::Date& deliveryDate() const;
        const QuantLib::Currency& baseCurrency() const;
        const QuantLib::Currency& termCurrency() const;

        QuantLib::Real fairForwardPoints() const;
        QuantLib::Real forwardNetValueBase() const;
        QuantLib::Real forwardNetValueTerm() const;
        QuantLib::Real presentNetValueBase() const;
        QuantLib::Real presentNetValueTerm() const;
        QuantLib::Real forwardGrossValueBase() const;
        QuantLib::Real forwardGrossValueTerm() const;

    private:
        boost::shared_ptr<QuantLib::ForeignExchangeForward> forward_;
    };

}

#endif