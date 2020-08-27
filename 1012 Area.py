A,B,C = map(float,input().split())

AreaTriangulo = (A*C)/2
AreaCirculo = (3.14159)*(C**2)
AreaTrapezio = ((A+B)*C)/2
AreaQuadrado = B*B
AreaRetangulo = A*B
print('TRIANGULO: {:0.3f}'.format(AreaTriangulo))
print('CIRCULO: {:0.3f}'.format(AreaCirculo))
print('TRAPEZIO: {:0.3f}'.format(AreaTrapezio))
print('QUADRADO: {:0.3f}'.format(AreaQuadrado))
print('RETANGULO: {:0.3f}'.format(AreaRetangulo))