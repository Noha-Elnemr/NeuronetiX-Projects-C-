# Online Shopping Cart System

## Purpose and Concept

The Online Shopping Cart System simulates an e-commerce platform where users can browse a catalog of products, manage their shopping carts, and proceed to checkout. This project explores advanced OOP concepts, including polymorphism, interfaces, and composition, and integrates user interaction with product management and checkout processes.

## Main Features

### Product Catalog

- **Browse Products**: Display a list of products with details such as name, description, price, and stock quantity.
- **Search and Filter**: Allow users to search for products and apply filters based on categories or price ranges.

### Shopping Cart

- **Add/Remove Items**: Enable users to add products to their cart, update quantities, or remove items.
- **View Cart**: Provide a summary view of the cart, including item details, quantities, and total price.
- **Apply Discounts**: Implement functionality to apply discount codes or promotions to the cart.

### Checkout Process

- **Order Summary**: Display a final summary of the order before purchase, including total cost and shipping details.
- **Payment Processing**: Simulate payment processing, which might include integrating with a mock payment gateway.
- **Order Confirmation**: Provide confirmation to users after a successful purchase, including order details and estimated delivery time.

### Classes

- **Product**: Attributes include name, description, price, and stock quantity.
- **Cart**: Methods include `addItem()`, `removeItem()`, `updateQuantity()`, and `calculateTotal()`.
- **User**: Attributes include user information and cart details.
- **Order**: Attributes include order summary, payment status, and shipping details.

### Relationships

- **Aggregation**: `User` has a `Cart`, and a `Cart` contains multiple `Products`.
- **Association**: `Order` is associated with `User` and contains a `Cart`.

## How to run the project

- **in the terminal write** `g++ main.cpp -o main`
- **to genrate** `./main`
