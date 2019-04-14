output : StockTeller.o definitions.o
	g++ StockTeller.o definitions.o -o output

StockTeller.o : StockTeller.cpp 
	g++ -c StockTeller.cpp

definitions.o : definitions.cpp ShopDetails.h
	g++ -c definitions.cpp

clean : 
	rm.*o output