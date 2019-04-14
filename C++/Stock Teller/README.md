# Stock Teller Project Description

Given Project intends to keep the information about various products in a shopping mall. Project can tell the description about each
and every product like its currrent stock and price. These details will be shown to the User, who will buy various products. The User
information must be stored. And finally display his purchasing details.

# Details about each file
###1. ShopDetails.h: 
  This file contains all the structures and classes which will be used in the main program.
  This file is well documented using comments describing the usage each and every function

###2. definitions.cpp: 
  This file contains all the definitions of all the methods declared in the ShopDetails.h
  This is also well documented with the comments
  
###3. Stock Teller.cpp: 
  This is the main program of the project. It uses the definitions in the definitions.cpp and do several tasks given in the project description.
  
## Makefile
  If you are well aware of the makefile and its usage, I have created a makefile also.
  If you don't know such thing then use the following code in your cmd(Windows) or Linux terminal
  ```bash
  g++ "Stock Teller.cpp" definitions.cpp -o out
  ```

