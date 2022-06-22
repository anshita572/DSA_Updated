def compound_interest(p, r, t):
    n = 1  # yearly
    f = (1+(r/n))
    m = pow(f, n*t)
    ci = p*m
    return ci
