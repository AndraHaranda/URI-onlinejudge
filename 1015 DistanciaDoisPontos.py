import math
x1, y1 = map(float, input().split())
x2, y2 = map(float, input().split())
distancia = math.sqrt((x2-x1)**2 + (y2-y1)**2)
print('{:.4f}'.format(distancia))X = int(input(''))
Y = float(input(''))
total = (X / Y)
print('{:.3f} km/l'.format(total))