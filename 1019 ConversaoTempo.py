import math
N = int(input(''))
hora = N//3600
min = ((N - hora * 3600) / 60)
seg = N%60
print('{}:{}:{}'.format(math.floor(hora), math.floor(min), seg))