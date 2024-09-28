#include "user.h"
#include "product.h"
#include "cart.h"
#include "order.h"

cart userCart;

user::user()
{

}

user::user(string newName, int phone, string emailAddress, string city, string streetName, int buildingNo, int floorNo, int apartmentNo)
{
	name = newName;
	contactInformation.phoneNumber = phone;
	contactInformation.email = emailAddress;
	shippingAddress.city = city;
	shippingAddress.streetName = streetName;
	shippingAddress.buildingNumber = buildingNo;
	shippingAddress.floorNumber = floorNo;
	shippingAddress.apartmentNumber = apartmentNo;
}
user::~user()
{

}

void user::viewCart(vector<product>&shoppingCart) {

	userCart.view(userCart.shoppingCart);
	//cart::view(cart::shoppingCart);

}

//void user::checkout() {
//
//	cout << "your cart:" << endl;
//
//	cart::view();
//
//
//
//}






