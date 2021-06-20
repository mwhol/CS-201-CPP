// MIKE WHOLEY
// ASSIGNMENT 5
// 11/8/2018

#include "pch.h"
#include "Product.h"


Product::Product() {
	price = 0.0;
	quantity = 0;
	description = "";
}

Product::Product(double price, int quantity) {
	this->price = price;
	this->quantity = quantity;
	description = "";
}

void Product::setPrice(double price) {
	this->price = price;
}

void Product::setQuantity(int quantity) {
	this->quantity = quantity;
}

void Product::setDescription(string description) {
	this->description = description;
}

double Product::calculateTotal() {
	return quantity * price;
}