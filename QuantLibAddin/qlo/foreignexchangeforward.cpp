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

    QuantLib::Real ForeignExchangeForward::fairForwardPoints() const {
        return forward_->fairForwardPoints();
    }

    QuantLib::Real ForeignExchangeForward::forwardNetValueBase() const {
        return forward_->forwardNetValueBase().value();
    }
    
    QuantLib::Real ForeignExchangeForward::forwardNetValueTerm() const {
        return forward_->forwardNetValueTerm().value();
    }

    QuantLib::Real ForeignExchangeForward::presentNetValueBase() const {
        return forward_->presentNetValueBase().value();
    }

    QuantLib::Real ForeignExchangeForward::presentNetValueTerm() const {
        return forward_->presentNetValueTerm().value();
    }

    QuantLib::Real ForeignExchangeForward::forwardGrossValueBase() const {
        return forward_->forwardGrossValueBase().value();
    }

    QuantLib::Real ForeignExchangeForward::forwardGrossValueTerm() const {
        return forward_->forwardGrossValueTerm().value();
    }

}