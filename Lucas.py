def calc(n, r, p):
    c = [0] * (n + 1)
    c[0] = 1
    for i in range(1, (n + 1)):
        j = min(i, r)
        while(j > 0):
            c[j] = (c[j] + c[j - 1]) % p
            j -= 1
    return c[r]
def Luc(n, r, p):
    if (r == 0):
        return 1;
    ni = int(n % p)
    ri = int(r % p)
    return (Luc(int(n / p), int(r / p), p) * calc(ni, ri, p)) % p;
n1 = input ("n: ")
r1 = input ("r: ")
p1 = input ("p: ")
n = int(n1)
r = int(r1)
p = int(p1)
print(Luc(n, r, p))