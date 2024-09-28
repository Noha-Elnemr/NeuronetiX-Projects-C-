#include "order.h"
#include "product.h"
#include "user.h"
#include "cart.h"
#include <iostream>

cart cartOrder;

order::order()
{

}
order::~order()
{

}


void order::summary(vector<product> &shoppingCart) {

    cartOrder.view(shoppingCart);
    cout << "shipping details: " << shippingDetails << endl;
    if (!paymentStatus) {
        cout << "order not confirmed" << endl;
    }

}

void order::processPayment() {

    cout << "processing payment..." << endl;
    paymentStatus = true;
    cout << "payment successful!" << endl;

}

void order::confirmOrder() {

    processPayment();

    shippingDetails = "shipped";

    if (paymentStatus) {
        cout << "order confirmed!" << endl;
        cout << "shipping details: " << shippingDetails << endl;
    }
    else {
        cout << "payment not completed. order cannot be confirmed." << endl;
    }
}


