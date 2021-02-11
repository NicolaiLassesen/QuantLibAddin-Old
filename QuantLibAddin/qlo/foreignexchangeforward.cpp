#include <qlo/qladdindefines.hpp>
#include <qlo/foreignExchangeForward.hpp>

namespace QuantLibAddin {

    ForeignExchangeForward::ForeignExchangeForward(
        const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
        const QuantLib::Date& deliveryDate,
        const QuantLib::Money& baseNotionalAmount,
        const QuantLib::ExchangeRate& contractAllInRate,
        const QuantLib::ForeignExchangeForward::Type& forwardType,
        bool permanent)
        : Instrument(properties, permanent) {
        libraryObject_ = forward_ = boost::shared_ptr<QuantLib::ForeignExchangeForward>(
            new QuantLib::ForeignExchangeForward(deliveryDate, baseNotionalAmount, contractAllInRate, forwardType));
    }

    const QuantLib::ForeignExchangeForward::Type ForeignExchangeForward::forwardType() const {
        return forward_->forwardType();
    }

    const QuantLib::Date& ForeignExchangeForward::deliveryDate() const {
        return forward_->deliveryDate();
    }
    
    const QuantLib::Currency& ForeignExchangeForward::baseCurrency() const {
        return forward_->baseCurrency();
    }

    const QuantLib::Currency& ForeignExchangeForward::termCurrency() const {
        return forward_->termCurrency();
    }

}