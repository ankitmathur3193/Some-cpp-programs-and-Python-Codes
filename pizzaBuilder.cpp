#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
//Product
//it is the final product which will be made by builder
class Pizza
{
public:
	void setDough(const string& dough)
	{
		p_dough=dough;
	}
	void setSauce(const string& sauce)
	{
		p_sauce=sauce;
	} 
	void setTopping(const string& topping)
	{
		p_topping=topping;
	}
	void setPrice(const float &price)
	{
		p_price=price;
	}
	void open()
	{
		cout<<"Pizza with "<<p_dough<<" dough "<<p_sauce<<" sauce and "<<p_topping<<" topping having price "
		<<p_price<<endl;
	}
private:
	string p_topping;
	string p_sauce;
	string p_dough;
	float p_price;
};
//Abstract Builder
//An interface which will be implemented by all builder classes
class PizzaBuilder
{
public:
	virtual ~PizzaBuilder(){};
	Pizza *getPizza()
	{
		return p_pizza;
	}
	void createNewPizzaProduct()
	{
		p_pizza=new Pizza;
	}
	virtual void buildDough()=0;
	virtual void buildSauce()=0;
	virtual void buildTopping()=0;
	virtual void buildPrice()=0;
protected:
Pizza *p_pizza;	

};
class PeppyPaneerPizza:public PizzaBuilder
{
public:
	virtual ~PeppyPaneerPizza(){};
	virtual void buildDough()
	{
		p_pizza->setDough("cross");
	}
	virtual void buildSauce()
	{
		p_pizza->setSauce("mild");
	}
	virtual void buildTopping()
	{
		p_pizza->setTopping("paneer+onion");
	}
	virtual void buildPrice()
	{
		p_pizza->setPrice(156.25);
	}
};
class FarmHousePizza : public PizzaBuilder
{
public:
	virtual ~FarmHousePizza(){};
	virtual void buildDough()
	{
		p_pizza->setDough("pan baked");
	}
	virtual void buildSauce()
	{
		p_pizza->setSauce("hot");
	}
	virtual void buildTopping()
	{
		p_pizza->setTopping("Pepperoni+salami");
	}
	virtual void buildPrice()
	{
		p_pizza->setPrice(350.28);
	}
};
///Director
//This will direct the builder instanses to build different types of pizza
class Director
{
public:
	void openPizza()
	{
		p_pizzaBuilder->getPizza()->open();
	}
	void makePizza(PizzaBuilder* pb)
	{
		p_pizzaBuilder=pb;
		p_pizzaBuilder->createNewPizzaProduct();
		p_pizzaBuilder->buildDough();
		p_pizzaBuilder->buildSauce();
		p_pizzaBuilder->buildTopping();
		p_pizzaBuilder->buildPrice();
	}
private:
	PizzaBuilder *p_pizzaBuilder;
};

int main()
{
	Director cook;
	FarmHousePizza farmHousePizza;
	PeppyPaneerPizza peppyPaneerPizza;

	cook.makePizza(&farmHousePizza);
	cook.openPizza();

	cook.makePizza(&peppyPaneerPizza);
	cook.openPizza();
	return 0;
}