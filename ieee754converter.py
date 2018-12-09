x = float(input())                                          # Faktyczny kod
znak = int(x<=0)
cecha = -126
while cecha < 128 and abs(x) >= 2**cecha:
    cecha = cecha + 1
cecha = cecha + 126
mantysa = float(abs(x)/(2**(cecha - 127))) - 1
print(znak, ' ', cecha, ' ',mantysa + 1)
c = []                                                      # Wyświetlanie
while True:
    c.insert(0,(cecha % 2))
    if cecha <= 1: break
    else: cecha = int(cecha/2)
i = len(c)
while i < 8:
    c.insert(0,0)
    i = i + 1
bitcecha = ''.join(str(i) for i in c)
m = []
i = 0
while i <= 21:
    pom = mantysa * 2 >= 1
    m.append(int(pom))
    mantysa = mantysa * 2
    if pom: mantysa = mantysa - 1
    i = i + 1
bitmantysa = ''.join(str(i) for i in m)
print (znak,bitcecha,bitmantysa)