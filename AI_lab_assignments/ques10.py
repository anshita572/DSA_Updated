# ques10
from calculateCompound import *


def compound_interest(p, r, t):
    n = 1  # yearly
    f = (1+(r/n))
    m = pow(f, n*t)
    ci = p*m
    return ci


# (a)
print(compound_interest(4000, 0.2, 7))

# (b)
print(compound_interest(4000, 0.2, 7))
