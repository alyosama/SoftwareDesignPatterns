#include <iostream>
using namespace std;
class PayPal {

public:
   void sendPayment(int amount) {
        // Paying via Paypal //
        cout<<"Paying via PayPal: "<<amount;
    }
};

class PaymentAdapter {
public:
    virtual void pay(int amount)=0;
};

class PaypalAdapter : public PaymentAdapter {

private:
    PayPal* paypal;

public:
    PaypalAdapter(PayPal *paypal) {
        this->paypal = paypal;
    }

    void pay(int amount) {
        this->paypal->sendPayment(amount);
    }
};
int main(){
    PaypalAdapter paypal= new PaypalAdapter(new PayPal());
    paypal.pay(2629);
}


