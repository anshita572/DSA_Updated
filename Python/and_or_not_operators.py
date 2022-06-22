is_female=True
is_smart=True
if is_female and is_smart :
    print("You are a smart female")
elif not(is_female) and is_smart :
    print("You are not a female but you are smart")
elif is_female and not(is_smart) :
    print("You are a female but you are not smart")
else :
    print("You are neither a female nor smart")