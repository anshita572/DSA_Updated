# Dictionary is a collection of key-value pairs
# syntax :
# dictionary_name ={ key : value ,}
# keys have to be unique and it can be strings ,numbers

monthConversion={
    "Jan" : "January",
    "Feb" : "February",
    "Mar" : "March",
    1     : "April" ,
    # and so on we can give key-value pairs
}
print(monthConversion["Feb"])
#print(monthConversion["hi"])key does not exist,so gives error
print(monthConversion.get("Jan"))
print(monthConversion.get("hi")) #if key does not exist,it does not give error but returns none
print(monthConversion.get("hi","Not a valid key"))
print(monthConversion.get(1,"Not a valid key"))
#using .get(,) ,we can pass 2 parameters