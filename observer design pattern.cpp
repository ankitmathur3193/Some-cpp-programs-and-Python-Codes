#include<iostream>
#include<vector>
using namespace std;
/*
	A program to simulate stock market system
	Author:Ankit Mathur
*/




//Observer abstract class
class Observer
{
	
	public:
		virtual void update()=0;
		
};
//Subject abstract class
class Subject
{
	public:
		virtual void RegisterObserver(Observer *o)=0;//Used to register obserervers for this subject
		virtual void notifyObserver()=0;//Used to notify all Observers
};
class StockPriceGrabber:public Subject//Class for stock price subject
{
	/*
	It will privide methods to update and get stock prices of different companies
	Whenever a stock price updates,It will notify all the Observers.
	*/
	private:
		int IbmPrice;//It will store IBM Stock Price
		int GooglePrice;//It wil store Google Stock Price
		int SamsungPrice;//It will store Samsung Stock Price

		vector<Observer *>Observer_list;//It will store list of observers
	public:
		StockPriceGrabber(int IbmPrice,int GooglePrice,int SamsungPrice)
		{
			this->IbmPrice=IbmPrice;
			this->GooglePrice=GooglePrice;
			this->SamsungPrice=SamsungPrice;
		}
		int getIbmPrice()
		{
			return IbmPrice;
		}	
		int getGooglePrice()
		{
			return GooglePrice;
		}
		int getSamsungPrice()
		{
			return SamsungPrice;
		}
		void setIbmPrice(int val)
		{
			IbmPrice=val;
			notifyObserver();
		}
		void setGooglePrice(int val)
		{
			GooglePrice=val;
			notifyObserver();
		}
		void setSamsungPrice(int val)
		{
			SamsungPrice=val;
			notifyObserver();
		}
		void RegisterObserver(Observer *o)//Used by Observers to register
		{
			Observer_list.push_back(o);
		}
		void notifyObserver()//Used for notifying all Observers
		{
			for(int i=0;i<Observer_list.size();++i)
			{
				Observer_list[i]->update();
			}
		}
};
class GoogleObserver:public Observer//A class for Observing only Google stock prices
{
	private:
		int GooglePrice;//variable for storing current Google stock price
		StockPriceGrabber *model;
	public:
		GoogleObserver(StockPriceGrabber *s)
		{
			model=s;
			model->RegisterObserver(this);//registering this object
			GooglePrice=model->getGooglePrice();

		}
		void update()//This will be called as soon as price gets updated
		{
			GooglePrice=model->getGooglePrice();
			cout<<"GooglePrice updated "<<GooglePrice<<endl;
		}	

};
class AllStockPriceObserver:public Observer//Class for observing all Stock Prices
{
	private:
		int GooglePrice;
		int IbmPrice;
		int SamsungPrice;
		StockPriceGrabber *model;
	public:
		AllStockPriceObserver(StockPriceGrabber *s)
		{
			model = s;
			model->RegisterObserver(this);
			GooglePrice=model->getGooglePrice();
			SamsungPrice=model->getSamsungPrice();
			IbmPrice=model->getIbmPrice();
		}	
		void update()
		{
			GooglePrice=model->getGooglePrice();
			SamsungPrice=model->getSamsungPrice();
			IbmPrice=model->getIbmPrice();
			cout<<"GooglePrice: "<<GooglePrice<<" IbmPrice: "<<IbmPrice<<" SamsungPrice: "<<SamsungPrice<<endl;
		}
};
int main()
{
	StockPriceGrabber *source = new StockPriceGrabber(10,15,20);//stock price grabber instance
	GoogleObserver *dest1 = new GoogleObserver(source);
	AllStockPriceObserver *dest2 = new AllStockPriceObserver(source);
	source->setGooglePrice(10);
	return 0;
}