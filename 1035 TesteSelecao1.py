entrada = list(map(int, input('').split()))

A = entrada[0]
B = entrada[1]
C = entrada[2]
D = entrada[3]

if B > C and D > A and C+D > A+B and C > 0 and D > 0 and A % 2 == 0:
  print('Valores aceitos')
else:
  print('Valores nao aceitos')