def get_ind(pattern):
    b = len(pattern)
    ind = []
    for i in range(0,b):
        ind.append(0)
    n=0
    m=1
    while m!= b:
        if pattern[m] == pattern[n]:
            n += 1
            ind[m] = n
            m += 1
        elif n!= 0:
            n = prefix_arr[n-1]
        else:
            ind[m] = 0
            m += 1
    return ind

def KMP(pattern, text):
    a = len(text)
    b = len(pattern)
    ind = get_ind(pattern)
    initial = []
    m=0
    n=0
    while m!= a:
        if text[m] == pattern[n]:
            n += 1
            m += 1
        else:
            n = ind[n-1]

        if n == b:
            initial.append(m-n)
            n = ind[n-1]
        elif n == 0:
                m += 1

    return initial

pattern = str(input("Enter the patter nto be found: "))
text = str(input("Enter the complete text: "))
initial = KMP(pattern, text)
print("The starting index are: ", initial)
